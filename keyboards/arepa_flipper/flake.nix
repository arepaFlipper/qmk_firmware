{
  description = "QMK development environment for NixOS";

  inputs = {
    nixpkgs.url = "github:nixos/nixpkgs";
  };

  outputs = { self, nixpkgs }: {
    devShells.x86_64-linux = let
      pkgs = import nixpkgs {
        system = "x86_64-linux";
        config.allowUnfree = true;
      };
    in {
      default = pkgs.mkShell {
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
          hidapi  # HID device support
          via  # VIA support (optional)
          vial  # Vial support (optional)
          wget  # For downloading dependencies
          pico-sdk  # Raspberry Pi Pico SDK


            python3.pkgs.pip
            python3.pkgs.setuptools
            python3.pkgs.wheel
            # Common tools for serial access:
            minicom
            picocom
            screen
        ];

        shellHook = ''
            echo "[INFO] Setting up Python virtual environment"
            if [ ! -d "env" ]; then
              echo "[INFO] Creating virtual environment in ./env"
              python -m venv env
            fi

            echo "[INFO] Activating virtual environment"
            source env/bin/activate

            echo "[INFO] Installing pyboard.py"
            pip install pyboard

            echo "[READY] MicroPython Pico development environment ready!"
            echo "       - Use pyboard.py to run scripts on your Pico"
            echo "       - Serial tools available: minicom, picocom, screen"

          export PICO_SDK_PATH=${pkgs.pico-sdk}/lib/pico-sdk
          echo "QMK development environment loaded!"
          echo "Run 'qmk setup' if it's your first time."
        '';
      };
    };
  };
}

