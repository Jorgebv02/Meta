#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int direccion;
    char valor_sgt[30];
    char codInstr[16];
    int tipo;
} token;

typedef struct {
    char direccion[6];
    char codinstruccion[6];
    char parte1[6];
    char parte2[10];
} tlinea;
token temp_tok;
token list_tokens[1000];
int ctokens= 0;
int temp_dir = 0;
char token_buffer[80];

void clear_buffer(int pos){
	int i;
	for(i = 0; i < 128; i++){
		token_buffer[i] = 0;
	}
}

int check_reserved(){
	if( strcmp(token_buffer, "load") == 0){
        strcpy(temp_tok.codInstr ,"01");
        temp_tok.direccion = temp_dir;
        temp_tok.tipo = 1;
        temp_dir =  temp_dir + 4;
		return 1;
	}
	else if( strcmp(token_buffer, "loadl") == 0){
        strcpy(temp_tok.codInstr,"02");
        temp_tok.direccion = temp_dir;
        temp_tok.tipo = 1;
        temp_dir =  temp_dir + 9;
		return 2;
	}
	else if( strcmp(token_buffer, "store") == 0){
        strcpy(temp_tok.codInstr,"03");
        temp_tok.direccion = temp_dir;
        temp_tok.tipo = 1;
        temp_dir =  temp_dir + 4;
		return 3;
	}
	else if( strcmp(token_buffer, "add") == 0){
        strcpy(temp_tok.codInstr ,"04");
        temp_tok.direccion = temp_dir;
        temp_tok.tipo = 1;
        temp_dir =  temp_dir + 1;
		return 4;
	}
	else if( strcmp(token_buffer, "sub") == 0){
        strcpy(temp_tok.codInstr ,"05");
        temp_tok.direccion = temp_dir;
        temp_tok.tipo = 1;
        temp_dir =  temp_dir + 1;
		return 5;
	}
	else if( strcmp(token_buffer, "mult") == 0){
        strcpy(temp_tok.codInstr ,"06");
        temp_tok.direccion = temp_dir;
        temp_tok.tipo = 1;
        temp_dir =  temp_dir + 1;
		return 6;
	}
	else if( strcmp(token_buffer, "equal") == 0){
        strcpy(temp_tok.codInstr ,"07");
        temp_tok.direccion = temp_dir;
        temp_tok.tipo = 1;
        temp_dir =  temp_dir + 1;
		return 7;
	}
	else if( strcmp(token_buffer, "jmp") == 0){
        strcpy(temp_tok.codInstr,"08");
        temp_tok.direccion = temp_dir;
        temp_tok.tipo = 1;
        temp_dir =  temp_dir + 4;
		return 8;
	}
	else if( strcmp(token_buffer, "jmpz") == 0){
        strcpy(temp_tok.codInstr,"09");
        temp_tok.direccion = temp_dir;
        temp_tok.tipo = 1;
        temp_dir =  temp_dir + 4;
		return 9;
	}
	else if( strcmp(token_buffer, "jmpnz") == 0){
        strcpy(temp_tok.codInstr,"0A");
        temp_tok.direccion = temp_dir;
        temp_tok.tipo = 1;
        temp_dir =  temp_dir + 4;
		return 10;
	}
	else if( strcmp(token_buffer, "edit") == 0){
            //VER EL LARGO DEL STRING QUE SIGUE
        temp_tok.direccion = temp_dir;
        temp_tok.tipo = 1;
        temp_dir =  temp_dir + 2;
		return 11;
	}
	else if( strcmp(token_buffer, "print") == 0){
        strcpy(temp_tok.codInstr,"0C");
        temp_tok.direccion = temp_dir;
        temp_tok.tipo = 1;
        temp_dir =  temp_dir + 1;
		return 12;
	}
	else if( strcmp(token_buffer, "halt") == 0){
        strcpy(temp_tok.codInstr,"0D");
        temp_tok.direccion = temp_dir;
        temp_tok.tipo = 1;
        temp_dir =  temp_dir + 1;
		return 13;
	}
	else if( strcmp(token_buffer, "space") == 0){
	    //VER EL NUMERO D E ESPACIOS
        temp_tok.direccion = temp_dir;
        temp_tok.tipo = 1;
        temp_dir =  temp_dir + 1;
		return 14;
	}
	else if( strcmp(token_buffer, "block") == 0){
        temp_tok.direccion = temp_dir;
        temp_tok.tipo = 1;
        temp_dir =  temp_dir + 1;
        strcpy(temp_tok.valor_sgt,token_buffer);
		return 15;
	}
	else if( strcmp(token_buffer, "end") == 0){
        temp_tok.direccion = temp_dir;
        temp_tok.tipo = 1;
        temp_dir =  temp_dir + 1;
        strcpy(temp_tok.valor_sgt,token_buffer);
		return 16;
	}
	else{
        temp_tok.direccion = temp_dir;
        strcpy(temp_tok.valor_sgt,token_buffer);
        temp_tok.tipo = 0;
		return 17;
	}
}
void procesar_linea(char linea[1000]){
    int c;
 	int pos = 0;
	int pos_buf=0;
    c = linea[pos];
   clear_buffer(pos_buf);
    while(isalnum(c) || c == '_'){
        token_buffer[pos_buf] = c;
        pos_buf++;
        pos++;
        c = linea[pos];
    }
   // printf("Token: %s",token_buffer);
    int instr = check_reserved();
    if(c == ' '){
        pos++;
        clear_buffer(pos_buf);
        pos_buf = 0;
        c = linea[pos];
        while(c != ' '){
             token_buffer[pos_buf] = c;
             pos_buf++;
             pos++;
             c = linea[pos];
        }
        if(instr != 15){
            strcpy(temp_tok.valor_sgt,token_buffer);
        }
        if(instr == 11){ //edit
            char out_string [18];
            int t = strlen(token_buffer) - 2;
            sprintf(out_string, "1%x",t);
            strcpy(temp_tok.codInstr,out_string);
        }
        else if(instr==14){
            char out_string [18];
            int k;
            k = atoi(token_buffer);
            sprintf(out_string, "2%x", k);
            strcpy(temp_tok.codInstr,out_string);
        }
    }
    //printf("  %s,  %x,   %s ,  %d \n",temp_tok.codInstr,temp_tok.direccion,temp_tok.valor_sgt,temp_tok.tipo);
    list_tokens[ctokens] = temp_tok;
    ctokens++;
}

void leer_vasm(){
    FILE *arch;
    arch=fopen("prueba.vasm","rb");
    char linea[1000];
    if (arch==NULL)
        exit(1);

    while(!feof(arch))
    {
        fgets(linea, 1000,arch);
        procesar_linea(linea);
    }
    fclose(arch);
}

void cargarArchBinario(){
    FILE *arch;
    arch=fopen("prueba.vbin","ab");
    if (arch==NULL)
        exit(1);
    token temporalt;
    tlinea templ;
    for(int i=0;i<ctokens;i++){
        temporalt = list_tokens[i];
        sprintf(templ.direccion,"%x",temporalt.direccion);
        strcpy(templ.parte1,"");
        strcpy(templ.parte2,"");
       // printf("direccion: %s",templ.direccion);
        if(temporalt.tipo != 0 && strcmp(temporalt.valor_sgt,"block") != 0
           && strcmp(temporalt.valor_sgt,"end") != 0){
            strcpy(templ.codinstruccion,temporalt.codInstr);
           // printf(" ----codInstrucc: %s",templ.codinstruccion);
        }
        else{
            strcpy(templ.codinstruccion,"");
        }
        //necesito ver si es una instruccion con algo mas
        if(temporalt.tipo != 0 && strcmp(temporalt.valor_sgt,"block") != 0
           && strcmp(temporalt.valor_sgt,"end") != 0){
            if(strcmp(temporalt.codInstr,"02")==0){ //loadl
                sprintf(templ.parte2,"000000%s",temporalt.valor_sgt);
            }
            else if(strcmp(temporalt.codInstr,"01") == 0 ||strcmp(temporalt.codInstr,"03") == 0||
                    (temporalt.codInstr,"08")==0|| strcmp(temporalt.codInstr,"09")==0||
                    strcmp(temporalt.codInstr,"0A")==0){
                sprintf(templ.parte1,"0000%x",temporalt.codInstr);
                strcpy(templ.parte2,"");
            }
            else{
                if(temporalt.codInstr[0] == '1'){ //edit
                    int c = temporalt.valor_sgt[0];
                    sprintf(templ.parte1,"%x",c);
                    strcpy(templ.parte2,"");
                    //int ttt = strlen(temporalt.valor_sgt);
                   // int c;
                    // for(int k=0;k<ttt;k++){
                    //    c= temporalt.valor_sgt[k];
                    //    sprintf(templ.parte1,"%x",c);
                   //  }
                }

            }
        }
         //printf(" --- parteI: %s ----- parteII: %s \n",templ.parte1,templ.parte2);
        fwrite(&templ, sizeof(templ), 1, arch);
    }
    fclose(arch);
}

void listado()
{
    FILE *arch;
    arch=fopen("prueba.vbin","rb");
    if (arch==NULL)
        exit(1);
    tlinea linea;
    fread(&linea, sizeof(tlinea), 1, arch);
    while(!feof(arch))
    {
        printf("%s - %s %s %s\n", linea.direccion, linea.codinstruccion, linea.parte1,linea.parte2);
        fread(&linea, sizeof(tlinea), 1, arch);
    }
    fclose(arch);
}
