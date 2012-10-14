#include "c_busquedas.h"


C_busquedas::C_busquedas(void){

  cant_nodos = 0;

  b_adya();

 // show_adya();

  b_costos();

  //show_costos();

  b_heuristica();

  //show_heuristica();



};

C_busquedas::~C_busquedas(void){

  for ( unsigned int i = 0; i < cant_nodos; i++ ){

      delete m_adyacencia[i];

  }

  delete m_adyacencia;


  for ( unsigned int i = 0; i < cant_nodos; i++ ){

      delete m_costos[i];

  }

  delete m_costos;


  for ( unsigned int i = 0; i < cant_nodos; i++ ){

      delete m_heuristica[i];

  }

  delete m_heuristica;


  cant_nodos = 0;



};

void C_busquedas::b_adya(void){

  ifstream fe("./MatrizAdyacencia.txt");

  fe >> cant_nodos;

  m_adyacencia = new int*[cant_nodos];

  for ( unsigned int i = 0; i < cant_nodos; i++ ){

    m_adyacencia[i] = new int[cant_nodos];

    for ( unsigned int j = 0; j < cant_nodos; j++ ){

      m_adyacencia[i][j] = 0;

    }

  }

  for ( unsigned int i = 0; i < cant_nodos; i++ ){

    for ( unsigned int j = 0; j < cant_nodos; j++ ){

      fe >> m_adyacencia[i][j];

    }

  }

  fe.close();

};


void C_busquedas::b_costos(void){

  ifstream fe("./MatrizCostos.txt");

  fe >> cant_nodos;

  m_costos = new int*[cant_nodos];

  for ( unsigned int i = 0; i < cant_nodos; i++ ){

    m_costos[i] = new int[cant_nodos];

    for ( unsigned int j = 0; j < cant_nodos; j++ ){

      m_costos[i][j] = 0;

    }

  }

  for ( unsigned int i = 0; i < cant_nodos; i++ ){

    for ( unsigned int j = 0; j < cant_nodos; j++ ){

      fe >> m_costos[i][j];

    }

  }


  fe.close();

};


void C_busquedas::b_heuristica(void){

  ifstream fe("./MatrizEvaluacionHeuristica.txt");

  fe >> cant_nodos;

  m_heuristica = new int*[cant_nodos];

  for ( unsigned int i = 0; i < cant_nodos; i++ ){

    m_heuristica[i] = new int[cant_nodos];

    for ( unsigned int j = 0; j < cant_nodos; j++ ){

      m_heuristica[i][j] = 0;

    }

  }

  for ( unsigned int i = 0; i < cant_nodos; i++ ){

    for ( unsigned int j = 0; j < cant_nodos; j++ ){

      fe >> m_heuristica[i][j];

    }

  }


  fe.close();

};


void C_busquedas::parada(void){

  char aux;

  cin >> aux;


}

void C_busquedas::show_adya(void){


  for ( unsigned int i = 0; i < cant_nodos; i++ ){

    for ( unsigned int j = 0; j < cant_nodos; j++ ){

      cout << m_adyacencia[i][j] << " ";


    }

    cout << endl;



  }


  parada();


};


void C_busquedas::show_costos(void){


  for ( unsigned int i = 0; i < cant_nodos; i++ ){

    for ( unsigned int j = 0; j < cant_nodos; j++ ){

      cout << m_costos[i][j] << " ";


    }

    cout << endl;



  }


  parada();


};


void C_busquedas::show_heuristica(void){


  for ( unsigned int i = 0; i < cant_nodos; i++ ){

    for ( unsigned int j = 0; j < cant_nodos; j++ ){

      cout << m_heuristica[i][j] << " ";


    }

    cout << endl;



  }


  parada();


};


void C_busquedas::menu(void){

  int opc = -1;

  do{

  cout << "************" << endl;
  cout << "* 1. BFS" << endl;
  cout << "* 2. DFS" << endl;
  cout << "* 3. A* " << endl;
  cout << "* 0. Salir" << endl;
  cout << "************" << endl;

  cin >> opc;

  switch(opc){

    case 1:

      BFS();


    break;

    case 0:

    break;


    default:

      cout << "> Opcion introducida no valida" << endl;

  }


  } while (opc != 0);

};



void C_busquedas::BFS(void){

  int init = 0;
  int last = 0;
  int cant_cola = 0;
  int aux = 0;
  bool terminado = false;

  int i = 0;

  cout << "> Introduzca el nodo inicial: ";
  cin >> init;
  init--;
  cout << endl;
  cout << "> Introduzca el nodo final: ";
  cin >> last;
  cout << endl;
  last--;


  bool visitados[cant_nodos];
  int padre[cant_nodos];
  int cola[cant_nodos];


  for ( int i = 0; i < cant_nodos; i++ ){

    visitados[i] = false;
    padre[i] = -1;
    cola[i] = -1;

  }


  visitados[init] = true;
  cola[cant_cola] = init;
  cant_cola++;

  while ( (terminado != true) && (cant_cola != 0) ){

    i = 0;

    aux = cola[0];

    if ( aux == last ){

      terminado = true;


    } else {

      cola[0] = -1;
      cant_cola--;

      while ( cola[i+1] != -1 ){

         cola[i] = cola[i+1];
         i++;

      }

      cola[i] = -1;

      for ( int j = 0; j < cant_nodos; j++ ){

        if ( m_adyacencia[aux][j] != 0 ){

          if ( visitados[j] == false ){

            visitados[j] = true;
            padre[j] = aux;
            cola[cant_cola] = j;
            cant_cola++;


          }


        }

      }

    }

  }


  int j = last;
  int distancia = 0;

  cout << "> Camino minimo" << endl;
  cout << "-----------------" << endl;


  while ( j != init ){

    cout << j + 1 << "->";
    distancia += m_costos[j][padre[j]];

    j = padre[j];

  }

  cout << init + 1 << endl << endl;

  cout << "> Distancia total" << endl;
  cout << "------------------" << endl;
  cout << distancia << endl;
  cout << endl;


};
