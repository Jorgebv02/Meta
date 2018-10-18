#include<stdio.h>

typedef struct {
    char valor[80];
    int direccion;
    char nombre[10];
    int tipo; //1 = Palabra reservada , 0 = etiqueta
} token;


token list_tokens[1000];
void procesar_linea(char linea[1000], int temp_dir){

}
void leer_vasm(){
    FILE *arch;
    arch=fopen("prueba.vasm","rb");
    int temp_dir = 0x0;
    char linea[1000];
    if (arch==NULL)
        exit(1);

    while(!feof(arch))
    {
        fgets(linea, 1000,arch);
        procesar_linea(linea,temp_dir);
    }
    fclose(arch);
}

