#include <iostream>

using namespace std;

#include <fstream>


class C_busquedas{

  private:

    unsigned int cant_nodos;

    int** m_adyacencia;
    int** m_costos;
    int** m_heuristica;



  public:


    C_busquedas(void);
    ~C_busquedas(void);


  private:

    void b_adya(void);
    void b_costos(void);
    void b_heuristica(void);


   // METODOS TESTS

   void parada(void);

   void show_adya(void);
   void show_costos(void);
   void show_heuristica(void);



};

