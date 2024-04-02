#include <stdio.h>


struct {
  unsigned int var_1; // 4 bajty
  unsigned int var_2; // znowu
} status1;


struct {
  unsigned int var_1 : 2;
  unsigned int : 4;
  unsigned int var_2 : 3;
  // 1 1 p p p p 2 2 2 p p p p p p p ... do 32 bitow
  // 1 1 2 2 | 2 p p p
} status2;


int main() {
  printf("size status1 : %lu \n", sizeof(status1));
  printf("size status2 : %lu \n", sizeof(status2));
  status2.var_1 = 5; // = 0b01
  status2.var_2 = 5; // = 0b101
  printf("status.var_1 = %u, status.var_2 = %u \n", status2.var_1, status2.var_2);
  return 0;
}
