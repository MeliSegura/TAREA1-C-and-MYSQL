#include <mysql.h>
#include <iostream>
using namespace std;
class ConexionBD
{
   private : MYSQL* conectar;
       public:
		   void abrir_conexion() {
			   conectar = mysql_init(0); //extraida de main.cpp.
			   conectar = mysql_real_connect(conectar, "localhost", "root", "2024", "db_empresa1", 3306, NULL, 0); //extraida de main.cpp
		   }
		   MYSQL* getConectar() { //este metodo fue creado para cerrar_conexion.
			   return conectar;
		   }
		   void cerrar_conexion() {
			   mysql_close(conectar);
		   }
};
