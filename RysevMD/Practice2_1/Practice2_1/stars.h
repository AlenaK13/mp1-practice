#ifndef _Star
#define _Star

typedef struct {
	char name[50];
	float dist;
	float magnitude;
	float deg;
	float min;
	float sec;
}Star;

typedef struct {
	char name[50];
	Star* stars;
}�onstellation;

void Callocate(�onstellation** cns, int c);
void Sallocate(Star** st, int c);
void cfree(�onstellation** cns);

void cnst_table(�onstellation* cns);
void read_data(�onstellation** cns);
void print_data(�onstellation* cns, int n);
void choice(�onstellation* cns);
#endif
