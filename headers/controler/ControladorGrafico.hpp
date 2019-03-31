#ifndef CONTROLADORGRAFICO_HPP_
#define CONTROLADORGRAFICO_HPP_

#include <map>
#include <string>
#include <SDL2/SDL_image.h>

using namespace std;

struct SDL_Window;
struct SDL_Renderer;



class ControladorGrafico{
	public:
		ControladorGrafico();
		~ControladorGrafico();

		/*SDL_Surface* loadImage
		 * Carga una imagen al mapa de spritesheets si no existe todavia
		 * Entonces cada imagen solo se carga una vez
		 * Devuelve la imagen haya sido cargada recien o anteriormente
		 */
		SDL_Surface* cargarImagen(const string &filePath);

		/*void dibujarImagen
		 * Dibuja una textura en la pantalla
		 */

		void dibujarImagen(SDL_Texture* source, SDL_Rect* rectanguloOrigen, SDL_Rect* rectanguloDestino);

		void render();

		/*void limpia
		 * limpia la imagen
		 */
		void limpiar();
		/* SDL_Renderes getRenderer
		 * Returns the renderer
		 */

		SDL_Renderer* getRenderer() const;

	private:
		SDL_Window* _window;
		SDL_Renderer* _renderer;
		map<string, SDL_Surface*> _spriteSheets;
};




#endif
