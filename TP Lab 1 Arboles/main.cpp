#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <iomanip>

using namespace std;

struct arboles{
int codigo;
char nombre[30];
float precio;
int distancia;
};

struct presupuestos{
int codigo;
int dni;
int vLados[4];
int vArboles[4];
};

const int CANT_ARBOLES=10;
const int CANT_PRESUPUESTOS=10;

#include "funciones.h"
#include "cargararbol.h"
#include "cargarpresupuesto.h"
#include "informes.h"

int main(){

    arboles vArb [CANT_ARBOLES];
    presupuestos vPresup [CANT_PRESUPUESTOS];

    int opc;
    int cArboles, cPresupuestos, vCantPresup[CANT_PRESUPUESTOS];

    cArboles=cPresupuestos=0;



    while(true){
     clrscr();
     textcolor(0,0);
        clrscr();
        recuadro(6, 0, 37, 18, cVERDE_CLARO, cMAGENTA);
        recuadro(8, 1, 33, 16, cAMARILLO, cGRIS);
        textcolor(cAMARILLO, cGRIS);
        gotoxy(10,3);
    cout << "MENU PRINCIPAL" << endl;
        gotoxy(10,4);
    cout << "-----------------------" << endl;
    gotoxy(10,5);
    cout << "1) ARBOLES" << endl;
    gotoxy(10,6);
    cout << "2) PRESUPUESTOS" << endl;
    gotoxy(10,7);
    cout << "3) INFORMES" << endl;
    gotoxy(10,8);
    cout << "-----------------------" << endl;
    gotoxy(10,9);
    cout << "0) SALIR DEL PROGRAMA" << endl << endl;
    gotoxy(10,10);
    cout << endl;
    gotoxy(10,12);
    cout << "OPCION: ";

    cin >> opc;
cout << endl << endl << endl << endl << endl;

 switch(opc){
      case 1:
        menuArboles(vArb, &cArboles);
      break;
      case 2:
        menuPresupuestos(vPresup, &cPresupuestos);
      break;
      case 3:
        //menuInformes(vArb, &cArboles, vPresup, &cPresupuestos);
      break;
      case 0:
        return 0;
      break;
    }






}

return 0;
}

