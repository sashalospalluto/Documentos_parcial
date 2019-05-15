#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "fantasma.h" //cambiar por nombre entidad

void fantasma_hardcodeo(Fantasma arrayFantasma[])
{
    strcpy(arrayFantasma[0].nombre,"Sasha");//Sasha
    strcpy(arrayFantasma[0].apellido,"Lospalluto");
    arrayFantasma[0].sexo='f';
    arrayFantasma[0].telefono=1166262107;
    strcpy(arrayFantasma[0].email,"sasha@hotmail.com");
    arrayFantasma[0].dia=21;
    arrayFantasma[0].mes=07;
    arrayFantasma[0].agno=1997;
    arrayFantasma[0].isEmpty=0;
    arrayFantasma[0].idUnico=1;

    strcpy(arrayFantasma[1].nombre,"Juan");//Juan Manuel
    strcpy(arrayFantasma[1].apellido,"Chico");
    arrayFantasma[1].sexo='m';
    arrayFantasma[1].telefono=1168940444;
    strcpy(arrayFantasma[1].email,"juan@hotmail.com");
    arrayFantasma[1].dia=25;
    arrayFantasma[1].mes=8;
    arrayFantasma[1].agno=1997;
    arrayFantasma[1].isEmpty=0;
    arrayFantasma[1].idUnico=2;

    strcpy(arrayFantasma[2].nombre,"Sandra Angelica");//Sandra Angelica
    strcpy(arrayFantasma[2].apellido,"Alvez");
    arrayFantasma[2].sexo='f';
    arrayFantasma[2].telefono=1165808344;
    strcpy(arrayFantasma[2].email,"sandra@hotmail.com");
    arrayFantasma[2].dia=26;
    arrayFantasma[2].mes=01;
    arrayFantasma[2].agno=1972;
    arrayFantasma[2].isEmpty=0;
    arrayFantasma[2].idUnico=3;

    strcpy(arrayFantasma[3].nombre,"Ricardo");//Sandra Angelica
    strcpy(arrayFantasma[3].apellido,"Rojas");
    arrayFantasma[3].sexo='f';
    arrayFantasma[3].telefono=1165808344;
    strcpy(arrayFantasma[3].email,"ricardo@hotmail.com");
    arrayFantasma[3].dia=26;
    arrayFantasma[3].mes=01;
    arrayFantasma[3].agno=1972;
    arrayFantasma[3].isEmpty=0;
    arrayFantasma[3].idUnico=4;
}

/** \brief  To indicate that all position in the array are empty,
*          this function put the flag (isEmpty) in TRUE in all
*          position of the array
* \param array fantasma Array of fantasma
* \param size int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int fantasma_Inicializar(Fantasma array[], int size)                                    //cambiar fantasma
{
    int retorno=-1;
    if(array!= NULL && size>0)
    {
        for(;size>0;size--)
        {
            array[size-1].isEmpty=1;
        }
        retorno=0;
    }
    return retorno;
}

//*****************************************
//Buscar
//Int
/** \brief Busca el primer lugar vacio en un array
* \param array fantasma Array de fantasma
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra un lugar vacio o Error [Invalid length or NULL pointer] - (0) si encuentra una posicion vacia
*
*/
int fantasma_buscarEmpty(Fantasma array[], int size, int* posicion)                    //cambiar fantasma
{
    int retorno=-1;
    int i;
    if(array!= NULL && size>=0 && posicion!=NULL)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;
}

/** \brief Busca un ID en un array y devuelve la posicion en que se encuentra
* \param array fantasma Array de fantasma
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int fantasma_buscarID(Fantasma array[], int size, int valorBuscado, int* posicion)                    //cambiar fantasma
{
    int retorno=-1;
    int i;
    if(array!= NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else if(array[i].idUnico==valorBuscado)                                                   //cambiar campo ID
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;
}
/** \brief Busca un int en un array y devuelve la posicion en que se encuentra
* \param array fantasma Array de fantasma
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int fantasma_buscarInt(Fantasma array[], int size, int valorBuscado, int* posicion)                    //cambiar fantasma
{
    int retorno=-1;
    int i;
    if(array!= NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
          /*  else if(array[i].varInt==valorBuscado)                                                   //cambiar campo varInt
            {
                retorno=0;
                *posicion=i;
                break;
            }
            */
        }
    }
    return retorno;
}

//String
/** \brief Busca un string en un array
* \param array fantasma Array de fantasma
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int fantasma_buscarString(Fantasma array[], int size, char* valorBuscado, int* indice)                    //cambiar fantasma
{
    int retorno=-1;
    int i;
    if(array!=NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else if(strcmpi(array[i].nombre,valorBuscado)==0)                                        //cambiar campo nombre
            {
                *indice=i;
                retorno=0;
                break;
            }
        }
    }
    return retorno;
}

//*****************************************
//Alta
/** \brief Solicita los datos para completar la primer posicion vacia de un array
* \param array fantasma Array de fantasma
* \param size int Tamaño del array
* \param contadorID int* Puntero al ID unico que se va a asignar al nuevo elemento
* \return int Return (-1) si Error [largo no valido o NULL pointer o no hay posiciones vacias] - (0) si se agrega un nuevo elemento exitosamente
*
*/
int fantasma_alta(Fantasma array[], int size, int* contadorID)                          //cambiar fantasma
{
    int retorno=-1;
    int posicion;
    /*if (fantasma_todoVacio(array,size)==0)
    {
        printf("\nNo ingreso ningun fantasma\n");
    }
    else
    {*/
        if(array!=NULL && size>0 && contadorID!=NULL)
        {
            if(fantasma_buscarEmpty(array,size,&posicion)==-1)                          //cambiar fantasma
            {
                printf("\nNo hay lugares vacios");
            }
            else
            {
                if(utn_getFloat("\nTelefono: ","\nError",1,13,0,sizeof(float),1,&array[posicion].telefono)==0 &&            //mensaje + cambiar campo telefono
                   utn_getName("\nNombre: ","\nError",1,TEXT_SIZE,1,array[posicion].nombre)==0 &&                      //mensaje + cambiar campo nombre
                   utn_getName("\nApellido: ","\nError",1,TEXT_SIZE,1,array[posicion].apellido)==0)
                   {
                       utn_getChar("\nIngrese sexo (F o M): ","\nError",1,sizeof(char),3,&array[posicion].sexo);
                       if (array[posicion].sexo=='f' || array[posicion].sexo=='F' || array[posicion].sexo=='m' || array[posicion].sexo=='M')
                       {
                           if (utn_getEmail("\ningrese email: ", "\nerror\n",1,TEXT_SIZE,3,array[posicion].email)==0 &&
                                utn_getFecha(&array[posicion].dia,&array[posicion].mes,&array[posicion].agno)==0)
                                {
                                    (*contadorID)++;
                                    array[posicion].idUnico=*contadorID;                                                       //campo ID
                                    array[posicion].isEmpty=0;
                                    printf("\n Posicion: %d\n ID: %d\n telefono: %f\n nombre: %s\n apellido: %s \n Sexo: %c\n Email: %s\n Fecha: %d/%d/%d\n",
                                    posicion, array[posicion].idUnico,array[posicion].telefono,array[posicion].nombre,array[posicion].apellido,array[posicion].sexo, array[posicion].email,array[posicion].dia,array[posicion].mes, array[posicion].agno);
                                }
                       }
                       else
                       {
                           printf("\nError al poner el sexo\n");
                       }
                   }
                retorno=0;
            }
        }
   // }
    return retorno;
}

//*****************************************
//Baja valor unico
/** \brief Borra un elemento del array por ID
* \param array fantasma Array de fantasma
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se elimina el elemento exitosamente
*
*/
int fantasma_baja(Fantasma array[], int sizeArray)                                      //cambiar fantasma
{
    int retorno=-1;
    int posicion;
    int id;
    int opcion;
    if (fantasma_todoVacio(array,sizeArray)==0)
    {
        printf("\nNo ingreso ningun fantasma\n");
    }
    else
    {
        if(array!=NULL && sizeArray>0)
        {
            utn_getUnsignedInt("\nID a cancelar: ","\nError",1,sizeof(int),1,sizeArray,1,&id);          //cambiar si no se busca por ID
            if(fantasma_buscarID(array,sizeArray,id,&posicion)==-1)                                   //cambiar si no se busca por ID
            {
                printf("\nNo existe este ID");                                                          //cambiar si no se busca por ID
            }
            else
            {
                utn_getUnsignedInt("\n\tOPCIONES\n1-Si\n2-No\nSeguro que lo desea eliminar?: ","\nError",1,sizeof(int),1,sizeArray,3,&opcion);
                if(opcion==1)
                {
                    printf("\nBORRADO CON EXITO\n");
                    array[posicion].isEmpty=1;
                    retorno=0;
                }
            }
        }
    }
    return retorno;
}

//Baja valor repetido
/** \brief Borra todos los elemento del array que contengan el valor buscado
* \param array fantasma Array de fantasma
* \param size int Tamaño del array
* \param valorBuscado int Valor a buscar en el array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se elimina el elemento exitosamente
*
*/
int fantasma_bajaValorRepetidoInt(Fantasma array[], int sizeArray, int valorBuscado) //cuando hay que dar de baja todas las posiciones en las que se encuentra ese int
{
    int retorno=-1;
    int i;
    if(array!=NULL && sizeArray>0)
    {
        for(i=0;i<sizeArray;i++)
        {
            if(array[i].idUnico==valorBuscado)                                                        //cambiar si no se busca por ID
            {
                array[i].isEmpty=1;
                array[i].idUnico=0;                                                                   //cambiar campo id
//                array[i].varInt=0;                                                               //cambiar campo varInt
                array[i].telefono=0;                                                             //cambiar campo telefono
                strcpy(array[i].nombre,"");                                                   //cambiar campo nombre
                strcpy(array[i].apellido,"");                                               //cambiar campo apellido
            }
        }
        retorno=0;
    }
    return retorno;
}



//*****************************************
//Modificar
/** \brief Busca un elemento por ID y modifica sus campos
* \param array fantasma Array de fantasma
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se modifica el elemento exitosamente
*
*/
int fantasma_modificar(Fantasma array[], int sizeArray)                                //cambiar fantasma
{
    int retorno=-1;
    int posicion;
    int id;                                                                                         //cambiar si no se busca por ID
    int opcion;

    //auxiliares
    Fantasma auxArray;
    if (fantasma_todoVacio(array,sizeArray)==0)
    {
        printf("\nNo ingreso ningun fantasma\n");
    }
    else
    {
        if(array!=NULL && sizeArray>0)
        {
            utn_getUnsignedInt("\nIngrese el codigo del fantasma: ","\nError",1,sizeof(int),1,sizeArray,1,&id);         //cambiar si no se busca por ID
            if(fantasma_buscarID(array,sizeArray,id,&posicion)==-1)                                   //cambiar si no se busca por ID
            {
                printf("\nNo existe este ID");                                                          //cambiar si no se busca por ID
            }
            else
            {
                do
                {       //copiar printf de alta
                    printf("\n 1-nombre: %s\n 2-apellido: %s \n3-sexo: %c \n4-Telefono: %2.f \n5-email: %s\n6-SALIR\n",
                           array[posicion].nombre,array[posicion].apellido, array[posicion].sexo,array[posicion].telefono,array[posicion].email);
                    utn_getUnsignedInt("\nIngrese opcion: ","error",1,7,1,6,3,&opcion);
                    switch(opcion)
                    {
                        case 1:
                            if (utn_getName("\nNombre: ","\nError",1,TEXT_SIZE,1,auxArray.nombre)==0)
                            {
                                strcpy(array[posicion].nombre,auxArray.nombre);
                            }
                            else
                            {
                                printf("\nError al cargar el dato");
                            }
                            break;
                        case 2:
                            if(utn_getTexto("\nApellido: ","\nError",1,TEXT_SIZE,1,auxArray.apellido)==0)
                            {
                                strcpy(array[posicion].apellido,auxArray.apellido);
                            }
                            else
                            {
                                printf("\nError al cargar el dato");
                            }
                            break;
                        case 3:
                            utn_getChar("\nIngrese sexo (F o M): ","\nError",1,sizeof(char),3,&auxArray.sexo);
                            if (auxArray.sexo=='f' || auxArray.sexo=='F' || auxArray.sexo=='m' || auxArray.sexo=='M')
                            {
                                array[posicion].sexo=auxArray.sexo;
                            }
                            else
                            {
                                printf("\nError al cargar el dato");
                            }
                            break;
                        case 4:
                            if(utn_getFloat("\nTelefono: ","\nError",1,13,0,sizeof(float),1,&auxArray.telefono)==0)
                            {
                                array[posicion].telefono=auxArray.telefono;
                            }
                            else
                            {
                                printf("\nError al cargar el dato");
                            }
                            break;
                        case 5:
                            if(utn_getEmail("\ningrese email: ", "\nerror\n",1,TEXT_SIZE,3,auxArray.email)==0)
                            {
                                strcpy(array[posicion].email,auxArray.email);
                            }
                            else
                            {
                                printf("\nError al cargar el dato");
                            }
                            break;
                        case 6:
                            break;
                        default:
                            printf("\nOpcion no valida");
                    }
                }while(opcion!=6);
                retorno=0;
            }
        }
    }
    return retorno;
}

//*****************************************
//Ordenar
/** \brief Ordena por campo XXXXX los elementos de un array
* \param array fantasma Array de fantasma
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer] - (0) si se ordena exitosamente
*
*/

void fantasma_ordenarPorString(Fantasma array[],int size)                              //cambiar autor
{
    printf("\nORDENADO POR APELLIDO Y NOMBRE\n");
    int i;
    Fantasma auxiliar;
    int j;

      for(i=0 ; i<size-1 ; i++)
        {
            for(j=i+1; j<size ; j++)
            {
                if((array[i].isEmpty==0) && (array[j].isEmpty==0))
                {
                    if ((strcmpi(array[j].apellido,array[i].apellido)<0))
                    {
                        auxiliar=array[i];
                        array[i]=array[j];
                        array[j]=auxiliar;
                    }else if((strcmpi(array[j].apellido,array[i].apellido)==0) && (strcmpi(array[j].nombre,array[i].nombre)<0))
                        {
                            auxiliar=array[i];
                            array[i]=array[j];
                            array[j]=auxiliar;
                        }
                }
            }
        }
}


//*****************************************
//Listar
/** \brief Lista los elementos de un array
* \param array fantasma Array de fantasma
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer] - (0) si se lista exitosamente
*
*/
int fantasma_listar(Fantasma array[], int size)                      //cambiar fantasma
{
    int retorno=-1;
    int i;
    if (fantasma_todoVacio(array,size)==0)
    {
        printf("\nNo ingreso ningun fantasma\n");
    }
    else
    {
        if(array!=NULL && size>=0)
        {
            fantasma_ordenarPorString(array,size);
            //fantasma_ordenarPorStringInsercion(array,size);
            for(i=0;i<size;i++)
            {
                if(array[i].isEmpty==1)
                    continue;
                else
                    printf("\n ID: %d\n telefono: %2.f\n nombre: %s\n apellido: %s \n Sexo: %c \n email: %s, \n fecha: %d/%d/%d\n",
                           array[i].idUnico,array[i].telefono,array[i].nombre,array[i].apellido, array[i].sexo, array[i].email,array[i].dia,array[i].mes,array[i].agno);      //cambiar todos
            }
            retorno=0;
        }
    }
    return retorno;
}

int fantasma_todoVacio(Fantasma array[], int size)
{
    int ret=-1;
    int contador=0;
    int i;
    for(i=0;i<size;i++)
    {
        if(array[i].isEmpty==1)
        {
            contador++;
            if(contador==size)
            {
               ret=0;
            }
        }
    }
    return ret;
}

//Ordenar
/** \brief Ordena por campo XXXXX los elementos de un array
* \param array fantasma Array de fantasma
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer] - (0) si se ordena exitosamente
*
*/
int fantasma_ordenarPorStringInsercion(Fantasma array[],int size)                              //cambiar fantasma
{
    int retorno=-1;
    int i, j;
    char bufferNombre[TEXT_SIZE];                               //cambiar campo varString
    char bufferApellido[TEXT_SIZE];
    int bufferId;
    char bufferSexo;
    float bufferTelefono;
    char bufferEmail[TEXT_SIZE];
    int dia;
    int agno;
    int mes;
    int bufferIsEmpty;

    if(array!=NULL && size>=0)
    {
        for (i = 1; i < size; i++)
        {
            strcpy(bufferNombre,array[i].nombre);
            strcpy(bufferApellido,array[i].apellido);                      //cambiar campo varString
            bufferId=array[i].idUnico;                                   //cambiar campo id
            bufferIsEmpty=array[i].isEmpty;
            bufferSexo=array[i].sexo;                                //cambiar campo varInt
            bufferTelefono=array[i].telefono;                            //cambiar campo varFloat
            strcpy(bufferEmail,array[i].email);
            dia=array[i].dia;
            agno=array[i].agno;
            mes=array[i].mes;
            j = i - 1;
            while ((j >= 0) && strcmpi(bufferNombre,array[j].nombre)<0)         //cambiar campo varString                 //Si tiene mas de un criterio se lo agrego, Ej. bufferInt<array[j].varInt
            {                                                                                                               //buffer < campo ascendente   buffer > campo descendente
                strcpy(array[j + 1].nombre,array[j].nombre);          //cambiar campo varString
                array[j + 1].idUnico=array[j].idUnico;                                //cambiar campo id
                array[j + 1].isEmpty=array[j].isEmpty;
                array[j + 1].sexo=array[j].sexo;                        //cambiar campo varInt
                array[j + 1].telefono=array[j].telefono;                        //cambiar campo varInt
                array[j + 1].dia=array[j].dia;                        //cambiar campo varInt
                array[j + 1].mes=array[j].mes;                        //cambiar campo varInt
                array[j + 1].agno=array[j].agno;                        //cambiar campo varInt
                strcpy(array[j + 1].apellido,array[j].apellido);  //cambiar campo varLongString
                strcpy(array[j + 1].email,array[j].email);  //cambiar campo varLongString
                j--;
            }
            strcpy(array[j + 1].nombre,bufferNombre);                     //cambiar campo varString
            strcpy(array[j + 1].apellido,bufferApellido);                     //cambiar campo varString
            array[j + 1].idUnico=bufferId;                                        //cambiar campo id
            array[j + 1].isEmpty=bufferIsEmpty;
            array[j + 1].dia=dia;                                                        //cambiar campo varInt
            array[j + 1].sexo=bufferSexo;                                                        //cambiar campo varInt
            array[j + 1].mes=mes;                                                        //cambiar campo varInt
            array[j + 1].agno=agno;                                                        //cambiar campo varInt
            array[j + 1].telefono=bufferTelefono;                                                    //cambiar campo varFloat
            strcpy(array[j + 1].email,bufferEmail);                                  //cambiar campo varLongString
        }
        retorno=0;
    }
    return retorno;
}
