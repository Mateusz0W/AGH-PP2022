Mamy daną strukturę 

struct 
{
    char name[50];
    char surname[50];
    int *pts;
}driver ={"george","russek",(int[8]){6,12,1,4,5,6,7,8}};

chcemy zapisać dane do pliku zaznacz poprawne warianty(zakładamu że dla każdego wariantu wskaźnik file został poprawnie zainicjalizowany)

fprintf(file"%s %s )
