/* EXERCISE DESCRIPTION:
    Write your own simplistic shell. It should read user input and be able to run a command without parameters,
    such as pwd, ls, top, pstree and so on.
    
    Hint: use man system
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
  // Assume that our command will be at most of 60 chars
  char cmd[60];
  
  // Get the command from the user as an input
  scanf("%s", cmd);

  // pass the command to the host environment to be executed by the system terminal
  system(command);
  
  return(0);
}
