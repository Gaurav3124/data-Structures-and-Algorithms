#include<bits/stdc++.h>
using namespace std;

#define ll long long

int ceil(int a, int b){
    if(a%b==0) return a/b;
    return a/b + 1;
}

int n, m, k;
vector<int> arr;

void solve() {
    cin >> n >> m;
    string s;
    cin >> s;
    vector<int> lf(n), rgt(n);

    lf[0] = -1;
    for(int i=0;i<n;i++){
        if(i>0) lf[i] = lf[i-1];
        if(s[i] == '0') lf[i] = i;
    }

    rgt[n-1] = n;
    for(int i=n-1;i>=0;i--){
        if(i<n-1) rgt[i] = rgt[i+1];
        if(s[i]=='1') rgt[i] = i;
    }


    set<pair<int,int> > pairs;
    for(int i=0;i<m;i++){
        int l,r;
        cin >> l >> r;
        int lvalue = rgt[l-1], rvalue = lf[r-1];

        if(lvalue > rvalue) pairs.insert( make_pair(-1,-1));
        else pairs.insert(make_pair(lvalue, rvalue));
    }

    cout << pairs.size() << endl;

}

int main (){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}