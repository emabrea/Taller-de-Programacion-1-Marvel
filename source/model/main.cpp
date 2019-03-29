#include <Juego.hpp>
#include <controler/ControladorJson.hpp>
#include <controler/ControladorLogger.hpp>
#include <Parallax.hpp>
#include <iostream>


time_t my_time = time(NULL);
ControladorJson *controladorJson = new ControladorJson();
ControladorLogger *controladorLogger = new ControladorLogger(controladorJson->nivelDebug());
Parallax *p = nullptr;

int main(int argc, char **argv){

	controladorJson->leerArchivo();
	p = new Parallax();

	return 0;

}

