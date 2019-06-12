#ifndef SPRITEANIMADO_HPP_
#define SPRITEANIMADO_HPP_

#include <string>
#include <vector>
#include <Animacion.hpp>

using namespace std;

class ControladorGrafico;
class Animacion;

class SpriteAnimado{

	public:

		~SpriteAnimado();
		SpriteAnimado(string nombre);
		bool iniciarAnimacion(string animacion);
		void update();
		void cambiarAnimacion(string animacion);
		void agregarAnimacion(int frames, int x, int y, string nombre, int ancho, int alto);
		void cargarAnimaciones(string nombre);
		int getFrameIndex();
		string getAnimacionActual();
		string getNombre();
		SDL_Rect rectOrigen();
		int getAlto();
		int getAncho();


	private:

		Animacion *animacionActual;
		Animacion * quieto,*moverDerecha,*moverIzquierda,*salto,*agacharse,*cambioEntrada,*golpeS,*patadaS,*patadaA,*golpeSS,*patadaSS,*golpeF,*patadaF,*golpeA,*golpeSF,*patadaSF,*defensa,*disparo,*tiro,*rgolpe;
		Animacion * mouseOut,*mouseOver,*mouseDown,*mouseUp;
		vector<Animacion*> animaciones;
		int frameIndex = 0;
		int regulador = 0;
		string nombreSprite;
		bool boton =true;

};

#endif
