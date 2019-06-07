#include<stdio.h>
#include<conio.h>

FILE *f;
int a[10][10], n, b[10][10];

void citire()
{
	f = fopen("graf.txt", "r");
	if (f)
	{
		printf("Fisierul a fost deschis cu succes! \n");
		fscanf(f, "%d", &n);

		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= n; j++)
			{
				fscanf(f, "%d", &a[i][j]);
				printf("%d", a[i][j]);
			}
			printf("\n ");
		}
	}
	fclose(f);
	printf("\n");
}

void afisare()
{
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++)
		{
			printf("%d", b[i][j]);
		}
		printf("\n");
	}
}

void RoyWarshall()
{
	int i, j, k;
	for (i = 1; i <= n;i++)
		for (j = 1; j <= n; j++)
		b[i][j] = a[i][j];

	for (i = 1; i <= n;i++)
		for (j = 1; j <= n;j++)
			if (b[i][j])
				for (k = 1; k <= n;k++)
					if (b[i][k] < b[k][j])
						b[i][k] = b[k][j];
}

void main()
{
	citire();
	RoyWarshall();
	afisare();
	_getch();
}