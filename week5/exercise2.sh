# Exercise Description:
#   Write a shell script that produces a file of sequential numbers by reading the last number in the file,
#   adding 1 to it, and then appending it to the file. Run one instance of the script in the background and one
#   in the foreground, each accessing the same file.

# Assume that there's a file called "input.txt" with some number(s) in the same directory as this script file

in=input.txt
awk -v last="$last" 'END { printf "\n%s",$0=$0+1 }' $in >> $in

# This will take the last number in the file, add 1 to it and append the resulting value in the file.
