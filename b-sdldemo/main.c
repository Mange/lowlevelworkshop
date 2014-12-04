#import <stdio.h>
#import <SDL2/SDL.h>
#import <SDL2/SDL_video.h>
#import <SDL2/SDL_shape.h>

#import "main.h"

#define RESOLUTION_X 2880
#define RESOLUTION_Y 1800

int main(int argc, char** argv) {
  setup();
  run();
  teardown();
  return 0;
}

void setup() {
  if(SDL_Init(SDL_INIT_EVERYTHING) != 0) {
    print_sdl_error("Could not initialize SDL");
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

void print_sdl_error(char* message) {
  printf("Error! %s: %s\n", message, SDL_GetError());
}

void run() {
  SDL_Window* window;
  SDL_Renderer* renderer;

  if (
    0 != SDL_CreateWindowAndRenderer(
      RESOLUTION_X,
      RESOLUTION_Y,
      SDL_WINDOW_FULLSCREEN | SDL_WINDOW_ALLOW_HIGHDPI,
      &window, &renderer
    )
  ) {
    print_sdl_error("Cannot create window or renderer");
    die();
  }

  demoscene();

  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
}

void demoscene() {
  int quit = 0;
  SDL_Event event;

  while(!quit) {
    while(SDL_PollEvent(&event)) {
      switch(event.type) {
        case SDL_QUIT:
        case SDL_KEYDOWN:
        case SDL_MOUSEBUTTONDOWN:
          quit = 1;
      }
    }
  }
}
