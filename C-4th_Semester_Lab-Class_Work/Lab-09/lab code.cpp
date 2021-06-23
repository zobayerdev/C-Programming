#include<bits\stdc++.h>
#include<queue>
using namespace std;

#define NEG_INF -999999
#define WHITE 1
#define GRAY 2
#define BLACK 3

int adj[100][100];
int color[100];
int parent[100];
int dis[100];
int node,edge;

void bfs(int start)
{
    for(int i=0;i<node;++i)
    {
        color[i]=WHITE;
        dis[i]=NEG_INF;
        parent[i]=-1;
    }

    parent[start]=-1;
    dis[start]=0;

    queue <int> q;
    q.push(start);
    while(!q.empty())
    {
        int x;
        x=q.front();
        q.pop();
        color[x]=GRAY;

        printf("Visited node: %d\n",x);

        for(int i=0;i<node;++i)
        {
            if(adj[x][i]==1)
            {
                if(color[i]==WHITE)
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

    for(int i=0;i<edge;i++)
    {
        scanf("%d %d",&n1,&n2);
        adj[n1][n2]=1;
        adj[n2][n1]=1;
    }

    bfs(0);

    for(int i=0;i<node;i++)
    {
        printf("Distance from starting node 0 to %d: %d\n",i,dis[i]);
    }
}

