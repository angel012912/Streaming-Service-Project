/*
Author: Jose Angel Garcia Gomez
Date: 02-2023
Description: Application execution
*/

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
