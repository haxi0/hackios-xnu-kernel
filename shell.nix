# Nix / NixOS: `nix-shell` at the top of the workspace gives the host tools the build and the
# runs need (common/setup.sh lists them). theos (cctools + iPhoneOS16.5.sdk) still comes from
# $THEOS as on any other Linux.
{ pkgs ? import <nixpkgs> { } }:
let
  llvm = pkgs.llvmPackages_21;
  # ios165/fetch.sh calls `7z` and needs 7-Zip 23+ (APFS); nixpkgs' p7zip is 17.x
  sevenZip = pkgs.writeShellScriptBin "7z" ''exec ${pkgs._7zz}/bin/7zz "$@"'';
  # Mu-Silicium's CLANGPDB toolchain (edk2 tools_def: $CLANG_BIN): unwrapped clang with lld and the
  # llvm tools; the Nix wrapper's --gcc-toolchain is an unused argument there, an error under -Werror
  clangPdb = pkgs.symlinkJoin { name = "clang-pdb"; paths = [ llvm.clang-unwrapped llvm.lld llvm.llvm ]; };
in
pkgs.mkShell {
  packages = with pkgs; [
    git curl sevenZip gcc llvm.clang llvm.lld llvm.llvm qemu python3
    flex bison gnum4 perl autoconf automake libtool gnumake xz lz4
    ncurses # tcsh (xnu-deps) needs tgetent()
    libuuid # uuid/uuid.h for the kernel build's host tools (xnu-deps/hostinc/hostcompat.h)
    nasm acpica-tools # Mu-Silicium (uefi/README.md): nasm in place of mu_nasm, iasl for ACPI
    meson ninja # tools/mk-mesa.sh (GL=1); llvm-ar is in llvm.llvm
    pkg-config libdrm expat zlib # tools/air/mk-host.sh: Mesa for this machine (air_run, softpipe)
  ];
  # the loader is freestanding and the kernel is Mach-O: no glibc hardening flags
  hardeningDisable = [ "all" ];
  # xnu-deps/host/bin/xnu-clang: the plain clang (no Nix wrapper adding glibc paths)
  XNU_CLANG_DIR = "${llvm.clang-unwrapped}/bin";
  CLANG_BIN = "${clangPdb}/bin/";
  # qemu/run.sh: the aarch64 UEFI firmware that ships with nixpkgs' qemu
  QEMU_EFI = "${pkgs.qemu}/share/qemu/edk2-aarch64-code.fd";
  QEMU_VARS = "${pkgs.qemu}/share/qemu/edk2-arm-vars.fd";
}
