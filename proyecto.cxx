/*
 * Proyecto 2.
 *
 * Representar la jerarquía de clases usando herencia.
 * Clase Base: Empleado
 *      Variables miembros privada: DUI, Nombre, Apellido, Salario
 * Clase Derivada: Profesor Univeritario
 *      Variables miembros privada: Escalafón con valores PUI, PUII y PUII,
 * Clase Derivada: Administrativo
 *      Variables miembro privada: Puesto: Ordenanza, vigilante, Jefe de Centro de computo.
 * Crear métodos adecuados para recuperar y establecer las variables miembros privadas.
 * Crear un método virtual que indique el nombre de la persona y si es profesor o administrativo.
 * Crear un arreglo de punteros de objetos de tamaño 5 de la clase base y asignar en tiempo de
 * ejecución objetos profesor universitario o administrativo.
 *
 * Raúl Valentín Cortez Ares CA16007.
 * José Wilfredo Iraheta Martínez IM16003.
 * Esmeralda Guadalupe Morales Alfaro MA16009.
 */

#include <iostream>

using namespace std;

/*
 * Creamos tres enum para representar las opciones del switch que se usará para crear los objetos
 * en tiempo de ejecución.
 */
enum CARGOS { EMPLEADO, PROFESOR, ADMINISTRATIVO };
enum ESCALAFONES { ESCALAFON, PUI, PUII, PUIII };
enum PUESTOS { PUESTO, ORDENANZA, VIGILANTE, JEFE };
const int NumEmpleados = 5;

/*
 * Clase base del empleado. Esta clase crea un empleado, posee cuatro variables, número de Dui,
 * el cual es una cadena debido al guion que poseen, nombre, apellido y salario. Posee un método
 * que indica el nombre del empleado.
 */
class Empleado{
public:
    Empleado(string, string, string, float);
    ~Empleado() {} ;

    void asignarDui(string dui) { suDui = dui; }
    void asignarNombre(string nombre) { suNombre = nombre; }
    void asignarApellido(string apellido) { suApellido = apellido; }
    void asignarSalario(float salario) { suSalario = salario; }

    string obtenerDui() const { return suDui; }
    string obtenerNombre() const { return suNombre; }
    string obtenerApellido() const { return suApellido; }
    float obtenerSalario() const { return suSalario; }

    virtual void datos() { cout << "Nombre: " << suNombre << endl;}

private:
    string suDui;
    string suNombre;
    string suApellido;
    float suSalario;
};

/*
 * Clase derivada del profesor. Esta clase crea un profesor universitario, posee cinco variables,
 * las cuatro de la clase Base y el escalafón del profesor. Posee un método que indica el nombre
 * y el escalafón del profesor.
 */
class Profesor : public Empleado{
public:
    Profesor(string, string, string, float, string);
    ~Profesor() {} ;

    void asignarEscalafon(string escalafon) { suEscalafon = escalafon; }
    string obtenerEscalafon() { return suEscalafon; }

    void datos();

private:
    string suEscalafon;
};

/*
 * Clase derivada del Administrativo. Esta clase crea un empleado administrativo, posee cinco
 * variables, las cuatro de la clase Base y el puesto del empleado administrativo.
 * Posee un método que indica el nombre y el puesto del empleado administrativo.
 */
class Administrativo : public Empleado{
public:
    Administrativo(string, string, string, float, string);
    ~Administrativo() {};

    void asignarPuesto(string puesto) { suPuesto = puesto; }
    string obtenerPuesto() { return suPuesto; }

    void datos();

private:
    string suPuesto;
};

/*
 * Constructor de la clase Empleado. A este constructor se le pasan los parámetros, dui, nombre
 * y apellido, los cuales son cadenas, y el parámetro salario, el cual es un número flotante.
 */
Empleado::Empleado(string dui, string nombre, string apellido, float salario){
    suDui = dui;
    suNombre = nombre;
    suApellido = apellido;
    suSalario = salario;
}

/*
 * Constructor de la clase Profesor. A este constructor se le pasan los parámetros, dui, nombre
 * y apellido, los cuales son cadenas, el parámetro salario, el cual es un número flotante y la
 * cadena escalafon, la cual indica el escalafon del profesor.
 */
Profesor::Profesor(string dui, string nombre, string apellido, float salario, string escalafon)
    : Empleado(dui, nombre, apellido, salario) {
    suEscalafon = escalafon;
}

/*
 * Método datos de la clase Profesor. Este método invoca el método datos de la clase Empleado e
 * indica el cargo del profesor universitario.
 */
void Profesor::datos(){
    Empleado::datos();
    cout << "Cargo: Profesor." << endl;
}

/*
 * Constructor de la clase Administrativo. A este constructor se le pasan los parámetros, dui,
 * nombre y apellido, los cuales son cadenas, el parámetro salario, el cual es un número flotante
 * y la cadena puesto, la cuan indica el puesto del empleado administrativo.
 */
Administrativo::Administrativo(string dui, string nombre, string apellido, float salario,
        string puesto) : Empleado(dui, nombre, apellido, salario) {
    suPuesto = puesto;
}

/*
 * Método datos de la clase Administrativo. Este método invoca el método datos de la clase
 * Empleado e indica el puesto del empleado administrativo.
 */
void Administrativo::datos(){
    Empleado::datos();
    cout << "Cargo: Administrativo." << endl;
}


int main()
{
    //Creamos un arreglo de punteros de objetos Empleado de tamaño cinco.
    Empleado * elArreglo[NumEmpleados];
    Empleado * elEmpleado;
    int opcion, i;
    string dui, nombre, apellido;
    float salario;
    int escalafon, puesto;

    //Iniciamos la asignación en tiempo de ejecución de los objetos.
    for (i = 0; i < NumEmpleados; i++)
    {
        cout << "(1) Profesor Universitario (2) Administrativo" << endl;
        cin >> opcion;

        //Este switch nos indica si el objeto es un Profesor o un Administrativo.
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
                //Este switch se usa para ingresar el escalafón del profesor.
                switch(escalafon){
                    case PUI:
                        elEmpleado = new Profesor(dui, nombre, apellido, salario, "PUI");
                        break;
                    case PUII:
                        elEmpleado = new Profesor(dui, nombre, apellido, salario, "PUII");
                        break;
                    case PUIII:
                        elEmpleado = new Profesor(dui, nombre, apellido, salario, "PUIII");
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
                cin >> puesto;
                //Este switch se usa para ingresar el puesto del empleado administrativo.
                switch(puesto){
                    case ORDENANZA:
                        elEmpleado = new Administrativo(dui, nombre, apellido, salario,
                            "Ordenanza");
                        break;
                    case VIGILANTE:
                        elEmpleado = new Administrativo(dui, nombre, apellido, salario,
                            "Vigilante");
                        break;
                    case JEFE:
                        elEmpleado = new Administrativo(dui, nombre, apellido, salario,
                            "Jefe de Centro de Computo");
                        break;
                }
                break;
        }

        //Después de crearlos, los almacenamos en el arreglo de objetos creado anteriormente.
        elArreglo[i] = elEmpleado;
    }

    //Por último, usaremos el método datos en cada uno de los empleados del arreglo.
    for (i = 0; i < NumEmpleados; i++)
    {
        elArreglo[i]->datos();
    }

    return 0;
}
