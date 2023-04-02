#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e5+5;

vector<int> graph[MAX];
int visited[MAX];

int dfs(int u, int parent)
{
    visited[u] = true;
    for(int v: graph[u])
    {
        if(!visited[v])
        {
            if(dfs(v, u))
                return true;
        }
        else if(v != parent)

            return true;
    }
    return false;
}

int flag (int n)
{
    (visited,sizeof(visited));
    for(int i=1; i<=n; i++)
    {
        if(!visited[i])
        {
            if(dfs(i, -1))

                return true;
        }
    }
    return false;
}

int main()
{
    int n, m;
    cin >> n >> m;
    for(int i=0; i<m; i++)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    if(flag(n)) cout << "Cycle Exist" << endl;
    else cout << "No Cycle" << endl;
    return 0;
}

