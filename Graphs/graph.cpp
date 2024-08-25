#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

class Solution {
    public : 
        vector<int> bfsGraphTraversal(int V, vector<int> adj[]){
            vector<int> vis(V,0);
            vis[0] = 1;
            queue<int> q;
            q.push(0);
            vector<int> bfs;

            while(!q.empty()){
                int node = q.front();
                q.pop();
                bfs.push_back(node);
                for(auto it : adj[node]){
                    if(!vis[it]){
                        vis[it] = 1;
                        q.push(it);
                    }
                }
            }
            return bfs;
        }

        vector<int> dfsGraphTraversal(int V, vector<int> adj[]){
            vector<int> vis(V,0);
            vector<int> dfsoutput;
            vis[0] = 1;
            queue<int> q;
            q.push(0);

            while(!q.empty()){
                int node = q.front();
                q.pop();
                for(auto it : adj[node]){
                    dfs(node, vis, dfsoutput, adj);
                }
            }
            return dfsoutput;
        }

    private :
        void dfs(int node, vector<int> &vis, vector<int> &dfsoutput, vector<int> adj[]){
            vis[node] = 1;
            dfsoutput.push_back(node);
            for(auto it : adj[node]){
                if(!vis[it]){
                    dfs(it, vis, dfsoutput, adj);
                }
            }
        }
};

void addEdge(vector <int> adj[], int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void printAns(vector <int> &ans) {
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
}

int main() 
{
    vector <int> adj[5];
    
    addEdge(adj, 0, 1);
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 0, 4);

    Solution obj;
    vector <int> ansBFS = obj.bfsGraphTraversal(5, adj);
    printAns(ansBFS);

    vector<int> ansDFS = obj.dfsGraphTraversal(5, adj);
    printAns(ansDFS);

    return 0;
}