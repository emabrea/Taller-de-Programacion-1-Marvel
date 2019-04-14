#include <Personaje.hpp>
#include <ControladorJson.hpp>
#include <string>
#include <math.h>
#include <ControladorLogger.hpp>

extern ControladorJson *controladorJson;
extern ControladorLogger *controladorLogger;

#define constanteDeAltura 39.2f //Viene de despejar la velocidad en funcion a una h_max = 2*alto
#define constanteTiempoCiclos 0.3
#define limiteFondoIzq  controladorJson->anchoVentana() * 1/16
#define limiteFondoDer  controladorJson->anchoVentana() * 15/16
#define alturaPiso 80

using namespace std;

Personaje::~Personaje(){
}

Personaje::Personaje(ControladorGrafico &graficos, string nombre, int posicionXinicial, SDL_RendererFlip flip){
	if(!controladorJson->existePersonaje(nombre)){
		controladorLogger->registrarEvento("ERROR","ControladorJson::No se pudo encontrar la imagen del personaje: "+ nombre);
		nombre = "sinSprite";
	}
	this->posx= posicionXinicial;
	this->alto = controladorJson->alturaPersonaje(nombre);
	this->ancho = controladorJson->anchoPersonaje(nombre);
	this->posy = controladorJson->alturaVentana() - alturaPiso - alto;
	this->spriteAnimado=SpriteAnimado(graficos,controladorJson->pathImagen(nombre),nombre);
	this->velocidadInicial = sqrt(constanteDeAltura * alto);
	this->flip = flip;
}

void Personaje::dibujar(ControladorGrafico &graficos){
	if(saltando)
		this->Saltar();
	this->spriteAnimado.dibujar(graficos,this->posx,this->posy,alto, ancho, this->flip);
	this->spriteAnimado.update();

}
void Personaje::cambiarAnimacion(string nombre){
	this->spriteAnimado.cambiarAnimacion(nombre);
}

bool Personaje::MoverDerecha(Personaje *enemigo,bool finEscenarioDerecha){
	SDL_Rect rect_enemigo = enemigo->obtenerRectangulo();
	if(!saltando)
		this->spriteAnimado.iniciarAnimacion("movDerecha");
	if(posx + ancho >limiteFondoDer){
		if (rect_enemigo.x > limiteFondoIzq && !finEscenarioDerecha){
			enemigo->CorrerAIzquierda();
			controladorLogger->registrarEvento("DEBUG", "Personaje::Personaje en el limite derecho. Se corre el oponente a la izquierda");
			return true;
		}
		controladorLogger->registrarEvento("DEBUG", "Personaje::Ambos jugadores en el borde de la pantalla.");
		return false;
	}
	this->posx=this->posx+velocidad;
	controladorLogger->registrarEvento("DEBUG", "Personaje::Personaje se mueve a la derecha");
	return false;
}
int Personaje::getFrameIndex(){
	return this->spriteAnimado.getFrameIndex();
}
void Personaje::detenerAnimacion(){
	this->spriteAnimado.pararAnimacion();
}
bool Personaje::MoverIzquierda(Personaje *enemigo,bool finEscenarioIzquierda){
	SDL_Rect rect_enemigo = enemigo->obtenerRectangulo();
	if(!saltando)
		this->spriteAnimado.iniciarAnimacion("movIzquierda");
	if(posx  < limiteFondoIzq){
		if (rect_enemigo.x + rect_enemigo.w < limiteFondoDer && !finEscenarioIzquierda){
			enemigo->CorrerADerecha();
			controladorLogger->registrarEvento("DEBUG", "Personaje:: Personaje en el limite izquierdo. Se corre el oponente a la derecha");
			return true;
		}
		controladorLogger->registrarEvento("DEBUG", "Personaje::Ambos jugadores en el borde de la pantalla.");
		return false;
	}
	this->posx=this->posx-velocidad;
	controladorLogger->registrarEvento("DEBUG", "Personaje::Personaje se mueve a la izquierda");
	return false;
}

void Personaje::CorrerAIzquierda(){
	if(posx  < limiteFondoIzq)
			return;
	this->posx=this->posx-velocidad;
}

void Personaje::CorrerADerecha(){
	if(posx + ancho > limiteFondoDer)
			return;
	this->posx=this->posx+velocidad;
}

void Personaje::agacharse(){
	if(saltando) return;
	this->spriteAnimado.iniciarAnimacion("agacharse");
}
void Personaje::Cambio(){
	this->spriteAnimado.iniciarAnimacion("cambioEntrada");
}
void Personaje::Saltar(){
	this->spriteAnimado.iniciarAnimacion("salto");
	if( ! saltando) saltando = true;
	else{
		if(alturaActualSalto <= 0 && tiempo != 0 ){
			saltando = false; 	tiempo = 0; posy=controladorJson->alturaVentana() - alturaPiso - alto;; 	return;
		}
		else{
			tiempo += constanteTiempoCiclos;
			float alturaPrevia  = alturaActualSalto;
			alturaActualSalto = (velocidadInicial - 4.9* tiempo)*tiempo;
			//El 4.9 viene de 0.5*gravedad
			posy -= (alturaActualSalto - alturaPrevia);
		}
	}
}

void Personaje::Flip(){
	if (this->flip == 0){
		this->flip = SDL_FLIP_HORIZONTAL;
	}else{
		this->flip = SDL_FLIP_NONE;
	}
}

float Personaje::getXDer(){
	return (this->posx + this->ancho);
}

float Personaje::getPosX(){
	return this->posx;
}

float Personaje::getPosY(){
	return this->posy;
}

SDL_Rect  Personaje::obtenerRectangulo(){
	SDL_Rect rectangulo = { static_cast<int>(posx), static_cast<int>(posy), ancho, alto};
	return rectangulo;
}
/*
bool Personaje::colisionaAlaDerecha(SDL_Rect rectanguloOponente){
	SDL_Rect rectanguloFuturo = { static_cast<int>(posx)+15, static_cast<int>(posy), ancho, alto};
	return SDL_HasIntersection( &rectanguloFuturo, &rectanguloOponente );
}

bool Personaje::colisionaAlaIzquierda(SDL_Rect rectanguloOponente){
	SDL_Rect rectanguloFuturo = { static_cast<int>(posx)-15, static_cast<int>(posy), ancho, alto};
	return SDL_HasIntersection( &rectanguloFuturo, &rectanguloOponente );
}*/


