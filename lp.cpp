#include <stdio.h>
#include <conio.h>

int prim, ultim, varf, c[10], v[10], a[10][10], n, m;
FILE *f;

void citireGraf()
{
	f = fopen("graf.txt", "r");
	if (f)
	{
		printf("Deschiderea fisierului a avut succes \n");
		fscanf(f, "%d", &n);
		fscanf(f, "%d", &m);
		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= n; j++)
			{
				fscanf(f, "%d", &a[i][j]);
				printf("%d ", a[i][j]);
			}
			printf("\n");
		}


	}
}

void parcurgere()
{
	while (prim <= ultim)
	{
		varf = c[prim];
		for (int k = 1; k <= n; k++)
		{
			if (a[varf][k] == 1 && !v[k])
			{
				ultim++; 
				c[ultim] = k;
				v[k] = 1;

			}
		}
		prim++;

	}
}


void main()
{
	int i, j;
	citireGraf();
	int nd;
	prim = ultim = 1;
	printf("Introduceti nodul de inceput \n");
	scanf("%d", &nd);
	v[nd] = 1;
	c[prim] = nd;
	parcurgere();
	for (int i = 1; i <= ultim; i++)
		printf("%d ", c[i]);
	_getch();
}
