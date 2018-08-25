#Exercise Description:
#  Create directory “week1” in home directory
#  List entries in /usr/bin that contain “gcc” in reverse alphabetical order.
#  Save results in “~/week1/ex1.txt”.

#Exercise Solution:
mkdir ~/week1
cd ~/week1
ls -d ~/user/bin/*gcc* | sort -r | tail > ~/week1/ex1.txt
