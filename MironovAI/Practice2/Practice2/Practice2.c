#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>


int random_function(int start, int end)
{
	int n;

	

	n = start + rand() % (end - start + 1);

	return n;
}


int main() {

	int guess, n, mode, w;

	n = random_function(1, 1000);
	printf("Witch of this game mode do u want to choose: Input 1 or 2   ");
	scanf("%i", &mode);


	
	
	if (mode == 1) {

		int c = 0, number;

	

		while (c == 0) {

			printf("Input a  number. Can u guess it now?");
			scanf("%d", &number);

			while (number > 1000 || number < 0) {
				printf("Input a number from 0 to 1000   ");
				scanf("%d", &number);
			}


			if (number == n) {
				c = 1;
				printf("You are a winner! Congretulations! ");
			}
			else {

				if (number < n) printf("Your number is smoller   ");
				else printf("Your number is too huge    ");
				
					
			}


		}

	}
	else {
		int n1, number, r = 1000, l = 1, z = 0;
		char q;
		
		printf("Input a number and I`ll try to guess it   ");
		scanf("%d", &number);
		getchar();

		while (z == 0) {

					
			n1 = random_function(l, r);

			printf("Print >, < or = if my variant is bigger or smoller pls \n ");
			printf("It is a my number:\n %d", n1);
			printf("It is bigger, smoller or mb i guessed? \n");
			scanf("%c", &q);
			getchar();
			
			
			if (q == '>') r = n1;

			else if (q == '<') l = n1;

			else if (q == '=') {
				printf("I new that! GG");
				z = 1;
			}
			
			
		}

		
		


	}


	
	return 0;
}