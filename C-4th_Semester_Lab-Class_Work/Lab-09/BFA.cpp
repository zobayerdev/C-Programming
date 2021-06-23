#include<bits\stdc++.h>
#include<queue>
using namespace std;

#define NEG_INF -999999
#define WHITE 1 //unvisited node
#define GRAY 2 //current node
#define BLACK 3 //visited node

int adj[100][100];   // For store neighbor
int color[100];    // Store defined color code
int parent[100]; // Store parent
int dis[100];  // Store distance from parent to current node

int node,edge;

void bfs(int start)
{
    for(int i=0;i<node;++i)
    {
        color[i]=WHITE;
        dis[i]=NEG_INF;
        parent[i]=-1;
    }

    parent[start]=-1; // starting node er parent nei jar jonne -1
    dis[start]=0;

    queue <int> q;
    q.push(start); //Push starting node in queue

    while(!q.empty()) // jotokkhon queue empty na hobe
    {
        int x;//uwu
        x=q.front();
        q.pop();
        color[x]=GRAY;

        printf("Visited node: %d\n",x);

        for(int i=0;i<node;++i) // this loop is for checking neighbor
        {
            if(adj[x][i]==1) // x er neighbor i
            {
                if(color[i]==WHITE) // x no node ta hocche i no node er parent
                {
                    dis[i]=dis[x]+1;
                    parent[i]=x;
                    q.push(i);
                }
            }
        }
        color[x]=BLACK;
    }
}

int main()
{
    cout << "Enter Number of node and edge: ";
    scanf("%d %d", &node,&edge);

    int n1,n2;

    for(int i=0;i<edge;i++)  //checking neighbor
    {
        scanf("%d %d",&n1,&n2);
        adj[n1][n2]=1;
        adj[n2][n1]=1;
    }

    for(int i=0;i<edge;i++)
    {
        for(int j=0;j<node;j++)
        {
            printf("%d  ",adj[i][j]);
        }
        printf("\n");
    }

    bfs(0); //call bfs function with starting node 0

    for(int i=0;i<node;i++)
    {
        printf("Distance from starting node 0 to %d: %d\n",i,dis[i]);
    }
}

