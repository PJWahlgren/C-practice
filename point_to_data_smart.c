#include <stdio.h>
#include <string.h>

int main() {
  int num = 4;
  unsigned long temp = (unsigned long)&num;
  unsigned char data[8];
  printf("Address: %p\n", &num);
  printf("Type converted: %x\n", temp);
  memcpy(data, &temp, sizeof(int *));
  printf("Copied data: ");
  for (char i = 0; i < 8; i++) {
    printf("%x", data[7 - i]);
  }
  printf("\n");
  unsigned long ptr = 0;
  memcpy(&ptr, data, sizeof(int *));
  printf("Recopied: %p\n", (int *)ptr);
  printf("Value should be 4: %d", *((int *)ptr));
}
