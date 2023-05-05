/*
 * Autor: Kevin Yavari Yoshioka y Juan Calvo
 * Fecha de creación: 05 / de mayo / 2023
 * Fecha última modificación: 05 / de mayo / 2023
 * Versión: 1.0
 * 
 * Archivo encabezado libreria TAD Colas De Prioridad
 * Representación Estructuras colas de prioridad
 */

#ifndef __COLASDEPRIORIDAD_H
#define __COLASDEPRIORIDAD_H
#include <iostream>
#include <vector>
typedef int Elemento;

using namespace std;

class ColaPrioridad{
   vector<Elemento> vec;

   public:
      ColaPrioridad(); 
      Elemento front();
      void deque();
      void enqueue(Elemento);
      bool empty();
};


#endif