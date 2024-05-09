//#include <mysql.h> //(esta incluido en ConexionBD.h)
#include <iostream>
#include "Cliente.h"
using namespace std;


int main()
{
    string nit, nombres, apellidos, direccion, fecha_nacimiento;
    int telefono;

    cout << "Ingrese Nit: ";
    getline(cin, nit);
    cout << "Ingrese Nombres: ";
    getline(cin, nombres);
    cout << "Ingrese Apellidos: ";
    getline(cin, apellidos);
    cout << "Ingrese Direccion: ";
    getline(cin, direccion);
    cout << "Ingrese Telefono: ";
    cin >> telefono;
    cin.ignore();
    cout << "Ingrese Fecha de Nacimiento: ";
    cin >> fecha_nacimiento;
    
    
    Cliente c = Cliente (nombres,apellidos,direccion,telefono,fecha_nacimiento,nit);
    c.crear();
    c.Leer();
    
    // MYSQL* conectar;(esta incluido en ConexionBD.h)
     //MYSQL_ROW fila; (esta incluido en Cliente.h)
     //MYSQL_RES* resultado; (esta incluido en Cliente.h)
     //conectar = mysql_init(0); (esta incluido en Conexion.h)
     //conectar = mysql_real_connect(conectar, "localhost", "root", "2024", "db_empresa1", 3306, NULL, 0);(esta incluido en Conexion.h)
     //if (conectar) {
         //cout << "Conexion Exitosa"<<endl;
         /*string puesto;
         cout << "Ingrese Puesto: ";
         cin >> puesto;
         string insert = "insert into puestos (puesto) values ('" + puesto + "')";
         const char* i = insert.c_str();
         q_estado = mysql_query(conectar, i);
         if (!q_estado) {
             cout << "Ingreso Exitoso" << endl;
         }
         else {
             cout << "xxxx Error al Ingresar xxxx" << endl;
         }*/

         /*string consulta = "select * from puestos";
         const char* c = consulta.c_str();
         q_estado = mysql_query(conectar, c);
         if (!q_estado) {
             resultado = mysql_store_result(conectar);
             while (fila = mysql_fetch_row(resultado)) {
                 cout << fila[0] << "," << fila[1] << endl;
             }
         } else {
             cout<<"xxxx Error al Consultar xxxx" << endl;
         } (Esta incluido en Cliente.h)*/

         //} else {
             //cout << "No fue posible conectar";} (Estructura de IF colocado en Cliente.h)

  
    system("pause");
    return 0;
};

