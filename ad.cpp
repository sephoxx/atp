#pragma warning( disable: 4996)
#include <stdio.h>
#include <fstream>

#define INF 100000

typedef struct
{
	float cost;
	int pred;
}LABEL;

LABEL* dijkstra(float **w, int n, int v0)
{
	LABEL *r;
	int *a, *b, la, lb, i, poz,j;

	a = new int[n];
	a[0] = v0;
	la = 1;

	b = new int[n - 1];
	lb = 0;
	for (i = 1; i <= n; i++)
		if (i != v0)
			b[lb++] = i;

	r = new LABEL[n];
	for (i = 0; i < n; i++)
		r[i].cost = INF;
	r[v0 - 1].cost = 0;
	r[v0 - 1].pred = -1;

	for (j = 1; j < n; j++)
	{
		for (i = 0; i < lb; i++)
			if (r[b[i] - 1].cost > r[a[la-1] - 1].cost + w[a[la-1] - 1][b[i] - 1])
			{
				r[b[i] - 1].cost = r[a[la-1] - 1].cost + w[a[la-1] - 1][b[i] - 1];
				r[b[i] - 1].pred = a[la - 1];
			}

		poz = 0;
		for (i = 0; i < lb; i++)
			if (r[b[i]-1].cost < r[b[poz]-1].cost)
				poz = i;

		a[la++] = b[poz];

		for (i = poz; i < lb - 1; i++)
			b[i] = b[i + 1];
		lb--;
		
	}
	
	delete a;
	delete b;
	
	return r;
}


int read(char *fname, int *n, int *m, int ***tabel, float **ponderi)
{
	int er, i;

	FILE *f;
	fopen_s(&f, fname, "r");

	if (!f)
		er = 1;
	else
	{
		er = 0;
		fscanf_s(f, "%d %d", n, m);
		*tabel = new int*[*m];
		for (i = 0; i < *m; i++)
			(*tabel)[i] = new int[2];

		*ponderi = new float[*m];

		for (i = 0; i < *m; i++)
			fscanf_s(f, "%d%d%f", &(*tabel)[i][0], &(*tabel)[i][1], &(*ponderi)[i]);

		fclose(f);
	}
	
	return er;
}


float **weights(int n,int m, int **tabel, float *ponderi)
{
	int i, j;
	float **w;

	w = new float*[n];
	for (i = 0; i < n; i++)
		w[i] = new float[n];

	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			w[i][j] = INF;

	for (i = 0; i < m; i++)
		w[tabel[i][0] - 1][tabel[i][1] - 1] = w[tabel[i][1] - 1][tabel[i][0] - 1] = ponderi[i];

	return w;
}


int main()
{
	int i, **tab, nrv, nrm, er;
	float *pon, **mat;
	LABEL *d;
	char fis[50];
	printf("File name: "); 
	scanf("%s", fis);

	er = read(fis, &nrv, &nrm, &tab, &pon);
	mat = weights(nrv,nrm, tab, pon);
	d = dijkstra(mat, nrv, 3);

	for (i = 0; i < nrv; i++)
		printf("%2.0f ", d[i].cost);

	printf("\n");

	for (i = 0; i < nrv; i++)
		printf("%d ", d[i].pred);
	

	printf("\n");

	free(d);
	for (i = 0; i < nrv; i++)
		free(mat[i]);
	free(mat);
	return 0;
}