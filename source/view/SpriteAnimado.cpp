#include <SpriteAnimado.hpp>
#include <ControladorGrafico.hpp>
#include <Animacion.hpp>
#include <ControladorLogger.hpp>
#include <ControladorJson.hpp>

using namespace std;
extern ControladorSonido *controladorSonido;

SpriteAnimado::~SpriteAnimado(){

	for(Uint16 i = 0; i<animaciones.size();i++)
		if(animaciones[i]) delete animaciones[i];

	animaciones.clear();
}

SpriteAnimado::SpriteAnimado(string nombre){
	this->nombreSprite = nombre;
	cargarAnimaciones(nombre);
}

string SpriteAnimado::getAnimacionActual(){
	return this->animacionActual->getNombre();
}

string SpriteAnimado::getNombre(){
	return this->nombreSprite;
}

int SpriteAnimado::getAlto(){
	return this->animacionActual->getAlto();
}

int SpriteAnimado::getAncho(){
	return this->animacionActual->getAncho();
}

void SpriteAnimado::cargarAnimaciones(string nombre){
	if(nombre == "CapitanAmerica" ){
		quieto = new Animacion("quieto",9,0,18,95,115,6);
		moverDerecha = new Animacion("movDerecha",6,0,158,100,122,4);
		moverIzquierda = new Animacion("movIzquierda",6,0,288,100,122,4);
		salto = new Animacion("salto",9,0,590,125,161,6);
		agacharse = new Animacion("agacharse",3,0,748,100,93,4);
		cambioEntrada = new Animacion("cambioEntrada",13,0,418,120,159,4);
		golpeS=new Animacion("golpeS",3,0,872,140,114,10);//golpe simple LISTO
		patadaS=new Animacion("patadaS",3,0,2079,123,120,6);//patada simple LISTO
		golpeF=new Animacion("golpeF",7,0,1042,231,125,3);//golpe fuerte LISTO
		patadaF=new Animacion("patadaF",4,400,2077,130,130,6);//patada fuerte LISTO
		golpeA=new Animacion("golpeA",4,470,860,125,150,6);//golpe agachado fuerte LISTO
		patadaA=new Animacion("patadaA",4,0,3993,120,82,4);//patada agachado LISTO
		golpeSaltando=new Animacion("golpeSaltando",5,310,2943,155,163,7);//golpe saltando LISTO
		golpeSaltandoF=new Animacion("golpeSaltandoF",4,1250,2135,150,170,9);//golpe saltando LISTO
		patadaSaltando=new Animacion("patadaSaltando",7,0,3513,172,163,5);//patada saltando LISTO
		patadaSaltandoF=new Animacion("patadaSaltandoF",7,0,7185,172,163,5);//patada saltando LISTO
		golpeAF=new Animacion("golpeAF",4,1094,860,125,150,6); // golpe agachado fuerte
		patadaAF=new Animacion("patadaAF",4,1248,3993,120,82,4); //patada agachada fuerte
		defensa=new Animacion("defensa",2,385,742,103,110,7); //LISTO
		disparo=new Animacion("disparar",7,0,1539,125,115,6); //LISTO
		Animacion *atraparEscudo = new Animacion("atraparEscudo",6,435,1668,145,124,6);//LISTO
		animaciones.push_back(atraparEscudo);
		tiro=new Animacion("tirar",7,0,6793,120,137,3);//LISTO
		rgolpe=new Animacion("recibirGolpe",3,850,5170,112,140,6);//LISTO
		rgolpeF=new Animacion("recibirGolpeF",5,1295,5191,179,115,6);//LISTO
		levantarse=new Animacion("levantarse",2,1150,5359,87,96,10);//LISTO
		serLanzado=new Animacion("serLanzado",8,0,6989,179,135,5);//LISTO
		festejo=new Animacion("festejo",14,0,7425,140,209,5);//LISTO
		boton = false;
	}
	else if(nombre=="Spiderman"){
		quieto = new Animacion("quieto",10,1365,7,105,85,5);
		moverDerecha = new Animacion("movDerecha",12,0,120,100,99,2);
		moverIzquierda = new Animacion("movIzquierda",12,0,120,100,99,2);
		salto = new Animacion("salto",14,0,482,100,124,5);
		agacharse = new Animacion("agacharse",13,0,1205,110,65,4);
		cambioEntrada = new Animacion("cambioEntrada",14,0,227,110,133,2);
		golpeS=new Animacion("golpeS",5,0,633,155,85,4);//golpe simple LISTO
		patadaS=new Animacion("patadaS",4,1270,930,149,102,4);//patada simple LISTO
		golpeSaltando=new Animacion("golpeSaltando",10,0,5323,138,120,4);//golpe saltando LISTO
		golpeSaltandoF=new Animacion("golpeSaltandoF",10,0,766,138,120,4);//golpe saltando LISTO
		patadaSaltando=new Animacion("patadaSaltando",10,0,5192,152,125,4);//patada saltando LISTO
		patadaSaltandoF=new Animacion("patadaSaltandoF",10,0,1900,152,125,4);//patada saltando LISTO
		golpeF=new Animacion("golpeF",8,900,608,151,145,4);//golpe fuerte LISTO
		patadaF=new Animacion("patadaF",6,150,916,145,125,4);//patada fuerte LISTO
		golpeA=new Animacion("golpeA",8,790,2748,155,150,5);//golpe agachado LISTO
		patadaA=new Animacion("patadaA",5,1030,1405,140,70,5);//patada agachado LISTO
		golpeAF=new Animacion("golpeAF",8,790,5480,155,150,5);//golpe agachado fuerte
		patadaAF=new Animacion("patadaAF",5,1769,1405,140,70,5);//patada agachado fuerte
		defensa=new Animacion("defensa",4,0,2377,110,110,6); //LISTO
		disparo=new Animacion("disparar",7,0,2500,125,84,3); //LISTO
		tiro=new Animacion("tirar",10,7,5020,145,128,2);//LISTO
		rgolpe=new Animacion("recibirGolpe",3,0,3477,160,113,4); //LISTO
		rgolpeF=new Animacion("recibirGolpeF",7,0,3721,157,93,3);//LISTO
		levantarse=new Animacion("levantarse",5,1099,3721,157,93,5);//LISTO
		serLanzado=new Animacion("serLanzado",8,0,3610,147,116,4);
		festejo=new Animacion("festejo",11,0,3960,100,155,4);
		boton = false;
	}
	else if(nombre=="Venom" ){
		quieto = new Animacion("quieto",13,0,10,160,120,5);//LISTO
		moverDerecha = new Animacion("movDerecha",10,0,260,155,122,4);//LISTO
		moverIzquierda = new Animacion("movIzquierda",10,0,260,155,122,4);//LISTO
		salto = new Animacion("salto",11,0,524,160,170,5);//LISTO
		agacharse = new Animacion("agacharse",9,0,390,117,90,2);//LISTO
		cambioEntrada = new Animacion("cambioEntrada",11,0,700,160,170,2);//LISTO
		golpeS=new Animacion("golpeS",3,0,130,219,108,8);//golpe simple//LISTO
		patadaS=new Animacion("patadaS",3,0,1050,220,119,8);//patada simple//LISTO
		golpeSaltando=new Animacion("golpeSaltando",9,0,1226,215,160,6);//golpe saltando//LISTO
		golpeSaltandoF=new Animacion("golpeSaltandoF",9,2144,1229,215,160,6);//golpe saltando//LISTO
		patadaSaltando=new Animacion("patadaSaltando",9,0,1400,215,170,6);//patada saltando//LISTO
		patadaSaltandoF=new Animacion("patadaSaltandoF",9,2406,7,215,170,6);//patada saltando//LISTO
		golpeF=new Animacion("golpeF",7,0,1800,190,178,5);//golpe fuerte//LISTO
		patadaF=new Animacion("patadaF",9,0,1980,210,124,6);//patada fuerte//LISTO
		golpeA=new Animacion("golpeA",3,0,875,220,90,8);//golpe agachado//LISTO
		patadaA=new Animacion("patadaA",4,0,1570,215,109,8);//patada agachado//LISTO
		golpeAF=new Animacion("golpeAF",3,658,875,220,90,8);//golpe agachado fuerte
		patadaAF=new Animacion("patadaAF",4,951,1570,215,109,8);//patada agachado fuerte
		defensa=new Animacion("defensa",8,0,2924,170,172,8);//LISTO
		disparo=new Animacion("disparar",12,0,3230,145,128,2);//LISTO
		tiro=new Animacion("tirar",11,10,4432,250,160,6);//LISTO
		rgolpe=new Animacion("recibirGolpe",5,0,3500,170,140,4);//LISTO
		rgolpeF=new Animacion("recibirGolpeF",3,0,3640,180,140,4);//LISTO
		levantarse=new Animacion("levantarse",6,0,3780,180,132,4);//LISTO
		serLanzado=new Animacion("serLanzado",7,6,4840,185,134,4); //LISTO
		festejo=new Animacion("festejo",18,0,5000,300,220,4); //LISTO
		boton = false;
	}
	else if(nombre=="MegaMan" ){
		quieto = new Animacion("quieto",6,0,0,90,75,10);//LISTO
		moverDerecha = new Animacion("movDerecha",12,0,75,90,75,4);//LISTO
		moverIzquierda = new Animacion("movIzquierda",12,0,150,90,75,4);//LISTO
		salto = new Animacion("salto",13,0,260,90,115,6);//LISTO
		agacharse = new Animacion("agacharse",8,0,585,90,65,2);//LISTO
		cambioEntrada = new Animacion("cambioEntrada",12,0,375,90,147,2);//LISTO
		golpeS=new Animacion("golpeS",4,0,750,115,75,6);//golpe simple//LISTO
		patadaS=new Animacion("patadaS",4,0,880,110,80,8);//patada simple//LISTO
		golpeSaltando=new Animacion("golpeSaltando",9,0,1275,110,140,8);//golpe saltando//LISTO
		golpeSaltandoF=new Animacion("golpeSaltandoF",9,0,1680,100,140,8);//golpe saltando//LISTO
		patadaSaltando=new Animacion("patadaSaltando",9,0,1445,110,140,8);//patada saltando//LISTO
		patadaSaltandoF=new Animacion("patadaSaltandoF",9,0,3941,110,140,8);//patada saltando//LISTO
		golpeF=new Animacion("golpeF",8,0,1680,100,140,8);//golpe fuerte//LISTO
		patadaF=new Animacion("patadaF",8,0,1900,100,95,6);//patada fuerte//LISTO
		golpeA=new Animacion("golpeA",4,0,1105,110,65,8);//golpe agachado//LISTO
		patadaA=new Animacion("patadaA",5,0,1170,110,65,8);//patada agachado//LISTO
		golpeAF=new Animacion("golpeAF",4,0,4423,110,65,8);//golpe agachado fuerte
		patadaAF=new Animacion("patadaAF",5,0,4490,110,65,8);//patada agachado fuerte

		defensa=new Animacion("defensa",4,0,965,90,83,8);//LISTO
		disparo=new Animacion("disparar",11,0,2160,105,80,2);//LISTO
		tiro=new Animacion("tirar",10,3,2912,100,75,6);
		rgolpe=new Animacion("recibirGolpe",4,0,2380,85,90,4);//LISTO
		rgolpeF=new Animacion("recibirGolpeF",6,0,2465,105,85,4);//LISTO
		levantarse=new Animacion("levantarse",7,0,2600,90,100,4);//LISTO
		serLanzado=new Animacion("serLanzado",10,3,3025,116,90,3);//LISTO
		festejo=new Animacion("festejo",8,0,3812,150,95,3);//LISTO
		boton = false;
	}
	else if(nombre=="Hulk" ){
		quieto = new Animacion("quieto",8,0,0,170,130,10);
		moverDerecha = new Animacion("movDerecha",16,0,130,170,150,4);
		moverIzquierda = new Animacion("movIzquierda",16,0,285,170,150,4);
		salto = new Animacion("salto",10,0,580,170,215,6);
		agacharse = new Animacion("agacharse",5,0,450,170,123,4);
		cambioEntrada = new Animacion("cambioEntrada",8,0,1119,170,248,3);
		golpeS=new Animacion("golpeS",5,0,450,170,123,4);//golpe simple
		patadaS=new Animacion("patadaS",5,0,450,170,123,4);//patada simple
		golpeSaltando=new Animacion("golpeSaltando",5,0,450,170,123,4);//golpe saltando
		golpeSaltandoF=new Animacion("golpeSaltandoF",5,0,450,170,123,4);//golpe saltando
		patadaSaltando=new Animacion("patadaSS",5,0,450,170,123,4);//patada saltando
		patadaSaltandoF=new Animacion("patadaSS",5,0,450,170,123,4);//patada saltando
		golpeF=new Animacion("golpeF",3,0,1032,225,172,8);//golpe fuerte
		patadaF=new Animacion("patadaF",6,0,1204,225,172,6);//patada fuerte
		golpeA=new Animacion("golpeA",3,0,1548,225,172,8);//golpe agachado
		patadaA=new Animacion("patadaA",4,0,1376,225,172,16);//patada agachado
		defensa=new Animacion("defensa",1,1,1,1,1,1);
		disparo=new Animacion("disparar",8,0,3268,225,172,8);
		tiro=new Animacion("tirar",6,0,3440,225,172,8);
		rgolpe=new Animacion("recibirGolpe",3,0,4128,225,172,8);
		rgolpeF=new Animacion("recibirGolpeF",5,1295,5191,179,115,20);
		levantarse=new Animacion("levantarse",3,850,5170,112,140,20);
		serLanzado=new Animacion("serLanzado",7,1494,1752,126,252,3);
		festejo=new Animacion("festejo",7,1494,1752,126,252,3);
		boton = false;
	}
	else if(nombre=="SinSprite" ){
		quieto = new Animacion("quieto",1,0,0,600,600,10);
		moverDerecha = new Animacion("movDerecha",1,0,0,600,600,4);
		moverIzquierda = new Animacion("movIzquierda",1,0,0,600,600,4);
		//cambioSalida = new Animacion("cambioSalida",1,0,0,600,600,4);
		cambioEntrada = new Animacion("cambioEntrada",1,0,0,600,600,4);
		salto = new Animacion("salto",1,0,0,600,600,10);
		agacharse = new Animacion("agacharse",1,0,0,600,600,2);
		golpeS=new Animacion("golpeS",1,0,0,600,600,2);//golpe simple
		patadaS=new Animacion("patadaS",1,0,0,600,600,2);//patada simple
		golpeSaltando=new Animacion("golpeSaltando",1,0,0,600,600,2);//golpe saltando
		golpeSaltandoF=new Animacion("golpeSaltandoF",1,0,0,600,600,2);//golpe saltando
		patadaSaltando=new Animacion("patadaSS",1,0,0,600,600,2);//patada saltando
		patadaSaltando=new Animacion("patadaSS",1,0,0,600,600,2);//patada saltando
		golpeF=new Animacion("golpeF",1,0,0,600,600,10);//golpe fuerte
		patadaF=new Animacion("patadaF",1,0,0,600,600,10);//patada fuerte
		golpeA=new Animacion("golpeA",1,0,0,600,600,10);//golpe agachado
		patadaA=new Animacion("patadaA",1,0,0,600,600,10);//patada agachado
		defensa=new Animacion("defensa",1,0,0,600,600,10);
		disparo=new Animacion("disparar",1,0,0,600,600,10);
		tiro=new Animacion("tirar",1,0,0,600,600,10);
		rgolpe=new Animacion("recibirGolpe",1,0,0,600,600,10);
		rgolpeF=new Animacion("recibirGolpeF",5,1295,5191,179,115,20);
		levantarse=new Animacion("levantarse",3,850,5170,112,140,20);
		serLanzado=new Animacion("serLanzado",7,1494,1752,126,252,3);
		festejo=new Animacion("festejo",7,1494,1752,126,252,3);
		boton = false;
	}
	if(!boton){
		animaciones.push_back(disparo);
		animaciones.push_back(tiro);
		animaciones.push_back(rgolpe);
		animaciones.push_back(rgolpeF);
		animaciones.push_back(levantarse);
		animaciones.push_back(defensa);

		animaciones.push_back(golpeS);
		animaciones.push_back(golpeF);
		animaciones.push_back(golpeA);
		animaciones.push_back(golpeSaltando);
		animaciones.push_back(golpeSaltandoF);

		animaciones.push_back(golpeAF);
		animaciones.push_back(patadaAF);
		animaciones.push_back(patadaS);
		animaciones.push_back(patadaF);
		animaciones.push_back(patadaA);
		animaciones.push_back(patadaSaltando);
		animaciones.push_back(patadaSaltandoF);

		animaciones.push_back(quieto);
		animaciones.push_back(moverDerecha);
		animaciones.push_back(moverIzquierda);
		animaciones.push_back(salto);
		animaciones.push_back(agacharse);
		animaciones.push_back(cambioEntrada);
		animaciones.push_back(serLanzado);
		animaciones.push_back(festejo);
		animacionActual = quieto;
		return;
	}
	if(nombre=="CapitanAmericaArrojable"){
		arrojable = new Animacion("arrojar",3,950,1560,175,30,5);
		Animacion* escudo = new Animacion("regresoEscudo",4,1550,1550,50,45,5);
		animaciones.push_back(arrojable);
		animaciones.push_back(escudo);
		return;
	}
	else if(nombre=="SpidermanArrojable"){
			arrojable = new Animacion("arrojar",7,1080,2510,90,40,5);
			animaciones.push_back(arrojable);
			return;
		}
	else if(nombre=="VenomArrojable"){
			arrojable = new Animacion("arrojar",7,250,3415,50,35,5);
			animaciones.push_back(arrojable);
			return;
		}
	else if(nombre=="MegaManArrojable"){
			arrojable = new Animacion("arrojar",7,500,2271,125,85,5);
			animaciones.push_back(arrojable);
			return;
		}

	if(nombre=="CapitanAmericaBoton"){
		mouseOut = new Animacion("mouseOut",1,0,0,159,129,10);
		mouseOver = new Animacion("mouseOver",1,160,0,159,129,10);
		mouseDown = new Animacion("mouseDown",1,319,0,159,129,10);
		mouseUp = new Animacion("mouseUp",1,478,0,159,129,10);
	}
	else if(nombre=="SpidermanBoton"){
		mouseOut = new Animacion("mouseOut",1,0,0,170,138,10);
		mouseOver = new Animacion("mouseOver",1,171,0,170,138,10);
		mouseDown = new Animacion("mouseDown",1,342,0,170,138,10);
		mouseUp = new Animacion("mouseUp",1,513,0,170,138,10);
	}
	else if(nombre=="HulkBoton"){
		mouseOut = new Animacion("mouseOut",1,0,0,164,129,10);
		mouseOver = new Animacion("mouseOver",1,165,0,164,129,10);
		mouseDown = new Animacion("mouseDown",1,330,0,164,129,10);
		mouseUp = new Animacion("mouseUp",1,495,0,164,129,10);

	}
	else if(nombre=="MegaManBoton"){
		mouseOut = new Animacion("mouseOut",1,0,0,164,129,10);
		mouseOver = new Animacion("mouseOver",1,165,0,164,129,10);
		mouseDown = new Animacion("mouseDown",1,330,0,164,129,10);
		mouseUp = new Animacion("mouseUp",1,495,0,164,129,10);
	}
	else if(nombre=="VenomBoton"){
		mouseOut = new Animacion("mouseOut",1,0,0,175,145,10);
		mouseOver = new Animacion("mouseOver",1,176,0,175,145,10);
		mouseDown = new Animacion("mouseDown",1,352,0,175,145,10);
		mouseUp = new Animacion("mouseUp",1,528,0,175,145,10);
	}
	else if(nombre=="SinSpriteBoton"){
		mouseOut = new Animacion("mouseOut",1,0,0,71,61,10);
		mouseOver = new Animacion("mouseOver",1,72,0,71,61,10);
		mouseDown = new Animacion("mouseDown",1,144,0,71,61,10);
		mouseUp = new Animacion("mouseUp",1,216,0,71,61,10);
	}else {
		mouseOut = new Animacion("mouseOut",1,0,0,175,145,10);
		mouseOver = new Animacion("mouseOver",1,175,0,175,145,10);
		mouseDown = new Animacion("mouseDown",1,350,0,175,145,10);
		mouseUp = new Animacion("mouseUp",1,525,0,175,145,10);
	}
	animaciones.push_back(mouseOut);
	animaciones.push_back(mouseOver);
	animaciones.push_back(mouseDown);
	animaciones.push_back(mouseUp);
	animacionActual = mouseOut;
}

bool SpriteAnimado::iniciarAnimacion(string nombre){
	string nombreAnimacion = animacionActual->getNombre();
	if(nombre!="recibirGolpeF"&&(nombreAnimacion=="cambioEntrada"|| nombreAnimacion=="disparar"|| nombreAnimacion=="recibirGolpeF"||nombreAnimacion=="recibirGolpe"||nombreAnimacion=="tirar"||nombreAnimacion=="serLanzado"))
		return false;


//	if(animacionActual->getNombre() == "festejo") return false;
	if( animacionActual->getNombre() != nombre || nombre=="quieto")
		cambiarAnimacion(nombre);

	return true;
}

void SpriteAnimado::cambiarAnimacion(string nombre){
	sonidoEnviado = false;
	for(Uint8 i=0; i<animaciones.size();i++){
		if(animaciones[i]->getNombre() == nombre )
			animacionActual = animaciones[i];
	}
	frameIndex = 0;
}

void SpriteAnimado::update(){
	if( regulador < animacionActual->getVelocidad()){
		regulador++;
		return;
	}
	if (frameIndex < animacionActual->getFrames() - 1 )
		frameIndex++;
	else{
		string nombreAnimacion = animacionActual->getNombre();
		if(nombreAnimacion=="agacharse" || nombreAnimacion=="defensa")
			return;
		frameIndex=0;
		if(nombreSprite == "CapitanAmerica" && nombreAnimacion=="disparar")
			cambiarAnimacion("atraparEscudo");
		else if(nombreAnimacion=="golpeA" || nombreAnimacion=="patadaA" || nombreAnimacion=="golpeAF" || nombreAnimacion=="patadaAF" )
			cambiarAnimacion("agacharse");
		else if(nombreAnimacion=="recibirGolpeF" ||nombreAnimacion=="serLanzado" )
			cambiarAnimacion("levantarse");
		else if(nombreAnimacion!="movDerecha" && nombreAnimacion!="movIzquierda")
			cambiarAnimacion("quieto");
	}
	regulador = 0;
}

int SpriteAnimado::getFrameIndex(){
	return this->frameIndex;
}

SDL_Rect SpriteAnimado::rectOrigen(){
	return animacionActual->getRectOrigen(this->frameIndex);
}

string SpriteAnimado::getSonido(){
	if(!sonidoEnviado){
		sonidoEnviado=true;
		return controladorSonido->getSonidoAnimacion(nombreSprite, animacionActual->getNombre());
	}
	return "";
}
