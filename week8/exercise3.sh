# EXERCISE DESCRIPTION:
#    Run exercise2.c program in the background and then run `top`.

top -d 1

# Running exercise2 in background and running 'top' afterwards
./exercise2 &
top
