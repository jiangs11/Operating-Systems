#include "console.h"

void terminal_print_line(char* str) {
  // Keeps track of number of times this function was called
  // Used to calculate which line to begin printing
  numTimesCalled++;
  
	unsigned int i = 0;

	while (str[i] != '\0') {
		VGA_MEMORY[cursor] = str[i];
		VGA_MEMORY[cursor+1] = 0x07;
		i++;
		cursor = cursor + 2;
	}
  
  // Calculate the cursor's next starting position
  cursor = 2 * VGA_WIDTH * numTimesCalled;
}

void scroll() {
	// Go through the entire memory, looking for non-null characters, and
	// shift all the lines up by one.
  // 753664 is the length of the entire memory
	for (int i = 0; i < 753664; i++)
	{
		if (VGA_MEMORY[i] != '\0')
		{
      // Moves the current element up 160 bytes which is exactly one line
			VGA_MEMORY[i - 2 * VGA_WIDTH] = VGA_MEMORY[i];
			// Set old place to null
			VGA_MEMORY[i] = '\0';
		}
	}
}

void putchar(char i) {
  VGA_MEMORY[cursor] = i;
  VGA_MEMORY[cursor+1] = 0x07;
  cursor = cursor + 2;
}