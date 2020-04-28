#ifndef CARGARARBOL_H_INCLUDED
#define CARGARARBOL_H_INCLUDED

bool cargarArbol (arboles *, int);            ///Carga arboles en el sistema

int buscarArboles (arboles *, int, int);        ///Busca arboles existentes para no cargar dos veces el mismo

void listarArboles (arboles *, int);            ///Lista a todos los arboles

void listarArbolesXcodigo (arboles *, int);     ///Lista arboles mediante su codigo


void menuArboles(arboles *vArb, int *cArboles){
  int opc;
  while(true){
    textcolor(0,0);
        clrscr();
        recuadro(6, 0, 37, 18, cVERDE_CLARO, cMAGENTA);
        recuadro(8, 1, 33, 16, cVERDE_CLARO, cGRIS);
        textcolor(cBLANCO, cGRIS);
        gotoxy(10,3);
    cout << "MENU ARBOLES" << endl;
        gotoxy(10,4);
    cout << "-----------------------" << endl;
        gotoxy(10,5);
    cout << "1) CARGAR ARBOL" << endl;
        gotoxy(10,6);
    cout << "2) LISTAR TODOS LOS ARBOLES" << endl;
        gotoxy(10, 7);
    cout << "3) LISTAR ARBOL POR CODIGO" << endl;
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
        if(cargarArbol(vArb, *cArboles)){
          *cArboles = *cArboles + 1;
          cout << endl << "ARBOL CARGADO CON EXITO" << endl;
          system("pause");
        }
        else{
          cout << endl << "NO SE PUDO CARGAR EL ARBOL" << endl;
          cout << endl;
          pausa();
        }
      break;
      case 2:
      if(*cArboles > 0){
        listarArboles(vArb, *cArboles);
        }
        else{
        cout << "NO SE CARGARON ARBOLES"<<endl;
        system("pause");
      }
      break;
      case 3:
        if(*cArboles > 0){
        listarArbolesXcodigo(vArb, *cArboles);
        break;
        }
        else{
        cout << "NO SE CARGARON ARBOLES"<<endl;
        system("pause");
        }
      case 0:
      return;
        }

    }
}


bool cargarArbol(arboles *vArb, int cant){
  int codArbol, pos;
  //int dia, mes, anio;
  clrscr();
  cout << "CODIGO DE ARBOL: ";
  cin >> codArbol;
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

int buscarArboles(arboles *vArb, int codArbol, int cant){
  int i;
  for(i=0; i<cant; i++){
    if(vArb[i].codigo == codArbol){
      return i;
    }
  }
  return -1;
}

void listarArboles (arboles *vArb, int cant){
    int i;
    clrscr();
    for(i=0; i<cant; i++){
        cout << "NOMBRE DEL ARBOL: " << vArb[i].nombre<<endl;
        cout << "CODIGO: " << vArb[i].codigo<<endl;
        cout << "PRECIO UNITARIO: $" << vArb[i].precio<<endl;
        cout << "DISTANCIA DE PLANTADO: " << vArb[i].distancia<<endl;
     cout << "---------------------------" << endl;
}
system("pause");
}

void listarArbolesXcodigo(arboles *vArb, int cant){
int i, codArbolAbus, pos = -1;
clrscr();
cout <<"--------------------------------" << endl;
cout << "CODIGO DE ARBOL A BUSCAR: ";
cin >> codArbolAbus;
cout << endl <<"--------------------------------" << endl;
    for(i=0; i<cant; i++){
    if(vArb[i].codigo == codArbolAbus){
      pos = i;
        }
    }
    if(pos == -1){
        cout << "NO SE ENCONTRARON ARBOLES PARA ESE CODIGO" << endl;
        system("pause");
    }
    else{
        cout << "NOMBRE DEL ARBOL: " << vArb[pos].nombre<<endl;
        cout << "CODIGO: " << vArb[pos].codigo<<endl;
        cout << "PRECIO UNITARIO: " << vArb[pos].precio<<endl;
        cout << "DISTANCIA DE PLANTADO: " << vArb[pos].distancia<<endl;
     cout << "---------------------------" << endl;
        system("pause");
        }
}



#endif // CARGARARBOL_H_INCLUDED
