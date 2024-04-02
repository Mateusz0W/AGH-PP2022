#include <stdio.h>

struct str_1{
    char a;
    int b;
    char c[2];}a;
struct str_2{
    int b;
    char a;
    char c[2];}b;
union un_3{
    char a;
    char c[2];
    int b;
}c;

int main(void){
    printf("%d %d %d",sizeof(a),sizeof(b),sizeof(c));
}