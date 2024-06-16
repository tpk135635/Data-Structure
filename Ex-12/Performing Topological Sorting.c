#include <stdio.h>
#include <stdlib.h>

#define MAX 100

void topologicalSort(int graph[MAX][MAX], int numVertices) {
    int indegree[MAX] = {0};
    int stack[MAX];
    int top = -1;
    int sorted[MAX];
    int index = 0;

    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            if (graph[i][j] == 1) {
                indegree[j]++;
            }
        }
    }

    for (int i = 0; i < numVertices; i++) {
        if (indegree[i] == 0) {
            stack[++top] = i;
        }
    }

    while (top != -1) {
        int vertex = stack[top--];
        sorted[index++] = vertex;

        for (int i = 0; i < numVertices; i++) {
            if (graph[vertex][i] == 1) {
                indegree[i]--;
                if (indegree[i] == 0) {
                    stack[++top] = i;
                }
            }
        }
    }

    if (index != numVertices) {
        printf("The graph has a cycle, topological sort not possible.\n");
        return;
    }

    printf("Topological Sort: ");
    for (int i = 0; i < index; i++) {
        printf("%d ", sorted[i]);
    }
    printf("\n");
}

int main() {
    int numVertices = 6;
    int graph[MAX][MAX] = {0};

    graph[5][2] = 1;
    graph[5][0] = 1;
    graph[4][0] = 1;
    graph[4][1] = 1;
    graph[2][3] = 1;
    graph[3][1] = 1;

    topologicalSort(graph, numVertices);

    return 0;
}
