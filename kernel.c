#include "./shell/console.h"
#include "./io/io.h"

void kernel_early(void) {
}

int main(void) {

  unsigned char byte;
  char str[1000];
  int i = 0;
  
  while (1) {
    while( byte = scan()) {
      str[i] = charmap[byte];
      str[++i] = '\0';
      
      putchar(charmap[byte]);
          
      // Only start checking when we have at least 4 characters inputted
      if (i > 3) {
        // Start from the first character of the last four inputted characters
        int j = i - 4;
        
        while (str[j] != '\0') {
          // Stop when the last four inputted characters are 'e', 'x', 'i', 't' respectively
          if (str[j] == 'e' && str[j+1] == 'x' && str[j+2] == 'i' && str[j+3] == 't') {
              terminal_print_line("Goodbye!");
              return 0;
          }
          j++;
        }
      }
    }
  }
}