#!/bin/bash

# Verificar si se proporcionó un parámetro
if [ -z "$1" ]; then
    echo "Error: Debes proporcionar un nombre de archivo."
    exit 1
fi

# Crear el archivo con el nombre del primer parámetro
touch "$1.md"
touch "$1.cpp"
cp temple.cpp $1.cpp
cp temple.md $1.md
nvim $1.cpp $1.md
