#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "Pelicula.h"
#include "Serie.h"
#include "Netflix.h"

using namespace std;

int main()
{
    Netflix n1;
    n1.leerArchivo();
    n1.iniciar();
}
