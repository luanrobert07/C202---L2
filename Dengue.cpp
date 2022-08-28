#include <iostream> // Entrada e sa?da
#include <climits> // INT_MAX
#include <algorithm> // next_permutation
using namespace std;

int main()
{
	int custo[100][100]; // 100 -> numero maximo de focos
						 // custo[i][j] = custo de ir do foco 'i' para o foco 'j'
	int n; // numero de focos
	int foco_inicial;
	
	cin >> n;

	for(int i = 0;i < n;i++)
		for(int j = i+1;j < n;j++)
		{
			cout << "Entre com o custo de ir da cidade " << i << " para a cidade " << j << endl;
			cin >> custo[i][j];
			custo[j][i] = custo[i][j];
		}
	cin >> foco_inicial;
	
	
	int v[100]; // vetor com o numero de focos a serem permutadas
	int p; // var. auxiliar
	int menor_custo; // menor custo 
	int custo_caminho; // custo do caminho
	
	// colocando os focos que serao permutadas no vetor (todas exceto a inicial)
	p = 0;
	for(int i = 0;i < n;i++)
		if(i != foco_inicial)
		{
			v[p] = i;
			p++;
		}

	// forca bruta
	menor_custo = INT_MAX; // inicializo o custo com infinito
	do
	{
		custo_caminho = custo[foco_inicial][v[0]]; // custo do caminho inicial -> v[0]
		
		for(int i = 0;i < n-2;i++) // somar custo de v[0]->v[1]->v[2]...v[n-3]->v[n-2]
			custo_caminho += custo[v[i]][v[i+1]];
		
		custo_caminho += custo[v[n-2]][foco_inicial]; // custo v[n-2] -> local inicial
		
		menor_custo = min(menor_custo,custo_caminho);
	}while(next_permutation(v,v+(n-1))); // n-1 = numero de focos a serem permutadas

	cout << "Menor custo = " << menor_custo << endl;
	return 0;
}
