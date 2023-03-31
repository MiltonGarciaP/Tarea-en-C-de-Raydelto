#include "constantes.h"
#include "solucion.h"
#include "logica.h"


#include <iostream>
using namespace std;

/*
* Implementar esta función.
* Dependiendo el estado del juego esta debe retornar:  

GANO_X: Si Ha ganado el jugador X
GANO_O: Si Ha ganado el jugador O
EMPATE: Si ya se llenaron todas las casillas y no hay ganador
JUEGO_EN_CURSO: Si el juego aún no se ha terminado.
*/
int GetEstado()
{
    /*
    Puedes acceder a las casillas del tablero mediante el arreglo de 
    dos dimensiones tablero.  

    Los índices empiezan en cero, de modo que puedes acceder a la segunda fila, primera columna 
    de la siguiente manera:
    tablero[1][0]
    */
    char** tablero = GetTablero();
    if(
        (tablero[0][0] == 'X' && tablero[0][1] == 'X' && tablero[0][2] == 'X') // horiz 0
      ||(tablero[1][0] == 'X' && tablero[1][1] == 'X' && tablero[1][2] == 'X') // horiz 1
      ||(tablero[2][0] == 'X' && tablero[2][1] == 'X' && tablero[2][2] == 'X') // horiz 2

      ||(tablero[0][0] == 'X' && tablero[1][0] == 'X' && tablero[2][0] == 'X') // vert 0
      ||(tablero[0][1] == 'X' && tablero[1][1] == 'X' && tablero[2][1] == 'X') // vert 1
      ||(tablero[0][2] == 'X' && tablero[1][2] == 'X' && tablero[2][2] == 'X') // vert 2

      ||(tablero[0][0] == 'X' && tablero[1][1] == 'X' && tablero[2][2] == 'X') //Diagonal '\'
      ||(tablero[0][2] == 'X' && tablero[1][1] == 'X' && tablero[2][0] == 'X') //Diagonal '/'
    ){
        //Codigo dentro del If
        cout<<"Ha ganado X"<<endl;
        return GANO_X;

    }else if(
        (tablero[0][0] == 'O' && tablero[0][1] == 'O' && tablero[0][2] == 'O') // horiz 0
      ||(tablero[1][0] == 'O' && tablero[1][1] == 'O' && tablero[1][2] == 'O') // horiz 1
      ||(tablero[2][0] == 'O' && tablero[2][1] == 'O' && tablero[2][2] == 'O') // horiz 2

      ||(tablero[0][0] == 'O' && tablero[1][0] == 'O' && tablero[2][0] == 'O') // vert 0
      ||(tablero[0][1] == 'O' && tablero[1][1] == 'O' && tablero[2][1] == 'O') // vert 1
      ||(tablero[0][2] == 'O' && tablero[1][2] == 'O' && tablero[2][2] == 'O') // vert 2

      ||(tablero[0][0] == 'O' && tablero[1][1] == 'O' && tablero[2][2] == 'O') //Diagonal '\'
      ||(tablero[0][2] == 'O' && tablero[1][1] == 'O' && tablero[2][0] == 'O') //Diagonal '/'
    ){
        //Codigo dentro del ElseIf
        cout<<"Ha ganado O"<<endl;
        return GANO_O;

    }else if(
        tablero[0][0] != '_' && tablero[0][1] != '_' && tablero[0][2] != '_' 
    &&  tablero[1][0] != '_' && tablero[1][1] != '_' && tablero[1][2] != '_' 
    &&  tablero[2][0] != '_' && tablero[2][1] != '_' && tablero[2][2] != '_' 
    ){
         //Codigo dentro del ElseIf
         cout<<"La partida ha terminado Empate"<<endl;
        return EMPATE;
    }
    return JUEGO_EN_CURSO;
}
