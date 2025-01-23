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
    cin >> n >> k;
    unordered_map<int,int> mp;
    vector<int> arr(n);
    int startColor = -1;
    int endColor = -1;
    for(int i=0;i<n;i++){
        cin >> arr[i];
        if(i==0) startColor = arr[i];
        if(i==n-1) endColor = arr[i];
        mp[arr[i]]++;
    }
    int startidx = 0, scolor=0;
    int endidx = n-1, ecolor=0;

    while(startidx<n){
        if(arr[startidx]==startColor) scolor++;
        if(scolor==k) break;
        startidx++;
    }

    while(endidx>=0){
        if(arr[endidx] == endColor) ecolor++;
        if(ecolor==k) break;
        endidx--;
    }
    if(startColor==endColor){
        if(mp[startColor]>=k) cout << "YES" <<endl;
        else cout << "NO" <<endl;
        return;
    }
    (startidx<endidx) ? cout << "YES" << endl : cout << "NO" << endl;
}

int main (){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}