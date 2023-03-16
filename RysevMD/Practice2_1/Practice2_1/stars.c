#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stars.h"

void allocate(�onstellation** cns) {
	(*cns) = (�onstellation*)malloc(sizeof(�onstellation) * 11);
	for (int i = 0; i < 10; i++) {
		(*cns)[i].stars = (Star*)malloc(sizeof(Star) * 6);
	}
}
void cfree(�onstellation** cns) {
	free((*cns)->stars);
	free(*cns);
}

void read_data(�onstellation* cns) {
	FILE* fp;
	fp = fopen("data.txt", "r");
	if (fp == NULL) {
		printf("Empty file");
		return -1;
	}
	for (int i = 0; i < 10; i++) {
		fscanf(fp, "%s", cns[i].name);
		for (int j = 0; j < 5; j++) {
			fscanf(fp, "%s %f %f %f %f %f", cns[i].stars[j].name, &cns[i].stars[j].dist, &cns[i].stars[j].magnitude, &cns[i].stars[j].deg, &cns[i].stars[j].min, &cns[i].stars[j].sec);
		}
	}
	fclose(fp);
}
void print_data(�onstellation* cns, int n) {
	printf("\n%s:\n", cns[n].name);
	for (int j = 0; j < 5; j++) {
		printf("  %  s   %-0.3f   %0.3f   %0.3f�   %0.3f\'   %0.3f\"\n", cns[n].stars[j].name, cns[n].stars[j].dist, cns[n].stars[j].magnitude, cns[n].stars[j].deg, cns[n].stars[j].min, cns[n].stars[j].sec);
	}
	printf("\n");
}

void cnst_table(�onstellation* cns) {
	for (int i = 0; i < 5; i++) {
		printf("%d\. %s \t\t %d\. %s\n", i + 1, cns[i].name, i + 6, cns[i + 5].name);
	}
	printf("\nOutput format:\n\n  name distance magnitude coordinates(deg, min, sec)\n\n");
}
void choice(�onstellation* cns) {
	int num = -1;
	printf("Choose a constellation\n");
	while (num != 0) {
		printf(">> number: ");
		scanf("%d", &num);
		if (num >= 1 && num <= 10)
			print_data(cns, num - 1);
		else if (num != 0)
			printf("Not found\n");
	}
}