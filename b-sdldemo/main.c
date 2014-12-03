#import <stdio.h>
#import <SDL2/SDL.h>

#import "main.h"

int main(int argc, char** argv) {
  setup();
  demoscene();
  teardown();
  return 0;
}

void setup() {
  if(SDL_Init(SDL_INIT_EVERYTHING) != 0) {
    printf("Error. Could not initialize SDL: %s\n", SDL_GetError());
    die();
  }
}

void teardown() {
  SDL_Quit();
}

void die() {
  teardown();
  exit(1);
}

void demoscene() {
  SDL_Window* window = SDL_CreateWindow("DEMO SCENE!!!", 100, 100, 640, 480, SDL_WINDOW_SHOWN);
  if (window == NULL) {
    printf("Cannot create window: %s\n", SDL_GetError());
    die();
  }

  SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_ACCELERATED);
  if (renderer == NULL) {
    printf("Cannot create renderer: %s\n", SDL_GetError());
    die();
  }

  SDL_Delay(5000);
}
