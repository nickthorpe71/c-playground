#include<stdio.h>

void run();
void Display(char[9]);

int main() {
	run();
	return 0;	
}

void run() {
	char symbols[9] = {'1','2','3','4','5','6','7','8','9'};
	Display(symbols);
}

void Display(char symbols[9]) {
	printf("T i c   t a c   t o e\n");
	printf("Player 1 Symbol: X\n");
	printf("Player 2 Symbol: O\n");
	printf( "\n\t\t\t     |     |     ");
	printf("\n\t\t\t  %c  |  %c  |  %c  ",symbols[0],symbols[1],symbols[2]);
	printf( "\n\t\t\t-----|-----|-----");
	printf("\n\t\t\t  %c  |  %c  |  %c  ",symbols[3],symbols[4],symbols[5]);
        printf( "\n\t\t\t-----|-----|-----");	
	printf("\n\t\t\t  %c  |  %c  |  %c  ",symbols[6],symbols[7],symbols[8]);
	printf( "\n\t\t\t     |     |     ");
}
