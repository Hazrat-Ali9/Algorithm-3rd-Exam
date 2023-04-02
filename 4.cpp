#include<bits/stdc++.h>
using namespace std;

int sumVector(vector<int> v, int n) {
    if(n == 0)
        return 0;
    else
        return v[n-1] + sumVector(v, n-1);
}

int main() {
    int n, x;
    vector<int> v;

    cin >> n;

    for(int i=0; i<n; i++) {
        cin >> x;
        v.push_back(x);
    }

    cout << sumVector(v, n);

    return 0;
}

                                                                                                                          


