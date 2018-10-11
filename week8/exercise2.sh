# Compile and run the program in the background (./ex2 &) and run `vmstat 1` at the same time.
# Observe what happens to the memory. Pay attention to si and so fields

gcc exercis e2.c -o exercise2   # Compile
./exercise2 &                   # Run the program in background
vmstat 1                        # Run 'vmstat 1'
