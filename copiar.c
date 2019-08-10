/*
Para ejecutar este programa debemos especificar el origen y destino 
del archivo  " copiar origen destino "

Retorna 0 si se ejecuta satifactoriamente
Retorna -1 si no se ejecuta correctamente
*/

#include <stdio.h> // Biblioteca estandar de E/S
#include <fcntl.h> // Biblioteca de llamadas a sistema de ficheros

char buffer [BUFSIZ]; //Memoria intermedia para manipular datos
           		//Obtiene el tamaño del bufer por defecto

//argc: Inicializamos los argumentos que obtendremos en la linea de
//comandos
//argv[]: Espacio de memoria de trabajo - TODO: definir

main(int argc, char *argv[]){

int fd_origen; 
int fd_destino;
int nbytes;

//Realizamos analisis de arguentos desde linea de comandos
if(argc != 3){
	//Implementar un error
exit(-1);
}

//Apertura del fichero en modo lectura
if((fd_origen = open(argv[1], O_RDONLY)) == -1){
	//Implementar error
exit(-1);
}

//Apertura o creacion del fichero destino 
if((fd_destino=open(argv[2], O_WRONLY|O_TRUNC|O_CREAT, 0666)) == -1){
	//Implementar error
exit(-1);
}


//Funcion de copiado del fichero de una ruta a otra
while((nbytes = read(fd_origen, buffer, sizeof buffer)) > 0)
{
	write(fd_destino, buffer, nbytes);
}

close(fd_origen);
close(fd_destino);

exit(0);

}//Cierre main


