#ifndef VIDEO_H_
#define VIDEO_H_

#include <iostream>
#include <string>

using namespace std;

class Video
{
    private:
    string nombre, genero, idVideo, fecha_estreno_video;
    int duracionVideo;
    float calificacion;
    public:
    Video(string nom, string gen, string id, string fecha_estreno, int duracion, float cal);
    float obtenerCali();
    virtual void display();
    virtual void calificarVideo(float nueva);
    string getNombre();
    string getGenero();
    string getidVideo();
    string getFecha_estreno_video();
    int getduracionVideo();
    float getCalificacion();
    bool operator>= (float cali);
    
};
#endif