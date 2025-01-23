#include<bits/stdc++.h>
using namespace std;

#define ll long long

int ceil(int a, int b){
    if(a%b==0) return a/b;
    return a/b + 1;
}

int n,m,ans;
void go (int curr, int previous, int consecCats, vector<vector<int> >& tree, vector<bool>& cat) {

    if(consecCats>m) return;

    bool isLeaf = true;
    for(int i=0;i<tree[curr].size();i++) {
        int next = tree[curr][i];
        if(next!=previous){
            isLeaf = false;
            go(next, curr,(cat[next])? consecCats+cat[next] : 0, tree, cat);
        }
    }
    if(isLeaf) ans++;
}

void solve() {
    cin >> n >> m;
    ans=0;

    vector<vector<int> > tree(n+1);
    vector<bool> cat(n+1);
    for(int i=0;i<n;i++) {
        int x;
        cin >> x;
        cat[i+1] = x;
    }

    for(int i =1;i<n;i++){
        int x,y;
        cin >> x >> y;
        tree[x].push_back(y);
        tree[y].push_back(x);
    }

    go(1,0,cat[1],tree,cat);
    cout << ans << endl;

}

int main (){
    int t=1;
    //cin >> t;
    while(t--){
        solve();
    }
    return 0;
}