//https://www.youtube.com/watch?v=y8Y13enIuUM
#include<iostream>
#include <stdlib.h>
using namespace std;

class Persona{
    public: //Métodos
        Persona(string, int); //Constructor
        void mostrarPersona();
    private: //Atributos
        string nombre;
        int edad;
};

class Alumno : public Persona{
    public: //Métodos
        Alumno(string, int, string, float); //Constructor de la clase Alumno
        void mostrarAlumno();
    private: //Atributos
        string codigoAlumno;
        float notaFinal;
};

//Constructor de la clase Persona (Clase Padre)
Persona::Persona(string _nombre, int _edad){
    nombre = _nombre;
    edad = _edad;
}

//Constructor de la clase Álumno (Clase Hija)
Alumno::Alumno(string _nombre, int _edad, string _codigoAlumno, float _notaFinal) : Persona(_nombre, _edad) {
    codigoAlumno = _codigoAlumno;
    notaFinal = _notaFinal;
}

void Persona::mostrarPersona(){
    cout << "Nombre: " << nombre << endl;
    cout << "Edad: " << edad << endl;
}

void Alumno::mostrarAlumno(){
    mostrarPersona();
    cout << "Código de Alumno: " << codigoAlumno << endl;
    cout << "Nota Final: " << notaFinal << endl;
}

int main(){
    Alumno alumno1("Alejandro", 20, "1231213", 15.6);

    alumno1.mostrarAlumno();

    return 0;
}
