/*
  Exercise Description:
   • Write a shell script that produces a file of sequential numbers by reading the last number in the file,
     adding 1 to it, and then appending it to the file. Run one instance of the script in the background and
     one in the foreground, each accessing the same file.
     
   • Modify the script to prevent the race.
     Hint: use ln file file.lock to lock the data file.
     
*/

# Create the target file and redirect the standard output stream
if test ! -f output
then
  echo 0 > output
fi

# Lock the data file
if ln output output.lock
then
  # Loop through 60 times
	for i in `seq 1 60`;
	do
		# Get last number from the file
		LASTNUMBER=`tail -1 output`
  
    # Increment the last number we got
		LASTNUMBER=$((LASTNUMBER+1))
  
    # Rewrite the incremented value to the file
		echo $LASTNUMBER >> output
	done

	# Unlock the file upon completion
	rm output.lock
fi
