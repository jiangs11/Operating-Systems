static char* const VGA_MEMORY = (char*) 0xb8000;

static const int VGA_WIDTH = 80;
static const int VGA_HEIGHT = 25;
static unsigned int cursor = 0;
static unsigned int numTimesCalled = 0;

void terminal_print_line(char* str);
void scroll();
void putchar(char);