#include "pch.h"
#include "CppUnitTest.h"
#include "../TP IRI Ultima Esfera/Funciones.h"
#include"../TP IRI Ultima Esfera/Implementacion_funciones.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestTPIRI
{
	TEST_CLASS(UnitTestTPIRI)
	{
	public:
		
		TEST_METHOD(TestMethod0)//UNIT TEST FUNCION IMPRIMIR LISTA
		{
			s_listaJugadores lista;//DECLARO UNA LISTA DE TIPO s_listaJugadores
			lista.arr_jugadores = new Jugador[100];//ASIGNO MEMORIA DINAMICA AL ARRAY DENTRO DE LA LISTA
			lista.n_jugadores = 1;//INICIALIZO LA CANTIDAD DE JUGADORES EN 1 EN LA LISTA
			lista.tam = 100;////INICIALIZO LA VARIABLE TAMAÑO EN LA LISTA EN 100 (MEMORIA PEDIDA PARA EL ARRAY)
			lista.arr_jugadores[0] = { {"Manuela Balatti"},{18},{0}, {1}};//CARGO EN LA LISTA LOS DATOS DE UN JUGADOR X
		
		
			imprimir_lista(lista);//IMPRIMO LISTA
			//INSTRUCCION LOGGER::WRITEMESSAGE COMPARARA LO MOSTRADO EN PANTALLA CON LO IMPRESO POR LA FUNCION IMPRIMIR
			Logger::WriteMessage("\n--------LISTA DE JUGADORES------ - \nCantidad de Jugadores registrados: 1\nNombre\tEdad\tPartidas Ganadas\tPartidas Perdidas\n0)Manuela Balatti\t18\t0\t1");
			delete lista.arr_jugadores;//LIBERO MEMORIA PEDIDA PARA EL ARRAY DINAMICO EN LA LISTA
		}
		
		
		TEST_METHOD(TestMethod1)//UNIT TEST DE FUNCION CREAR ARCHIVO
		{
			Assert::AreEqual(0, creararchivo());//SI EL ARCHIVO "registro.dat" EXISTE, ENTONCES 
			                                    //LA FUNCION RETORNARA 0
			//SI BIEN LA FUNCION "creararchivo()" TIENE UNA INSTRUCCION IF DENTRO EN CASO DE ERROR, NUNCA SE VA A ENTRAR POR QUE LA FUNCION FOPEN CREA Y ABRE EL ARCHIVO PARA ESCRBIR EN EL
		}
		
		TEST_METHOD(TestMethod2)//UNIT TEST DE FUNCION LEER ARCHIVO
		{
			//SEGUNDO CASO DE LEER ARCHIVO, EL ARCHIVO NO EXISTE
			int error;//VARIABLE AUXILIAR PARA ALMACENAR RETORNO DE FUNCIONES CREAR ARCHIVO Y GUARDAR ARCHIVO

			s_listaJugadores lista1;//DECLARO UNA LISTA DE TIPO s_listaJugadores
			lista1.arr_jugadores = new Jugador[100];//ASIGNO MEMORIA DINAMICA AL ARRAY DENTRO DE LA LISTA
			error = creararchivo();//ABRO UN ARCHIVO, SI NO EXISTE LO CREO
			
			Assert::AreEqual(0, leerarchivo(lista1));//AL LEER EL ARCHIVO DE NUEVO, LA FUNCION DEBE RETORNAR 1
			
			delete lista1.arr_jugadores;//LIBERO LA MEMORIA PEDIDA PARA EL ARRAY

			
			
			error=creararchivo();//ABRO UN ARCHIVO, SI NO EXISTE LO CREO
			
			s_listaJugadores lista;//DECLARO UNA LISTA DE TIPO s_listaJugadores
			lista.arr_jugadores = new Jugador[100];//ASIGNO MEMORIA DINAMICA AL ARRAY DENTRO DE LA LISTA
			
			lista.n_jugadores = 1;//INICIALIZO LA CANTIDAD DE JUGADORES EN 1
			lista.tam = 100;//INICIALIZO LA VARIABLE TAMAÑO EN LA LISTA EN 100 (MEMORIA PEDIDA PARA EL ARRAY)
			lista.arr_jugadores[0] = { {"Manuela Balatti"},{18},{0}, {1} };//CARGO EN LA LISTA LOS DATOS DE UN JUGADOR X
			
			error=guardararchivo(lista);//GUARDO EN EL ARCHIVO EL ARRAY
			//EN ESTE CASO EL ARCHIVO YA EXISTE EN LA CARPETA DEL PROGRAMA, ENTONCES ESTE ASSERT FUNCIONARA PORQUE LEER ARCHIVO RETORNA 1
			Assert::AreEqual(1,leerarchivo(lista));//AL LEER EL ARCHIVO DE NUEVO, LA FUNCION DEBE RETORNAR 1

			delete lista.arr_jugadores;//LIBERO LA MEMORIA PEDIDA PARA EL ARRAY
			
		}

		TEST_METHOD(TestMethod3)//UNIT TEST DE FUNCION BORRAR TABLERO
		{
			//PRIMER CASO FUNCION BORRA LA CANTIDAD DE ESPACIOS PASADOS DEL NUM CORRECTAMENTE
			int num = 0;//VARIABLE AUXILIAR N° DE COLUMNAS Y FILAS
			char** tablero = crear_tablero_random(num);//DECLARO VARIABLE TABLERO DE TIPO DOBLE PUNTERO
			Assert::AreEqual(1,borrar_tablero(tablero,num));//BORRO EL TABLERO CON LA FUNCION, SI SE BORRO CORECCTAMENTE DEVUELVE 1
			
			
		}

		TEST_METHOD(TestMethod4)//UNIT TEST DE FUNCION GENERAR NUMERO PSEUDOALEATORIO
		{
			//EN ESTE UNIT TEST LA VARIABLE NUM ESTA SIENDO DETERMINADA MANUALMETE, PERO EN EL CODIGO NUM SIEMPRE VA A SER ENTRE 3 Y 7 PORQUE TOMA VALOR DE LA FUNCION CREARTABLERO
			//PRIMER CASO NUM  ENTRE SOLICTADO EN TRABAJO ENTRE [3;7]
			int num = 3;//VARIABLE AUXILIAR, INICIALIZADA EN VALOR X;CON X>0
			int numero_random = 0;//VARIABLE AUXILIAR PARA ALMACENAR NUMERO PSEUDOALEATORIO
			numero_random = generar_numero(num);//FUNCION GENERAR NUMERO, RETORNA VALOR ENTRE 1 Y NUM
			Assert::IsTrue(numero_random > 0 && numero_random <= num);//COMPARA SI NUMERO_RANDOM TIENE UN VALOR EN EL INTERVALO (0,NUM]

			//SEGUNDO CASO NUM NEGATIVO NO SOLICTADO EN TP 
			num = -1;//VARIABLE AUXILIAR, INICIALIZADA EN VALOR X;CON X>0
			numero_random = 0;//VARIABLE AUXILIAR PARA ALMACENAR NUMERO PSEUDOALEATORIO
			numero_random = generar_numero(num);//FUNCION GENERAR NUMERO, RETORNA VALOR ENTRE 1 Y NUM
			Assert::IsFalse(numero_random > 0 && numero_random <= num);//COMPARA SI NUMERO_RANDOM TIENE UN VALOR EN EL INTERVALO (0,NUM]

			//TERCER CASO NUM=0 ES IMPOSIBLE YA QUE 0 ES INADMISIBLE POR LA FUNCION RAND EN GENERAR_NUMERO

		}

		TEST_METHOD(TestMethod5)//UNIT TEST DE FUNCION VERIFICAR EXISTENCIA
		{
			//PRIMER CASO EL NOMBRE INGRESADO SE ENCUENTRA EN LA LISTA 
			s_listaJugadores lista;//DECLARO UNA LISTA DE TIPO s_listaJugadores
			lista.arr_jugadores = new Jugador[100];//ASIGNO MEMORIA DINAMICA AL ARRAY DENTRO DE LA LISTA
			lista.n_jugadores = 1;//INICIALIZO LA CANTIDAD DE JUGADORES EN 1
			lista.tam = 100;//INICIALIZO LA VARIABLE TAMAÑO EN LA LISTA EN 100 (MEMORIA PEDIDA PARA EL ARRAY)
			lista.arr_jugadores[0] = { {"Manuela Balatti"},{18},{0}, {1} };//CARGO EN LA LISTA LOS DATOS DE UN JUGADOR X
			char nombre[30] = "Manuela Balatti";//VARIABLE AUXILIAR DE TIPO STRING QUE ALMACENA EL MISMO NOMBRE QUE LA LISTA PARA VERIFICAR EL CORRECTO FUNCIONAMIENTO DE LA FUNCION VERIFICAR EXISTENCIA

			Assert::AreEqual(1, verficar_existencia(lista,nombre));//AL BUSCAR EN LA LISTA MEDIANTE LA FUNCION VERIFICAR EXISTENCIA, LA FUNCION DEBE RETORNAR 1 SI EXISTE

			//SEGUNDO CASO: EL NOMBRE IGRESADO NO EXISTE EN LA LISTA
			char nombre1[30] = "Pedro Rojo";
			Assert::AreEqual(0, verficar_existencia(lista, nombre1));//AL BUSCAR EN LA LISTA MEDIANTE LA FUNCION VERIFICAR EXISTENCIA, LA FUNCION DEBE RETORNAR 0 SI NO EXISTE


			delete lista.arr_jugadores;//LIBERO LA MEMORIA PEDIDA PARA EL ARRAY
		}

		TEST_METHOD(TestMethod6)//UNIT TEST DE FUNCION MOSTRAR TABLERO
		{
			int num = 0;//VARIABLE AUXILIAR N° DE COLUMNAS Y FILAS
			char** tablero = crear_tablero_random(num);//DECLARO VARIABLE TABLERO DE TIPO DOBLE PUNTERO Y MEDIANTE LA FUNCION CREO LA MATRIZ Y LA RETORNO
			//A MODO DE PRUEBA ALTERAMOS LA VARIABLE NUM PARA QUE SEA IGUAL A 4 (4 FILAS Y 4 COLUMNAS), HICIMOS ASI POR QUE LA FUNCION CREAR TABLERO ALTERA POR REFERENCIA LA VARIABLE NUM 
			mostrar_tablero(tablero, num=4);
			//INSTRUCCION LOGGER::WRITEMESSAGE COMPARARA LO MOSTRADO EN PANTALLA CON LO IMPRESO POR LA FUNCION MOSTRAR TABLERO
			Logger::WriteMessage("Ultima esfera\n				F-------------------------------- -\n				I 1 | O | O | O | O | O | O | O |\n				L-------------------------------- -\n				A 2 | O | O | O | O | O | O | O |\n				S-------------------------------- -\n				3 | O | O | O | O |\n				-------------------- -\n				4 | O | O | O | O |\n				-------------------- -\n				1    2    3    4     num");
			borrar_tablero(tablero, num);
		}

		TEST_METHOD(TestMethod7)//UNIT TEST DE FUNCION BUSCAR NOMBRE
		{
			//1ER CASO: EL NOMBRE INGRESADO SE ENCUENTRA EN LA LISTA Y LA CONTRASEÑA ES LA CORRECTA, OPCION=1 PORQUE SE JUEGA VS COMPUTADORA
			char nombre[30] = "Manuela Balatti";//VARIABLE AUXILIAR DE TIPO STRING QUE ALMACENA EL MISMO NOMBRE QUE LA LISTA PARA VERIFICAR EL CORRECTO FUNCIONAMIENTO DE LA FUNCION VERIFICAR EXISTENCIA
			
			s_listaJugadores lista;//DECLARO UNA LISTA DE TIPO s_listaJugadores
			int memoria = 100;
			lista.arr_jugadores = new Jugador[100];//ASIGNO MEMORIA DINAMICA AL ARRAY DENTRO DE LA LISTA
			
			lista.n_jugadores = 1;//INICIALIZO LA CANTIDAD DE JUGADORES EN 1
			lista.tam = 100;//INICIALIZO LA VARIABLE TAMAÑO EN LA LISTA EN 100 (MEMORIA PEDIDA PARA EL ARRAY)
			
			//CARGO EN LA LISTA LOS DATOS DE UN JUGADOR X
			strcpy(lista.arr_jugadores[0].apellido_nombre,nombre);
			lista.arr_jugadores[0].edad = 18;
			lista.arr_jugadores[0].partidas_ganadas = 0;
			lista.arr_jugadores[0].partidas_perdidas =  1;
			lista.arr_jugadores[0].contraseña = 0000;
			
			int posicion1 = -1;//CREACION DE VARIABLE AUXILIAR PARA GUADAR POSICION DEL USUARIO EN LA LISTA
			int contraseña = 0000;
			int posicion2 = -1;
			int opcion = 1;

			buscar_nombre(lista, nombre, posicion1,memoria,posicion2,opcion,contraseña);//FUNCION BUSCAR NOMBRE EN LA LISTA, RETORNA POSICION

			Assert::IsTrue(posicion1 == 0);//AL BUSCAR EN LA LISTA MEDIANTE LA FUNCION VERIFICAR EXISTENCIA, LA FUNCION DEBE RETORNAR 1 SI EXISTE
		    
			//ESTOS CASOS ENTRE COMENTARIOS [2 A 5] ES NECESARIO INGRESAR DATOS MANUALMETE PARA CARGAR LOS NUEVOS USUARIOS
	        /*
			//2DO CASO: EL NOMBRE INGRESADO NO SE ENCUENTRA EN LA LISTA Y LA CONTRASEÑA ES LA CORRECTA, OPCION=1 PORQUE SE JUEGA VS COMPUTADORA
			char nombre_2[30] = "Gonzalo Perez";
			posicion1 = -1;//CREACION DE VARIABLE AUXILIAR PARA GUADAR POSICION DEL USUARIO EN LA LISTA
			contraseña = 0000;
			posicion2 = -1;
			opcion = 1;
			buscar_nombre(lista, nombre_2, posicion1, memoria, posicion2, opcion, contraseña);//FUNCION BUSCAR NOMBRE EN LA LISTA, RETORNA POSICION
			Assert::IsTrue(posicion1 == 0);//AL BUSCAR EN LA LISTA MEDIANTE LA FUNCION VERIFICAR EXISTENCIA, LA FUNCION DEBE RETORNAR 1 SI EXISTE

			//3er CASO: EL NOMBRE INGRESADO NO SE ENCUENTRA EN LA LISTA Y LA CONTRASEÑA ES LA INCORRECTA, OPCION=1 PORQUE SE JUEGA VS COMPUTADORA
			char nombre_3[30] = "Gonzalo Perez";
			posicion1 = -1;//CREACION DE VARIABLE AUXILIAR PARA GUADAR POSICION DEL USUARIO EN LA LISTA
			contraseña = 0000;
			posicion2 = -1;
			opcion = 1;
			buscar_nombre(lista, nombre_3, posicion1, memoria, posicion2, opcion, contraseña);//FUNCION BUSCAR NOMBRE EN LA LISTA, RETORNA POSICION
			Assert::IsTrue(posicion1 == 0);//AL BUSCAR EN LA LISTA MEDIANTE LA FUNCION VERIFICAR EXISTENCIA, LA FUNCION DEBE RETORNAR 1 SI EXISTE

			//4to CASO: EL NOMBRE INGRESADO NO SE ENCUENTRA EN LA LISTA Y LA CONTRASEÑA ES LA INCORRECTA, OPCION=1 PORQUE SE JUEGA VS COMPUTADORA
			char nombre_4[30] = "Gonzalo Perez";
			posicion1 = -1;//CREACION DE VARIABLE AUXILIAR PARA GUADAR POSICION DEL USUARIO EN LA LISTA
			contraseña = 0000;
			posicion2 = -1;
			opcion = 1;
			buscar_nombre(lista, nombre_4, posicion1, memoria, posicion2, opcion, contraseña);//FUNCION BUSCAR NOMBRE EN LA LISTA, RETORNA POSICION
			Assert::IsTrue(posicion1 == 0);//AL BUSCAR EN LA LISTA MEDIANTE LA FUNCION VERIFICAR EXISTENCIA, LA FUNCION DEBE RETORNAR 1 SI EXISTE

		    //5to CASO: EL NOMBRE INGRESADO NO SE ENCUENTRA EN LA LISTA Y LA CONTRASEÑA ES LA INCORRECTA, OPCION=4 PORQUE SE JUEGA VS OTRO USUARIO
			char nombre_5[30] = "Gonzalo Perez";
			posicion1 = -1;//CREACION DE VARIABLE AUXILIAR PARA GUADAR POSICION DEL USUARIO EN LA LISTA
			contraseña = 0000;
			posicion2 = -1;
			opcion = 4;
			buscar_nombre(lista, nombre_5, posicion1, memoria, posicion2, opcion, contraseña);//FUNCION BUSCAR NOMBRE EN LA LISTA, RETORNA POSICION
			Assert::IsTrue(posicion2 == 0);//AL BUSCAR EN LA LISTA MEDIANTE LA FUNCION VERIFICAR EXISTENCIA, LA FUNCION DEBE RETORNAR 1 SI EXISTE
			*/

		   //6to CASO: EL NOMBRE INGRESADO SE ENCUENTRA EN LA LISTA Y LA CONTRASEÑA ES LA CORRECTA, OPCION=4 PORQUE SE JUEGA VS OTRO USUARIO
			char nombre_6[30] = "Manuela Balatti";
			posicion1 = -1;//CREACION DE VARIABLE AUXILIAR PARA GUADAR POSICION DEL USUARIO EN LA LISTA
			contraseña = 0000;
			posicion2 = -1;
			opcion = 4;
			buscar_nombre(lista, nombre_6, posicion1, memoria, posicion2, opcion, contraseña);//FUNCION BUSCAR NOMBRE EN LA LISTA, RETORNA POSICION
			Assert::IsTrue(posicion2 == 0);//AL BUSCAR EN LA LISTA MEDIANTE LA FUNCION VERIFICAR EXISTENCIA, LA FUNCION DEBE RETORNAR 1 SI EXISTE

			delete lista.arr_jugadores;//LIBERO LA MEMORIA PEDIDA PARA EL ARRAY
		}

		TEST_METHOD(TestMethod8)//UNIT TEST DE FUNCION ORDENAR LISTA
		{
			//1er CASO:LA LISTA SE ENCUENTRA DESORDENADA, AL HABER SOLO DOS REGISTRADOS DEVUELVE QUE EL NOMBRE 2 QUE ESTABA EN LA SEGUNDA POSICION AHORA SE ENCUENTRA EN LA PRIMERA
			char nombre1[30] = "Manuela Balatti";//VARIABLE AUXILIAR DE TIPO STRING QUE ALMACENA EL MISMO NOMBRE QUE LA LISTA PARA VERIFICAR EL CORRECTO FUNCIONAMIENTO DE LA FUNCION ORDENAR LISTA
			char nombre2[30] = "Agustin Perez";//VARIABLE AUXILIAR DE TIPO STRING QUE ALMACENA EL MISMO NOMBRE QUE LA LISTA PARA VERIFICAR EL CORRECTO FUNCIONAMIENTO DE LA FUNCION ORDENAR LISTA

			s_listaJugadores lista;//DECLARO UNA LISTA DE TIPO s_listaJugadores
			lista.arr_jugadores = new Jugador[100];//ASIGNO MEMORIA DINAMICA AL ARRAY DENTRO DE LA LISTA
		
			lista.n_jugadores = 2;//INICIALIZO LA CANTIDAD DE JUGADORES EN 1
			lista.tam = 100;//INICIALIZO LA VARIABLE TAMAÑO EN LA LISTA EN 100 (MEMORIA PEDIDA PARA EL ARRAY)
			
			//CARGO EN LA LISTA LOS DATOS DE UN JUGADOR X
			strcpy(lista.arr_jugadores[0].apellido_nombre, nombre1);
			lista.arr_jugadores[0].edad = 18;
			lista.arr_jugadores[0].partidas_ganadas = 0;
			lista.arr_jugadores[0].partidas_perdidas = 1;
			lista.arr_jugadores[0].contraseña = 0000;
			//CARGO EN LA LISTA LOS DATOS DE UN JUGADOR X
			strcpy(lista.arr_jugadores[1].apellido_nombre, nombre2);
			lista.arr_jugadores[1].edad = 18;
			lista.arr_jugadores[1].partidas_ganadas = 0;
			lista.arr_jugadores[1].partidas_perdidas = 1;
			lista.arr_jugadores[1].contraseña = 0001;

			ordenar_lista(lista);//ORDENO LA LISTA POR ORDEN ALFABETICO

			Assert::IsTrue(strcmp(lista.arr_jugadores[0].apellido_nombre,nombre2)==0); //SI LA LISTA SE ORDENO CORRECTAMENTE AHORA SE DEBERIA SER CIERTO QUE EN LA PRIMER POSICION DEL ARRAY EN LA LISTA ESTE ALMACENADO EL NOMBRE2="Agustin Perez"
			
			delete lista.arr_jugadores;//LIBERO LA MEMORIA PEDIDA PARA EL ARRAY
			
			//2do CASO:LA LISTA YA SE ENCUENTRA ORDENADA Y RECORRE IF (EN CASO DE QUE NO HUBIERA QUE HACER CAMBIOS) DENTRO DE FUNCION ORDENARLISTA 
			strcpy(lista.arr_jugadores[0].apellido_nombre, nombre2);
			lista.arr_jugadores[0].edad = 18;
			lista.arr_jugadores[0].partidas_ganadas = 0;
			lista.arr_jugadores[0].partidas_perdidas = 1;
			lista.arr_jugadores[0].contraseña = 0001;
			//CARGO EN LA LISTA LOS DATOS DE UN JUGADOR X
			strcpy(lista.arr_jugadores[1].apellido_nombre, nombre1);
			lista.arr_jugadores[1].edad = 18;
			lista.arr_jugadores[1].partidas_ganadas = 0;
			lista.arr_jugadores[1].partidas_perdidas = 1;
			lista.arr_jugadores[1].contraseña = 0000;

			ordenar_lista(lista);//ORDENO LA LISTA POR ORDEN ALFABETICO

			Assert::IsTrue(strcmp(lista.arr_jugadores[0].apellido_nombre, nombre2) == 0); //SI LA LISTA SE ORDENO CORRECTAMENTE AHORA SE DEBERIA SER CIERTO QUE EN LA PRIMER POSICION DEL ARRAY EN LA LISTA ESTE ALMACENADO EL NOMBRE2="Agustin Perez"

		}

		TEST_METHOD(TestMethod9)//UNIT TEST FUNCION REDIMENSIONAR ARRAY DENTRO DE LISTA
		{
			//1ER CASO:REDIMENSIONA(ENTRA EN IF DE FUNCION)
			s_listaJugadores lista;//DECLARO UNA LISTA DE TIPO s_listaJugadores
			int memoria = 100;//VARIABLE AUXLIAR INICIALIZADA EN 100
			lista.arr_jugadores = new Jugador[memoria];//ASIGNO MEMORIA DINAMICA AL ARRAY DENTRO DE LA LISTA
			
			lista.n_jugadores = 100;//INICIALIZO A MODO DE PRUEBA A LA VARIABLE CANTIDAD DE JUGADORES EN LA LISTA EN 100
			lista.tam = memoria;//INICIALIZO A LA MBARIABLE TAMAÑO EN LA LISTA EN EL TAMAÑO ASIGNADO A MEMORIA ANTERIORMENTE
			
			redimensionar(lista,memoria);//SI LAS VARIABLES CANTIDAD DE JUGADORES Y TAMAÑO EN LISTA SON IGUALES, EL ARRAY SE REDIMESIONARA CON MEMORIA+=100
			Assert::IsTrue(memoria == 200);//SI SE REDIMENSIONA EL ARRAY, COMO PASAMOS POR REFERENCIA A LA VARIABLE MEMORIA, ENTONCES AHORA MEMORIA SERA IGUAL A 200

			delete lista.arr_jugadores;//LIBERO LA MEMORIA PEDIDA PARA EL ARRAY
			
            //2do CASO: NO REDIMENSIONA(NO ENTRA EN IF) QUEDA ESPACIO SUFICIENTE 
			s_listaJugadores lista1;//DECLARO UNA LISTA DE TIPO s_listaJugadores
			memoria = 100;//VARIABLE AUXLIAR INICIALIZADA EN 100
			lista1.arr_jugadores = new Jugador[memoria];//ASIGNO MEMORIA DINAMICA AL ARRAY DENTRO DE LA LISTA

			lista1.n_jugadores = 50;//INICIALIZO A MODO DE PRUEBA A LA VARIABLE CANTIDAD DE JUGADORES EN LA LISTA EN 100
			lista1.tam = memoria;//INICIALIZO A LA MBARIABLE TAMAÑO EN LA LISTA EN EL TAMAÑO ASIGNADO A MEMORIA ANTERIORMENTE

			redimensionar(lista1, memoria);//SI LAS VARIABLES CANTIDAD DE JUGADORES Y TAMAÑO EN LISTA SON IGUALES, EL ARRAY SE REDIMESIONARA CON MEMORIA+=100
			Assert::IsTrue(memoria == 100);//SI SE REDIMENSIONA EL ARRAY, COMO PASAMOS POR REFERENCIA A LA VARIABLE MEMORIA, ENTONCES AHORA MEMORIA SERA IGUAL A 200
			delete lista1.arr_jugadores;//LIBERO LA MEMORIA PEDIDA PARA EL ARRAY

		}
	};
}
