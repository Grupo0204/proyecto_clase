#include <iostream>
#include<string>
#include <sstream>
#include "Clases.h"
#include <fstream>
using namespace std;


void buscarCliente(int codigo) {
    ifstream archivo("clientes.txt");
    if (archivo.is_open()) {
        string linea;
        bool encontrado = false;
        while (getline(archivo, linea)) {
            if (linea.find("Codigo: ") != string::npos) {
                int codigoCliente = stoi(linea.substr(linea.find("Codigo: ") + 8));
                if (codigo == codigoCliente) {
                    cout << "----Registro de clientes----" << endl;
                    cout << linea << endl;
                    for (int i = 0; i < 6; i++) {
                        getline(archivo, linea);
                        cout << linea << endl;
                    }
                    encontrado = true;
                    break;
                }
            }
        }
        archivo.close();

        if (!encontrado) {
            cout << "No se encontro ningun cliente con el codigo ingresado" << endl;
        }
    } else {
        cout << "No se pudo abrir el archivo de clientes" << endl;
    }
}


void menu(int opc){
    Vendedores* ve[10];
    Productos* pr[5];
    Personas* persona= nullptr;

    string nombres, correo, direccion, ruc="0",telf="0",tipo,descripcion;
    int codigoBusqueda,codigo,clave,capacidad,contproductos=0;
    static int contClientes=0,contVendedores=1,contProductos=0;
    double salario;
    float precio;
    string stock;
    char categoria='D';
    switch (opc){
        case 1:
            cout << "Ingrese su codigo: ";
            cin >> codigo;
            while (ruc.length()!=11){
                cout << "Ingrese el RUC: ";
                cin >>ruc;
                if (ruc.length()==11){cout << "el RUC esta correcto"<<endl;break;}
                else{cout << "El RUC no posee 11 digitos"<<endl;}
            }
            cout <<"Ingrese su nombre y apellido: ";
            cin.ignore();
            getline(cin,nombres);
            while (telf.length()!=9){
                cout << "Ingrese el telefono: ";
                cin >>telf;
                if (telf.length()==9){cout << "el telefono esta correcto"<<endl;break;}
                else{cout << "El numero ingresado no posee 9 digitos"<<endl;}
            }
            cout << "Ingrese el correo electronico: ";
            cin >> correo;
            while(categoria=='D'){
                cout << "Ingrese la categoria del cliente: ";
                cin >> categoria;
                if(categoria == 'A'||categoria == 'B' || categoria == 'C'||categoria =='D'){
                    cout<<"Categoria registrada"<<endl;break;}
                else{cout << "La categoria ingresada no es valida vuenva a ingresar"<<endl;}
            }
            cout << "Ingrese su direccion:" ;
            cin.ignore();
            getline(cin,direccion);
            cout << "Ingrese su clave: ";
            cin>> clave;
            persona = new ClienteCorporativo(001,"Pedro Sanchez", "20227167754","194258828","pedroS.20@gmail.com",1234,'A',"Urb. San Martín De Socabaya");
            persona->imprimir();
            contClientes++;
            persona = new ClienteCorporativo(002,"Katherine Lopez", "63585477248","904701759","katalec894@extemer.com",5678,'B',"Av Los Fresnos"); 
            persona->imprimir();
            contClientes++;
            persona = new ClienteIndividual(003,"Miriam Duran", "00205555617","446372843","midiki3267@extemer.com",9101,'C',"Jr. Antonio Raymondi"); 
            persona->imprimir();
            contClientes++;
            if (contClientes < 6) {
                if (categoria == 'A' || categoria == 'B') {
                    persona = new ClienteCorporativo(codigo, nombres, ruc, telf, correo, clave, categoria, direccion);
                    persona->imprimir();
                     
                }    
                else if (categoria == 'C' || categoria == 'D'){
                    persona = new ClienteIndividual(codigo, ruc, nombres, telf, correo, clave, categoria, direccion);
                    persona->imprimir();
                }
                contClientes++;
            }else{cout << "Agenda llena"<<endl;}

            system("pause");
            system("cls");
            break;
            case 2:
                cout << "Ingrese el codigo del cliente a buscar: ";
                cin >> codigoBusqueda;
                buscarCliente(codigoBusqueda);
            system("pause");
            system("cls");
            break;
            case 3:
                if(contVendedores==1){
                    Vendedores ve("juan perez",111,350);
                    contVendedores++;ve.agregar();
                }
                else if(contVendedores==2){
                    Vendedores ve("Angela Lopez",112,350);
                    contVendedores++;ve.agregar();
                }
                else if(contVendedores==3){
                    Vendedores ve("Anthony Alegre",113,350);
                    contVendedores++;ve.agregar();
                    }
                else if(contVendedores==4){
                    Vendedores ve("Pedro Lopez",114,350);
                    contVendedores++;ve.agregar();
                }
                else if(contVendedores==5){
                    Vendedores ve("Luana Duran",115,350);
                    contVendedores++;ve.agregar();
                }
                else if(contVendedores==6){
                    Vendedores ve("Anthonella Alegre",116,350);
                    contVendedores++;ve.agregar();
                }
                else if(contVendedores==7){
                    Vendedores ve("Noelia Galindo",117,350);
                    contVendedores++;ve.agregar();
                }
                if(contVendedores<=7){
                    if (contVendedores <10)
                {
                    cout <<"Ingrese el nombre del vendedor:";
                    cin.ignore();
                    getline(cin,nombres);
                    cout << "Ingrese codigo del vendedor: ";
                    cin >> codigo;
                    cout << "Ingrese el salario: ";
                    cin >> salario;
                    Vendedores ve(nombres,codigo,salario);
                    ve.agregar();
                    contVendedores++;
                }else{cout <<"lleno"<<endl;}
                }      

            system("pause");
            system("cls");
            break;
            case 4:{
                cout << "Ingrese el codigo del producto: ";
                cin >> codigo;
                cout << "Ingrese el nombre del producto: ";
                cin >> nombres;
                cout << "Ingrese su descripcion: ";
                cin.ignore();
                getline(cin,descripcion);
                cout << "Ingrese el precio: ";
                cin >> precio;
                cout << "Desea revisar el stock?(si/no): ";
                cin >> stock;
                cout<< "Ingrese la capacidad: ";
                cin >> capacidad;
                Productos pd(codigo,descripcion,precio,nombres,stock,capacidad);
                ofstream archivo("productos.txt",ios::app);
                if(archivo.is_open())
                {
                    if(contproductos<5)
                    {
                        archivo<< pd <<endl;
                        contproductos++;
                        archivo.close();
                    }
                } 
                else{cout << "No se pudo abrir el archivo"<<endl;}
                } 
            system("pause");
            system("cls");
            break;
            case 5:
            cout << "Ingrese el codigo del cliente: ";
            cin >>codigo;
            system("pause");
            system("cls");
            break;
            case 6:{
            ifstream archivo("clientes.txt");
            if (archivo.is_open()){
                string linea;
                while(getline(archivo,linea)){
                    cout<<linea<<endl;
                }
                archivo.close();
            }
            }
            system("pause");
            system("cls");
            break;
            case 7:
            {
            ifstream archivo("vendedores.txt");
            if (archivo.is_open()){
                string linea;
                while(getline(archivo,linea)){
                    cout<<linea<<endl;
                }
                archivo.close();
            }
            }
            system("pause");
            system("cls");
            break;
            case 8:
            system("pause");
            system("cls");
            break;
            default:
               cout << "Error: Opcion invalida."<<endl;
            system("pause");
            system("cls");
            break;
        };



}

int main() {
    // utilzar try catch 
    int opc;
    do {
        cout << "------SISTEMA COMERCIAL------" << endl<<
        "1. Nuevos Clientes " << endl<<// completo
        "2. Buscar Clientes " << endl<<//comppleto
        "3. Nuevo Vendedor " << endl<<// implementar codigo, ingresar 10 vendedores
        "4. Nuevo producto " << endl<<// revisar documento
        "5. Ventas " << endl<< // falta implementar
        "6. Lista de Clientes " << endl<<
        "7. Lista de Vendedores " <<endl<<
        "8. Salir " << endl<<"Ingrese la opcion a realizar: ";
        cin >> opc;
        menu(opc);
    } while (opc != 8);
}