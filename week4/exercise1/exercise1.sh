#Shell script to run the program 10 times as mentioned in the exercise description.
gcc exercise1.c -o exercise1    #Compile the C program to get an executable
for i in {1..10}; do ./exercise1 ; done   #Run the executable 10 times
