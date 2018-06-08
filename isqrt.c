// Include libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

#include <time.h>
clock_t start, end;
double cpu_time_used;

int isqrt(int x)
{
  unsigned int opr=(unsigned int)x;
  unsigned int res=0;
  unsigned int one=1<<30;

  while (one>opr) one>>=2;
  while (one!=0) {
    if (opr>=res+one) {
      opr=opr-res-one;
      res=res+(one<<1);
    }
    res>>=1;
    one>>=2;
  }
  // if (opr>res) res++; // Round up
  return (int)res;
}

int main(void)
{

  start=clock();
  { /* The Timed Section */
    unsigned int i;
    int isqr,fsqr;

    for (i=0;i<4294967295;i++) {
      isqr=isqrt(i);
      fsqr=(int)(sqrt((i)+0.5));
      if (isqr!=fsqr) {
        printf("Error %d %d %u\n",i,isqr,fsqr);
        getchar();
      }
    }
  }
  end=clock();
  cpu_time_used=((double)(end-start))/CLOCKS_PER_SEC;
  printf("Elapsed time %lf seconds\n",cpu_time_used);

  return(0);
}
