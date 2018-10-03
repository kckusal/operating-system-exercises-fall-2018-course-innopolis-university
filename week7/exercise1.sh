# EXERCISE DESCRIPTION:
#   Use size shell command to determine the size of text, data and bss segments of any of your programs.
#   Save the output to file ex1.txt

# Compile a requisite C program named 'ex1_requisite.c' and create executable 'ex1_requisite'
gcc ex1_requisite.c -o ex1_requisite

# Output size of the bss, text segment and data segment for created object file
size ex1_requisite > ex1.txt
