// ==========================================��Ŀ1109����ͨͼ   C++
// �����ѵ��֮ǰ����Runtime Error �Ĵ���Ӧ�����ڴ治����ԭ���µģ���������ǽ�adj��������鶨��Ϊȫ�ֱ�����˳���Ϊ��bool���͡�
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

// ==========================================��Ŀ1109����ͨͼ   C
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
        if (n==0)// ���������Ϊ0������
            return 0;
        if (m==0)// �������Ϊ0��ֱ�ӷ���NO
        {
            printf("NO\n");
            continue;
        }

        for (int i=0; i<n; i++) // ��ʼ���ڽӾ���
            for (int j=0; j<n; j++)
                adj[i][j]=0;

        int s,t;
        for (int i=0; i<m; i++) // �����ڽӾ���
        {
            scanf("%d %d",&s,&t);
            adj[s-1][t-1]=1;
            adj[t-1][s-1]=1;
        }

        int count=0;

        for (int i=0; i<n; i++) // ��ʼ��visited ����
            visited[i]=0;

        DFS(n,s-1,&count);// ��һ�������ӵĶ��㿪ʼ�������������

        if (count<n)// �����������ȫ��������YES������NO
            printf("NO\n");
        else
            printf("YES\n");
    }
    return 0;
}
