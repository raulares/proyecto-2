#include <iostream>

using namespace std;

class Empleado{
public:
    Empleado(string, string, string, float);
    ~Empleado() {} ;

    void asignarDui(string dui) { Dui = dui; }
    void asignarNombre(string nombre) { nombre = nombre; }
    void asignarApellidos(string apellidos) { Apellidos = apellidos; }
    void asignarSalario(float salario) { Salario = salario; }

    string obtenerDui() const { return Dui; }
    string obtenerNombre() const { return Nombre; }
    string obtenerApellidos() const { return Apellidos; }
    float obtenerSalario() const { return Salario; }

    virtual void datos() { cout << "Nombre: " << Nombre << endl;}

private:
    string Dui;
    string Nombre;
    string Apellidos;
    float Salario;
};

class Profesor : public Empleado{
public:
    Profesor(string, string, string, float, string);
    ~Profesor() {} ;

    void asignarEscalafon(string escalafon) { Escalafon = escalafon; }
    string obtenerEscalafon() { return Escalafon; }

    void datos();

private:
    string Escalafon;
};

class Administrativo : public Empleado{
public:
    Administrativo(string, string, string, float, string);
    ~Administrativo() {};

    void asignarPuesto(string puesto) { Puesto = puesto; }
    string obtenerPuesto() { return Puesto; }

    void datos();

private:
    string Puesto;
};

Empleado::Empleado(string dui, string nombre, string apellidos, float salario){
    Dui = dui;
    Nombre = nombre;
    Apellidos = apellidos;
    Salario = salario;
}

Profesor::Profesor(string dui, string nombre, string apellidos, float salario, string escalafon) : Empleado(dui, nombre, apellidos, salario) {
    Escalafon = escalafon;
}

void Profesor::datos(){
    Empleado::datos();
    cout << "Cargo: Profesor." << endl;
}

Administrativo::Administrativo(string dui, string nombre, string apellidos, float salario, string puesto) : Empleado(dui, nombre, apellidos, salario) {
    Puesto = puesto;
}

void Administrativo::datos(){
    Empleado::datos();
    cout << "Cargo: Administrativo." << endl;
}


int main(){

    Profesor Pablo("654", "Pablo", "Juarez", 215.5, "PUIII");
    Administrativo Ricardo("64554", "Ricardo", "Juarez", 125.5, "Vigilante");

    Pablo.datos();
    Ricardo.datos();
    return 0;
}
