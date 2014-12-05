#import <stdio.h>
#import <time.h>

#import <SDL2/SDL.h>
#import <SDL2/SDL_video.h>
#import <SDL2/SDL_shape.h>

#import "main.h"
#import "utils.h"

#define RESOLUTION_X 2880
#define RESOLUTION_Y 1800

int main(int argc, char** argv) {
  srand(time(NULL));

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

  demoscene(renderer);

  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
}

void demoscene(SDL_Renderer* renderer) {
  init_demostate();
  while(!demostate.quit) {
    handle_events();
    update();
    render(renderer);
  }
}

void init_demostate() {
  demostate.quit = 0;

  demostate.a_x = random_int(RESOLUTION_X);
  demostate.a_y = random_int(RESOLUTION_Y);

  demostate.b_x = random_int(RESOLUTION_X);
  demostate.b_y = random_int(RESOLUTION_Y);
}

void handle_events() {
  SDL_Event event;

  while(SDL_PollEvent(&event)) {
    switch(event.type) {
      case SDL_QUIT:
      case SDL_KEYDOWN:
      case SDL_MOUSEBUTTONDOWN:
        demostate.quit = 1;
    }
  }
}

void update() {
  demostate.b_x += random_int_range(-2, 2);
  demostate.b_y += random_int_range(-2, 2);
}

void render(SDL_Renderer* renderer) {
  SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
  SDL_RenderClear(renderer);

  SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
  SDL_RenderDrawLine(renderer, demostate.a_x, demostate.a_y, demostate.b_x, demostate.b_y);

  SDL_RenderPresent(renderer);
}
