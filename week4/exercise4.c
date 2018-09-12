/* EXERCISE DESCRIPTION:
    Extend your previous code to handle commands with parameters and running processes in background.
    
    Hint: use man fork and man execve
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
  // Assume that our command will be at most of 500 chars
  char cmd[500];
  
  // Get the command from the user as an input: taking entire line as input gets the arguments too
  scanf("%[^\n]%*c", cmd);

  // pass the command to the host environment to be executed by the system terminal
  system(cmd);
  
  return(0);
}
