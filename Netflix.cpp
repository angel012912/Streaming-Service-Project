#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <windows.h>
#include "Netflix.h"


using namespace std;

Netflix::Netflix(){};

void Netflix::iniciar(){
    int op;
    cout << "\n----- Bienvenido a su servicio de Streaming -----\n" << endl;
    cout << "\n1 - Mostrar resumen de la lectura de la base de datos. "<<endl;
    cout << "\n2 - Mostrar los videos en general de un cierto género."<<endl;
    cout << "\n3 - Mostrar los videos en general a partir de una cierta calificacion."<<endl;
    cout << "\n4 - Mostrar los episodios de una determinada serie con una calificación determinada."<<endl;
    cout << "\n5 - Mostrar las peliculas a partir de cierta calificacion."<<endl;
    cout << "\n6 - Calificar un video en específico.\n"<<endl;
    cout << "\n7 - Terminar \n"<<endl;
    cout <<"\n- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - \n"<<endl;
    cout << "\nPor favor ingrese el número de la opción que desee desplegar: ";
    cin >> op;

    if (op == 1)
    {
        try
        {
            Netflix::resumen();
            try {
                Netflix::ultiMensaje();
            }
            catch(string &mensaje){
                cout<<mensaje<<endl;
            }
        }
        catch(string &mensaje){
            cout<<mensaje<<endl;
            try {
                Netflix::ultiMensaje();
            }
            catch(string &mensaje){
                cout<<mensaje<<endl;
            }
        }
    }
    else if(op == 2){
        cout <<"\n- - - - - - - - - - - - - - Mostrar videos por genero - - - - - - - - - - - - - - - - - - \n"<<endl;
        cout<<"Ingresa el género (En ingles y con la primer letra en mayúscula) que quieres desplegar: ";
        string gene;
        cin >> gene;
        try
        {
           Netflix::imprimirGenero(gene);
           try {
                Netflix::ultiMensaje();
            }
            catch(string &mensaje){
                cout<<mensaje<<endl;
            }
        }
        catch(string &mensaje)
        {
            cout << mensaje << endl;
            try {
                Netflix::ultiMensaje();
            }
            catch(string &mensaje){
                cout<<mensaje<<endl;
            }
        }
    }
    else if(op == 3){
        cout <<"\n- - - - - - - - - - - - - - Mostrar videos apartir de una calificacion - - - - - - - - - - - - - - - - - - \n"<<endl;
        cout<<"Ingrese la calificacion(en un rango de 1 a 5): ";
        float cali;
        cin >>cali;
        try{
            Netflix::mostrar_apartir_cal(cali);
            try {
                Netflix::ultiMensaje();
            }
            catch(string &mensaje){
                cout<<mensaje<<endl;
            }
        }
        catch(string &mensaje){
            cout << mensaje <<endl;
            try {
                Netflix::ultiMensaje();
            }
            catch(string &mensaje){
                cout<<mensaje<<endl;
            }
        }
    }
    else if(op == 4){
        cout <<"\n- - - - Mostrar los episodios de una determinada serie con una calificación determinada - - - - \n"<<endl;
        cout<<"Ingrese el nombre de la serie a desplegar: ";
        string nomb;
        cin.ignore();
        getline(cin,nomb);
        cout<<"\nIngrese la calificacion que quiere desplegar(en un rango de 1 a 5): ";
        float cali;
        cin >> cali;
        try{
            Netflix::mostrarEpisodios_Serie_Calificacion(nomb, cali);
            try {
                Netflix::ultiMensaje();
            }
            catch(string &mensaje){
                cout<<mensaje<<endl;
            }
        }
        catch(string &mensaje){
            cout<<mensaje<<endl;
            try {
                Netflix::ultiMensaje();
            }
            catch(string &mensaje){
                cout<<mensaje<<endl;
            }
        }
    }
    else if(op == 5){
        cout <<"\n- - - - Mostrar las peliculas a partir de cierta calificacion - - - - \n"<<endl;        
        cout << "Ingrese la calificacion a desplegar(en un rango de 1 a 5): ";
        float cali;
        cin >> cali;
        try{
            Netflix::mostrarPelicula_Calificacion(cali);
            try {
                Netflix::ultiMensaje();
            }
            catch(string &mensaje){
                cout<<mensaje<<endl;
            }
        }
        catch(string &mensaje){
            cout<<mensaje<<endl;
            try {
                Netflix::ultiMensaje();
            }
            catch(string &mensaje){
                cout<<mensaje<<endl;
            }
        }
    }
    else if(op == 6){
        cout <<"\n- - - - Calificar un video en específico - - - - \n"<<endl;
        cout <<"\nIngresa el nombre del video que quiere calificar: ";
        string nombre;
        cin.ignore();
        getline(cin, nombre);
        float cal;
        cout<<"\nIngresa la calificacion que le quiere asignar (en una escala de 1 a 5): ";   
        cin>>cal;
        cout <<"\n- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - \n"<<endl;
        try
        {
            Netflix::calificarVideoEsp(nombre, cal);
            try {
                Netflix::ultiMensaje();
            }
            catch(string &mensaje){
                cout<<mensaje<<endl;
            }
        }
        catch(string &mensaje)
        {
            cout <<mensaje<<endl;
            try {
                Netflix::ultiMensaje();
            }
            catch(string &mensaje){
                cout<<mensaje<<endl;
            }
        }
        
    }
    else if(op == 7){
            cout<<"\nGracias por preferir nuestro servicio de Streaming...";
            cout <<"\n- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - \n"<<endl;
    }
    else{
        cout<<"\n- - - - - Error: opcion invalida, voy a terminar el programa. - - - -\n"<<endl;
    }
}

void Netflix::leerArchivo(){
    ifstream archivo;
    archivo.open("BasePeliculas4.csv");
    string linea;
    getline(archivo, linea);
    string id, nombre, duracion, genero, calificacion, fecha_estreno, nombreEp, idEp, temporada, linea_numEp, comilla_numEp, numEp;
    while(archivo.peek()!=EOF){
        getline(archivo, id, ';');
        getline(archivo, nombre, ';');
        getline(archivo, duracion, ';');
        getline(archivo, genero, ';');
        getline(archivo, calificacion, ';');
        getline(archivo, fecha_estreno, ';');
        getline(archivo, nombreEp, ';');
        getline(archivo, idEp, ';');
        getline(archivo, temporada, ';');
        getline(archivo, linea_numEp, '\n');
        stringstream stream(linea_numEp);
        getline(stream, comilla_numEp, ',');n
        stringstream abc(comilla_numEp);
        getline(abc, numEp, '"');
        int duracion_i = stoi(duracion);
        float calificacion_i = stof(calificacion);

        if (numEp=="" || numEp==" ")
        {
            Pelicula p1(nombre, genero, id, fecha_estreno, duracion_i, calificacion_i);
            Peliculas.push_back(p1);
        }
        else
        {
            int temp_i = stoi(temporada);
            Episodio ep1(nombreEp,idEp, temp_i, nombre, genero, id, fecha_estreno, duracion_i, calificacion_i);
            if (Series.size()>0)
            {
                bool encontrar = false;
                for(int i = 0; i < Series.size();i++){
                    if (Series[i].getNombre() == nombre)
                    {
                        encontrar = true;
                        Series[i].agregarEpisodio(ep1);
                    }
                }
                if (encontrar==false){
                    Serie s1 (nombre, id);
                    s1.agregarEpisodio(ep1);
                    Series.push_back(s1);
                } 
            }
            else
            {
                Serie s1(nombre, id);
                s1.agregarEpisodio(ep1);
                Series.push_back(s1);
            }
        }
    }
    archivo.close();
}

void Netflix::resumen(){
    int contEp, contTot;
    for (int i = 0; i < Series.size();i++){
        contEp = contEp + Series[i].getEpisodios().size();
    }
    contTot = contEp + Peliculas.size();
    cout << "\n - - - - - - - - - - - - - - -  Resumen  - - - - - - - - - - - - -  \n"<<endl;
    cout << "Se leeyeron "<<contTot<<" videos de los cuales: "<<Peliculas.size()<<" son peliculas y ";
    cout<<contEp<<" son episodios que forman parte de "<<Series.size()<<" series." <<endl;
    cout << "\n- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - \n"<<endl;
    cout<<"\n1 - Mostrar las peliculas disponibles.\n"<<endl;
    cout<<"\n2 - Mostrar las series disponibles.\n"<<endl;
    cout<<"\n- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - \n"<<endl;
    int opres;
    cout<<"\nIngresa la opcion que quiere desplegar: ";cin>>opres;
    cout<<"\n- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - \n"<<endl;
    if (opres != 1 && opres != 2){
        string mensaje ="- - - - Error: opcion no válida - - - -";
        throw(mensaje);
    }
    else{
        if (opres == 1){
            Netflix::mostrarPeliculas();
        }
        else if(opres==2){
            Netflix::mostrarSeries();
            int opEp;
            cout << "\n1 - Mostrar los episodios de una serie en específico.\n"<<endl;
            cout << "\n2 - Regresar al menu principal \n"<<endl;
            cout<<"\n- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - \n"<<endl;
            cout << "Ingresar la opcion deseada: ";
            cin >> opEp;
            cout<<"\n- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - \n"<<endl;
            if (opEp != 1 && opEp != 2){
                string mensaje="- - - - Error: opcion no válida - - - -";
                throw(mensaje);
            }
            else if (opEp == 1)
            {
                cout <<"\nIngrese el nombre de la serie: ";
                string nombreSerie;
                cin.ignore();
                getline(cin, nombreSerie);
                cout<<"\n- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - \n"<<endl;
                try{
                    Netflix::mostrarEpsSerie(nombreSerie);
                    cout<<"\n- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - \n"<<endl;
                }
                catch(string &mensaje){
                    cout << mensaje <<endl;
                }
            }
            else if(opEp == 2)
            {
                Netflix::iniciar();
            } 
        }
    }
}

void Netflix::imprimirGenero(string gene)
{
    string genero_alt;
    genero_alt = " "+gene; 
    string generos;
    cout <<"\n- - - - - - - - -  Genero "<<gene<<" - - - - - - - - -  \n"<<endl;
    bool evaluarP = false;
    bool evaluarS = false;
    for (int i = 0; i < Peliculas.size();i++){
        generos = Peliculas[i].getGenero();
        stringstream stream(generos);
        vector<string> lista_generos; 
        string primerGenero;
        while (stream.peek() != EOF){
            getline(stream, primerGenero, ',');
            lista_generos.push_back(primerGenero);
        }
        if (find(lista_generos.begin(), lista_generos.end(), gene) != lista_generos.end()){
            evaluarP = true;
            Peliculas[i].display(i);
        }
        
        else if(find(lista_generos.begin(), lista_generos.end(), genero_alt) != lista_generos.end())
        {
            evaluarP = true;
            Peliculas[i].display(i);
        }
    }
    for (int i = 0; i < Series.size();i++){
        for(int a = 0; a < Series[i].getEpisodios().size();a++){
            generos = Series[i].getEpisodios()[a].getGenero();
            stringstream stream(generos);
            vector<string> lista_generos; 
            string primerGenero;
            while (stream.peek() != EOF){
                getline(stream, primerGenero, ',');
                lista_generos.push_back(primerGenero);
            }
            if (find(lista_generos.begin(), lista_generos.end(), gene) != lista_generos.end()){
                evaluarS = true;
                Series[i].getEpisodios()[a].display(a);
            }
            
            else if(find(lista_generos.begin(), lista_generos.end(), genero_alt) != lista_generos.end())
            {
                evaluarS = true;
                Series[i].getEpisodios()[a].display(a);
            }
        }
    }
    if (evaluarP == false && evaluarS == false){
        string mensaje = "\n- - - - - - Error: Genero no válido- - - - -\n";
        throw(mensaje);
    }
}

void Netflix::mostrar_apartir_cal(float cal){
    if (cal < 0 || cal > 5){
        string mensajeC = "\n- - - - - - Error: Tu calificacion ingresada no es válida - - - - -\n";
        throw(mensajeC);
    }
    else{
        cout <<"\n- - - - - - - - -  Calificacion mayor o igual "<<cal<<" - - - - - - - - -  \n"<<endl;
        bool evaluarP = false;
        bool evaluarS = false;
        for (int i = 0;i<Peliculas.size();i++){
            if (Peliculas[i] >= cal){
                evaluarP = true;
                Peliculas[i].display(i);
            }
        }
        for (int i = 0;i<Series.size();i++){
            for(int a = 0; a<Series[i].getEpisodios().size();i++){
                if (Series[i].getEpisodios()[a] >= cal){
                    evaluarS = true;
                    Series[i].getEpisodios()[a].display(i);
                }
            }
        }
        if (evaluarP == false && evaluarS == false){
            string mensaje = "\n- - - - - - Error: No se encontraron videos con calificacion mayor o igual a la que ingresaste - - - - -\n";
            throw(mensaje);
        }
    }
}

void Netflix::mostrarEpisodios_Serie_Calificacion(string nom, float cal){
    if (cal < 0 || cal > 5){
        string mensaje ="\n- - - - Error: Calificacion no valida - - - - \n";
        throw(mensaje);
    }
    else{
        cout<< "\n - - - Estos son los episodios de la serie "<<nom<<" con calificacion mayor o igual "<<cal<<" - - -\n"<<endl;
        bool siEstaSerie = false;
        bool siEstaEp = false;
        for (int i = 0;i<Series.size();i++){
            if (Series[i].getNombre() == nom){
                siEstaSerie = true;
                for(int a = 0;a<Series[i].getEpisodios().size();a++){
                    if(Series[i].getEpisodios()[a] >= cal){
                        siEstaEp = true;
                        Series[i].getEpisodios()[a].display(a);
                    }
                }
            }
        }    
        if (siEstaSerie == false){
            string mensaje = "\n- - - - Error: No se encuentra la serie que a usted le interesa en nuestra base de datos - - - - \n";
            throw(mensaje);
        }
        else if(siEstaEp == false){
            string mensaje = "\n- - - - Error: No se encuentran episodios que cumplan con la calificacion ingresada - - - - \n";
            throw(mensaje);
        }
    }
}

void Netflix::mostrarPelicula_Calificacion(float cal){
    if(cal < 0 || cal > 5){
        string mensaje = "\n- - - - Error: No hay peliculas que cumplan con ese requisito en nuestra base de datos - - - -\n";
        throw(mensaje);
    }
    else{
        cout<< "\n - - - Estos son las peliculas con calificacion mayor o igual a "<<cal<<" - - - \n"<<endl;
        bool siEsta = false;
        for (int i = 0;i<Peliculas.size();i++){
            if (Peliculas[i] >= cal){
                siEsta = true;
                Peliculas[i].display(i);
            }
        }
        if (siEsta == false){
            string mensaje ="\n- - - - Error: No hay peliculas que cumplan con ese requisito en nuestra base de datos - - - -\n";
            throw(mensaje);
        }
    }
}

void Netflix::mostrarPeliculas()
{
    for(int i=0;i < Peliculas.size();i++)
    {
        Peliculas[i].display(i);
    }
}

void Netflix::mostrarSeries()
    {
        for(int i=0;i < Series.size();i++)
        {
            Series[i].display(i);
        }
    }

void Netflix::mostrarEpsSerie(string nombreSerie){
    bool evalua = false;
    for (int i = 0; i < Series.size();i++ ){
        if(Series[i].getNombre()==nombreSerie){
            evalua = true;
            Series[i].displayEpisodios();
        }
    }
    if (evalua == false){
        string mensaje = "\n- - - - - - Error: Serie no válida- - - - -\n";
        throw(mensaje);
    }
}

void Netflix::calificarVideoEsp(string nom, float cal){
    if (cal < 0  || cal > 5){
        string mensaje = "\n- - - - Error: Calificacion ingresada invalida - - - -\n";
        throw(mensaje);
    }
    else{
        bool estaP = false;
        bool estaS = false;
        for(int a = 0; a < Peliculas.size(); a ++){
            if(Peliculas[a].getNombre()==nom){
                estaP = true;
                Peliculas[a].calificarVideo(cal);
            }
        }
        for(int b = 0; b < Series.size(); b ++){
            vector<Episodio> eps = Series[b].getEpisodios();
            for (int c = 0; c < eps.size(); c ++){
                if (eps[c].getTitulo()==nom){
                    estaS = true;
                    eps[c].calificarVideo(cal);
                    cout<<"\nLa nueva calificacion promedio de la serie "<<Series[b].getNombre()<<" es: "<< Series[b].obtenerCalificacionProm()<<"\n"<<endl;
                }
            }
        }
        if (estaP == false && estaS == false){
            string mensaje = "\n- - - - Error: No se encuentra el video que desea calificar - - - - \n";
            throw(mensaje);
        }
    }
}

void Netflix::ultiMensaje(){
        int opcion=0;
        cout <<"\n- - - - - - - Elija una opcion - - - - - - \n"<<endl;
        cout <<"\n1 - Volver a mostrar el menu."<<endl;
        cout <<"\n2 - Salir. "<<endl;
        cout <<"\n- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - \n"<<endl;
        cin >> opcion;
        if (opcion != 1 && opcion != 2){
            string mensaje="- - - - Error: Opcion no valida, voy a terminar el programa. - - - -";
            throw(mensaje);
        }
        else if(opcion == 1){
            Netflix::iniciar();
        }
        else if(opcion == 2){
            cout<<"\nGracias por preferir nuestro servicio de Streaming\n"<<endl;
            cout <<"\n- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - \n"<<endl;
        }
}
