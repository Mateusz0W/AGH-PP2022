struct {
    int age;
    char *name;
    double lucky_numbers[2];} var_1={1,"JAN",{1.0,2.0}};

struct {
    int age;
    char name[10];
    double lucky_numbers[2];} var_2={1,"JAN",{1.0,2.0}};

zakładając że wskaźnik fp został poprawnie utworzony

fwrite(&var_2,sizeof(var_2),1,fp);
fwrite(&var_1,sizeof(var_1),1,fp);

które polecenia są poprawne