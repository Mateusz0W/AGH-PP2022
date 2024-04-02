 #include <stdio.h>
 char *c[] = {"HOOD","LATE","RING","BABY"};
  char **cp[] = {  c+3, c+2, c+1, c };
  char ***cpp = cp+2;
 int main(void)
 {
     printf("%s", **++cpp+1 );
     printf("%s ", *++*--cpp-2 );
    printf("%s", *cpp[-1]+2 );
    printf("%s\n", cpp[-2][-1]+2 );

    int i;
    for(i=sizeof(c)/sizeof(*c);i>0;i--){
        printf("\n%d  %s\n",sizeof(c)/sizeof(*c)-i,*cp[i-1]);
    }
    printf("%s ggg",*cp[1]);
    return(0);

    
 }