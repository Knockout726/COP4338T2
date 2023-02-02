#include <string.h>
#include "balance.h"

char opening_symbol[51]; 
char closing_symbol[51];

void pair(char list[]){
    int i = 0, j = 0, k = 0;
    int len = strlen(list);
    while (j < len) {
        if (list[j] == ',') {
            opening_symbol[i] = list[k];
            closing_symbol[i++] = list[j-1];
            k = j + 2;
        }
        j++;
    }
    opening_symbol[i] = closing_symbol[i] = '\0';
}
