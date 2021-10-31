#include "string.h"
main()
{
  char x[100] = "Amit Hanish Mahesh Amit";
  char y[3][100];
  int i = 0, k = 0, j = 0, c = 0, end, t;
  int current = 1;
  while (x[i] != '\0') {
    if (x[i] != ' ') {
      y[k][j] = x[i];
      j++;
      i++;
    } else {
      // c = c + 1;
      i++;
      k++;
      j = 0;
    }
    y[k][j] = '\0';
  }

  for (end = 1; end <= 3; end++) {
    for (t = 0; t < end; t++) {
      if (strcmp(y[end], y[t]) == 0) break;
    }
    if (end == t) {
      strcpy(y[current],y[t]);
       current++;
    }
  }
  y[current] = 0;
  cout<<y;
}