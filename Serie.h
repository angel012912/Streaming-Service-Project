/*
Author: Jose Angel Garcia Gomez
Date: 02-2021
Description: Definition of the Serie classs
*/

#ifndef SERIE_H_
#define SERIE_H_

#include "Episodio.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Serie 
{
    private:
    string nombre, idSerie;
    vector<Episodio> episodios;
    public:
    Serie(string nom, string id);
    float obtenerCalificacionProm();
    void agregarEpisodio(Episodio ep);
    string getNombre();
    string getidSerie();
    vector<Episodio> getEpisodios();
    void display(int i);
    void displayEpisodios();
};
#endif