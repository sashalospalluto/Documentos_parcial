#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "fantasma.h"
#include"utn.h"
#define QTY_TIPO 7

int main()
{
    int opcion;
    int contadorIdFantasma=0;                   //cambiar
    Fantasma arrayFantasma[QTY_TIPO];
    fantasma_Inicializar(arrayFantasma,QTY_TIPO);
    fantasma_hardcodeo(arrayFantasma);

    do
    {
        utn_getUnsignedInt("\n\t\tMENU\n1) Alta fantasma \n2) Modificar fantasma \n3) Baja fantasma \n4) Listar fantasma\n"
                               "5) Salir\n \tIngrese una opcion: ",                //cambiar
                      "\nError",1,sizeof(int),1,6,1,&opcion);
        switch(opcion)
        {
            case 1: //Alta
                fantasma_alta(arrayFantasma,QTY_TIPO,&contadorIdFantasma);
                break;
            case 2: //Modificar
                fantasma_modificar(arrayFantasma,QTY_TIPO);
                break;
            case 3: //Baja
                fantasma_baja(arrayFantasma,QTY_TIPO);
                break;
            case 4://Listar
                fantasma_listar(arrayFantasma,QTY_TIPO);

                break;
            case 5://Salir
                break;
            default:
                printf("\nOpcion no valida");
        }
    }
    while(opcion!=5);
    return 0;
}
