/*
Author: Jose Angel Garcia Gomez
Date: 02-2021
Description: Implementation of the Pelicula classs methods
*/

#include "Pelicula.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

Pelicula::Pelicula(string nom, string gen, string id, string fecha_estreno, int duracion, float cal):Video(nom, gen, id, fecha_estreno, duracion, cal){
}

void Pelicula::display(int i){
    cout<<"\n- - - - - Pelicula "<<i+1<<" - - - -\n"<<endl;
    Video::display();
}

void Pelicula::calificarVideo(float nueva){
    Video::calificarVideo(nueva);
    cout<<"\nLa nueva calificacion de la pelicula "<<Video::getNombre()<<" es: "<<Video::obtenerCali()<<"\n"<<endl;
}