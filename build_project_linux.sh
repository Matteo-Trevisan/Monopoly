#!/bin/bash
BUILD_DIRECTORY="build"

# Crea una cartella di build ne non esiste
if [ ! -d "$BUILD_DIRECTORY" ]; then
  mkdir build
fi

# Entra nella cartella di build
cd build || exit

# Prepara i file per la compilazione
cmake ..

# Compila il progetto
make


echo ""
echo "Progetto costruito e compilato in /$BUILD_DIRECTORY"
echo "Per eseguire usare ./$BUILD_DIRECTORY/Monopoly"