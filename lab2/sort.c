#include <stdio.h>
#include "sort.h"
#include <stdbool.h>

bool array_is_sorted(int array[], unsigned int length)
{

    unsigned int i = 0u;
    bool b = true;

  while (i < length-1 && b) {
    b = (array[i] <= array[i+1]);
     i = i+1;
}

	return b;
}

void swap (int array[],unsigned int i,unsigned int j)
{
        int temp = array[i];

        array[i] = array[j];
        array[j] = temp;
}

unsigned int min_pos_from (int array[],unsigned int length, unsigned int i)
{
    unsigned int min = i;
    for ( ; i < length; i++)
         if (array[i] <= array[min])
            min = i;

    return min;
}

void selection_sort(int array[], unsigned int length)
{
    void swap (int array[],unsigned int i,unsigned int j);
    unsigned int min_pos_from (int array[],unsigned int length, unsigned int i);

    unsigned int i = 0u;
    unsigned int minum = 0u;
    for ( ; i < length ; i++ ){
       minum = min_pos_from (array, length, i);
       swap (array, i, minum);
	}
}

void insertion_sort(int array[], unsigned int length) {
   unsigned int i = 0;

   for ( ; i < length; i++){
       unsigned int j = i;
       while (j > 0 && array[j] < array[j-1]){

    	   swap (array , j, j - 1);
       j = j - 1;
      }
  }

}
unsigned int partition (int array[], unsigned int lft, unsigned int rgt)
{
	unsigned int i = lft + 1;
    unsigned int j = rgt;
	unsigned int ppiv = lft;

	while (i <= j){
			if (array[i] <= array[ppiv]){
				i = i + 1;
			}
			else if (array[j] >= array[ppiv]){
				j = j - 1;
			}
			else{ //((array[i] > array[ppiv]) && (array[j] < array[ppiv]))
					swap (array, i, j);
					i = i + 1;
					j = j - 1;
			}

	}
	swap (array, ppiv, j);
 	ppiv = j;
	return ppiv;
}


void quick_sort_rec(int array[], unsigned int lft, unsigned int rgt)
{
	unsigned int ppiv;
    if  (rgt > lft){
		ppiv = partition (array, lft, rgt);

		if (ppiv != 0){
			quick_sort_rec (array, lft, ppiv - 1);
		}
	quick_sort_rec (array, ppiv + 1 , rgt);

	}
}

void quick_sort(int array[], unsigned int length)
{
	quick_sort_rec (array, 0, length -1);
}
