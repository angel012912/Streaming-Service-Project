/*
Author: Jose Angel Garcia Gomez
Date: 02-2021
Description: Implementation of the Episodio class methods
*/

#include "Episodio.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

Episodio::Episodio(string tit, string idE, int temp, string nom, string gen, string id, string fecha_estreno, int duracion, float cal):Video(nom, gen, id, fecha_estreno, duracion, cal){
    tituloEpisodio = tit;
    idEpisodio = idE;
    temporada = temp;
}

vector <string> Episodio::obtenerGeneros(){
    stringstream stream(getGenero());
    vector<string> generos; 
    string primerGenero;
    while (stream.peek() != EOF){
        getline(stream, primerGenero, ',');
        generos.push_back(primerGenero);
    }
    return generos;
}

string Episodio::getTitulo(){
    return tituloEpisodio;
}

string Episodio::getidSerie(){
    return idEpisodio;
}

int Episodio::getTemporada(){
    return temporada;
}

void Episodio::display(int i){
    cout << "\n- - - - Episodio "<< i +1 <<" - - - -\n" <<endl;
    cout << "Nombre del Episodio: " << tituloEpisodio <<endl;
    cout << "Id Episodio: "<< idEpisodio <<endl;
    cout << "Temporada:  "<<temporada<<endl;
    Video::display();
}

void Episodio::calificarVideo(float nueva){
    Video::calificarVideo(nueva);
    cout<<"\nEl episodio: "<<tituloEpisodio<<" de la serie "<<Video::getNombre() <<" cambio de calificacion a: "<<Video::obtenerCali()<<"\n"<<endl;
}