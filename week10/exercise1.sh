# EXERCISE DESCRIPTION:
# Create _ex1.txt
#   • Link it to _ex1_1.txt and _ex1_2.txt
#   • Check i-node numbers of all the files and
# Save the output to the file ex1.txt

# Note: Check exercise1_result folder for this program's results

# Create _ex1.txt
echo >> _ex1.txt

# Link to other files
ln _ex1.txt _ex1_1.txt
ln _ex1.txt _ex1_2.txt

# Check i-node of all files
ls -i _ex1.txt >> ex1.txt
ls -i _ex1_1.txt >> ex1.txt
ls -i _ex1_2.txt >> ex1.txt
