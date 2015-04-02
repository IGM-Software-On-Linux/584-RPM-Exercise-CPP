#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#define HEIGHT 800
#define WIDTH 600
#define IMG_PATH "/usr/share/sharkapp/assets/leftshark.png"

int main(int, char**){

	//texture height/width
	int h,w;

	if (SDL_Init(SDL_INIT_VIDEO) != 0){
		std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
		return 1;
	}

	SDL_Window *win = SDL_CreateWindow("Shark world", 5, 5, WIDTH, HEIGHT, SDL_WINDOW_SHOWN);
	if (win == nullptr){
		std::cout << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
		SDL_Quit();
		return 1;
	}

	SDL_Renderer *ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (ren == nullptr){
		SDL_DestroyWindow(win);
		std::cout << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
		SDL_Quit();
		return 1;
	}

	SDL_Texture *img = IMG_LoadTexture(ren, IMG_PATH);
	SDL_QueryTexture(img, NULL, NULL, &w, &h);
	SDL_Rect texr; texr.x = (WIDTH/2) - w/2; texr.y = (HEIGHT/2) - h/2; texr.w = w; texr.h = h;

	SDL_RenderClear(ren);
	SDL_RenderCopy(ren, img, NULL, &texr);
	SDL_RenderPresent(ren);

	SDL_Delay(2000);

	SDL_DestroyTexture(img);
	SDL_DestroyRenderer(ren);
	SDL_DestroyWindow(win);
	SDL_Quit();

	return 0;
}
