{
  description = "QMK setup for my Dactyl Manuform";

  inputs = {
    nixpkgs.url = "github:nixos/nixpkgs?ref=nixos-unstable";
  };

  outputs = { self, nixpkgs }: {
    devShells = {
      x86_64-linux = let
        pkgs = import nixpkgs {
          system = "x86_64-linux"; # Adjust if you're on a different architecture
        };
      in
        {
          default = pkgs.mkShell {
            buildInputs = with pkgs; [
              qmk
              python310
              vimPlugins.qmk-nvim
            ];
          };
        };
    };
  };
}

