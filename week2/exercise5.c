/*
  EXERCISE DESCRIPTION:
  • Add several functions to your ex3.c file, so user could print different figures on his choice;
  
*/

#include <stdio.h>

// Prints the stars in a right isoceles representation having height=width=n
void rightIsoceles(int n) {
  for (int i=1; i<=n; i++) {
    for (int j=1; j<=i; j++) {
      printf("*");
    }
    printf("\n");
  }
}

// Prints the stars in a square representation having height=width=n
void square(int n) {
  for (int i=1; i<=n; i++) {
    for (int j=1; j<=n; j++) {
      printf("*");
    }
    printf("\n");
  }
}

// Prints the rectangular representation having height = n and width = l
void rectangular(int n, int l) {
  for (int i=1; i<=n; i++) {
    for (int j=1; j<=l; j++) {
      printf("*");
    }
    printf("\n");
  }
}

// Prints the sideways traingle representation having height = 2n-1 and width = n
void sidewaysTriangle(int n) {
  int toPrint=0;
  for (int i=1; i<=(2*n-1); i++) {
    if (i<=n) {
      toPrint = i;
    } else {
      toPrint = n-i+n;
    }

    for (int j=1; j<=toPrint; j++) {
      printf("*");
    }
    printf("\n");
  }
}

int main(void) {
  int n;
  printf("Enter 'n' and press 'enter':");
  scanf("%d", &n);

  printf("The right-isoceles triangle:\n");
  rightIsoceles(n);

  printf("The square:\n");
  square(n);

  printf("The rectangular (length=5):\n");
  rectangular(n, 5);

  printf("The sideways triangle:\n");
  sidewaysTriangle(n);
  return 0;
}
