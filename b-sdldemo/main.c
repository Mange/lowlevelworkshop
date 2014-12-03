#import <stdio.h>
#import <SDL2/SDL.h>
#import <SDL2/SDL_video.h>
#import <SDL2/SDL_shape.h>

#import "main.h"

#define RESOLUTION_X 2880
#define RESOLUTION_Y 1800

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
  SDL_Window* window;
  SDL_Renderer* renderer;

  if (SDL_CreateWindowAndRenderer(RESOLUTION_X, RESOLUTION_Y, SDL_WINDOW_FULLSCREEN | SDL_WINDOW_ALLOW_HIGHDPI, &window, &renderer) != 0) {
    printf("Cannot create window or renderer: %s\n", SDL_GetError());
    die();
  }

  SDL_Delay(5000);

  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
}
