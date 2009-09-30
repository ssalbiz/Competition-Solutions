#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

//use a simple singly linked list to store the flake ids
typedef struct unique_flake {
  int id;
  struct unique_flake* next;
} unique_flake;

int exists(int id, unique_flake *head) {
  
  unique_flake *current = head;
  while (current->next != NULL) {
    if (id == current->id) return 1;
    current = current->next;
  }
  unique_flake *new_flake = (unique_flake*) malloc(sizeof(unique_flake));
  new_flake->id = id;
  new_flake->next = NULL;
  current->next = new_flake;
  return 0;

}

int main () {
  
  FILE* fin = fopen("input", "r");
  FILE* fout= fopen("output", "w");
  assert(fin != NULL && fout != NULL);
  int test_cases, flakes, flake_id;
  int i,j,k, max;
  unique_flake head;

  fscanf(fin, "%d\n", &test_cases);
  for ( i = 0; i < test_cases; i++) {
    fscanf(fin, "%d\n", &flakes);
    head.id = -1;
    head.next = NULL;
    max = 0;
    for ( j = 0; j < flakes; j++) {
      fscanf(fin, "%d\n", &flake_id);
      if (!exists(flake_id, &head))
       max++;
    }
  }

  printf("%d\n", max);
  fclose(fin);
  fclose(fout);


return 0;
}
