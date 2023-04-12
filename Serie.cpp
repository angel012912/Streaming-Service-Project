#include "Serie.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;
Serie::Serie(string nom, string id){
    nombre = nom;
    idSerie = id;
}

float Serie::obtenerCalificacionProm(){
    float calificaciones = 0;
    int vector_tamaño = episodios.size();
    for(int i = 0; i< vector_tamaño; i++){
        calificaciones = calificaciones + episodios[i].obtenerCali();
    }
    float calFinal = calificaciones/episodios.size();
    return calFinal;
}

void Serie::agregarEpisodio(Episodio ep){
    episodios.push_back(ep);
}

string Serie::getNombre(){
    return nombre;
}

string Serie::getidSerie(){
    return idSerie;
}

vector<Episodio > Serie::getEpisodios(){
    return episodios;
}


void Serie::display(int i)
{
    cout<<"\n- - - Serie "<<i+1<<" - - -\n"<<endl;
    cout<<"Nombre de la Serie: "<<nombre<<endl;
    cout<<"Id Serie: "<<idSerie<<endl;
    cout<<"Capitulos: "<<episodios.size()<<endl;
    cout<<"Calificacion Promedio de la Serie: "<<Serie::obtenerCalificacionProm()<<"\n"<<endl;
}

void Serie::displayEpisodios(){
    cout<<"Los episodios de la serie "<<nombre<<" son: "<<endl;
    for (int i = 0; i < episodios.size(); i ++){
        episodios[i].display(i);
    }
}