#!/bin/bash

# Directory containing the files
DIRECTORY="."

# Counter for the new filenames
counter=1

# Loop through all files in the directory
for file in "$DIRECTORY"/*; do
  # Check if it's a file
  if [ -f "$file" ]; then
    # Format the new filename with leading zeros
    filename=$(printf "animation%02d.gif" "$counter")
    new_filename=$(printf "animation%d.xpm" "$counter")
    
    # Apply the convert command to resize the image
    convert "$DIRECTORY/$filename" -resize 64x64 "../textures/$new_filename"
    
    # Increment the counter
    counter=$((counter + 1))
  fi
done

echo "Renaming and conversion completed."