#include <stdio.h>  /* printf(), fprintf()        */
#include "map.h"    /* funciones del TAD map_t    */
#include "string.h" /* Funciones del TAD string_t */


int main(void){
  map_t map = map_empty();

  map = map_put(map, string_create("joaquin"),string_create("feltes"));
  map = map_put(map, string_create("guido"),string_create("ivetta"));
  map = map_put(map, string_create("rodrigo"),string_create("ortiz"));
  map = map_put(map, string_create("hillary"),string_create("clinton"));
//  map = map_put(map, string_create("gaspar"),string_create("ceballo"));
//  map = map_put(map, string_create("oscar"),string_create("perez"));
//  map = map_put(map, string_create("cesar"),string_create("vallero"));
//  map = map_put(map, string_create("donald"),string_create("trump"));
  map = map_put(map, string_create("viter"),string_create("bolas"));
//  map = map_put(map, string_create("donald"),string_create("trump"));



  printf("Arbol orignial -----------------------------" );
  printf("\n\n");
  map_dump(map, stdout);
  printf("\n");

  printf("delete viter \n");
  map = map_remove(map, string_create("viter"));
  printf("Primer remove ----------------------------" );
  printf("\n\n");

  map_dump(map, stdout);
/*
  printf("delete donald \n");
  map = map_remove(map, string_create("donald"));
  printf("Segundo remove ----------------------------- " );
  printf("\n\n");

  map_dump(map, stdout);
*/
}

  //string_dump(string_create("joaquin"), stdout);
  /*int main()
  {
    map_t map = map_empty();
    map = map_put(map, string_create("joaquin"),string_create("feltes"));
    map = map_put(map, string_create("guido"),string_create("ivetta"));
    map = map_put(map, string_create("rodrigo"),string_create("ortiz"));
    map = map_put(map, string_create("cesar"),string_create("valleros"));
    map = map_put(map, string_create("gaspar"),string_create("ceballo"));

    printf("Arbol orignial-----------------------------" );
    printf("\n\n");
    map_dump(map, stdout);
    printf("\n");

      printf("\nDelete joaquin\n");
      map = map_remove(map, string_create("joaquin"));
      //map_destroy(map);

      printf("Arbol nuevo-----------------------------" );
      printf("\n\n");
      map_dump(map, stdout);
      return 0;
  }
*/
