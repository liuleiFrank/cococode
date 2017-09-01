// ==========================================题目1109：连通图   C++
// 经验教训：之前出现Runtime Error 的错误，应该是内存不够等原因导致的；解决方法是将adj这个大数组定义为全局变量，顺便改为了bool类型。
/*
#include<stdio.h>
bool visited[1001];
bool adj[1001][1001];
int n,m;

void DFS(int n,int v,int &count)
{
visited[v]=true;
count++;
for (int j=0;j<n;j++)
if (adj[v][j]==true && visited[j]==false)
DFS(n,j,count);
}

int main()
{
while(scanf("%d %d",&n,&m)!=EOF)
{
if (n==0)
return 0;
if (m==0)
{
printf("NO\n");
continue;
}
for (int i=0;i<n;i++)
for (int j=0;j<n;j++)
adj[i][j]=false;
int s,t;
for (int i=0;i<m;i++)
{
scanf("%d %d",&s,&t);
adj[s-1][t-1]=true;
adj[t-1][s-1]=true;
}

int count=0;

for (int i=0;i<n;i++)
visited[i]=false;
DFS(n,s-1,count);

if (count<n)
printf("NO\n");
else
printf("YES\n");

}
return 0;
}
*/

// ==========================================题目1109：连通图   C
#include<stdio.h>
int visited[1001];
int adj[1001][1001];
int n,m;

void DFS(int n,int v,int *count)
{
    visited[v]=1;
    (*count)++;
    for (int j=0; j<n; j++)
        if (adj[v][j]==1 && visited[j]==0)
            DFS(n,j,count);
}

int main()
{
    while(scanf("%d %d",&n,&m)!=EOF)
    {
        if (n==0)// 如果顶点数为0，结束
            return 0;
        if (m==0)// 如果边数为0，直接返回NO
        {
            printf("NO\n");
            continue;
        }

        for (int i=0; i<n; i++) // 初始化邻接矩阵
            for (int j=0; j<n; j++)
                adj[i][j]=0;

        int s,t;
        for (int i=0; i<m; i++) // 输入邻接矩阵
        {
            scanf("%d %d",&s,&t);
            adj[s-1][t-1]=1;
            adj[t-1][s-1]=1;
        }

        int count=0;

        for (int i=0; i<n; i++) // 初始化visited 矩阵
            visited[i]=0;

        DFS(n,s-1,&count);// 以一个有连接的顶点开始，深度优先搜索

        if (count<n)// 如果搜索到了全部顶点则YES，否则NO
            printf("NO\n");
        else
            printf("YES\n");
    }
    return 0;
}
