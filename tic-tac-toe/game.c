#include<stdio.h>
#include<stdlib.h>

struct gameBoardCell 
{
	int position;
	char character;
}inputValue();

void run();
void Display(char[9]);
int checkBoard(char[9], char, int);

int main() 
{
	char reStart;
	again:
	run();
	printf("\nTo play again press 1 and enter \notherwise hit any key: ");
	scanf("%s", &reStart);
	if(reStart == '1')
	{
		system("cls");
		goto again;
	}	
	else
	{
		exit(0);
	}
	return 0;	
}

void run() 
{
	//TODO: rework and rename symbols to be a 2d array and call it board or something

	int count = 0;
	struct gameBoardCell info;
	char symbols[9] = {'1','2','3','4','5','6','7','8','9'};
	Display(symbols);
	
	nextTurn:
	info = inputValue(symbols, count);
	symbols[info.position] = info.character;
	system("cls");
	Display(symbols);
	if(checkBoard(symbols, info.character, count)==1);
	else
	{
		count++;
		goto nextTurn;
	}
}

int checkBoard(char symbols[9], char input, int count)
{
	// TODO: rework checkBoard into one effecitent loop

	// Rows
	for (int i = 0; i < 3; i++)
	{
		if (symbols[i] == input && symbols[i + 1] == input && symbols[i + 2] == input)
		{
			printf("%c WINS!!!", input);
			return 1;
		}
	}
	
	// Columns
	for (int i = 0; i < 3; i++)
	{	
		if (symbols[i] == input && symbols[i + 3] == input && symbols[i + 6] == input)
		{
			printf("%c WINS!!!", input);
			return 1;
		}
	}

	// Diaglonals
	if (symbols[0] == input && symbols[4] == input && symbols[8] == input)
	{
		printf("%c WINS!!!", input);
		return 1;
	}
	else if (symbols[2] == input && symbols[4] == input && symbols[6] == input)
	{		
		printf("%c WINS!!!", input);
		return 1;
	}
	// Check draw
	else if (count == 8) // replace 8 with board size or max turn variable
	{
		printf("DRAW GAME");
		return 1;
	}

	return 0;
}

// take input
struct gameBoardCell inputValue(char symbols[9], int count)
{
	int i;
	char value;
	struct gameBoardCell info;
	
	inputAgain:
	if (count%2 == 0)
	{
		printf("\nEnter your choice X:");
	} 
	else 
	{
		printf("\nEnter your choice O:");
	}

	scanf("%s", &value);

	for (i = 0; i < 9; i++)
	{
		if (value==symbols[i])
		{
			info.position = i;
			if (count%2 == 0)
			{
				info.character = 'X';
			}	
			else
			{
				info.character = 'O';
			}
			break;
		}
		else
		{
			info.position = -1;
			info.character = ' ';
		}
	}
	if (info.position == -1)
	{
		printf("\nInput is not valid");

		goto inputAgain;
	}
	return info;
}


void Display(char symbols[9]) 
{
	printf("\t\t\tT i c   t a c   t o e\n");
	printf( "\n\t\t\t     |     |     ");
	printf("\n\t\t\t  %c  |  %c  |  %c  ",symbols[0],symbols[1],symbols[2]);
	printf( "\n\t\t\t-----|-----|-----");
	printf("\n\t\t\t  %c  |  %c  |  %c  ",symbols[3],symbols[4],symbols[5]);
        printf( "\n\t\t\t-----|-----|-----");	
	printf("\n\t\t\t  %c  |  %c  |  %c  ",symbols[6],symbols[7],symbols[8]);
	printf( "\n\t\t\t     |     |     \n");
	printf("Player 1 Symbol: X\n");
	printf("Player 2 Symbol: O\n");
}
