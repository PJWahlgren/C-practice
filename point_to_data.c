#include <stdio.h>
typedef unsigned long ulong;
void point_to_char_array(int *p, unsigned char data[8]) {
  printf("Pointer size: %lu\n", sizeof(p));
  printf("Address: %p\n", p);
  ulong l = (ulong)p;
  printf("Type converted: %lu\n", l);
  for (char i = 0; i < 8; i++) {
    ulong adjust = (0xFF00000000000000 >> (i * 8));
    ulong temp = l;
    // printf("Adjust{%d}: %lu\n", i, adjust);
    temp &= adjust;
    // printf("relevant: %x\n", temp);
    temp = temp >> (8 * (7 - i));
    // printf("after shift: %x\n", temp);
    // printf("type conv: %x\n", (unsigned char)temp);
    // printf("-----\n");
    data[i] = (unsigned char)temp;
  }
}

int *char_array_to_point(unsigned char data[8]) {
  ulong l = 0;
  for (char i = 0; i < 8; i++) {
    ulong tmp = ((ulong)data[i]) << 8 * (7 - i);
    // printf("Reconstructing{%d}: %x\n", i, tmp);
    l |= tmp;
    // printf("l: %x\n", l);
    // printf("----\n");
  }
  return (int *)l;
}
int main() {
  int i = 4;
  unsigned char data[8];
  point_to_char_array(&i, data);
  for (char i = 0; i < 8; i++) {
    printf("%x", data[i]);
  }
  printf("\n");
  printf("%p\n", char_array_to_point(data));
  printf("Should print 4: %d\n", *char_array_to_point(data));
}
