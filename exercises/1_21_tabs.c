#include <stdio.h>

// entab: replaces strings of blanks with tabs and any extra spaces necessary
int main()
{
	unsigned int tab_width = 8; // this value is effectively ignored if set to < 2
	int sequential_blank_count = 0;
	char c;


	while ((c = getchar()) != EOF) {
		if (c == ' ') {
			sequential_blank_count++;
			if (sequential_blank_count >= 2 && sequential_blank_count == tab_width) {
				putchar('\t');
				sequential_blank_count = 0;
			}
		} else {
			for (int i = 0; i < sequential_blank_count; ++i)
				putchar(' ');
			sequential_blank_count = 0;
			putchar(c);
		}
	}

	return 0;

}
