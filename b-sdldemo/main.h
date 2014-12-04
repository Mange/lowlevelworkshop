int main(int, char**);
void setup();
void teardown();
void run();
void demoscene();
void handle_events();
void update();
void render();
void die();
void print_sdl_error(char *);

void init_demostate();

struct {
  int quit;
} demostate;
