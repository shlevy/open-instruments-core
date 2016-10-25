let
  pkgs = import <nixpkgs> {};

  version = let
    version_ = builtins.readFile ./VERSION;
  in builtins.substring 0 ((builtins.stringLength version_) - 1) version_;
in
{ stdenv ? pkgs.stdenv
, uri ? pkgs.uri
, cmake ? pkgs.cmake
}: stdenv.mkDerivation {
  name = "open-instruments-core-${version}";

  src = builtins.filterSource (path: type: baseNameOf path != ".git" && baseNameOf path != "build") ./.;

  buildInputs = [ cmake uri ];

  cmakeFlags = [ "-DBUILD_SHARED_LIBS=ON" ];
}
