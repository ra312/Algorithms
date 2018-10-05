#include <stdlib.h>
#include <stdio.h>
struct tList
{
  int element;
  struct tList* next;
};
typedef struct tList tList;
// First in Last Out Linked List
tList* push(tList* L, int element)
{
  // L points to the last element which is head
  tList* new = (tList*) malloc(sizeof(tList));
  // L->next == NULL is true now
// L is the last element;

  new->element = element;
  new->next = L;
  L = new;
  // returning the pointer to the last added element
  return L;
}

tList* init(int values[], int n)
{
  int i;
  tList* L;

  for (i=0; i<n; i++)
  {
    L = push(L, values[i]);
  }
  return L;
}
void print(tList* L)
{
  while (L->next != NULL)
  {
    printf("%i ",L->element);
    L = L->next;
  }
  printf("\n");
  return;
}
int main()
{
  tList* L;

  int values[4]={1,2,3,4};
  int n=4;

  L = init(values,n);

  // printf("%i\n",L->next->next->element);
  print(L);
  return 0;
}
