#include<stdio.h>
#include<conio.h>

FILE *f;
int a[10][10], n, b[10][10];
#define MAX 999

void citire()
{
	f = fopen("graf.txt", "r");
	if (f)
	{
		printf("fisierul a fost deschis cu succes \n");
		fscanf(f, "%d", &n);
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

void RoyFloyd()
{
	printf("Incep RoyFloyd \n");

	for (int i = 1; i <= n;i++)
	for (int j = 1; j <= n; j++)
		b[i][j] = a[i][j];

	for (int i = 1; i <= n;i++)
		for (int j = 1; j <= n;j++)
			if (b[i][j] < MAX)
				for (int k = 1; k <= n;k++)
					if (b[i][k] > b[i][j] + b[j][k])
						b[i][k] = b[i][j] + b[j][k];
}

void afisare()
{
	printf("incep afisarea \n");
	int i, j;
	for (i = 1; i <= n; i++){
		for (j = 1; j <= n; j++)
			printf("%d ", b[i][j]);
		printf("\n");
	}
	
}

void main()
{
	citire();
	RoyFloyd();
	afisare();
	_getch();
}