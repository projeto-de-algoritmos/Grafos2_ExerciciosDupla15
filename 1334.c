#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

//exercicio 1334 do leetcode

typedef struct {
    int from;
    int to;
    int weight;
} Edge; // Aresta contendo, respectivamente: origem, destino e peso (distancia)

int findTheCity(int n, Edge* edges, int edgeCount, int distanceThreshold) {
    int D[n][n];

    for (int i = 0; i < n; i++) { //inicializa D com os valores maximizados
        for (int j = 0; j < n; j++) {
            D[i][j] = INT_MAX;
        }
    }

    for (int i = 0; i < n; i++) { //a distancia do vertice para ele mesmo eh 0
        D[i][i] = 0;
    }

    for (int i = 0; i < edgeCount; i++) { // define D com o peso(distancia)
        int from = edges[i].from;
        int to = edges[i].to;
        int wt = edges[i].weight;

        D[from][to] = wt;
        D[to][from] = wt;
    }

    for (int k = 0; k < n; k++) { //busca os caminhos mais curtos entre as cidades
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (D[i][k] == INT_MAX || D[k][j] == INT_MAX)
                    continue;
                else if (D[i][k] + D[k][j] < D[i][j])
                    D[i][j] = D[i][k] + D[k][j];
            }
        }
    }

    int minNoOfCity = INT_MAX;
    int res = -1;

    /*contabiliza o total de cidades que estão dentro do alcance (seguindo as distancias)
       para cada cidade                                                            */
    for (int i = 0; i < n; i++) {
        int noCityCount = 0;
        for (int j = 0; j < n; j++) {
            if (i == j)
                continue;
            if (D[i][j] <= distanceThreshold)
                noCityCount++;
        }
        if (noCityCount <= minNoOfCity) {
            minNoOfCity = noCityCount;
            res = i;
        }
    }

    return res;
}

int main() {
    int n;
    printf("Informe o total de cidades: ");
    scanf("%d", &n);

    int maxEdges = n * (n - 1) / 2; //total de arestas para grafo completamente conectado
    Edge* edges = (Edge*)malloc(maxEdges * sizeof(Edge));
    int edgeCount = 0;
    int from, to, weight;

    printf("Informe, em ordem, ORIGEM, DESTINO, DISTANCIA:  (Insira CTRL + Z para poder inserir o limite)\n");
    while (scanf("%d %d %d", &from, &to, &weight) == 3) {
        edges[edgeCount].from = from;
        edges[edgeCount].to = to;
        edges[edgeCount].weight = weight;
        edgeCount++;
    }

    int distanceThreshold;
    printf("Informe o limite do alcance: ");
    scanf("%d", &distanceThreshold);

    int result = findTheCity(n, edges, edgeCount, distanceThreshold);

    printf("A cidade com o menor numero de cidades vizinhas no limite do alcance eh: %d\n", result);

    free(edges);

    return 0;
}
