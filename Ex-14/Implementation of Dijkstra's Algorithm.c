#include<stdio.h>
#define inf 99999
#define max 100

typedef struct{
    int vi;
    int pre;
    int dis;
} Node;
int mindis(Node node[]);
int n,a[max][max];
void displayDistances(Node node[]) {
    printf("Vertex\tDistance from Source\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\n", i, node[i].dis);
    }
}
void dis(int so)
{
    Node node[max];
    for(int i=0;i<n;i++)
    {
      node[i].vi=0;
      node[i].pre=-1;
      node[i].dis=inf;
    }
    node[so].dis=0;
    for(int i=0;i<n-1;i++)
    {
        int u=mindis(node);
        node[u].vi=1;
        for(int v=0;v<n;v++)
    {
        if(!(node[v].vi)&&(node[u].dis!=inf)&&a[u][v]&&node[u].dis+a[u][v]<node[v].dis){
            node[v].dis=node[u].dis+a[u][v];
             node[v].pre=u;
        }
        
    }
    }
    displayDistances(node);
}
int mindis(Node node[])
{
    int min=inf,minind=-1;
    for(int i=0;i<n;i++)
    {
        if(!node[i].vi &&  node[i].dis<min)
        {
            min=node[i].dis;
            minind=i;
        }
    }
    return minind;
}


int main() {
    n = 5; 

    
    int edges[5][5] = {
        {0, 10, 0, 0, 5},
        {10, 0, 1, 0, 2},
        {0, 1, 0, 4, 0},
        {0, 0, 4, 0, 3},
        {5, 2, 0, 3, 0}
    };

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            a[i][j] = edges[i][j];
        }
    }

    int src = 0; 

    
    dis(src);

    return 0;
}
