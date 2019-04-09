#include <iostream>
using namespace std;

int knapsack(int W, int wt[], int b[], int n)
{
	// tabela V que será preenchida
	int V[n + 1][W + 1];

	// inicializa a primeira linha e primeira coluna com 0
	for(int w = 0; w <= W; w++)
		V[0][w] = 0;
	for(int i = 1; i <= n; i++)
		V[i][0] = 0;

	for(int i = 1; i <= n; i++)
	{
		for(int w = 1; w <= W; w++)
		{	
			// elementos podem fazer parte da solução
			if(wt[i - 1] <= w)
			{
				// max...
				if((b[i - 1] + V[i - 1][w - wt[i - 1]]) > V[i - 1][w])
					V[i][w] = b[i - 1] + V[i - 1][w - wt[i - 1]];
				else
					V[i][w] = V[i - 1][w];
			}
			else
				V[i][w] = V[i - 1][w]; // wi > w
		}
	}

	// retorna o valor máximo colocado na mochilaa
	return V[n][W];
}

int main(int argc, char *argv[])
{
	// capacidade máxima da mochila
	int CapacidadeMochila = 35;

	// número de elementos
	int n_elementos = 5;

	// vetor com os valores de cada elemento
	int V_valores[] = {7, 9, 6, 10, 8};

	// vetor com os pesos de cada elemento
	int V_pesos[] = {10, 15, 4, 20, 5};

	// obtém o máximo valor que pode ser colocado na mochila
	int max_valor = knapsack(CapacidadeMochila, V_pesos, V_valores, n_elementos);

	cout << "Valor maximo: " << max_valor << endl;

	return 0;
}