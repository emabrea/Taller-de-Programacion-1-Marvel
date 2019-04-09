#ifndef JUGADOR_HPP_
#define JUGADOR_HPP_

#include <string>
#include <SDL2/SDL_image.h>

class Personaje;
class ControladorGrafico;

class Jugador{

	public:

		Jugador(ControladorGrafico &grafico, std::string nombrePersonaje1,
				std::string nombrePersonaje2, int posicionXinicial, SDL_RendererFlip flip);
		~Jugador();
		void personajeActualDibujar(ControladorGrafico &grafico);
		void cambiarPersonaje();
		Personaje * devolverPersonajeActual();

	private:

		Personaje *personaje1;
		Personaje *personaje2;
		Personaje *personajeActual;
		bool personajePrincipal;

};

#endif
