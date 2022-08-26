#pragma once
#ifndef MY_FUNCTION_H
#define MY_FUNCTION_H
#define ARCHIVO "registro.dat"//DEFINIMOS EL NOMBRE DEL ARCHIVO CON LA PALABRA "ARCHIVO"
#define ARCHIVO_TEST "Testdata.txt"

//ENUMS UTILIZADOS EN EL PROYECTO, DEFINO NOMBRES QUE TIENEN UN VALOR ESTABLECIDO
enum Resultado
{
	SIGUE = -1,
	PERDIO1,
	GANO1,
	PERDIO2,
	GANO2,
};
enum Error
{
	ERROR = -1,
	ERROR_1 = 0,
	CORRECTO = 1,
};
enum Existencia
{
	Existe = 1,
	No_existe = 0,
};
enum Opciones_menu2
{
	REPETIR = 0,
	SALIR = 1,
	SALIR_1 = 2,
};

//STRUCTS UTILIZADOS EN EL PROYECTO
//STRUCT JUGADOR 
//4 VARIABLES: 1 DE TIPO CHAR Y 3 DE TIPO INT
struct Jugador {
	char apellido_nombre[30];//NOMBRE DE JUGADOR
	int partidas_ganadas;//CANTIDAD DE PARTIDAS GANADAS DEL JUGADOR
	int partidas_perdidas;//CANTIDAD DE PARTIDAS GANADAS DEL JUGADOR
	int edad;//EDAD DEL JUGADOR
	int contraseña;//CONTRASEÑA DEL JUGADOR
};
//STRUCT LISTA DE JUGADORES
//3 VARABLES: 2 DE TIPO INT Y 1 DE TIPO JUGADOR(STRUCT)
struct s_listaJugadores {
	int tam;//TAMAÑO DE MEMORIA PEDIDO PARA EL ARRAY DINAMICO
	int n_jugadores;//NUMERO DE JUGADORES EN LA LISTA
	Jugador *arr_jugadores;//ARRAY DE TIPO JUGADOR QUE SERA LAL LISTA DE JUGADORES
	//STRCUT DENTRO DE OTRO (RAMIFICACIONES)
};


//DECLARACION DE FUNCIONES UTILIZADAS EN EL PROYECTO
void menu1(s_listaJugadores &lista, int &posicion1, int &memoria, int &posicion2, int &opcion);
int menu2(s_listaJugadores &lista, int &posicion1, char **tablero, int &total_jugadas, int &num, int &jugador, int &resultado, int &opcion2, int &posicion2, int &memoria);
void agregar_jugador(s_listaJugadores &lista, int &posicion1, int &memoria, int &posicion2, int &opcion);
int verficar_existencia(s_listaJugadores lista, char* nombre);
void ordenar_lista(s_listaJugadores &lista);
void usuario_existente(s_listaJugadores &lista, int &posicion1, int &memoria, int &posicion2, int &opcion);
void buscar_nombre(s_listaJugadores &lista, char *nombre, int &posicion1,int &memoria,int &posicion2, int &opcion, int contraseña);
void imprimir_lista(s_listaJugadores &lista);
void cargar_datos(s_listaJugadores &lista, int &resultado, int &posicion1, int &posicion2);
char** crear_tablero_random(int &num);
void inicializar_tablero(char** tablero, int num);
void mostrar_tablero(char** tablero, int &num);
int generar_numero(int &num);
int jugar(char **tablero, int &num, int &total_jugadas, int &jugador, int &resultado, s_listaJugadores &lista, int &posicion1, int &posicion2);
int hacer_jugada(int jugador, int &num, char** tablero, s_listaJugadores &lista, int &posicion1);
int comprobar_fin(char** tablero, int num, int &jugador,int &posicion1 ,int &posicion2, s_listaJugadores &lista);
int borrar_tablero(char** tablero, int &num);
int creararchivo();
int guardararchivo(s_listaJugadores &lista);
int leerarchivo(s_listaJugadores &lista);
void redimensionar(s_listaJugadores &p, int &memoria);
int hacer_jugadavsjugador(int jugador, int &num, char** tablero, s_listaJugadores &lista, int &posicion1, int &posicion2);

#endif