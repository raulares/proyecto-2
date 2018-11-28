#include <iostream>

using namespace std;

enum CARGOS { EMPLEADO, PROFESOR, ADMINISTRATIVO };
enum ESCALAFONES { ESCALAFON, PUI, PUII, PUIII };
enum PUESTOS { PUESTO, ORDENANZA, VIGILANTE, JEFE };
const int NumEmpleados = 5;

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

Profesor::Profesor(string dui, string nombre, string apellidos, float salario, string escalafon)
    : Empleado(dui, nombre, apellidos, salario) {
    Escalafon = escalafon;
}

void Profesor::datos(){
    Empleado::datos();
    cout << "Cargo: Profesor." << endl;
}

Administrativo::Administrativo(string dui, string nombre, string apellidos, float salario,
        string puesto) : Empleado(dui, nombre, apellidos, salario) {
    Puesto = puesto;
}

void Administrativo::datos(){
    Empleado::datos();
    cout << "Cargo: Administrativo." << endl;
}


int main(){
    Empleado * elArreglo[NumEmpleados];
    Empleado * aptr;
    int opcion, i;
    string dui, nombre, apellido;
    float salario;
    int escalafon, puesto;

    for (i = 0; i < NumEmpleados; i++)
    {
        cout << "(1) Profesor Universitario (2) Administrativo" << endl;
        cin >> opcion;
        switch(opcion) {
            case PROFESOR:
                cout << "Ingrese el nombre del profesor" << endl;
                cin >> nombre;
                cout << "Ingrese el apellido del profesor" << endl;
                cin >> apellido;
                cout << "Ingrese el DUI del profesor" << endl;
                cin >> dui;
                cout << "Ingrese el salario del profesor" << endl;
                cin >> salario;
                cout << "Ingrese el escalafon del profesor (1) PUI (2) PUII (3) PUIII" << endl;
                cin >> escalafon;
                switch(escalafon){
                    case PUI:
                        aptr = new Profesor(dui, nombre, apellido, salario, "PUI");
                        break;
                    case PUII:
                        aptr = new Profesor(dui, nombre, apellido, salario, "PUII");
                        break;
                    case PUIII:
                        aptr = new Profesor(dui, nombre, apellido, salario, "PUIII");
                        break;
                }
                break;
            case ADMINISTRATIVO:
                cout << "Ingrese el nombre del funcionario administrativo" << endl;
                cin >> nombre;
                cout << "Ingrese el apellido del funcionario administrativo" << endl;
                cin >> apellido;
                cout << "Ingrese el DUI del funcionario administrativo" << endl;
                cin >> dui;
                cout << "Ingrese el salario del funcionario administrativo" << endl;
                cin >> salario;
                cout << "Ingrese el puesto del profesor (1) Ordenanza (2) Vigilante ";
                cout << "(3) Jefe de Centro de Computo" << endl;
                cin >> escalafon;
                switch(escalafon){
                    case ORDENANZA:
                        aptr = new Administrativo(dui, nombre, apellido, salario, "Ordenanza");
                        break;
                    case VIGILANTE:
                        aptr = new Administrativo(dui, nombre, apellido, salario, "Vigilante");
                        break;
                    case JEFE:
                        aptr = new Administrativo(dui, nombre, apellido, salario,
                            "Jefe de Centro de Computo");
                        break;
                }
                break;
        }
        elArreglo[i] = aptr;
    }

    for (i = 0; i < NumEmpleados; i++)
    {
        elArreglo[i]->datos();
    }

    return 0;
}
