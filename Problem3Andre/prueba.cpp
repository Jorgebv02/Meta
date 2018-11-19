/*Programa para correr el programa*/

/*Includes requeridos*/
#include <map>
#include <vector>
#include <string>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <iostream>
#include <iterator>
#include "scan.hpp"
#include <cstring>
#include <cstdlib>
#include<stdlib.h>


using std::cout;
using std::endl;
using namespace std;
using namespace scanpp;


/*Class prueba en la cual se declaran variables requeridas y funciones necesarias*/

class Prueba{

    /*Estructura de nodo necesaria para la pila*/
    struct Nodo{
    int dato;           //Valor que se ira almacenando
    Nodo*siguiente;     //Puntero al siguiente nodo
    };

    int programCounter = 0;                 //Program counter del programa
    string nombreArchivo = "code.vbin";     //Nombre del archivo del cual se tomara el programa
    vector<vector<string>> tokens = tokenize_lines(nombreArchivo);  //Matriz donde se almacenaran las instrucciones tokenizadas
    Nodo*pila = NULL;                       //Estructuraque inicia la pila vacia 
    int x=0;                            //Valor x que se utiliza como memoria


    //Funcion que hara push a la pila
    void push(Nodo *&pila, int n){
        Nodo *nuevoNodo = new Nodo();
        nuevoNodo -> dato = n;
        nuevoNodo ->siguiente = pila;
        pila = nuevoNodo;
    } 

    //Funcion que ahra pull a la pila
    Nodo* pull(Nodo *&pila, int&n){
        Nodo *aux = pila;
        n = aux->dato;
        pila=aux->siguiente;
        return aux;
    }

    
    //Funcion que recibe la linea en la cual se esta trabajando para determinar lo siguiente a hacer
    void run(int linea){ 

        int banderaJMP=-1;                          //Bandera que se utiliza en los jumps para encontrar la etiqueta
        vector<string> lineaActual = tokens[linea]; //Se obtinene la line actual que se esta trabajando 
        string instruccion=lineaActual[0];          //Se obtiene la instruccion

        //A continuacion se evaluan todas las posibles instrucciones que se pueden obtener 

        int dato;                                   //Variable necesaria en la mayoria de casos

        if(instruccion=="load"){

            //Load posee dos posibilades
            instruccion=lineaActual[1];            //Caso en que la instrcuccion sea con x
            if (instruccion=="x"){
                push(pila,x);                       //Push del valor en el DIR(x)
            }
            else{                                   //Caso en que la isntruccion sea con un valor
                dato = std::stoi(instruccion);      //Conversion a entero
                push(pila,dato);                    //Push del valor que indican
            }

        }
        else if(instruccion=="store"){

            instruccion=lineaActual[1];            //Caso en que la instrcuccion sea con x
            if (instruccion=="x"){
                Nodo *aux=pull(pila,dato);         //Se saca el top de la pila     
                x=aux->dato;                       //Se almacena en x el valor del top
                delete aux;                        //Se elimina el nodo 
                }

        }else if(instruccion=="add"){

            Nodo *aux=pull(pila,dato);          //Se saca el top de la pila     
            Nodo *aux2=pull(pila,dato);         //Se saca el siguiente elemento de la pila          
            dato = aux->dato + aux2->dato;      //Se guarda en dato el valor de la suma de los dos pull
            push(pila,dato);                    //Se hace push del valor de la suma
            delete aux; delete aux2;            //Se eliminan ambos auxiliares     


        }else if(instruccion=="sub"){

            Nodo *aux=pull(pila,dato);          //Se saca el top de la pila     
            Nodo *aux2=pull(pila,dato);         //Se saca el siguiente elemento de la pila          
            dato = aux->dato - aux2->dato;      //Se guarda en dato el valor de la resta de los dos pull
            push(pila,dato);                    //Se hace push del valor de la suma
            delete aux; delete aux2;            //Se eliminan ambos auxiliares 

        }else if(instruccion=="mult"){

            Nodo *aux=pull(pila,dato);          //Se saca el top de la pila     
            Nodo *aux2=pull(pila,dato);         //Se saca el siguiente elemento de la pila          
            dato = aux->dato * aux2->dato;      //Se guarda en dato el valor de la multiplicacion de los dos pull
            push(pila,dato);                    //Se hace push del valor de la suma
            delete aux; delete aux2;            //Se eliminan ambos auxiliares 

        }else if(instruccion=="equal"){
            
            Nodo *aux=pull(pila,dato);          //Se saca el top de la pila     
            Nodo *aux2=pull(pila,dato);         //Se saca el siguiente elemento de la pila          
            dato = aux->dato - aux2->dato;      //Se guarda en dato el valor de la resta de los dos pull
            push(pila,dato);                    //Se hace push del valor de la suma
            delete aux; delete aux2;            //Se eliminan ambos auxiliares 

        }else if(instruccion=="jmp"){

            string etiqueta=lineaActual[1];                 //Obtencion de la etiqueta a la que se quiera saltar
            for (int i=0; i<tokens.size(); i++){            //For que recorre todas las intrucciones para buscar la etiqueta        
                vector<string> lineaTemp = tokens[linea];   //Se obtine la linea sesun el for 
                if (lineaTemp[0]==etiqueta){                //Enceuntra la linea donde se encuentra la etiqueta
                    banderaJMP=i;                           //Almacena en banderaJMP la linea a la que debe brincar
                    break;
                }
            }

        }else if(instruccion=="jmpz"){

            Nodo *aux=pull(pila,dato);          //Se saca el top de la pila     
            dato = aux->dato;                   //Guarda el valor en la variable dato
            if(dato==0){                        //Revisa si el valor es 0
                string etiqueta=lineaActual[1];                 //Obtencion de la etiqueta a la que se quiera saltar
                for (int i=0; i<tokens.size(); i++){            //For que recorre todas las intrucciones para buscar la etiqueta        
                    vector<string> lineaTemp = tokens[linea];   //Se obtine la linea sesun el for 
                    if (lineaTemp[0]==etiqueta){                //Enceuntra la linea donde se encuentra la etiqueta
                        banderaJMP=i;                           //Almacena en banderaJMP la linea a la que debe brincar
                        break;
                    }
                }
            } 
            delete aux;                         //Elimina el nodo con el que se esta trabajando    

        }else if(instruccion=="jmpnz"){

            Nodo *aux=pull(pila,dato);          //Se saca el top de la pila     
            dato = aux->dato;                   //Guarda el valor en la variable dato
            if(dato!=0){                        //Revisa si el valor es 0
                string etiqueta=lineaActual[1];                 //Obtencion de la etiqueta a la que se quiera saltar
                for (int i=0; i<tokens.size(); i++){            //For que recorre todas las intrucciones para buscar la etiqueta        
                    vector<string> lineaTemp = tokens[linea];   //Se obtine la linea sesun el for 
                    if (lineaTemp[0]==etiqueta){                //Enceuntra la linea donde se encuentra la etiqueta
                        banderaJMP=i;                           //Almacena en banderaJMP la linea a la que debe brincar
                        break;
                    }
                }
            } 
            delete aux;                         //Elimina el nodo con el que se esta trabajando  

        }else if(instruccion=="edit"){

            //No implementado

        }else if(instruccion=="print"){

            //No implementado

        }else if(instruccion=="halt"){

            return;                             //Se detiene la ejecucion del programa

        }else if(instruccion=="space"){

            //No implementado

        }else if(instruccion=="block"){

            //No implementado

        }else if(instruccion=="end"){

            return;                         //Indica el final del codigo ensamblador

        }else if(instruccion=="x"){
            
            //Variable para gaurdar en memoria

        }else{
            //En case de no corresponder a ninguna instruccion se asume que es una etiqueta
        }

        
        //Se procede a revisar el estado de las banderas

        if(banderaJMP==-1){             //Si la bandera no ha sido modificada
            linea=linea+1;              //Se procede a evaluar la siguiente linea
        }
        else{                           //Si la bandera fue modificada
            linea=banderaJMP;           //Se procede a moverse a la linea indicada
        }

        run(linea);
        
        return;
    }

};


int main(int argc, char *argv[])
{

    auto v = Prueba();
    
}
