#ifndef NETFLIX_H_
#define NETFLIX_H_

#include <iostream>
#include <string>
#include <vector>
#include "Pelicula.h"
#include "Serie.h"
#include "Video.h"

class Netflix{
    private:
    vector<Serie> Series;
    vector<Pelicula> Peliculas;
    public:
    Netflix();
    void iniciar();
    void leerArchivo();
    void resumen();
    void imprimirGenero(string gen);
    void mostrar_apartir_cal(float cal);
    void mostrarEpisodios_Serie_Calificacion(string nom, float cal);
    void mostrarPelicula_Calificacion(float cal);
    void mostrarPeliculas();
    void mostrarSeries();
    void mostrarEpsSerie(string nombreSerie);
    void calificarVideoEsp(string nom, float cal);
    void ultiMensaje();
};


#endif