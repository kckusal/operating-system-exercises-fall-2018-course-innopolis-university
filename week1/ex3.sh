#Exercise Description:
#  Write a shell script “ex3.sh” that prints time (use date command), then sleep for 3 seconds (use sleep 3) and prints time again.
#
#Exercise Solution:
#  This will infinitely print time in 12-hour format every 3 seconds.
#  The loop can be removed or restricted to allow the process to execute a definite number of times.
#
while :
do
  date +"%r"
  sleep 3
done
