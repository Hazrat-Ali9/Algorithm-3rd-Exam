#include<bits/stdc++.h>
using namespace std;

vector<int> adj[1000];
bool flag[1000];

void dfs(int u) {
    flag[u] = true;
    for(int v : adj[u]) {
        if(!flag[v]) {
            dfs(v);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    for(int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1);


    if(flag[n]) {
        cout << "YES";
    } else {
        cout << "NO";
    }

    return 0;
}
