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
#include<stack>
#include <cmath>


using std::cout;
using std::endl;
using namespace std;
using namespace scanpp;


/*Class prueba en la cual se declaran variables requeridas y funciones necesarias*/

class Prueba{

    /*Estructura de pila*/

    void showstack(stack <int> s) 
    { 
        while (!s.empty()) 
        { 
            cout << '\t' << s.top(); 
            s.pop(); 
        } 
        cout << '\n'; 
    } 

    


    int programCounter = 0;                 //Program counter del programa
    string nombreArchivo = "code.vbin";     //Nombre del archivo del cual se tomara el programa
    vector<vector<string>> tokens = tokenize_lines(nombreArchivo);  //Matriz donde se almacenaran las instrucciones tokenizadas
    stack <int> pila;                       //Estructuraque inicia la pila vacia 
    int x=0;                                //Valor x que se utiliza como memoria
    std::vector<std::string> bufferSalida;  //Vector con los valores del output


    
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
                pila.push(x);                       //Push del valor en el DIR(x)
            }
            else{                                   //Caso en que la isntruccion sea con un valor
                dato = std::stoi(instruccion);      //Conversion a entero
                pila.push(dato);                    //Push del valor que indican
            }

        }
        else if(instruccion=="store"){

            instruccion=lineaActual[1];            //Caso en que la instrcuccion sea con x
            if (instruccion=="x"){
                x=pila.top();                        //Se almacena en x el valor del top
                pila.pop();                      //Se elimina el top de la pila
                }

        }else if(instruccion=="add"){

            int temp=pila.top();                 //Se saca el top de la pila     
            pila.pop();                         //Se elimina el top de la pila
            int temp2=pila.top();                //Se saca el siguiente elemento de la pila    
            pila.pop();                         //Se elimina el top de la pila
            dato = temp+temp2;                  //Se guarda en dato el valor de la suma de los dos pops
            pila.push(dato);                    //Se hace push del valor de la suma
            


        }else if(instruccion=="sub"){

            int temp=pila.top();                 //Se saca el top de la pila     
            pila.pop();                         //Se elimina el top de la pila
            int temp2=pila.top();                //Se saca el siguiente elemento de la pila    
            pila.pop();                         //Se elimina el top de la pila
            dato = temp-temp2;                  //Se guarda en dato el valor de la resta de los dos pops
            pila.push(dato);                    //Se hace push del valor de la suma

        }else if(instruccion=="mult"){

            int temp=pila.top();                 //Se saca el top de la pila     
            pila.pop();                         //Se elimina el top de la pila
            int temp2=pila.top();                //Se saca el siguiente elemento de la pila    
            pila.pop();                         //Se elimina el top de la pila
            dato = temp*temp2;                  //Se guarda en dato el valor de la mult de los dos pops
            pila.push(dato);                    //Se hace push del valor de la suma

        }else if(instruccion=="equal"){
            
            int temp=pila.top();                 //Se saca el top de la pila     
            pila.pop();                         //Se elimina el top de la pila
            int temp2=pila.top();                //Se saca el siguiente elemento de la pila    
            pila.pop();                         //Se elimina el top de la pila
            dato = temp+temp2;                  //Se guarda en dato el valor de la resta de los dos pops
            pila.push(dato);                    //Se hace push del valor de la suma

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

            dato=pila.top();                //Guarda el valor en la variable dato
            pila.pop();                         //Se saca el top de la pila     
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

        }else if(instruccion=="jmpnz"){

            dato=pila.top();                //Guarda el valor en la variable dato
            pila.pop();                         //Se saca el top de la pila     
            if(dato!=0){                        //Revisa si el valor es 0
                string etiqueta=lineaActual[1];                 //Obtencion de la etiqueta a la que se quiera saltar
                for (int i=0; i<tokens.size(); i++){            //For que recorre todas las intrucciones para buscar la etiqueta        
                    vector<string> lineaTemp = tokens[linea];   //Se obtine la linea sesun el for 
                    if (lineaTemp[0]==etiqueta){                //Enceuntra la linea donde se encuentra la etiqueta
                        banderaJMP=i;                           //Almacena en banderaJMP la linea a la que debe brincar
                        break;
                    }
                }
            }                         //Elimina el nodo con el que se esta trabajando  

        }else if(instruccion=="edit"){

            dato = pila.top();              //Se extrae el tope de la pila
            pila.pop();                     //Se elimina el tope de la pila
            int posicion=round(dato);       //Se redondea el dato
            string str = lineaActual[1];    //Se obtiene lo que se quiere insertar en el buffer salida
            bufferSalida[posicion] = str;   //Se inserta en el buffer salida el valor

        }else if(instruccion=="print"){

            for (int i = 0; i < 100; i++)
            {
                cout << bufferSalida[i] <<endl;     //Se imprime todo el bufferSalida
            }

        }else if(instruccion=="halt"){

            return;                             //Se detiene la ejecucion del programa

        }else if(instruccion=="space"){
    
            for (int i =0; i<std::stoi(lineaActual[1]); i++){    //Agrega N espacios al bufferSalida
                bufferSalida.push_back(" ");
            }

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
