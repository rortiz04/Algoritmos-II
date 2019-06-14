#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../stack.h"

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: ./reverse <string-to-reverse>\n");
        exit(EXIT_FAILURE);
    }
    char *str = argv[1];

    stack_t pila = stack_empty();


    for (unsigned int i = 0u; i < (unsigned)strlen(str); ++i){

        pila = stack_push(pila, (char) str[i]);
    }

    char *str2 = calloc(strlen(str)+1, sizeof(char));
    for (unsigned int i = 0u; i < (unsigned)strlen(str); ++i){

	str2[i] = (char) stack_top(pila);
        pila = stack_pop(pila);
    }
    str2[strlen(str)] = '\0';
    
    printf("%s\n", str2);
    free(str2);
    str2 = NULL;
    return 0;
}
