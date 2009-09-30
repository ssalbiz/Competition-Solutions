/*
ID: s.s.alb2
LANG: C
TASK: milk
*/


#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef struct {
	int price;
	int max;
} farmer;
#ifndef MAX_FARMER
#define MAX_FARMER 5000
#endif

int compare (const void *a, const void *b) {
	return( (*(farmer*)a).price - (*(farmer*)b).price );
}



int main() {
	FILE* fin  = fopen("milk.in", "r");
	FILE* fout = fopen("milk.out", "w");
	int N = 0, M = 0; //N - milk needed, M - # of farmers available
	int i = 0, cost = 0;
	farmer list[MAX_FARMER];
	assert(fin != NULL);
	
	fscanf(fin, "%d %d\n", &N, &M);
	assert(M <= 5000 && M >= 0);
	for (; i < M; i++) {
	  fscanf(fin, "%d %d\n", &list[i].price, &list[i].max);
	}
	qsort(list, M, sizeof(farmer), compare);

	for( i = 0; i < M; i++) {
	  printf("%d: %d %d\n", i, list[i].price, list[i].max);
	}
	i = 0;
	while (N > 0) {
	  if (list[i].max > N) {
	  	cost += N*list[i].price;
		N = 0;
	  } else {
	  	cost += list[i].max*list[i].price;
		N -= list[i].max;
	  }
	  i++;
	}
	printf("%d\n", cost);
	fprintf(fout, "%d\n", cost);




	fclose(fin);
	fclose(fout);
	return 0;
}
