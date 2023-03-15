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

void allocate(�onstellation** cns);
void cfree(�onstellation** cns);

void cnst_table(�onstellation* cns);
void read_data(�onstellation* cns);
void print_data(�onstellation* cns, int n);
void choice(�onstellation* cns);
#endif
