## Firmware Infos

- **Device:** OnePlus 8 (instantnoodle, IN2010), SM8250
- **Source:** the drivers of [Project-Silicium/Device-Binaries](https://github.com/Project-Silicium/Device-Binaries)
  `kebab` (OnePlus 8T, the same SoC), with Silicium's patches below, except the USB drivers:
  `UsbPwrCtrlDxe`, `UsbfnDwc3Dxe`, `UsbDeviceDxe`, `UsbConfigDxe`, `UsbInitDxe` are the OnePlus 8's
  own, `BOOT.XF.3.2-00295-SM8250-1` (OxygenOS 11), extracted from its `xbl_b` with
  [UEFIReader](https://github.com/WOA-Project/UEFIReader). With kebab's, the XNU loader's USB link
  did not start (`start_ex` returned EFI_NOT_FOUND); with these it does.
- `UsbConfigDxe` here is unpatched (kebab's removes the USB de-init at ExitBootServices).

## Patches/Fixes (kebab's set, from Device-Binaries)

### ButtonsDxe:

- Reason: Helps navigating Menus (e.g. UEFI Menu).
- Patch: Key code was patched for the power button to be mapped as ENTER instead of SUSPEND.
- Patch Creator: [Gustave Monce](https://github.com/gus33000)

### FeatureEnablerDxe:

- Reason: The TZ applet it already brought up.
- Patch: Both DXEs were patched to not start again the TZ applet.
- Patch Creator: [Gustave Monce](https://github.com/gus33000)

### UsbConfigDxe:

- Reason: Is Important to get USB working in Windows / Linux and UEFI.
- Patch Nr. 1: Exit BootServices routine was patched to not deinit USB after exit boot services.
- Patch Nr. 2: USB Mode has been Changed from Device Mode to Host Mode.
- Patch Creator: [Gustave Monce](https://github.com/gus33000) & [CloudSweets](https://github.com/cloudsweets)
