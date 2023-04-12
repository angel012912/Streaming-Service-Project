#ifndef PELICULA_H_
#define PELICULA_H_

#include "Video.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Pelicula: public Video 
{
    public:
    Pelicula(string nom, string gen, string id, string fecha_estreno, int duracion, float cal);
    void display(int i);
    void calificarVideo(float nueva);
};
#endif