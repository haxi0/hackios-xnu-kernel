  INF MdeModulePkg/Core/Dxe/DxeMain.inf
  INF MdeModulePkg/Universal/PCD/Dxe/Pcd.inf
  INF ArmPkg/Drivers/CpuDxe/CpuDxe.inf
  INF MdeModulePkg/Core/RuntimeDxe/RuntimeDxe.inf
  INF MdeModulePkg/Universal/SecurityStubDxe/SecurityStubDxe.inf

  INF Binaries/instantnoodle/QcomPkg/Drivers/TzDxe/ScmDxeLA.inf
  #INF Binaries/instantnoodle/QcomPkg/Drivers/TzDxe/TzDxeLA.inf

  INF MdeModulePkg/Universal/WatchdogTimerDxe/WatchdogTimer.inf
  INF MdeModulePkg/Universal/CapsuleRuntimeDxe/CapsuleRuntimeDxe.inf
  INF MdeModulePkg/Universal/ReportStatusCodeRouter/RuntimeDxe/ReportStatusCodeRouterRuntimeDxe.inf
  INF MdeModulePkg/Universal/StatusCodeHandler/RuntimeDxe/StatusCodeHandlerRuntimeDxe.inf
  INF MdeModulePkg/Universal/Variable/RuntimeDxe/VariableRuntimeDxe.inf
  INF EmbeddedPkg/EmbeddedMonotonicCounter/EmbeddedMonotonicCounter.inf
  INF EmbeddedPkg/SimpleTextInOutSerial/SimpleTextInOutSerial.inf
  INF MdeModulePkg/Universal/ResetSystemRuntimeDxe/ResetSystemRuntimeDxe.inf
  INF EmbeddedPkg/RealTimeClockRuntimeDxe/RealTimeClockRuntimeDxe.inf
  INF EmbeddedPkg/MetronomeDxe/MetronomeDxe.inf
  INF MdeModulePkg/Universal/PrintDxe/PrintDxe.inf
  INF MdeModulePkg/Universal/DevicePathDxe/DevicePathDxe.inf
  INF MdeModulePkg/Universal/Console/ConPlatformDxe/ConPlatformDxe.inf
  INF MdeModulePkg/Universal/Console/ConSplitterDxe/ConSplitterDxe.inf
  INF MdeModulePkg/Universal/Console/GraphicsConsoleDxe/GraphicsConsoleDxe.inf
  INF MdeModulePkg/Universal/HiiDatabaseDxe/HiiDatabaseDxe.inf

  INF Binaries/instantnoodle/QcomPkg/Drivers/EnvDxe/EnvDxe.inf

  INF ArmPkg/Drivers/ArmGicDxe/ArmGicDxe.inf
  INF ArmPkg/Drivers/TimerDxe/TimerDxe.inf

  INF Binaries/instantnoodle/QcomPkg/Drivers/ChipInfoDxe/ChipInfoDxe.inf
  INF Binaries/instantnoodle/QcomPkg/Drivers/SmemDxe/SmemDxe.inf
  INF Binaries/instantnoodle/QcomPkg/Drivers/ULogDxe/ULogDxe.inf
  INF Binaries/instantnoodle/QcomPkg/Drivers/NpaDxe/NpaDxe.inf
  INF Binaries/instantnoodle/QcomPkg/Drivers/CmdDbDxe/CmdDbDxe.inf
  INF Binaries/instantnoodle/QcomPkg/Drivers/PwrUtilsDxe/PwrUtilsDxe.inf
  INF Binaries/instantnoodle/QcomPkg/Drivers/RpmhDxe/RpmhDxe.inf
!if $(USE_CUSTOM_DISPLAY_DRIVER) == 1
  INF Binaries/instantnoodle/QcomPkg/Drivers/CPRDxe/CPRDxe.inf
!endif
  INF Binaries/instantnoodle/QcomPkg/Drivers/PdcDxe/PdcDxe.inf

  INF MdeModulePkg/Universal/Disk/DiskIoDxe/DiskIoDxe.inf
  INF MdeModulePkg/Universal/Disk/PartitionDxe/PartitionDxe.inf
  INF FatPkg/EnhancedFatDxe/Fat.inf
  INF MdeModulePkg/Universal/Disk/UnicodeCollation/EnglishDxe/EnglishDxe.inf

  INF Binaries/instantnoodle/QcomPkg/Drivers/DALSYSDxe/DALSYSDxe.inf
  INF Binaries/instantnoodle/QcomPkg/Drivers/ClockDxe/ClockDxe.inf
  INF Binaries/instantnoodle/QcomPkg/Drivers/VcsDxe/VcsDxe.inf
  INF Binaries/instantnoodle/QcomPkg/Drivers/HALIOMMUDxe/HALIOMMUDxe.inf
  INF Binaries/instantnoodle/QcomPkg/Drivers/HWIODxe/HWIODxe.inf
  #INF Binaries/instantnoodle/QcomPkg/Drivers/GpiDxe/GpiDxe.inf
  INF Binaries/instantnoodle/QcomPkg/Drivers/I2CDxe/I2CDxe.inf
  INF Binaries/instantnoodle/QcomPkg/Drivers/SPIDxe/SPIDxe.inf
  INF Binaries/instantnoodle/QcomPkg/Drivers/SPMIDxe/SPMIDxe.inf
  INF Binaries/instantnoodle/QcomPkg/Drivers/SdccDxe/SdccDxe.inf
  INF Binaries/instantnoodle/QcomPkg/Drivers/UFSDxe/UFSDxe.inf
  INF Binaries/instantnoodle/QcomPkg/Drivers/TLMMDxe/TLMMDxe.inf
  INF Binaries/instantnoodle/QcomPkg/Drivers/FeatureEnablerDxe/FeatureEnablerDxe.inf

!if $(USE_CUSTOM_DISPLAY_DRIVER) == 1
  INF Binaries/instantnoodle/QcomPkg/Drivers/DisplayDxe/DisplayDxe.inf
!else
  INF SiliciumPkg/Drivers/SimpleFbDxe/SimpleFbDxe.inf
!endif

  INF Binaries/instantnoodle/QcomPkg/Drivers/PlatformInfoDxe/PlatformInfoDxe.inf
  INF Binaries/instantnoodle/QcomPkg/Drivers/ButtonsDxe/ButtonsDxe.inf
  INF Binaries/instantnoodle/QcomPkg/Drivers/PmicDxe/PmicDxeLa.inf
  INF Binaries/instantnoodle/QcomPkg/Drivers/ChargerExDxe/ChargerExDxe.inf
  INF Binaries/instantnoodle/QcomPkg/Drivers/QcomChargerDxe/QcomChargerDxeLA.inf
  INF Binaries/instantnoodle/QcomPkg/Drivers/UsbPwrCtrlDxe/UsbPwrCtrlDxe.inf
  INF Binaries/instantnoodle/QcomPkg/Drivers/AdcDxe/AdcDxe.inf
  INF Binaries/instantnoodle/QcomPkg/Drivers/TsensDxe/TsensDxe.inf
  INF Binaries/instantnoodle/QcomPkg/Drivers/LimitsDxe/LimitsDxe.inf
  INF Binaries/instantnoodle/QcomPkg/Drivers/DDRInfoDxe/DDRInfoDxe.inf
  INF Binaries/instantnoodle/QcomPkg/Drivers/UsbfnDwc3Dxe/UsbfnDwc3Dxe.inf
  INF Binaries/instantnoodle/QcomPkg/Drivers/XhciPciEmulationDxe/XhciPciEmulationDxe.inf
  INF Binaries/instantnoodle/QcomPkg/Drivers/XhciDxe/XhciDxe.inf

  INF MdeModulePkg/Bus/Usb/UsbBusDxe/UsbBusDxe.inf
  INF MdeModulePkg/Bus/Usb/UsbKbDxe/UsbKbDxe.inf
  INF MdeModulePkg/Bus/Usb/UsbMassStorageDxe/UsbMassStorageDxe.inf

  INF Binaries/instantnoodle/QcomPkg/Drivers/UsbMsdDxe/UsbMsdDxe.inf
  INF Binaries/instantnoodle/QcomPkg/Drivers/UsbDeviceDxe/UsbDeviceDxe.inf
  INF Binaries/instantnoodle/QcomPkg/Drivers/UsbConfigDxe/UsbConfigDxe.inf
  INF Binaries/instantnoodle/QcomPkg/Drivers/UsbInitDxe/UsbInitDxe.inf
  INF Binaries/instantnoodle/QcomPkg/Drivers/HashDxe/HashDxe.inf
  INF Binaries/instantnoodle/QcomPkg/Drivers/CipherDxe/CipherDxe.inf
  INF Binaries/instantnoodle/QcomPkg/Drivers/MacDxe/MacDxe.inf
  INF Binaries/instantnoodle/QcomPkg/Drivers/RNGDxe/RngDxe.inf

  INF MdeModulePkg/Universal/BdsDxe/BdsDxe.inf

  #INF Binaries/instantnoodle/QcomPkg/Drivers/PILDxe/PILDxe.inf
  INF Binaries/instantnoodle/QcomPkg/Drivers/PILProxyDxe/PILProxyDxe.inf
  INF Binaries/instantnoodle/QcomPkg/Drivers/SPSSDxe/SPSSDxe.inf
  INF Binaries/instantnoodle/QcomPkg/Drivers/ShmBridgeDxe/ShmBridgeDxeLA.inf
