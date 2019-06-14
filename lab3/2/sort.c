/*
  @file sort.c
  @brief sort functions implementation
*/

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "helpers.h"
#include "sort.h"
#include "player.h"

bool goes_before(player_t x, player_t y){
  if (x.rank <= y.rank) {
    return true;
  } else {
    return false;
  }
}

bool array_is_sorted(player_t atp[], unsigned int length) {
  unsigned int i = 1u;
  while (i < length && goes_before(atp[i - 1u], atp[i])) {
    i++;
  }
  return (i == length);
}

void swap (player_t array[],unsigned int i,unsigned int j)
{
  player_t temp = array[i];

  array[i] = array[j];
  array[j] = temp;
}

unsigned int min_pos_from (player_t array[],unsigned int length, unsigned int i)
{
  unsigned int min = i;
  for ( ; i < length; i++){
    if (goes_before(array[i], array[min])){
     min = i;
    }
  }
  return min;
}

void selection_sort(player_t array[], unsigned int length)
{
  unsigned int i = 0u;
  unsigned int minum = 0u;
  for ( ; i < length ; i++ ){
    minum = min_pos_from (array, length, i);
    swap (array, i, minum);
  }
}

void sort(player_t array[], unsigned int length) {
  selection_sort(array, length);
}
