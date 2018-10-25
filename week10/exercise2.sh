# EXERCISE DESCRIPTION:
# • Create file.txt in week1 directory and access this file from week10 directory
#   via $ link <source> _ex2.txt   
# • Trace all links to file.txt:
#     $ find <path> –inum inodenumber
# • Remove all links from file.txt
#     $ find <path> –inum inodenumber -exec rm {} \;
# • Save output of all the step to file ex2.txt

link ../week1/file.txt _ex2.txt

ls -i _ex2.txt
# Output: 7699381 _ex2.txt

find -inum 7699381
# Output: ./_ex2.txt

find -inum 7699381 -exec rm {} \;

ls -i _ex2.txt
# Output: ls: cannot access '_ex2.txt': No such file or directory
