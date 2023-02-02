#define BUFSIZE 1000
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "stack.h"

static char buf[BUFSIZE];//buffer for opening symbols
static int bufp;//next free position in buf

void push(char c){
    buf[bufp] = c;
    bufp++;
}
char pop(void){
    if (is_empty())
        return '\0';
    bufp--;
    return buf[bufp];
}
char peek (void){
    return buf[bufp - 1];
}
bool is_empty(){
    printf("Checking if stack is empty...\n");
    return !bufp; //bufp == 0
}
int size(){
    return bufp;
}

bool is_opening_symbol(char c){ // hash table lookup
    extern char opening_symbol[];
    extern char closing_symbol[];
    int len = strlen(opening_symbol);
    for (int i = 0; i < len; i++) {
        if (c == opening_symbol[i]) {
            return true;
        }
    }
    return false;
}
bool is_closing_symbol(char c){ // hash table lookup
    extern char opening_symbol[];
    extern char closing_symbol[];
    int len = strlen(closing_symbol);
    for (int i = 0; i < len; i++) {
        if (c == closing_symbol[i]) {
            return true;
        }
    }
    return false;
}
bool check(char input[]){
    extern char opening_symbol[]; // this array has been defined somewhere else
    extern char closing_symbol[]; // this array has been defined somewhere else 

    printf("We are checking the following symbols %s   \n Opening symbols:  %s  \n Closing symbols: %s  \n", input, opening_symbol, closing_symbol); 

    bufp = 0; // empty out the stack!
    int len = strlen(input);
    for (int i = 0; i < len; i++) {
        if (is_opening_symbol(input[i])) {
            push(input[i]);
        } else if (is_closing_symbol(input[i])) {
            // match operation
            char c = pop();
            int j;
            for (j = 0; j < strlen(opening_symbol); j++) {
                if (c == opening_symbol[j]) {
                    break;
                }
            }
            if (input[i] != closing_symbol[j]) {
                return false;
            }
        } else {
            continue;
        }
    }
    return is_empty();
}


