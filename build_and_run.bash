#!/bin/bash

# Configs
  file_name="Caminho2D"
# No need to change these below
  extension_out="exe"
  extension_in="c++"
  path="${file_name}"
  output_file_path="${file_name}.${extension_out}"
  input_file_path="${file_name}.${extension_in}"

# Debug variables
  # echo $extension_out
  # echo $extension_in
  # echo $file_name
  # echo $path

  # echo output_file
  # echo input_file

# Script Running
  gcc -o ${output_file_path} ${input_file_path} -lglut -lGL -lGLU -lm    # Build

  ./${output_file_path}                                                  # Run
