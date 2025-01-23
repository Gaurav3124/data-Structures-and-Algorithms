#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1e9+7

int ceil(int a, int b){
    if(a%b==0) return a/b;
    return a/b + 1;
}

int n, m, k;


void solve() {
    cin >> n >> m;

    if(n==1 && m==1) cout << "1" << endl;
    else cout << m-n << endl;
}

int main (){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}