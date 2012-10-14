#include "c_busquedas.h"


C_busquedas::C_busquedas(void){

  cout << "holaa" << endl;
  cant_nodos = 0;

  b_adya();

  show_adya();

  b_costos();

  show_costos();

  b_heuristica();

  show_heuristica();



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


