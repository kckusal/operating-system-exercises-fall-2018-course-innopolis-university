# EXERCISE DESCRIPTION:
#   Use size shell command to determine the size of text, data and bss segments of any of your programs.
#   Save the output to file ex1.txt

# Compile a prerequisite C program named 'ex1_prerequisite.c' and create executable 'ex1_prerequisite'
gcc ex1_prerequisite.c -o ex1_prerequisite

# Output size of the bss, text segment and data segment for created object file
size ex1_prerequisite > ex1.txt
