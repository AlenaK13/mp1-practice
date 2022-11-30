#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define N 5
#define M 10
#include <stdlib.h>


int main() {
	int a[N] = { 0 };
	int u_a[N] = { 0 };
	int k, i, j, user_n;
	int flag, flag1, tmp, check_t, check_d;
	int bulls, cows, attempts;

	printf("Input k ");
	scanf ("%d", &k);
	while ((k<2) ||(k>5)) {
		printf("Incorrect data. Try again. Input 2 < k < 5 ");
		scanf ("%d", &k);
	}

	srand((unsigned int)time(NULL));
	a[0] = 1 + rand() % 9;
	for (i = 1; i <= k-1; i++) {
		flag = 1;
		while (flag == 1) {
			flag = 0;
			tmp = rand() % 10;
			for (j = 0; j < i; j++)
				if (tmp == a[j]) {
					flag = 1;
					break;
				}
			if (flag == 0)
				a[i] = tmp;
		}		
	}

	flag = 1;
	attempts = 0;
	check_t = 1;
	for (i = 0; i < k; i++) {
		check_t = check_t * 10;
	}
	check_d = 1;
	for (i = 0; i < k-1; i++) {
		check_d = check_d * 10;
	}
	while (flag == 1) {
		

		printf("Guess the hidden number \n");
		scanf("%d", &user_n);
		while ((user_n < check_d) || (user_n > check_t)) {
			printf("Incorrect data. Try again. Input %d < number < %d. \n", check_d, check_t);
			scanf("%d", &user_n);
		}

		for (i = k - 1; i > -1; i--) {
			u_a[i] = user_n % 10;
			user_n /= 10;
		}

		flag1 = 0;
		for (i = 0; i <= k - 1; i++) {
			for (j = i + 1; j <= k - 1; j++)
				if (u_a[i] == u_a[j]) {
					printf("Incorrect data. Try again. The numbers should not be repeated \n");
					flag1 = 1;
					break;
				}
			if (flag1 == 1)
				break;
		}
		if (flag1 == 1) 
			continue;
		
		bulls = 0;
		cows = 0;
		for (i = 0; i <= k - 1; i++)
			for (j = 0; j <= k - 1; j++)
				if (u_a[i] == a[j])
					if (i == j) 
						bulls += 1;
					else 
						cows += 1;

		if (bulls == k) {
			attempts += 1;
			printf("Congratulations! You guessed the number in %d attempts!", attempts);
			flag = 0;
		}
		else {
			attempts += 1;
			printf("bulls = %d, cows = %d \n", bulls, cows);
		}
	}
	   
	return 0;
}