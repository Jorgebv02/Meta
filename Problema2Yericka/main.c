#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


void crearArchBinario()
{
    FILE *arch;
    arch=fopen("prueba.vbin","wb");
    if (arch==NULL)
        exit(1);
    fclose(arch);
}


int main()
{
    leer_vasm();
    crearArchBinario();
    cargarArchBinario();
    listado();

}
