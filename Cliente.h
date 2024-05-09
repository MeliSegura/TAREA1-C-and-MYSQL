#include <mysql.h>
#include <iostream>
#include <string>
#include "ConexionBD.h"
#include "Persona.h"

using namespace std;
class Cliente : Persona {
	//atributos
private: string nit;
	   //contructor
public: Cliente() {
}

	  Cliente(string nom, string ape, string dir, int tel, string fn, string n) : Persona(nom, ape, dir, tel, fn) {
		  nit = n;
	  }

	  //metodos
	  //set (modificar)
	  void setNit(string n) { nit = n; }
	  void setNnombres(string nom) { nombres = nom; }
	  void setApellidos(string ape) { apellidos = ape; }
	  void setDireccion(string dir) { direccion = dir; }
	  void setTelefono(int tel) { telefono = tel; }
	  void setFecha_Nacimiento(string fn) { fecha_nacimiento = fn; }

	  //get (mostrar)
	  string getNit() { return nit; }
	  string getNombres() { return nombres; }
	  string getApellidos() { return apellidos; }
	  string getDireccion() { return direccion; }
	  int getTelefono() { return telefono; }
	  string getFecha_Nacimiento() { return fecha_nacimiento; }

	  //metodo
	  void crear() {
		  int q_estado;
		  ConexionBD cn = ConexionBD();
		  cn.abrir_conexion();
		  if (cn.getConectar()) {
			  string t = to_string(telefono);
			  string insert = "INSERT INTO clientes(nit,nombres,apellidos,direccion,telefono,fecha_nacimiento)VALUES()('" + nit + "','" + nombres + "','" + apellidos + "','" + direccion + "'," + t + ",'" + fecha_nacimiento + "');";
			  const char* i = insert.c_str();
			  q_estado = mysql_query(cn.getConectar(), i);
			  if (!q_estado) {
				  cout << "Ingreso Exitoso" << endl;
			  }
			  else {
				  cout << "xxxx Error al Ingresar xxxx" << endl;
			  }

		  }
		  else {
			  cout << "Error en la conexion" << endl;
		  }
		  cn.cerrar_conexion();
	  }

	  
	  
	  
	  // metodo (Leer)
	  void Leer() {
		  int q_estado;
		  ConexionBD cn = ConexionBD();
		  MYSQL_ROW fila;
		  MYSQL_RES* resultado;
		  cn.abrir_conexion();
		  if (cn.getConectar()) {
			  string consulta = "select * from Clientes"; //Codigos de lineas 44 a 56 extraidos de main.cpp. con modificaciones a las referencias.
			  const char* c = consulta.c_str();
			  q_estado = mysql_query(cn.getConectar(), c);
			  if (!q_estado) {
				  resultado = mysql_store_result(cn.getConectar());
				  cout << "---------------------------------Clientes-------------------------------" << endl;
				  while (fila = mysql_fetch_row(resultado)) {
					  cout << fila[0] << "," << fila[1] << "," << fila[2] << "," << fila[3] << "," << fila[4] << "," << fila[5] << "," << fila[6] << "," << fila[7] << endl;
				  }
			  }
			  else {
				  cout << "xxxx Error al Consultar xxxx" << endl;
			  }
		  }
		  else {
			  cout << "Error en la conexion" << endl;
		  }
		  cn.cerrar_conexion();
	  }
};
