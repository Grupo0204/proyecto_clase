#ifndef CLASES_H
#define CLASES_H
#include <iostream>
#include <fstream>
using namespace std;
class Personas{
private:
    int clave;
protected:
    string correo;
public:
    string nombres;
    int codigo;
    string telefono;
    Personas(){};
    Personas(string nombres, int cod)
    : codigo(cod),nombres(nombres){};
    Personas(int clave, string correo, string nombres,int cod,string telf)
    : clave(clave), correo(correo), nombres(nombres),codigo(cod), telefono(telf){};
    virtual float descuento(float) = 0;
    virtual void imprimir() const =0;
};

class ClienteIndividual : public Personas{
public:
    char categoria;
    string direccion;
    string ruc;
    ClienteIndividual(){};
    ClienteIndividual(int cod, string nombres, string ruc,string telf,string correo,int clave,char categoria,string direccion)
    : Personas(clave,correo,nombres,cod,telf),ruc(ruc),categoria(categoria),direccion(direccion){};
    
    float descuento(float totalparcial){
        return totalparcial*0.97-totalparcial;
        /*descuento del 3%*/}
    void imprimir() const {
    ofstream archivo("clientes.txt", ios::app);
    if (archivo.is_open()) {
        archivo << endl<<"----Registro de Clientes Individuales----" << endl
                << "Codigo: " << codigo << endl
                << "RUC: " << ruc << endl
                << "Nombres: " << nombres << endl
                << "Telefono: " << telefono << endl
                << "Correo: " << correo << endl
                << "Categoria: " << categoria << endl
                << "Direccion: " << direccion << endl;
        archivo.close();
    } else {
        cout << "No se pudo abrir el archivo de clientes" << endl;
    }
}

};

class ClienteCorporativo : public Personas{
public:
    char categoria;
    string direccion;
    string ruc;
    ClienteCorporativo(){};
    ClienteCorporativo(int cod,string nombres,string ruc, string telf,string correo,int clave,char categoria,string direccion) 
    : Personas(clave,correo,nombres,cod,telf),ruc(ruc),categoria(categoria),direccion(direccion){};

    float descuento(float totalparcial){
        return totalparcial*0.89-totalparcial;
        /*descuentdel 10%+1%*/ }
    void imprimir() const {
    ofstream archivo("clientes.txt", ios::app);
    if (archivo.is_open()) {
        archivo <<endl<< "----Registro de clientes Corporativos----" << endl
                << "Codigo: " << codigo << endl
                << "RUC: " << ruc << endl
                << "Nombres: " << nombres << endl
                << "Telefono: " << telefono << endl
                << "Correo: " << correo << endl
                << "Categoria: " << categoria << endl
                << "Direccion: " << direccion << endl;
        archivo.close();
    } else {
        cout << "No se pudo abrir el archivo de clientes" << endl;
    }
}

    
};


class Vendedores : public Personas{
private:
    double salario;
public: 
    Vendedores(string nombres,int cod, double salario)
    : Personas(nombres,cod),salario(salario){};
    virtual float descuento(float){};
    virtual void imprimir() const {};
    void agregar(){
        ofstream archivo("vendedores.txt", ios::app);
            if (archivo.is_open()) {
                archivo << "----Registro de Vendedor----" << endl
                    << "Nombre: " << nombres << endl
                    << "Código: " << codigo << endl
                    << "Salario: " << salario << endl;
                archivo.close();
                cout << "Vendedor registrado correctamente." << endl;
                } else {cout << "No se pudo abrir el archivo de vendedores." << endl;}
    }
};

class Productos{
private:
    int codigo;
    string descripcion;
    float precio;
    string nombres;
    string stock;
    int capacidad;
public:
    Productos(int cod,string descripcion,float precio,string nombres,string stock, int capacidad)
    :codigo(cod),descripcion(descripcion),precio(precio),nombres(nombres),stock(stock),capacidad(capacidad){};
    friend  ostream& operator<<(ostream &on, Productos& pd);
};
ostream& operator<<(ostream &on, Productos& pd){
    on <<"--------Producto------------"<<endl<<
     "Codigo: "<<pd.codigo<<endl<<
    "Nombre del producto: "<<pd.nombres<<endl<<
    "Descripcion: "<<pd.descripcion<<endl<<
    "Precio: "<<pd.precio<<endl<<
    "Capacidad: "<<pd.capacidad<<endl;
    return on; 
};
#endif