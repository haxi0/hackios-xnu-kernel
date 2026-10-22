#!/bin/bash
# Save our changes to the Mu-Silicium tree (../Mu-Silicium, a clone of Project-Silicium/Mu-Silicium
# with the redwood port in it) into this directory: mu-silicium.patch for the files that upstream
# has, files/ for the ones it does not. apply.sh puts them into a fresh clone.
set -e
cd "$(dirname "$(readlink -f "$0")")"
MU=../Mu-Silicium
git -C $MU rev-parse HEAD > BASE
git -C $MU diff -- BootShim Silicon > mu-silicium.patch
rm -rf files
mkdir -p files/Resources/Configs files/Resources/DTBs files/Binaries \
	files/Silicon/Silicium/SiliciumPkg/Library/BootManagerLib
cp $MU/Silicon/Silicium/SiliciumPkg/Library/BootManagerLib/XnuLoader.[ch] files/Silicon/Silicium/SiliciumPkg/Library/BootManagerLib/
# the devices that are not upstream, as Vendor/codename; a device without Binaries/<codename> here
# uses a set of Mu-Silicium's Binaries submodule (instantnoodle: kebab's, the OnePlus 8T, same SoC)
for device in Xiaomi/redwood OnePlus/instantnoodle; do
	vendor=${device%/*} name=${device#*/}
	mkdir -p files/Platforms/$vendor
	cp -r $MU/Platforms/$vendor/${name}Pkg files/Platforms/$vendor/
	cp $MU/Resources/Configs/$name.toml files/Resources/Configs/
	cp $MU/Resources/DTBs/$name.dtb files/Resources/DTBs/
	[ -n "$(git -C $MU ls-files --others -- Binaries/$name 2>/dev/null)" ] || [ ! -d $MU/Binaries/$name ] ||
		git -C $MU/Binaries ls-files --error-unmatch $name >/dev/null 2>&1 || cp -r $MU/Binaries/$name files/Binaries/
done
find files -name __pycache__ -prune -exec rm -rf {} +
echo "uefi/export.sh: base $(cut -c1-12 BASE), patch $(wc -l < mu-silicium.patch) lines, $(find files -type f | wc -l) files"
