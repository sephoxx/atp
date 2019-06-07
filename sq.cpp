#include<stdio.h>
#include<conio.h>
#pragma warning (disable:4996)
void quicksort(int v[], int n, int stanga, int dreapta)
{
	int i, j, mijloc, aux;
	i = stanga;
	j = dreapta;
	mijloc = v[(stanga + dreapta) / 2];
	while (i <= j)
	{
		while (v[i]<mijloc)
			i = i + 1;
		while (v[j]>mijloc)
			j = j - 1;
		if (i <= j)
		{
			aux = v[i];
			v[i] = v[j];
			v[j] = aux;
			i = i + 1;
			j = j - 1;
		}
	}
	if (stanga<j) quicksort(v, n, stanga, j);
	if (i<dreapta) quicksort(v, n, i, dreapta);
}
void main()
{
	int v[100], n, i;
	printf("n= ");
	scanf("%d", &n);
	for (i = 0; i<n; i++)
	{
		printf("v[%d]= ", i);
		scanf("%d", &v[i]);
	}
	quicksort(v, n, 0, n - 1);
	printf("Vectorul sortat prin QuickSort este \n");
	for (i = 0; i<n; i++)
		printf(" %d ", v[i]);
	_getch();
}