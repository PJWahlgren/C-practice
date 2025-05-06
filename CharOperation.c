#include "stdio.h"

typedef unsigned char u_char;

int main() {

    u_char x = 3;
    u_char y = 5;

    printf("Result: %u\nSize(Bytes): %d\n", x + y, sizeof(x + y));
    u_char z = (u_char) (x + y);
    
    printf("Result: %u\nSize(Bytes): %d\n", z, sizeof(z));
    return 0; 
}