#include "Video.h"
#include <iostream>
#include <string>

using namespace std;

Video::Video(string nom, string gen, string id, string fecha_estreno, int duracion, float cal){
    nombre = nom;
    genero = gen;
    idVideo = id;
    duracionVideo = duracion;
    calificacion = cal*5/10;
    fecha_estreno_video = fecha_estreno;
}
float Video::obtenerCali(){
    return calificacion;
}

void Video::display(){
    cout << "Nombre: " << nombre <<endl;
    cout << "Generos: " << genero <<endl;
    cout << "Id: " << idVideo <<endl;
    cout << "Duracion: " << duracionVideo <<endl;
    cout << "Calificacion: " << calificacion <<"/5"<<endl;
    cout << "Fecha de estreno: " << fecha_estreno_video <<"\n"<<endl;
}

void Video::calificarVideo(float nueva){
    float anterior;
    anterior = calificacion;
    calificacion = (nueva + anterior)/2 ;
}

string Video::getNombre(){
    return nombre;
}

string Video::getidVideo(){
    return idVideo;
}

string Video::getGenero(){
    return genero;
}

string Video::getFecha_estreno_video(){
    return fecha_estreno_video;
}
int Video::getduracionVideo(){
    return duracionVideo;
}

float Video::getCalificacion(){
    return calificacion;
}

bool Video::operator>=(float cali){
    bool resultado;
    resultado = calificacion >= cali;
    return resultado;
}
