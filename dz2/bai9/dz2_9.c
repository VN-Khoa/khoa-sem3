#include <stdio.h>
typedef struct Edge edge;
struct Edge
{
    int Ver_1;
    int Ver_2;
}; // Data structure type by edge
int main(int argc, char **argv)
{
    int n, m;
	int i, j, k;
	printf("The number of vertices:");
	scanf("%d", &n);
	printf("The number of edges:");
	scanf("%d", &m);
	edge E[n];
	int Res[n + 1][n + 1];
	for(i = 0; i < m; i++)
	{
		printf("Ver_1(%d):", i + 1);
		scanf("%d", &E[i].Ver_1);
		printf("Ver_2(%d):", i + 1);
		scanf("%d", &E[i].Ver_2);
	}
    // Initialize result matrix
	for(i = 0; i < n + 1; i++)
	{
		Res[0][i] = i;
		Res[i][0] = i;
	}
    // Process from graph to matrix
	for(i = 1; i < n + 1; i++)
	{	
		for(j = 1; j < n + 1; j++)
		{
			Res[i][j] = 0;
        }
	}
	for(i = 0; i < m; i++)
	{
		Res[E[i].Ver_1][E[i].Ver_2] = 1;
	}
    // Print result to the screen
	for(i = 0; i < n + 1; i++)
	{
		printf("\n");
		for(j = 0; j < n + 1; j++)
		{
			printf("%d ", Res[i][j]);
		}
	}
	return 0;
}