#include <ControladorTexturas.h>
#include <Personaje.h>
#include <ControladorGrafico.hpp>

Personaje::Personaje(ControladorGrafico &graficos, float x, float y):
	SpriteAnimado(graficos, "CaptainAmericaSprites.png", 0, 0, 16, 16, x, y, 100){
		graficos.cargarImagen("CaptainAmericaSprites.png");
	//	this->_facing = RIGHT;
		this->configurarAnimaciones();
		//objTexture = ControladorTexturas::LoadTexture(imagen);
	//xpos = x;
	//ypos = y;

}
void Personaje::configurarAnimaciones(){
	this->agregarAnimacion(1, 0, 0, "Avanzar", 16, 16, Vector2(0,0));
}
void Personaje::update(float tiempoTrancurrido){
	this->_x += this->_dx * tiempoTrancurrido;

	SpriteAnimado::update(tiempoTrancurrido);
	/*srcRect.h = 286;
	srcRect.w = 256;
	srcRect.x = 0;
	srcRect.y = 0;
	destRect.x = xpos;
	destRect.y = ypos;
	destRect.w = srcRect.w ;
	destRect.h = srcRect.h;*/

}

void Personaje::dibujar(ControladorGrafico &graficos){
	SpriteAnimado::dibujar(graficos, this->_x, this->_y);
	//SDL_RenderCopy(Juego::renderer, objTexture, &srcRect, &destRect);
}

void Personaje::MoverDerecha(){
	this->_dx = constantes_personajes::VELOCIDAD;
	this->iniciarAnimacion("Avanzar");
	//xpos += 30;
}

void Personaje::MoverIzquierda(){
	//xpos -= 30;
}
//test branch personajes