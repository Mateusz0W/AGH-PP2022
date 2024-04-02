#include <stdio.h>
#include <stdlib.h>

void file_copy (FILE *f1, FILE *f2){
   char *buffer;

   fseek(f2,0,SEEK_END);
   long file_size=ftell(f2);
   fseek(f2,0,SEEK_SET);
   buffer=malloc(file_size*sizeof(char));
   fread(buffer,sizeof(char),file_size,f2);
   fwrite(buffer,sizeof(char),file_size,f1);

}
int file_cmp (char *name1, char *name2){
   FILE *f1;
   FILE *f2;
   f1=fopen(name1,"rb");
   f2=fopen(name2,"rb");

   int a;
   int b;

   while ((a=fgetc(f1))!=EOF && (b=fgetc(f2))!=EOF)
   {
      if(a != b){
         fclose(f1);
         fclose(f2);
         return 1;
      }
   }
   
   fclose(f1);
   fclose(f2);
   return 0;

   
}

int main(){
double test[] = {1.0,2.3,2.1,5.2,1.9,2.9,4.3,4.4,5.0,5.2,3.5};	
		
FILE *ptr_txt ;	//wskaznik do pliku tekstowego
FILE *ptr_bin ; //wskaznik do pliku binarnego
int i;	
size_t test_len = sizeof(test)/sizeof(*test);

//zapis tablicy test do pliku binarnego 
ptr_bin = fopen ("b_1","wb");	
fwrite(test, 1, sizeof(test), ptr_bin);	
fclose(ptr_bin);

//zapis tablicy test do pliku tekstowego 
ptr_txt = fopen ("t_1","w");	
for (i = 0; i < test_len; i++)
   fprintf (ptr_txt, "%.1f ", test[i]);
fclose(ptr_txt);


//sprawdzenie
//wczytanie z pliku binarnego
ptr_bin = fopen ("b_1","rb");	
double *tab_1 = malloc (sizeof(test));
fread(tab_1, 1, sizeof(test), ptr_bin);	
fclose(ptr_bin);
 
puts("_______bin__________________") ;
for (i = 0; i < test_len; i++)
   printf ( " tab_1[%d]  %.1f  \n",i, tab_1[i]);
printf ("\n");   

//wczytanie z pliku tekstowego
ptr_txt = fopen ("t_1","r");	
double *tab_2 = malloc (sizeof(test));
for (int i = 0; i < test_len; i++)
   fscanf (ptr_txt, "%lf", tab_2 + i);
    
fclose(ptr_txt);
puts("_______text__________________") ;
for (i = 0; i < test_len; i++) 
  printf ( " tab_2[%d]  %.1f  \n",i, tab_2[i]);
////////////////////////////////////////////////////////////////////////////

 FILE *f1=fopen("b_2","wb");
    FILE *f2=fopen("b_1","rb");
    file_copy(f1,f2);
    fclose(f1);
    fclose(f2);

    f1=fopen("t_2","w");
    f2=fopen("t_1","r");
    file_copy(f1,f2);
    fclose(f1);
    fclose(f2);

    printf("porownanie b_1 i b_2: %d\n",file_cmp("b_1","b_2"));  
    printf("porownanie t_1 i t_2: %d\n", file_cmp("t_1","t_2"));  
    printf("porownanie b_1 i t_1: %d\n",file_cmp("b_1","t_1"));  

}
 