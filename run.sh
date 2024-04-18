#!/bin/bash
# NOTE: This section was written with the help of ChatGPT



# Check if an argument was provided
if [ $# -eq 0 ]
then
    echo "No file specified. Usage: $0 <filename> [args for the program]"
    exit 1
fi

# Save the filename argument and shift it out of the parameters list
file="$1"
shift

# Extract the filename without the extension
filename=$(basename -- "$file")
extension="${filename##*.}"
filename="${filename%.*}"

# Check if the file exists
if [ ! -f "$file" ]; then
    echo "File does not exist."
    exit 1
fi

# Check for proper file extension
if [ "$extension" != "c" ] && [ "$extension" != "cpp" ]; then
    echo "Unsupported file type. Please provide a .c or .cpp file."
    exit 1
fi

# Compile the file with GCC or G++
if [ "$extension" == "c" ]; then
    gcc -o "$filename" "$file"
else
    g++ -o "$filename" "$file"
fi

# Check if the compilation was successful
if [ $? -ne 0 ]; then
    echo "Compilation failed."
    exit 1
fi

# Run the compiled program with any additional arguments passed to the script
./"$filename" "$@"
