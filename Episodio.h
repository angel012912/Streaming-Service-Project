#ifndef EPISODIO_H_
#define EPISODIO_H_

#include "Video.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Episodio: public Video
{
    private:
    string tituloEpisodio, idEpisodio;
    int temporada;
    public:
    Episodio(string tit,string idE, int temp, string nom, string gen, string id, string fecha_estreno, int duracion, float cal);
    vector<string> obtenerGeneros();
    string getTitulo();
    string getidSerie();
    int getTemporada();
    void display(int i);
    void calificarVideo(float nueva);
};
#endif