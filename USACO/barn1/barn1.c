/*
ID: s.s.alb2
TASK: barn1
LANG: C
*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int compare(const void *a, const void *b) {
  return ( *(int*)b - *(int*)a  ); 
}

int compare_ascend(const void *a, const void *b) {
  return ( *(int*)a - *(int*)b  );
}


int main() {
  FILE* fin = fopen("barn1.in", "r");
  FILE* fout = fopen("barn1.out", "w");
 
  assert(fin != NULL && fout != NULL);
  int gaps[2000];
  int stalls[2000];
  int M=0,S=0,C=0, i, j = 0, total;
  int current_gap = 0, current_stall = 0, last_stall = 0; 
  
  fscanf(fin, "%d %d %d\n", &M, &S, &C);
  printf( "%d %d %d\n", M, S, C);
  total = M;

  for (i = 0; i < C; i++) {
    fscanf(fin, "%d\n", &stalls[i]);
  }
  qsort(stalls, C, sizeof(int), compare_ascend);

  for (i = 0; i < C; i++) {
    gaps[i] = (i != 0) ? (stalls[i]-stalls[i-1]-1):0;
  }
  qsort(gaps, C, sizeof(int), compare);

  for ( i = 0; i < M-1; i++) {
    total -= gaps[i];
    printf("%d\n\n", gaps[i]);
  }

  total -= (stalls[0]-1);
  total -= (M - stalls[C-1]);

  printf("%d\n", total); 	
  fprintf(fout, "%d\n", total); 	



  fclose(fin);
  fclose(fout);
  return 0;
}




