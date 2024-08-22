#!/bin/bash

# Directory containing the files
DIRECTORY="./torch"

# Counter for the new filenames
counter=1

# Loop through all files in the directory
for file in "$DIRECTORY"/*; do
  # Check if it's a file
  if [ -f "$file" ]; then
    # Format the new filename with leading zeros
    new_filename=$(printf "animation%d.xpm" "$counter")
    # Rename the file
    # Apply the convert command to resize the image
    convert "$file" -resize 256x256 "./textures/torch/$new_filename"
    
    # Increment the counter
    counter=$((counter + 1))
  fi
done

echo "Renaming and conversion completed."