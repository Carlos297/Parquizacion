#ifndef CARGARPRESUPUESTO_H_INCLUDED
#define CARGARPRESUPUESTO_H_INCLUDED

bool cargarPresupuesto (presupuestos *, int);            ///Carga un Presupuesto en el sistema

int buscarPresupuesto (presupuestos *, int, int);        ///Busca Presupuestos existentes para no cargar dos veces el mismo

void listarPresupuesto (presupuestos *, int);            ///Lista a todos los Presupuestos

void listarPresupuestoXcodigo (presupuestos *, int);     ///Lista Presupuestos mediante su codigo


void menuPresupuestos(presupuestos *vPresup, int *cPresup){
  int opc;
  while(true){
    textcolor(0,0);
        clrscr();
        recuadro(6, 0, 37, 18, cVERDE_CLARO, cMAGENTA);
        recuadro(8, 1, 33, 16, cVERDE_CLARO, cGRIS);
        textcolor(cBLANCO, cGRIS);
        gotoxy(10,3);
    cout << "MENU PRESUPUESTOS" << endl;
        gotoxy(10,4);
    cout << "-----------------------" << endl;
        gotoxy(10,5);
    cout << "1) CARGAR PRESUPUESTO" << endl;
        gotoxy(10,6);
    cout << "2) LISTAR TODOS LOS PRESUPUESTOS" << endl;
        gotoxy(10, 7);
    cout << "3) LISTAR PRESUPUESTO POR CODIGO" << endl;
        gotoxy(10, 8);
    cout << "-----------------------" << endl;
        gotoxy(10,9);
    cout << "0) VOLVER AL MENU PRINCIPAL" << endl << endl;
        gotoxy(10,10);
    cout << endl;
        gotoxy(10,11);
    cout << "OPCION: ";
    cin >> opc;
    cout << endl << endl << endl << endl << endl << endl << endl << endl;


    switch(opc){
      case 1:
        if(cargarPresupuesto(vPresup, *cPresup)){
          *cPresup = *cPresup + 1;
          cout << endl << "SE CARGO LA VENTA CON EXITO" << endl;
          system("pause");
        }
      break;
      case 2:
        if(*cPresup > 0){
          listarPresupuesto(vPresup, *cPresup);
        }
        else{
          cout << endl << "NO SE CARGARON PRESUPUESTOS";
          pausa();
        }
        break;
      case 3:
        if(*cPresup > 0){
          listarPresupuestoXcodigo(vPresup, *cPresup);
        }
        else{
          cout << endl << "NO SE CARGARON PRESUPUESTOS";
          pausa();
        }
        break;
      case 0:
        return;
        }


  }
}


bool cargarPresupuesto(presupuestos *vPresup, int cant){
  int dnicli, codPresup, pos;
  //int dia, mes, anio;
  clrscr();
  cout << "DNI DEL CLIENTE: ";
  cin >> dnicli;
  pos=buscarArboles(vArb, codArbol, cant);
  if(pos >= 0){
    cout << endl <<"YA EXISTE EL ARBOL INGRESADO";
    pausa();
    return false;
  }
  vArb[cant].codigo = codArbol;
  cout << endl <<"NOMBRE DEL ARBOL: ";
  cin.ignore();
  cin.getline(vArb[cant].nombre, 30);

  cout << endl << "PRECIO UNITARIO DEL ARBOL: $ ";
  cin >> vArb[cant].precio;

  cout << endl << "DISTANCIA DE PLANTADO(EN CENTIMETROS):  ";
  cin >> vArb[cant].distancia;

  return true;
}



#endif // CARGARPRESUPUESTO_H_INCLUDED
