#!/usr/bin/env python3
"""The start of the port's partition as one image for `fastboot flash`: for a phone whose partition
is one that the bootloader's fastboot can write as a whole (OnePlus 8: its userdata), instead of
writing it piece by piece from Android (tools/darwin-write.py, redwood's darwin).

usage: store-image.py [OUT]     (default userland/store.simg)

The layout is darwin's, the one the loader, the kernel and init expect (xnuloader/loader.c
BLOCK_WRITE_FIRST, bsd/dev/redwood_ufs.c UFS_WRITE_FIRST, userland/src/init.c flash_root):

  block 0        rootfs.apfs      the iOS volume (1374208 blocks of 4096): the APFS container in
                                  Apple's rootfs.dmg, `7z e -tdmg rootfs.dmg 3.apfs` (5628755968 bytes)
  block 1374208  cryptex-os.dmg   the OS cryptex: the dyld shared cache (665600 blocks)
  block 2039808  cryptex-app.dmg  the App cryptex (2560 blocks)
  block 2042368  where the writes of a run may begin (var_store's slots are further on)

The images are ios165/'s: the disk images ios165/fetch.sh downloads (KEEP=1 keeps them), the iOS volume
taken out of rootfs.dmg as above (the cryptexes are plain APFS containers as they are). Each must be exactly the
size above, a whole number of blocks; anything else and no image is made. The result is an Android
sparse image (img2simg) of exactly 2042368 blocks: fastboot writes those and leaves the rest of the
partition as it is.
"""
import os
import subprocess
import sys

BLOCK = 4096
LAYOUT = (('rootfs.apfs', 0, 1374208), ('cryptex-os.dmg', 1374208, 665600), ('cryptex-app.dmg', 2039808, 2560))
WRITE_FIRST = 2042368

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
IOS = os.path.join(ROOT, 'ios165')


def main():
    out = sys.argv[1] if len(sys.argv) > 1 else os.path.join(ROOT, 'userland', 'store.simg')
    raw = out + '.raw'
    end = 0
    for name, at, blocks in LAYOUT:
        path = os.path.join(IOS, name)
        if not os.path.isfile(path):
            sys.exit(f'store-image: no {path} (ios165/fetch.sh with KEEP=1; rootfs.apfs: 7z e -tdmg rootfs.dmg 3.apfs)')
        size = os.path.getsize(path)
        if size != blocks * BLOCK or at != end:
            sys.exit(f'store-image: {name} is {size} bytes at block {at}; the layout wants {blocks * BLOCK} at {end}')
        with open(path, 'rb') as f:
            magic = f.read(36)[32:36]
        if magic != b'NXSB':
            sys.exit(f'store-image: {name} is not an APFS container (no NXSB at 32)')
        end = at + blocks
    assert end == WRITE_FIRST
    with open(raw, 'wb') as o:
        for name, at, blocks in LAYOUT:
            with open(os.path.join(IOS, name), 'rb') as f:
                while chunk := f.read(64 << 20):
                    o.write(chunk)
        assert o.tell() == WRITE_FIRST * BLOCK
    subprocess.check_call(['img2simg', raw, out, str(BLOCK)])
    os.unlink(raw)
    print(f'store-image: {out}: {WRITE_FIRST} blocks ({WRITE_FIRST * BLOCK >> 20} MB) -- the iOS volume and both cryptexes')
    print(f'store-image: on the phone, in its bootloader\'s fastboot: fastboot flash userdata {out}')


if __name__ == '__main__':
    main()
