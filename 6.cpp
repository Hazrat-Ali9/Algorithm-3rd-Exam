 #include<bits/stdc++.h>
using namespace std;

int n, m, ax, ay;
string path = "";

char arr[500][500];
bool visited[500][500];

int arr1[] = {-1, 0, 1, 0};
int arr2[] = {0, 1, 0, -1};



bool validationCheck(int a, int b)
{
    if(a < 1 || a > n || b < 1 || b > m) return false;
    if(arr[a][b] == '#' || arr[a][b] == 'M') return false;
    return true;
}

bool safeBoundary(int a, int b)
{
    visited[a][b] = true;
    if(a == 1 || a == n || b == 1 || b == m) return true;
    for(int i=0; i<4; i++)
    {
        int nx = a + arr1[i], ny = b + arr2[i];
        if(validationCheck(nx, ny) && !visited[nx][ny])
        {
            if(i == 0) path += "U";
            if(i == 1) path += "R";
            if(i == 2) path += "D";
            if(i == 3) path += "L";
            if(safeBoundary(nx, ny)) return true;
            path.pop_back();
        }
    }
    return false;
}

int main()
{
    cin >> n >> m;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            cin >> arr[i][j];
            if(arr[i][j] == 'A') ax = i, ay = j;
        }
    }

    if(safeBoundary(ax, ay))
    {
        cout << "YES\n";
        cout << path.size() << "\n" << path << "\n";
    }
    else cout << "NO\n";

    return 0;
}
