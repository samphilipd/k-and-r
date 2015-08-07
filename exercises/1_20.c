#include <stdio.h>

// detab: replace tabs with a specified number of spaces
int main()
{
	int tab_width = 8;
	char c;

	while ((c = getchar()) != EOF) {
		if (c == '\t')
			for (int i = 0; i < tab_width; ++i)
				putchar(' ');
		else
			putchar(c);
	}

	return 0;

}
