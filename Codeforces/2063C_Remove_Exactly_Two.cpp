#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1e9+7

int ceil(int a, int b){
    if(a%b==0) return a/b;
    return a/b + 1;
}

int n, m, k;

void getandremove (unordered_map<int,vector<int> >& mp) {
    int nodewithmaxdegree = -1;
    int maxdegree = -1;
    for(auto it : mp){
        int listSize = it.second.size();
        if(listSize > maxdegree) {
            //cout << "maxdegree: " << maxdegree << " list size: " << it.second.size() << endl;
            maxdegree = it.second.size(); 
            nodewithmaxdegree = it.first;
        }
    }

    //cout << ">> " << nodewithmaxdegree << endl;
    for(int i=0;i<mp[nodewithmaxdegree].size();i++) {
        auto x = find(mp[mp[nodewithmaxdegree][i]].begin(), mp[mp[nodewithmaxdegree][i]].end(), nodewithmaxdegree);
        mp[mp[nodewithmaxdegree][i]].erase(x);
    }
    mp.erase(nodewithmaxdegree);
}

void dfs(int node, vector<bool> &visited, unordered_map<int, vector<int> > &mp) {
    stack<int> s;
    s.push(node);
    visited[node] = true;

    while (!s.empty()) {
        int current = s.top();
        s.pop();

        for (auto neighbor : mp[current]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                s.push(neighbor);
            }
        }
    }
}

int countConnectedComponents(int n, unordered_map<int, vector<int> > &mp) {
    vector<bool> visited(n, false);
    int componentCount = 0;

    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            dfs(i, visited, mp);
            componentCount++;
        }
    }

    return componentCount;
}

void solve() {
    cin >> n;
    unordered_map<int,vector<int> > mp;
    
    for(int i=0; i<n-1; i++) {
        cin>> m >> k;
        mp[m].push_back(k);
        mp[k].push_back(m);
    }

    int time = 2;
    while(time--) getandremove(mp);

    cout << countConnectedComponents(mp.size(), mp) << endl ;
}



int main (){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}