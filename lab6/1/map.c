#include <assert.h>
#include <stdlib.h>
#include "map.h"

struct _node_t {
    map_t left;
    map_t right;
    key_t key;
    value_t value;
};

map_t map_empty() {
  return NULL;
}

static map_t create_node(key_t key, value_t value, map_t left, map_t right) {
    map_t node = NULL;
    node = malloc(sizeof(struct _node_t));
    node->left = left;
    node->right = right;
    node->key = key;
    node->value = value;
    return(node);
}

static map_t free_node(map_t node) {
  free(node);
  return(node);
}
static bool is_empty(map_t node){
  return (node == NULL);
}

map_t map_put(map_t map, key_t key, value_t value){
    assert(key != NULL);
    assert(value != NULL);
    map_t node = map;
    if (is_empty(node)){
      node = create_node(key, value , map_empty(), map_empty());
    }
    else if (key_eq(key, node->key)){
    //  node->key = key; //leak
      node->value = value;
    }
    else if (key_less(key, node->key)){
     node->left = map_put(map->left, key, value);
    }
    else if (!key_less(key, node->key)){
     node->right = map_put(map->right, key, value);
    }
    return (node);
}

value_t map_get(map_t map, key_t key) {
    assert(key != NULL);
    value_t value = NULL;
    map_t node = map;

    if (key_eq(key, map->key)){
      value = node->value;
    }
    else if (key_less(key, map->key)){
     value = map_get(map->left, key);
    }
    else {
     value = map_get(map->right, key);
    }
    return (value);
}

bool map_contains(map_t map, key_t key) {
    assert(key != NULL);
    bool res = false;
    if (map != NULL) {
      if (key_eq(key, map->key)){
        res = true;
      }
      else if (key_less(key, map->key)){
       res = map_contains(map->left, key);
      }
      else if (!key_less(key, map->key)){
       res = map_contains(map->right, key);
      }
    }
    return (res);
}

map_t minValueNode(map_t node){
  map_t current = node;
  while (current && current->left != NULL){
    current = current->left;
  }
  return(current);
}
map_t map_remove(map_t map, key_t key) {
  map_t node = map;
  if (map == NULL){
    return (map);
  }
  if (key_less(key, map->key) && !key_eq(key, map->key))
    map->left = map_remove(node->left, key);

  else if (!key_less(key, map->key) && !key_eq(key, map->key))
    map->right = map_remove(node->right, key);
  else{
    if (map->left == NULL) {
      map_t temp = map->right;
      free(map);
      return(temp);
    }
    else if (map->right == NULL) {
      map_t temp = map->left;
      free(map);
      return(temp);
    }
    map_t temp = minValueNode(map->right);
    map->key = temp->key;
    map->right = map_remove(map->right, temp->key);
    map->value = temp->value;
  }
  return(map);
}

map_t map_destroy(map_t map) {
  if (is_empty(map)){
    return (NULL);
  }
  else {
    map_destroy(map->left);
    map_destroy(map->right);
    free_node(map);
  }
  return (NULL);
}

void map_dump(map_t map, FILE *file) {
    if (map != NULL) {
        map_dump(map->left, file);
        key_dump(map->key, file);
        fprintf(file, ": ");
        value_dump(map->value, file);
        fprintf(file, "\n");
        map_dump(map->right, file);
    }
}
