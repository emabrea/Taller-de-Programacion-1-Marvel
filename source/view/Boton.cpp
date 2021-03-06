#include <Boton.hpp>
#include <ControladorGrafico.hpp>
#include <iostream>

extern ControladorJson *controladorJson;
extern ControladorLogger *controladorLogger;

Boton::Boton(int posX, int posY, int width, int heigth, std::string nombre){
	this->botonClickeado=false;
	this->botonBlockeado=false;
	this->nombre=nombre;
	this->posicion.x = posX;
	this->posicion.y = posY;
	this->width = width;
	this->height = heigth;
	this->spriteActual = BOTON_SPRITE_MOUSE_OUT;
	this->spriteAnimado=new SpriteAnimado(nombre);
}

Boton::~Boton(){
	delete spriteAnimado;
}

std::string Boton::Nombre(){
	return this->nombre;
}

void Boton::setPosicion(int x, int y){
	this->posicion.x = x;
	this->posicion.y = y;
}

bool Boton::fueClickeado(){
	return this->botonClickeado;
}

bool Boton::fueBlockeado(){
	return this->botonBlockeado;
}

void Boton::handleEvent(SDL_Event e){
	//If mouse event happened
	this->botonClickeado = false;
	if( not this->botonBlockeado && (e.type == SDL_MOUSEMOTION || e.type == SDL_MOUSEBUTTONDOWN || e.type == SDL_MOUSEBUTTONUP )){
		//Obtengo posicion del mouse
		int x, y;
		x=e.button.x;
		y=e.button.y;

		//Mouse est[a dentro del boton
		bool inside = true;
		//El Mouse est[a fuera del boton
		if( x < this->posicion.x ){
			inside = false;
		}else if( x > this->posicion.x + this->width ){
			inside = false;
		}else if( y < this->posicion.y ){
			inside = false;
		}else if( y > this->posicion.y + this->height ){
			inside = false;
		}
        if( !inside ){
            this->spriteActual = BOTON_SPRITE_MOUSE_OUT;
        }

        //El mouse esta dentro del boton
        else{
            switch( e.type ){
                case SDL_MOUSEMOTION:
					this->spriteActual = BOTON_SPRITE_MOUSE_OVER_MOTION;
					break;
                case SDL_MOUSEBUTTONDOWN:
					this->spriteActual = BOTON_SPRITE_MOUSE_DOWN;
					break;
                case SDL_MOUSEBUTTONUP:
					this->spriteActual = BOTON_SPRITE_MOUSE_UP;

					break;
				}
        }
        switch(this->spriteActual){
			case BOTON_SPRITE_MOUSE_OUT:
				this->spriteAnimado->cambiarAnimacion("mouseOut");
				break;
			case BOTON_SPRITE_MOUSE_OVER_MOTION:
				this->spriteAnimado->cambiarAnimacion("mouseOver");
				break;
			case BOTON_SPRITE_MOUSE_DOWN:
				this->spriteAnimado->cambiarAnimacion("mouseDown");
				break;
			case BOTON_SPRITE_MOUSE_UP:
				this->spriteAnimado->cambiarAnimacion("mouseUp");
				this->botonClickeado = true;
				this->botonBlockeado = true;
				break;
        	}
	}
}

tuple<string,SDL_Rect, SDL_Rect ,SDL_RendererFlip > Boton::getDibujable(){
	SDL_Rect sourceRect =this->spriteAnimado->rectOrigen();
	SDL_Rect rectanguloDestino={this->posicion.x, this->posicion.y, this->width,this->height};
	this->spriteAnimado->update();
	return make_tuple(this->nombre,sourceRect,rectanguloDestino,SDL_FLIP_NONE);
}
