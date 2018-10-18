#include<stdio.h>

typedef struct {
    int codInst;
    char descripcion[8];
    int cantBytes;
} tinstruccion;


tinstruccion array[16];

void cargarInstrucciones(){
    char *tnombres[16] = {"load","loadl","store","add","sub","mult","equal","jmp","jmpz","jmpnz","edit","print","halt","space","block","end"};
    int cods[16] = {0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,0x09,0x0A,0,0x0C,0x0D,0,0x00,0x00};
    int cantbyt [16]= {4,9,4,1,1,1,1,4,4,4,2,1,1,1,1,1};
    tinstruccion temp;
    for(int i = 0; i < 16;i++){
        strcpy(temp.descripcion,tnombres[i]);
        temp.cantBytes = cantbyt[i];
        temp.codInst= cods[i];
        array[i] = temp;
    }
}
