{ pkgs ? import <nixpkgs> {} }:

pkgs.mkShell {
  name = "qmk-env";

  buildInputs = with pkgs; [
    qmk  # QMK CLI
    gcc-arm-embedded  # ARM toolchain for RP2040 and STM32
    python3  # Python for QMK scripting
    git  # Version control
    gnumake  # Make tool for compiling
    dfu-util  # DFU flashing utility
    avrdude  # AVR flashing utility (for ATmega controllers)
    dfu-programmer  # Alternative DFU flashing tool
    libusb  # USB communication library
    hidapi  # HID device support
    via  # VIA support (optional)
    vial  # Vial support (optional)
    wget  # For downloading dependencies
  ];

  shellHook = ''
    export PICO_SDK_PATH=${pkgs.pico-sdk}/lib/pico-sdk
    echo "QMK development environment loaded!"
    echo "Run 'qmk setup' if it's your first time."
  '';
}

