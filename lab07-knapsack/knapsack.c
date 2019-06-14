
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "item.h"
#include "helpers.h"
#include "string.h"

value_t maximon(value_t x, value_t y) {
  if (x>y) {
    return x;
  }
  else
  return y;
}

value_t knapsack_backtracking(item_t *items, unsigned int array_length, weight_t max_weight)
{
  value_t aux = 0;
  if (max_weight == 0) {
    aux = 0;
  }
  else if (max_weight > 0 && array_length == 0) {
    aux = 0;
  }
  else if (item_weight(items[array_length]) > max_weight && max_weight > 0 && array_length > 0) {
    aux = knapsack_backtracking(items, array_length-1, max_weight);
  }
  else if (max_weight >= item_weight(items[array_length]) && item_weight(items[array_length]) > 0 && array_length > 0) {
    aux = maximon(knapsack_backtracking(items, array_length-1,max_weight), item_value(items[array_length]) + knapsack_backtracking(items, array_length - 1, max_weight - item_weight(items[array_length])));
  }
  return aux;
}
value_t knapsack_dynamic(item_t *items, unsigned int array_length, weight_t max_weight)
{
  value_t A[array_length + 1][max_weight + 1];
  for (unsigned i = 0; i <= array_length; i++){
    A[i][0] = 0;
  }
  for (weight_t j = 1; j <= max_weight; j++){
    A[0][j] = 0;
  }
  for (unsigned i = 1; i <= array_length; i++) {
    for (weight_t j = 1; j <= max_weight; j++) {
      weight_t current_weight = item_weight(items[i - 1]);
      value_t current_value = item_value(items[i - 1]);
      if (current_weight > j) {
        A[i][j] = A[i - 1][j];
      }
      else {
        value_t using_it = current_value + A[i - 1][j - current_weight];
        value_t not_using_it = A[i - 1][j];
        A[i][j] = maximon(using_it, not_using_it);
      }
    }
  }
  return (A[array_length][max_weight]);
}

value_t knapsack_dynamic_selection(item_t *items, bool *selected, unsigned int array_length, weight_t max_weight)
{
  value_t A[array_length][max_weight];
for (unsigned i = 0; i < array_length; i++) {
    A[i][0] = 0;
}
for (weight_t j = 1; j < max_weight; j++) {
    A[0][j] = 0;
}
for (unsigned i = 1; i < array_length; i++) {
    for (weight_t j = 1; j < max_weight; j++) {
        weight_t current_weight = item_weight(items[i]);
        value_t current_value = item_value(items[i]);
        if (current_weight > j) {
            A[i][j] = A[i - 1][j];
        } else {
            value_t not_using_it = A[i - 1][j];
            value_t using_it = current_value + A[i - 1][j - current_weight];
            A[i][j] = maximon(using_it, not_using_it);
        }
    }
}

unsigned r = array_length;
weight_t s = max_weight;
while (A[r][s] > 0) {
    if (A[r][s] == A[r - 1][s]) {
        selected[r] = false;
    } else {
        selected[r] = true;
        s = s - item_weight(items[r]);
    }
    r = r - 1;
}

return (A[array_length - 1][max_weight - 1]);
}
