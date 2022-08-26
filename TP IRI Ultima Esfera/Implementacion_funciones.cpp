//DECLARACION DE LIBRERIAS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "conio.h"
#include "Funciones.h"
#include <iostream>
#include <string>

//FUNCION PRIMER MENU DE JUEGO (REGISTRO)  
void menu1(s_listaJugadores &lista,int &posicion1, int &memoria, int &posicion2,int &opcion)//PASAJE DE DATOS DE:LISTA DE JUGADORES, POSICION (POR REFERENCIA) EN LA LISTA DEL JUGADOR  Y TAMAÑO DE MEMORIA DE HASTA EL JUGADOR ACTUAL (POR REFERENCIA) 
{
	int opcion1 = 0;//VARIABLE AUXILIAR QUE ALMACENA LA OPCION ELEGIDAD POR EL USUARIO (INICIALIZA EN 0 PARA REDUCIR ERRORES DURANTE EL FUNCIONAMIENTO)
	printf("\n----------------MENU DEL JUEGO-----------------");//IMPRIMO EL MENU EN PANTALLA
	printf("\n 1)Usuario nuevo.");
    printf("\n 2)Usuario ya existente.\n");
	printf("\nIngrese opcion: ");
	scanf("%d", &opcion1);//PIDO INGRESO DE OPCION ELEGIDA POR EL USUARIO

	switch (opcion1)//INSTRUCCION SWITCH-CASE PARA DETERMINAR CADA CASO
	{
	 case 1://1ER CASO: EL USAURIO NO ESTA REGISTRADO SE PROCEDE A REGISTRARLO
		agregar_jugador(lista,posicion1,memoria,posicion2,opcion);//FUNCION AGREGAR NUEVO USUARIO
		break;//INSTRUCCION BREAK, SI SUCEDE EL CASO INDICA SALIR DE LA INSTRUCCION SWITCH-CASE
	 case 2://2DO CASO: EL USUARIO EXISTE ENTONCES SE VERFICA SU EXISTENCIA EN LA LISTA
		usuario_existente(lista,posicion1,memoria,posicion2,opcion);//FUNCION VERIFICAR EXISTENCIA DEL USUARIO REGISTRADO
		 break;//INSTRUCCION BREAK, SI SUCEDE EL CASO INDICA SALIR DE LA INSTRUCCION SWITCH-CASE
	}
}
//FUNCION SEGUNDO MENU DE JUEGO (JUGAR-VER LISTA DE JUGADORES-SALIR DEL JUEGO) SE LE PASA: LISTA DE JUGADORES Y TABLERO Y POR REFERENCIA: NUM(NUMERO DE COLUMNAS Y FILAS),
//POSICION DEL JUGADOR EN LA LISTA,TOTAL_JUGADAS (INDICA SI VA EL USUARIO (PAR) O EL OREDENADOR(IMPAR)),JUGADOR(INDICA AL QUE LE TOCA JUGAR), RESULTADO (QUIEN GANO), OPCION2 (OPCION ELEGIDA EN 2DO MENU PARA BUCLE ITERACION EN MAIN)
int menu2(s_listaJugadores &lista, int &posicion1 ,char **tablero,int &total_jugadas, int &num, int &jugador, int &resultado, int &opcion2, int &posicion2, int &memoria)
{
	int opcion = 0;//VARIABLE AUXILIAR PARA ALMACENAR OPCION ELGIDA POR EL USUARIO
	_getch();
	system("\ncls");
	printf("\n----------MENU-------------");
	printf("\t\t\t\tUsuario Principal:%s", lista.arr_jugadores[posicion1].apellido_nombre);
	printf("\n 1)Jugar partida vs computadora.");//IMPRIMO MENU
	printf("\n 2)Ver lista de jugadores.");
	printf("\n 3)Salir del juego.");
	printf("\n 4)Jugar partida vs otro jugador.");
	printf("\nIngrese opcion: ");
	_getch();
	scanf(" %d", &opcion);//REGISTRO LA OPCION ELEGIDA POR EL USUARIO

	switch (opcion)//INSTRUCCION SWITCH-CASE
	{
	case 1://1ER CASO EL USUARIO QUIERE JUGAR UNA PARTIDA CON LA COMPUTADORA
		opcion2 = jugar(tablero, num,total_jugadas, jugador, resultado,lista,posicion1,posicion2);
		break;////INSTRUCCION BREAK, SI SUCEDE EL CASO INDICA SALIR DE LA INSTRUCCION SWITCH-CASE
	case 2://2DO CASO EL USARIO QUIERE IMPRIMIR LA LISTA EN PANTALLA
		imprimir_lista(lista);//FUNCION IMPRIMIR JUGADORES
		return SALIR_1;//RETORNO DE VALOR QUE INDICA SALIR PERO SE VUELVE AL 2DO MENU
		break;//INSTRUCCION BREAK, SI SUCEDE EL CASO INDICA SALIR DE LA INSTRUCCION SWITCH-CASE
	case 3://CASO 3 EL USUARIO QUIERE SALIR DEL JUEGO
		return SALIR;//RETORNO DE VALOR QUE INDICA SALIR DEL JUEGO
		break;//INSTRUCCION BREAK, SI SUCEDE EL CASO INDICA SALIR DE LA INSTRUCCION SWITCH-CASE
	case 4://4TO CASO EL USUARIO QUIERE JUGAR UNA PARTIDA CON OTRO USUARIO
		printf("\nIngrese datos del segundo jugador.");
		menu1(lista, posicion1, memoria, posicion2,opcion);
		opcion2 = jugar(tablero, num, total_jugadas, jugador, resultado, lista, posicion1,posicion2);
		break;
	}	
}
//FUNCION QUE AGREGA UN JUEGADOR NUEVO A LA LISTA
void agregar_jugador(s_listaJugadores &lista, int &posicion1, int &memoria, int &posicion2,int &opcion)//LE PASAMOS LA LISTA Y POR REFERENCIA LA POSICION DEL JUGADOR EN LA LISTA Y EL TAMAÑO DE MEMORIA OCUPADO
{
	system("cls");
	char nombre[30];//VARIABLE AUXILIAR PARA ALMACENAR EL NOMBRE DEL USUARIO
	int contraseña;
	printf("\nREGISTRO DE  NUEVO JUGADOR");//IMPRIMO INDICACIONES A USUARIO 
	printf("\nIngrese su nombre: ");
	scanf(" %[^\n]", nombre);//GUARDO EL NOMBRE INGREASADO EN LA VARIABLE AUXILIAR
	redimensionar(lista, memoria);//FUNCION REDIMENSIONAR TAMAÑO DE MEMORIA PEDIDO AL PRINCIPIO
	strcpy(lista.arr_jugadores[lista.n_jugadores].apellido_nombre, nombre);//COPIO DE LA VARIABLE AUXILIAR A LA VARIABLE STRING DE LA LISTA EN LA ULTIMA POSICION.
	printf("\nIngrese su edad: ");
	_getch();
	scanf(" %d", &lista.arr_jugadores[lista.n_jugadores].edad);//REGISTRO LA EDAD INGREASADA POR EL USUARIO EN LA LISTA
	printf("\nIngrese contrasenia numerica: ");//REGISTRO DE CONTRASEÑA DE USUARIO NUEVO
	scanf(" %d", &contraseña);
	lista.arr_jugadores[lista.n_jugadores].contraseña = contraseña;

	if (verficar_existencia(lista, nombre) == Existe)//INSTRUCCION IF, INGRESA SI VERIFICAR EXISTENCIA DEVUELVE EL VALOR EXISTE(ENUM)
	{
		printf("\nError: Usuario ya existente.\n");//IMPRIMO ADVERTENCIA DE ERROR
		system("\nPause\n");
        //RETORNO CANTIDAD DE JUGADORES INGRESADOS EN LA LISTA HASTA EL MOMENTO, EL USUARIO A INGRESAR YA EXISTIA Y NO SE SUMA
	}
	else//INSTRUCCION ELSE, SI NO ENTRA INICIALIZO  LAS VARIABLES DE PARTIDAS GANADAS Y PERDIDAS DE LA ESTRUCTURA DEL ARRAY EN LA LISTA EN 0
	{
		lista.arr_jugadores[lista.n_jugadores].partidas_ganadas = 0;//INICIALIZO EN 0 LA VARIABLE PARTIDAS GANADAS
		lista.arr_jugadores[lista.n_jugadores].partidas_perdidas = 0;//INICIALIZO EN 0 LA VARIABLE PARTIDAS GANADAS
		lista.n_jugadores+=1;
	}
    ordenar_lista(lista);//FUNCION ORDENAR LISTA SE REALIZA DESPUES DE CADA INGRESO NUEVO DE USUARIO
	buscar_nombre(lista, nombre, posicion1,memoria,posicion2,opcion,contraseña);//FUNCION BUSCAR NOMBRE EN LA LISTA YA ORDENADA RETORNA VALOR POSICION POR REFERENCIA
	
	//RETORNA NUMERO DE JUGADORES EN LA LISTA +1 POR USUARIO NUEVO
}
//FUNCION VERIFICAR EXISTENCIA DE USUARIO 
int verficar_existencia(s_listaJugadores lista, char* nombre)//SE LE PASA LA LISTA Y EL NOMBRE INGRESADO AGREGAR_JUGADOR
{
	int i = 0;//VARIABLE AUXILIAR PARA CICLO FOR
	for (i = 0; i < lista.n_jugadores; i++)//CICLO FOR, RECORRO TODA LA LISTA
	{
		if (strcmp(lista.arr_jugadores[i].apellido_nombre, nombre) == 0)//INSTRUCCION IF COMPARO CADA NOMBRE EN LA LISTA CON EL STRING NOMBRE
		{
			return Existe;//SI ENCURENTRA UNO IGUAL DEVUELVE EL VALOR DE ENUM DE EXISTE
		}
	}
	return No_existe;//SI NO ENCUENTRA UN NOMBRE DEVUELVE EL VALOR DE NO EXISTE DE ENUM

}
//FUNCION ORDENAR LISTA
void ordenar_lista(s_listaJugadores &lista)
{
	int i = 0, j = 0;// VARIABLES AUXILIARES PARA ITERAR EN CICLO FOR
	int contador_cambio = 0;//VARIABLE AUXILIAR PARA CONTAR CAMBIOS Y AHORRAR TIEMPO 
	Jugador aux;//VARIABLE JUGADOR DE TIPO JUGADOR (STRUCT)

	for (i = 0; i < lista.n_jugadores - 1; i++)//CICLO FOR HASTA N-1 PARA RECORRER LISTA
	{
		contador_cambio = 0;//INICIALIZO CONTADOR DE CAMBIOS EN 0 
		for (j = 0; j < lista.n_jugadores - 1; j++)//CICLO FOR HASTA N-1 PARA RECORRER LISTA
		{
			if (strcmp(lista.arr_jugadores[j].apellido_nombre, lista.arr_jugadores[j + 1].apellido_nombre) > 0) //INSTRUCCION IF, ENTRA SI EL NOMBRE EN LA LISTA NO ESTA PRIMERO EN ORDEN ALFABETICO AL SIGUIENTE
			{
				aux = lista.arr_jugadores[j];//COPIO EN VARIABLE AUXILIAR LA ESTRUCTURA CORRESPONDIENTE AL PRIMER NOMBRE
				lista.arr_jugadores[j] = lista.arr_jugadores[j + 1];//COPIO EN EL LUGAR DEL PRIMER NOMBRE LA STRUCT DEL SIGUIENTE
				lista.arr_jugadores[j + 1] = aux;//COPIO LA ESTRUCTURA DE VARIABLE AUXILIAR EN LA POSICION DEL SEGUNDO NOMBRE
				contador_cambio++;//SI ENTRA AL IF Y SUCEDIO UN CAMBIO SE SUMA 1 A LA VARIABLE
			}
		}
		if (contador_cambio == 0)//INSTRUCCION IF SI NO HAY CAMBIOS SE SALE DE LOS BUCLES DE ITERACION PARA AHORRAR TIEMPO
		{
			break;//INSTRUCCION BREAK, SI SUCEDE EL CASO INDICA SALIR 

		}
	}
}
//FUNCION USUARIO EXISTENTE BUSCA POSICION EN LISTA
void usuario_existente(s_listaJugadores &lista, int &posicion1, int &memoria,int &posicion2, int &opcion)//PASAJE DE LISTA Y VARIABLE POSICION (POR REFERENCIA)
{
	char nombre[30];//VARIABLE AUXILIAR PARA ALMACENAR NOMBRE DE USUARIO
	int contraseña;
	printf("\nIngrese su nombre: ");
	scanf(" %[^\n]", nombre);//INGRESO DE NOMBRE POR EL USUARIO EN VARIABLE NOMBRE
	printf("\nIngrese su contrasenia numerica personal: ");
	scanf(" %d", &contraseña);
    buscar_nombre(lista,nombre,posicion1,memoria,posicion2,opcion,contraseña);//FUNCION BUSCAR NOMBRE EN LA LISTA, RETORNA POSICION
}
//FUNCION BUSCAR NOMRBE Y DEVUELVE POSICION
void buscar_nombre(s_listaJugadores &lista, char *nombre,int &posicion1, int &memoria, int &posicion2,int &opcion, int contraseña)
{
	int i = 0;//VARIABLE AUXILIAR PARA RECORRER LISTA
	for (i = 0; i < lista.n_jugadores; i++)//CICLO FOR PARA RECORRER LISTA HASTA CANTIDAD DE JUGADORES
	{
		
		if (verficar_existencia(lista, nombre) == No_existe)//INSTRUCCION IF PARA VERFICAR EXISTENCIA DE USUARIO EN LA LISTA
		{
			printf("\nEl usuario no existe.\n");
			system("\nPause\n");
			agregar_jugador(lista, posicion1, memoria,posicion2,opcion);//SI NO EXISTE REGISTRO EL JUGADOR
		}
		//INSTRUCCION IF, SI EL EL NOMBRE INGRESADO COINCIDE CON EL NOMBRE EN LA LISTA EN LA POSICION i ENTRO
		if(strcmp(nombre, lista.arr_jugadores[i].apellido_nombre) == 0)
		{
			while (lista.arr_jugadores[i].contraseña != contraseña)//INSTRUCCION WHILE, MIENTRAS QUE LA CONTRASEÑA INGRESADA SEA DISTINTA A LA DEL USUARIO EN LA POSICION i
			{//SE DEBERA SEGUIR INGRESANDO CONTRASEÑA HASTA LA CORRECTA
				printf("\nLa contraseña no es correcta.\n");
				system("\nPause\n");
				printf("\nIngrese la contraseña nuevamente: ");
				scanf(" %d", &contraseña);//REGISTRO CONTRASEÑA INGRESADA NUEVAMENTE
			}
		}
		//INSTRUCCION IF, SI EL NOMBRE Y LA CONTRASEÑA INGRESADOS COINDICEN CON EL DE LA POSICION i EN LA LISTA, ENTRO
		if((strcmp(nombre, lista.arr_jugadores[i].apellido_nombre) == 0) && lista.arr_jugadores[i].contraseña == contraseña)//INSTRUCCION IF  ENTRA SI EL USUARIO EXISTE Y LA CONTRASEÑA COINCIDE, STRCMP DEVUELVE 0 SI EL NOMBRE ES IGUAL AL DE LA LISTA 
		{//INSTRUCCION IF, SI SE SELECCIONO LA OPCION JUGAR CONTRA OTRO USUARIO EN MENU 2, ENTRO
			if (opcion == 4)
			{
				posicion2 = i;//COPIO VALOR DE I A LA VARIBLE POSICION 2(PASAJE POR REFERENCIA)
				break;//INSTRUCCION BREAK, SALGO DEL CICLO FOR
			}
			//SI ELIGIO JUGAR CONTRA LA MAQUINA, SOLO PASO POSICION 1
			else
			{
				posicion1 = i;
				break;//INSTRUCCION BREAK, SALGO DEL CICLO FOR
			}
		}
	}
}
//FUNCION IMPRIMIR LISTA
void imprimir_lista(s_listaJugadores &lista)
{
	system("cls");
	int i = 0;//VARIABLE AUXILIAR PARA ITERAR EN EL CICLO FOR
	printf("\n--------LISTA DE JUGADORES-------\n");
	printf("Cantidad de Jugadores registrados: %d\n", lista.n_jugadores);
	printf("Codigo\tNombre\t\t\tEdad\t\tPartidas Ganadas\t\tPartidas Perdidas");
	for (i = 0; i < lista.n_jugadores; i++)//CICLO FOR PARA IMPRIMIR LISTA
	{
		printf("\n%d)\t%s\t\t%d\t\t\t%d\t\t\t%d", i, lista.arr_jugadores[i].apellido_nombre, lista.arr_jugadores[i].edad, lista.arr_jugadores[i].partidas_ganadas, lista.arr_jugadores[i].partidas_perdidas);
	}
}
//FUNCION CARGAR DATOS SOBRE LAS PARTIDAS GANADAS Y PERDIDAS DEL JUGADOR
void cargar_datos(s_listaJugadores &lista, int &resultado, int &posicion1, int &posicion2)//PASO LISTA, RESULTADO(POR REFERENCIA) Y POSICION (POR REFERENCIA
{
	
	if (resultado == PERDIO1)//INSTRUCCION IF ENTRA SI EL RESULTADO ES IGUAL A PERDIO(ENUM)
	{
		lista.arr_jugadores[posicion1].partidas_perdidas++;//SUMA +1 A LA VARIABLE EN EL STRUCT LISTA DE PARTIDAS PERDIDAS
	}
	else if (resultado == GANO1)//INSTRUCCION ELSE IF ENTRA SI EL RESULTADO ES IGUAL 
	{
		lista.arr_jugadores[posicion1].partidas_ganadas++;//SUMA +1 A LA VARIABLE EN EL STRUCT LISTA DE PARTIDAS GANADAS
	}
	else if (resultado == PERDIO2)//INSTRUCCION 
	{
		lista.arr_jugadores[posicion1].partidas_ganadas++;
		lista.arr_jugadores[posicion2].partidas_perdidas++;
	}
	else if (resultado == GANO2)
	{
		lista.arr_jugadores[posicion1].partidas_perdidas++;
		lista.arr_jugadores[posicion2].partidas_ganadas++;
	}

}
//FUNCION CREAR TABLERO CON NUMERO PSEUDOALEATORIO
char** crear_tablero_random(int &num)//PASAJE DE NUMERO POR REFERENCIA
{
	srand(time(NULL));//SEMILLA DE SRAND  QUE TOMA COMO SEMILLA A LA HORA DEL MOMENTO
	num = (rand() % 5) + 3;//GENERACION DE NUMERO PSEUDOALEATORIO ENTRE 3 Y 7
	int i = 0;//VARIABLE AUXILIAR PARA INTERAR INICIALIZADA EN 0
	//CREAMOS TABLERO CON MEMORIA DINAMICA
	char** tablero = new char*[num];//CREAMOS TABLERO DE TIPO DOBLE PUNTERO Y PEDIMOS MEMORIA DE CANTIDAD NUMERO ALEATORIO GENERADO ANTERIOMENTE 
	for (i = 0; i < num; i++)//CICLO FOR PARA CREAR COLUMNAS DEL TABLERO DESDE 0 HASTA NUM 
	{
		tablero[i] = new char[num];//ASIGNO EL TAMAÑO DE NUM A CADA COLUMNA PARA QUE QUEDE COMO MATRIZ CUADRADA
	}
	
	inicializar_tablero(tablero, num);//FUNCION INICIALIZAR TABLERO, SE LE PASA TABLERO Y EL NUMERO ALEATORIO (NUM = CANTIDAD FILAS Y COLUMNAS)
	return tablero;//RETORNO DE DOBLE PUNTERO TABLERO 
}
//FUNCION INICIALIZAR TABLERO
void inicializar_tablero(char** tablero,int num) //Llenar tablero de O
{
	//VARIABLES AUXILIARES PARA ITERAR EN FOR
	int i = 0; 
	int j = 0;

	for (i = 0; i < num; i++)//CILO FOR PARA RECORRER CADA FILA
	{
		for (j = 0; j < num; j++)//CICLO FOR PARA RECORRER CADA COLUMNA
		{
			tablero[i][j] = 'O';//INICALIZO CADA LUGAR DE LA MATRIZ EN O
		}
	}
}
//FUNCION MOSTRAR TABLERO IMPRIME EL TABLRO EN PANTALLA
void mostrar_tablero(char** tablero,int &num)//PASAJE DE TABLERO Y NUMERO (CANTIDAD DE FILAS Y COLUMNAS)
{
	int i=0, j=0;
	int ficha=' ';

	system("cls");//INSTRUCCION PARA LIMPIAR PANTALLA
	//INSTRUCCIONES PARA IMPRIMIR TABLERO Y QUE SE PRESENTE ADECUADO Y CON FORMA DE TABLA
	printf("\n");
	for (j = 1; j <= num * 5 / 2; j++)
	{
		printf(" ");
	}
	printf("Ultima esfera");
	printf("\n F -");
	for (j = 1; j <= num + 1; j++)
	{
		printf("----");
	}
	printf("\n");

	for (i = 0; i < num; i++)
	{
		printf(" ");
		if (i == 0)
			printf("I");
		else if (i == 1)
			printf("A");
		else
			printf(" ");

		printf(" %d |", i + 1);

		for (j = 0; j < num; j++) {
			printf(" ");
			printf(" %c", tablero[i][j]);

			printf(" |");
		}
		printf(" ");
		if (i == 0) printf("\n L");
		else if (i == 1) printf("\n S");
		else printf("\n  ");

		printf(" -");
		for (j = 1; j <= num + 1; j++) printf("----");
		printf("\n");
	}
	printf("       ");
	for (j = 1; j <= num; j++)
	{
		printf("%d    ", j);
	}
	printf(" num\n");
	printf("\n");
}
//FUNCION GENERAR NUMERO PARA QUE EL ORDENADOR PUEDA JUGAR
int generar_numero(int &num)
{
	int random = 0;//VARIABLE AUXILIAR PARA ALMACENAR NUMERO RANDOM
	srand(time(NULL));//SEMILLA DE SRAND  QUE TOMA COMO SEMILLA A LA HORA DEL MOMENTO
	random = (rand() % num) + 1; //Devuelve un número entre 0 y num-1, porque al devolver el resto, este nunca puede ser superior a num-1.
	return random;//RETORNO DE NUMERO RANDOM
}
//FUNCION JUGAR
int jugar(char **tablero, int &num,int &total_jugadas,int &jugador, int &resultado, s_listaJugadores &lista, int &posicion1, int &posicion2)
{
	int aux = 0;//VARIABLE AUXILIAR INICALIZADA EN 0
	do {//INSTRUCCION DO-WHILE
		if (total_jugadas % 2 == 0)//INSTRUCCION IF ENTRA SI TOTAL JUGADAS ES PAR
		{
			jugador = 0; //Juega Usuario 1
		}
		else//SI NO ENTRA EN EL IF
		{
			jugador = 1; //Juega computadora o usuario2
		}
		total_jugadas++;//SE SUMA +1 A TOTAL JUGADAS PARA QUE EN EL SIGUIENTE TURNO JUEGUE LA COMPUTADORA

		mostrar_tablero(tablero, num);//FUNCION MOSTRAR TABLERO PARA IMPRIMIR TABLERO EN PANTALLA
		
		if (posicion2 >= 0)//INSTRUCCION IF PARA JUGAR O CON COMPUTADAORA O USUARIO
		{
			hacer_jugadavsjugador(jugador, num, tablero,lista,posicion1,posicion2);
		}
		else
		{//INSTRUCCION IF PARA CONTRALAR ERRORES
			if (hacer_jugada(jugador, num, tablero,lista, posicion1) == 0)//ENTRA SI HACER JUGADA DEVUELVE 0
			{
				printf("Jugada incorrecta.\n\n");//IMPRIMO ADVERTENCIA DE JUGADAS INCORRECTAS
			}
		}
		resultado = comprobar_fin(tablero, num, jugador,posicion1,posicion2,lista);//FUNCION COMPROBAR FIN, DEVUELVE QUIEN GANO O SI SE SIGUE JUGANDO
	} while (resultado == -1);//SI RESULTADO ES IGUAL A -1 SE SIGUE JUGANDO
	cargar_datos(lista, resultado, posicion1,posicion2);//FUNCION CARGAR DATOS, AL FINALIZAR CADA PARTIDA SE CARGAN LOS DATOS DE QUIEN GANO

	printf("\nQuiere volver al menu?\n1)SI.\t2)NO.");//AL FINAL CUANDO ALGUIEN TERMINA LA PARTIDA SE PREGUNTA SI QUIERE VOLVER A JUGAR OTRA
	printf("\nOpcion: ");
	scanf("%d", &aux);//REGISTRAMOS LA OPCION ELEGIDA 
	if (aux == 1)//INSTRUCCION IF, ENTRA  SI AUX ES IGUAL A 1 
	{
		posicion2 = NULL;
		return (REPETIR);//RETORNA INDICACION DE VOLVER AL MENU 2
	}
	else//SI NO ENTRA 
	{
		return SALIR;//RETORNA INDICACION DE SALIDA
	}
	
}
//FUNCION HACER JUGADA
int hacer_jugada(int jugador, int &num, char** tablero,s_listaJugadores &lista, int &posicion1) //Recibe 0 (Juega Usuario) o 1 (Juega computadora)
{
	int fila = 0, col = 0; //Para guardar la fila y columna en la que se saca la esfera.
	int i=0, j=0;
	char ficha = ' '; //ESPACIO VACIO FICHA DE USUARIO Y MAQUINA, SE SOBREESCRIBE EN LA MATRIZ
	int cantidad_esferas = 0;
	int contador_esferas = 0;
	int contador_espacios = 0;


	if (jugador == 0)
	{
		//ESPACIO VACIO FICHA DE USUARIO Y MAQUINA, SE SOBREESCRIBE EN LA MATRIZ
		printf("\nEl usuario %s saca esfera/s.\n",lista.arr_jugadores[posicion1].apellido_nombre);

		do {
			do {
				cantidad_esferas = 0;
				contador_esferas = 0;
				contador_espacios = 0;
				i = 0;
				j = 0;
				printf("\nIntroduce la fila de la que quieres sacar la/s esfera/s: ");
				scanf(" %d", &fila);
				fila = fila - 1; //Salvar error de empezar en 1
				if (fila > num || fila < 0)
				{
					printf("\nERROR: INGRESE OTRA FILA.\n");
				}
			} while (fila > num || fila<0);

			for (j = 0; j < num; j++)
			{
				if (tablero[fila][j] == ' ')
				{
					contador_espacios++;
				}
			}
			
			//CONTADOR DE ESFERAS DE LA FILA INDICADA POR EL USUARIO EN LA MATRIZ
			for (i = 0; i < num; i++)
			{
				if (tablero[fila][i] == 'O')
				{
					contador_esferas++;
				}
			}
			do {
				printf("\nIntroduce la cantidad de esferas que quieres sacar: ");
				scanf(" %d", &cantidad_esferas);
				if (cantidad_esferas > num || cantidad_esferas <= 0)
				{
					printf("\nError introduzca otra cantidad de esferas.\n");
				}
			} while (cantidad_esferas > num || cantidad_esferas <= 0);

		} while (cantidad_esferas > contador_esferas);
		//SOBREESCRIBO LA FILA  CON ESPACIOS VACIOS
	
			if (contador_espacios == 0)
			{
				for (i = 0; i < cantidad_esferas;i++)
				{
					tablero[fila][i] = ' ';
				}
			}
			else
			{
				for (j = contador_espacios; j < contador_espacios+cantidad_esferas; j++)
				{
					tablero[fila][j] = ' ';
				}
			}
		
		mostrar_tablero(tablero,num);
	} 
	else //JUEGA LA COMPUTADORA
	{ 
		
		printf("\nJuega la computadora.\n");

		system("\nPause");
		ficha = ' ';

		do {
			cantidad_esferas = 0;
			contador_esferas = 0;
			contador_espacios = 0;
			i = 0;
			j = 0;
			
			fila = generar_numero(num) - 1;

			do {
				cantidad_esferas = generar_numero(num);
			} while (cantidad_esferas > num || cantidad_esferas <= 0);

			for (j = 0; j < num; j++)
			{
				if (tablero[fila][j] == ' ')
				{
					contador_espacios++;
				}
			}


			for (i = 0; i < num; i++)
			{
				if (tablero[fila][i] == 'O')
				{
					contador_esferas++;
				}
			}
		} while (cantidad_esferas > contador_esferas);



		if (contador_espacios == 0)
		{
			for (i = 0; i < cantidad_esferas; i++)
			{
				tablero[fila][i] = ' ';
			}
		}
		else
		{
			for (j = contador_espacios; j < (contador_espacios + cantidad_esferas); j++)
			{
				tablero[fila][j] = ' ';
			}
		}

		mostrar_tablero(tablero, num);
		
	}
	return CORRECTO;
}
//FUNCION COMBRAR FIN DE PARTIDA (CUENTA LA CANTIDAD DE ESFERAS EN EL TABLERO)
int comprobar_fin(char** tablero, int num,int &jugador,int &posicion1,int &posicion2, s_listaJugadores &lista)//RECIBE DOBLE PUNTERO EL TABLERO, NUM CANTIDAD DE FILAS Y COLUMNAS Y TOTAL JUGADAS
//SI LA ULTIMA JUGADA ES UN N° PAR JUGO EL USUARIO SINO FUE LA COMPUTADORA
{
	int i = 0, j = 0;//VARIABLES AUXILIARES PARA ITERAR
	int contador_esferas = 0;//VARIABLE AUXILIAR PPARA CONTAR CANTIDAD DE ESFERAS RESTANTES

	for (i = 0; i < num; i++)//CICLO FOR  PARA RECORRER LAS FILAS DE LA MATRIZ
	{
		for (j = 0; j < num; j++)//CICLO FOR PARA RECOORER LAS COLUMNAS
		{
			if (tablero[i][j] == 'O')//INSTRUCCION IF, ENTRA IF SI EN LA POSICION HAY UNA ESFERA
			{
				contador_esferas++;//CONTADOR ESFERAS RESTANTES SE SUMA +1
			}
		}
	}
	if (contador_esferas > 1)//INSTRUCCION IF, ENTRA SI EL CANTIDAD DE ESFERAS ES MAYOR A 1
	{
	    return (SIGUE);//RETORNA INDICACION DE SEGUIR EL JUEGO
	}
	if ((contador_esferas == 1 || contador_esferas == 0) && jugador == 0)//INSTRUCCION ELSE IF, ENTRA SI LA CANTIDAD DE ESFERAS RESTANTES ES IGUAL A 1 O 0 Y SI TOTAL_JUGADAS ES PAR
	{
		printf("\nHa ganado el usuario %s!!\n\n",lista.arr_jugadores[posicion1].apellido_nombre);//IMPRIMO INDICACION DE QUE GANO EL USUARIO
		if (posicion2 >= 0)
		{
			return (PERDIO2);
		}
		return (GANO1);//RETORNO INDICACION DE GANO USUARIO
	}
	if ((contador_esferas == 1 || contador_esferas == 0) && jugador == 1)//INSTRUCCION ELSE, EN CASO CONTRARIO A LO ANTERIOR
	{
		if (posicion2 >= 0)
		{
			printf("\nHa ganado el usuario %s!!\n\n", lista.arr_jugadores[posicion2].apellido_nombre);//INDICO QUE A GANADO EL USUARIO 2
			return GANO2;
		}
		printf("\nHa ganado la computadora");//INDICO QUE A GANADO LA COMPUTADORA
		return (PERDIO1);//RETORNO INDICACION DE QUE PERDIO EL USUARIO
	}


}
//FUNCION BORRAR TABLERO
int borrar_tablero(char** tablero, int &num)//RECIBE EL TABLERO COMO DOBLE PUNTERO Y NUMERO DE FILAS Y COLUMNAS POR REFERENCIA
{
	int i = 0;//VARIABLE AUXILIAR DE TIPO INT PARA ITERAR
	int contador_borrado = 0;//VARIABLE AUXILIAR DE TIPO INT PARA CONTAR, INICALIZADO EN 0 PARA REDUCIR ERRORES
	for (i = 0; i < num; i++)//CICLO FOR PARA LIBERAR MEMORIA DEL DOBLE PUNTERO
	{
		delete[] tablero[i];//LIBERO MEMORIA DEL DOBLE PUNTERO DE CADA POSICION HASTA NUM
		contador_borrado++;
	}
	delete[] tablero;//LIBERO MEMORIA DEL PUNTERO SIMPLE

    return CORRECTO;//RETORNO DE VALOR CORRECTO=1(ENUM)
	
}
//FUNCION HACER JUGADA VS OTRO JUGADOR
int hacer_jugadavsjugador(int jugador, int &num, char** tablero, s_listaJugadores &lista, int &posicion1, int &posicion2) //Recibe 0 (Juega Usuario) o 1 (Juega computadora)
{
	int fila = 0, col = 0; //Para guardar la fila y columna en la que se saca la esfera.
	int i = 0, j = 0;
	char ficha = ' '; //ESPACIO VACIO FICHA DE USUARIO Y MAQUINA, SE SOBREESCRIBE EN LA MATRIZ
	int cantidad_esferas = 0;
	int contador_esferas = 0;
	int contador_espacios = 0;
		//ESPACIO VACIO FICHA DE USUARIO, SE SOBREESCRIBE EN LA MATRIZ
		if (jugador == 0)
		{
			printf("\nEl usuario %s saca esfera/s.\n",lista.arr_jugadores[posicion1].apellido_nombre);
		}
		else 
		{
			printf("\nEl usuario %s saca esfera/s.\n", lista.arr_jugadores[posicion2].apellido_nombre);
		}
		do {
			do {
				cantidad_esferas = 0;
				contador_esferas = 0;
				contador_espacios = 0;
				i = 0;
				j = 0;
				printf("\nIntroduce la fila de la que quieres sacar la/s esfera/s: ");
				scanf(" %d", &fila);
				fila = fila - 1; //Salvar error de empezar en 1
				if (fila > num || fila < 0)
				{
					printf("\nERROR: INGRESE OTRA FILA.\n");
				}
			} while (fila > num || fila < 0);

			for (j = 0; j < num; j++)
			{
				if (tablero[fila][j] == ' ')
				{
					contador_espacios++;
				}
			}

			//CONTADOR DE ESFERAS DE LA FILA INDICADA POR EL USUARIO EN LA MATRIZ
			for (i = 0; i < num; i++)
			{
				if (tablero[fila][i] == 'O')
				{
					contador_esferas++;
				}
			}
			do {
				printf("\nIntroduce la cantidad de esferas que quieres sacar: ");
				scanf(" %d", &cantidad_esferas);
				if (cantidad_esferas > num || cantidad_esferas <= 0)
				{
					printf("\nError introduzca otra cantidad de esferas.\n");
				}
			} while (cantidad_esferas > num || cantidad_esferas <= 0);

		} while (cantidad_esferas > contador_esferas);
		//SOBREESCRIBO LA FILA  CON ESPACIOS VACIOS

		if (contador_espacios == 0)
		{
			for (i = 0; i < cantidad_esferas; i++)
			{
				tablero[fila][i] = ' ';
			}
		}
		else
		{
			for (j = contador_espacios; j < contador_espacios + cantidad_esferas; j++)
			{
				tablero[fila][j] = ' ';
			}
		}

		mostrar_tablero(tablero, num);
		return CORRECTO;
}



//FUNCIONES DE ARCHIVOS

//FUNCION CREAR ARCHIVO
int creararchivo()
{
	//SI EL ARCHIVO NO EXISTE SE CREA UNO NUEVO
	char filename[30] = ARCHIVO;//VARIABLE AUXILIAR ALMACENA NOMBRE PREDEFINIDO DEL ARCHIVO
	FILE *fp;//VARIABLE FILE POINTER
	fp = fopen(filename, "w+b");//FUNCION PARA ABRIR ARCHIVO PARA ESCRIBIR Y LEER ARCHIVOS DE TIPO BINARIO
	if (fp == NULL)//INSTRUCCUIN IF, ENTRA SI EL FILE FOPEN DEVUELVE AL FILE POINTER VALOR NULL, INDICANDO UN ERROR
	{
		return (ERROR);//RETORNO DE INDICACION DE ERROR
	}
	fclose(fp);//FUNCION PARA CERRAR ARCHIVO
	return (0);//RETORNO DE 0
}
//FUNCION PARA GUARADAR ARCHIVO
int guardararchivo(s_listaJugadores &lista)//RECIBE LA LISTA DE USUARIOS
{
	char filename[30] = ARCHIVO;//VARIABLE AUXILIAR ALMACENA NOMBRE PREDEFINIDO DEL ARCHIVO
	FILE *fp;//VARIABLE FILE POINTER
	fp = fopen(filename, "r+b");//FUNCION PARA ABRIR ARCHIVO PARA ESCRIBIR Y LEER ARCHIVOS DE TIPO BINARIO
	if (fp == NULL)//INSTRUCCUIN IF, ENTRA SI EL FILE FOPEN DEVUELVE AL FILE POINTER VALOR NULL, INDICANDO UN ERROR
	{
		return (ERROR);//RETORNO DE INDICACION DE ERROR
	}
	fwrite(lista.arr_jugadores, sizeof(Jugador), lista.n_jugadores, fp);//FUNCION PARA ESCRIBIR EN EL ARCHIVO, RECIBE ARRAY DE JUGADORES,
	               //EL TAMAÑO DE LA VARIABLE JUGADOR(STRUCT), CANTIDAD DE JUGADORES REGISTRADOS Y EL ARCHIVO  
	fclose(fp);//FUNCION CERRAR ARCHIVO
	return 0;//RETORNO DE VALOR 0, NO HUBO ERROR
}
//FUNCION LEER ARCHIVO
int leerarchivo(s_listaJugadores &lista)//RECIBE LA LISTA DE USUARIOS REGISTRADOS
{
	int i = 0;//VARIABLE AUXILIAR PARA ITERAR 
	char filename[30] = ARCHIVO;//VARIABLE AUXILIAR ALMACENA NOMBRE PREDEFINIDO DEL ARCHIVO
	FILE *fp;//VARIABLE FILE POINTER
	fp = fopen(filename, "r+b");//FUNCION ABRIR ARCHIVO PARA LEER ARCHIVO DE TIPO BINARIO
	if (fp == NULL)//INSTRUCCUIN IF, ENTRA SI EL FILE FOPEN DEVUELVE AL FILE POINTER VALOR NULL, INDICANDO UN ERROR
	{
		return (ERROR_1);//RETORNO DE INDICACION DE ERROR
	}
	while (!feof(fp))
	{//INSTRUCCION DO-WHILE, SE REPITE HASTA QUE HASTA EL ULTIMO INDICE DEL ARCHIVO (INDICACION END OF FILE(EOF))
		fread(lista.arr_jugadores + i, sizeof(Jugador), 1, fp);//FUNCION LEER ARCHIVO, RECIBE LISTA  DE USARIOS REGISTRADOS, EL TAMAÑO EN BYTES DE LA VARIABLE JUGADOR(STRUCT) Y  1 PARA LEER DE A UN REGISTRO Y EL FILE POINTER. 
				  //EN CADA CICLO A LA DIRECCION DE LA LISTA DE JUGADORES SE LE SUMA LA VARABLE i PARA IR A ESA DIRECCION
		i++;//LA VARIABLE I AUMENTA EN UNO EN CADA CICLO 
	} //CONDICION DE SALIDA, ULTIMO REGISTRO EN EL ARCHIVO
	fclose(fp);//FUNCION CERRAR ARCHIVO
	return(i-1);//RETORNA CANTIDAD DE JUGADORES EN LA LISTA
}
//FUNCION DE TIPO VOID REDIMENSIONAR ARRAY DE MEMORIA DINAMICA
void redimensionar(s_listaJugadores &p,int &memoria)//RECIBE LISTA DE JUGADORES (STRUCT) Y EL TAMAÑO DE MEMORIA POR REFERENCIA
{
	if (p.tam == p.n_jugadores)//INSTRUCCION IF, ENTRA SI EL TAMAÑO DE MEMORIA EN LA LISTA ES IGUAL A LA CANTIDAD DE JUGADORES
	{
		realloc(p.arr_jugadores, memoria+=100);//FUNCION AGREGAR MEMORIA AL ARRAY SIN ALTERAR LOS QUE YA ESTA ESCRITO
		p.tam = memoria;//EL TAMAÑO DEL ARRAY ALMACENDO EN LA LISTA SE CAMBIA CON EL VALOR DE NUEVO TAMAÑO
	}
}