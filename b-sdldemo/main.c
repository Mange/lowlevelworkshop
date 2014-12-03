#import <stdio.h>
#import <SDL2/SDL.h>

#import "main.h"

int main(int argc, char** argv) {
  setup();
  teardown();
  return 0;
}

void setup() {
  if(SDL_Init(SDL_INIT_EVERYTHING) != 0) {
    printf("Error. Could not initialize SDL: %s\n", SDL_GetError());
    teardown();
    exit(0);
  }
}

void teardown() {
  SDL_Quit();
}
