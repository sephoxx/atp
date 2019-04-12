// ConsoleApplication2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

int *count_sort(int *toSort, int n, int maxi)
{
	int i, *countArr, *sorted;

	countArr = new int[maxi + 1];
	sorted = new int[n + 1];

	for (i = 0; i <= maxi; i++)
		countArr[i] = 0;

	for (i = 0; i < n; i++)
	{
		countArr[toSort[i]]++;
	}

	for (i =0; i <= maxi; i++)
	{
		countArr[i + 1] += countArr[i];
	}

	//for (i = 1; i <= maxi; i++)
		//printf("%d\n", countArr[i]);

	for (i = 0; i < n; i++)
	{
		sorted[countArr[toSort[i]]] = toSort[i];
		countArr[toSort[i]]-= 1;
		//for (int j = 1; j <= maxi; j++)
			//printf("%d\n", countArr[j]);

	}



	return sorted;
}

int main()
{

	FILE *f;
	char inName[30], outName[30];
	char *c = (char*)malloc(sizeof(char));
	int n, i, *before, val, maxi, *sorted;
	 
	maxi = 0;

	printf("Input file name to import from:\n");
	scanf("%s", inName);
	printf("\nInput file name to output to:\n");
	scanf("%s", outName);

	fopen_s(&f, inName, "r");
	fgets(c, 1000, f);
	n = atoi(c);
	
	before = new int[n];
	sorted = new int[n + 1];

	for (i = 0; i < n; i++)
	{
		fgets(c, 1000, f);
		val = atoi(c);
		if (val > maxi)
			maxi = val;
		before[i] = val;
	}



	fclose(f);
	sorted = count_sort(before, n, maxi);
	
	fopen_s(&f, outName, "w");

	fprintf(f, "%d\n", n);

	for (i = 1; i <= n; i++)
		fprintf(f, "%d\n", sorted[i]);
		
	fclose(f);

	printf("\nNumbers sorted successfully!");
	_getch();
}

