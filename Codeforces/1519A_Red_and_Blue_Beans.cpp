#include<bits/stdc++.h>
using namespace std;

#define ll long long

int ceil(int a, int b){
    if(a%b==0) return a/b;
    return a/b + 1;
}

int n, m, k;

void solve() {
    cin >> n >> m >> k;
    int minNum = min(n,m);
    int diff = abs(n-m);
    if(ceil(diff,minNum)>k) cout << "NO" << endl;
    else cout << "YES" << endl;
}

int main (){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}