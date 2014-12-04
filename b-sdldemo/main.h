int main(int, char**);
void setup();
void teardown();
void run();
void demoscene(SDL_Renderer*);
void handle_events();
void update();
void render(SDL_Renderer*);
void die();
void print_sdl_error(char*);

void init_demostate();

int random_int(int);
int random_int_range(int, int);

struct {
  int quit;

  int a_x;
  int a_y;

  int b_x;
  int b_y;
} demostate;
