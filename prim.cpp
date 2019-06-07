
#include<stdio.h>
#include<conio.h>
int a, b, n, i, j, ne = 1, x;
int visited[10] = { 0 }, min, mincost = 0, cost[10][10];
FILE *f;
void main()

{
	printf("\nEnter the number of nodes:");
	scanf("%d", &n);
	f = fopen("graf.txt", "r");
	if (f){
		printf("Fisierul a fost deschis cu succes \n");
		for (i = 1; i <= n; i++)
		for (j = 1; j <= n; j++)
		{
			fscanf(f, "%d", &cost[i][j]); // unde nu avem muchie avem 999

		}
	}
	fclose(f);
	printf("Introduceti nodul de inceput \n");
	scanf("%d", &x);
	visited[x] = 1;

	while (ne < n)
	{
		for (i = 1; i <= n;i++)
		for (j = 1; j <= n; j++)
		{
			if (cost[i][j] < min)
			if (visited[i] == 0)
			{
				min = cost[i][j];
				a = i;
				b = j;
			}
		}

		if (visited[a] == 0 || visited[b] == 0)
		{
			printf("Muchia %d este %d-%d, cost: %d", ne++, a, b, min);
			mincost += min;
			visited[b] = 1;

		}

		cost[a][b] = cost[b][a] = 999;
		
	}
	printf("\n Minimun cost=%d", mincost);
	_getch();

}
