//graph and Trees

//graph without a cycle is a tree

//input :

#include<bits/stdc++.h>
using namespace std;

const int N = 1e3 + 10;
int graph1[N][N];// adjecency matrix
vector<pair<int, int>> graph2[N]; // adjecency list
vector<int>vis[N]; //visited vertex


// dfs basic
void dfs(int vertex) {
	vis[vertex] = true;
	for (int child : grah1[vertex]) {
		dfs(child);
	}
}

// ****************Disjoint Set Union***********************
/*
Time Complexity : O(alpha(n)) if we combine both optimizations - path compression with union by size / rank - we will reach nearly constant time queries.
It turns out, that the final amortized time complexity is alpha(n),
where alpha(n) is the inverse Ackermann function, which grows very slowly.
In fact it grows so slowly, that it doesn't exceed 4 for all reasonable n
(approximately n < 10^{600}).
*/

using namespace std;
const N = 1e5 + 10;

int parent[N];
int size[N];

void make(int v) {
	parent[v] = v;
	size[v] = 1;
}

int find(int v) {
	if (parent[v] == v) return v;
	//path reduction / optimization
	return parent[v] = find(parent[v]);
}

void Union(int a, int b) {
	a = find(a);
	b = find(b);
	//if both of them have same parent then no need to merge

	if (a != b) {

		//merged by size
		if (size[a] < size[b])
			swap(a, b);
		parent[b] = a;
		size[a] += size[b];
	}
}

int main() {

}

//*********0-1 BFS****************



//**************Dijkstra algorithm************

// Function to find the shortest distance of all the vertices
// from the source vertex S.
vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
{

	// Create a priority queue for storing the nodes as a pair {dist,node}
	// where dist is the distance from source to the node.
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

	// Initialising distTo list with a large number to
	// indicate the nodes are unvisited initially.
	// This list contains distance from source to the nodes.
	vector<int> distTo(V, INT_MAX);

	// Source initialised with dist=0.
	distTo[S] = 0;
	pq.push({0, S});

	// Now, pop the minimum distance node first from the min-heap
	// and traverse for all its adjacent nodes.
	while (!pq.empty())
	{
		int node = pq.top().second;
		int dis = pq.top().first;
		pq.pop();

		if (dis > distTo[node]) continue;
		// Check for all adjacent nodes of the popped out
		// element whether the prev dist is larger than current or not.
		for (auto it : adj[node])
		{
			int v = it[0];
			int w = it[1];
			if (dis + w < distTo[v])
			{
				distTo[v] = dis + w;

				// If current distance is smaller,
				// push it into the queue.
				pq.push({dis + w, v});
			}
		}
	}
	// Return the list containing shortest distances
	// from source to all the nodes.
	return distTo;
}



//****************Bellman Ford Algorithm(for shortest path with negative cycle)***********

//only aplied on directed graph
/*  Function to implement Bellman Ford
	*   edges: vector of vectors which represents the graph
	*   S: source vertex to start traversing graph with
	*   V: number of vertices
	*/
vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {
	vector<int> dist(V, 1e8);
	dist[S] = 0;

	//doing N-1 relaxations
	for (int i = 0; i < V - 1; i++) {
		for (auto it : edges) {
			int u = it[0];
			int v = it[1];
			int wt = it[2];
			if (dist[u] != 1e8 && dist[u] + wt < dist[v]) {
				dist[v] = dist[u] + wt;
			}
		}
	}
	// Nth relaxation to check negative cycle
	for (auto it : edges) {
		int u = it[0];
		int v = it[1];
		int wt = it[2];
		if (dist[u] != 1e8 && dist[u] + wt < dist[v]) {
			return { -1};
		}
	}


	return dist;
}


//****************Floyd Warshall Method(Multisource shortest path b/w 2 nodes algo)**********************

//detectes -ve cycle as well

/*
4 3 5 from to cost
1 2 5
1 3 9
2 3 3
1 2  query from,to
2 1
1 3
1 4
3 2
*/

void solve()
{
	int n, m, q;
	cin >> n >> m >> q;
	vector<vector<ll>>matrix(n + 1, vector<ll>(n + 1, 1000000000LL * n + 1LL));

	for (int i = 0; i < m; i++) {
		int a, b;
		ll c;
		cin >> a >> b >> c;
		matrix[a][b] = min(c, matrix[a][b]);
		matrix[b][a] = min(c, matrix[b][a]) ;
	}
	for (int i = 1; i <= n; i++) matrix[i][i] = 0;

	for (int via = 1; via <= n; via++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				matrix[i][j] = min(matrix[i][j] , matrix[i][via] + matrix[via][j]);
			}
		}
	}

	while (q--) {
		int x, y;
		cin >> x >> y;
		cout << (matrix[x][y] == 1000000000LL * n + 1LL ? -1 : matrix[x][y]);
		cout << endl;
	}
}


//*************flattened tree euler tour / topological sort**************

#include<bits/stdc++.h>
#include <iostream>

using namespace std;
int timer = 1;

int In[10005];
int Out[10005];
int ft[20005];
vector<int> adj[10005];

void dfs(int node, int parent) {
	In[node] = timer;
	ft[timer] = node;
	timer++;
	for (auto child : adj[node]) {
		if (child == parent) continue;
		dfs(child, node);
	}
	Out[node] = timer;
	ft[timer] = node;
	timer++;
}

int main()
{
	int n = 5;
	for (int i = 0; i < n - 1; i++) {
		int x, y;
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	dfs(1, -1);
	for (auto i : In) cout << i << " ";
	cout << endl;
	for (auto i : Out) cout << i << " ";
	cout << endl;
	for (auto i : ft) cout << i << " ";
	cout << endl;
	return 0;
}



//**********************Diameter of a Tree*********************
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;

vector<vector<int>> adj(N, vector<int>());
vector<bool> visited(N, false);
vector<int> depth(N, 0);

void Dia_DFS(int root) {
	visited[root] = true;
	for (auto child : adj[root]) {
		if (!visited[child]) {
			depth[child] = depth[root] + 1;
			Dia_DFS(child);
		}
	}
}

int main() {
	int n, src, dest;
	cin >> n;

	int max_d = -1;
	int max_node;

	for (int i = 0; i < n - 1 ; i++) {
		cin >> src >> dest;
		// src--, dest--;
		adj[src].push_back(dest);
		adj[dest].push_back(src);
	}
	Dia_DFS(1);

	for (int i = 1; i <= n ; i++) {
		if (depth[i] > max_d) {
			max_d = depth[i];
			max_node = i;
		}
	}
	// We are resetting the visited vector and
	// depth vector(depth vector islie kyuki jab root node alag hoga
	//second dfs me to depth alag hogi islie hme reset krna pdega depth vector)
	//because we are gonna call DFS second time to find the Diameter
	for (int i = 0; i < n; i++) {visited[i] = 0; depth[i] = 0;}

	Dia_DFS(max_node);

	for (int i = 1; i <= n ; i++) {
		if (depth[i] > max_d) {
			max_d = depth[i];
		}
	}
	cout << max_d;

	return 0;
}



//****************Lowest Common Ancestor in binary tree***************
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
	//base case
	if (root == NULL || root == p || root == q) {
		return root;
	}
	TreeNode* left = lowestCommonAncestor(root->left, p, q);
	TreeNode* right = lowestCommonAncestor(root->right, p, q);

	//result
	if (left == NULL) {
		return right;
	}
	else if (right == NULL) {
		return left;
	}
	else { //both left and right are not null, we found our result
		return root;
	}

}


//**********************Multi Source BFS***************************

/*input :
3 7
H H H S H H H
S H H H H S H
H H H H H H H

output :
1 2 1 0 1 1 2
0 1 2 1 1 0 1
1 2 3 2 2 1 2

level from S to H shortest
*/


vector<pair<int, int>> movements = {
	{1, 0}, { -1, 0}, {0, 1}, {0, -1}
};

int main() {
	fast;
	int m, n;
	cin >> m >> n;
	vector<vector<char>> houses(m, vector<char>(n));
	vector<vector<int>> ans(m, vector<int>(n, -1));

	int level = 0;
	queue<pair<int, int>>q;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			char x;
			cin >> x;
			houses[i][j] = x;
			if (x == 'S') {
				ans[i][j] = level;
				//pushinng all the starting points in queue
				q.push({i, j});
			}
		}
	}

	while (!q.empty()) {
		int s = q.size();
		level++;
		for (int i = 0; i < s; i++) {
			auto p = q.front();
			q.pop();
			for (auto movement : movements) {
				int x = p.first + movement.first;
				int y = p.second + movement.second;
				if (x >= 0 && x < m && y >= 0 && y < n) {
					if (ans[x][y] == -1) {
						ans[x][y] = level;
						q.push({x, y});
					}
					else if (ans[x][y] > level) ans[x][y] == level;
					// this condition is not possible bc if a node is already visited then
					// it means it has lower level than the current
				}
			}
		}
	}

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) cout << ans[i][j] << " ";
		cout << endl;
	}

	return 0;
}

//**************Kosaraju's Algorithm(to count number of strongly connected component)*****

-> sort all the nodes in descending order of their finishing time (topological sort)
-> Transpose the vertices in the graph
-> DFS according to finishing time

void dfs(int node, stack<int> &st, vector<int> &vis, vector<int> adj[]) {
	vis[node] = 1;
	for (auto it : adj[node]) {
		if (!vis[it]) {
			dfs(it, st, vis, adj);
		}
	}

	st.push(node);
}
void revDfs(int node, vector<int> &vis, vector<int> transpose[]) {
	cout << node << " ";
	vis[node] = 1;
	for (auto it : transpose[node]) {
		if (!vis[it]) {
			revDfs(it, vis, transpose);
		}
	}
}
int main() {
	int n = 6, m = 7;
	vector<int> adj[n + 1];
	adj[1].push_back(3);
	adj[2].push_back(1);
	adj[3].push_back(2);
	adj[3].push_back(5);
	adj[4].push_back(6);
	adj[5].push_back(4);
	adj[6].push_back(5);

	stack<int> st;
	vector<int> vis(n + 1, 0);
	for (int i = 1; i <= n; i++) {
		if (!vis[i]) {
			dfs(i, st, vis, adj);
		}
	}

	vector<int> transpose[n + 1];

	for (int i = 1; i <= n; i++) {
		vis[i] = 0;
		for (auto it : adj[i]) {
			transpose[it].push_back(i);
		}
	}

	while (!st.empty()) {
		int node = st.top();
		st.pop();
		if (!vis[node]) {
			cout << "SCC: ";
			revDfs(node, vis, transpose);
			cout << endl;
		}
	}
	return 0;
}

//****************Segment Tree ***************
/*
Segment tree stores certain value from certain ranges from the given array.
Each node of the tree is assigned indexes so as to store it in the array.
Each node represents a range of indexs of the given array.
*/

//SC : 4*N , Time taken to build Seg : O(2*N -1), Time taken to run query : O(log N)

int a[100005], seg[4 * 100005];


void build(int ind, int low, int high) {

	if (low == high) {
		seg[ind] = a[low]; //or a[high]
		return;
	}

	int mid = (low + high) / 2;

	//calling left child
	build(2 * ind + 1, low, mid);

	//calling right child
	build(2 * ind + 2, mid + 1, high);

	seg[ind] = max(seg[2 * ind + 1], seg[2 * ind + 2]);
}

int query(int ind, int low, int high, int l, int r) {
	/*
	there are 3 conditions the given query satisfies a given range
	i) completely covers
	ii) partial overlap
	iii) not in range
	*/
	if (low >= l && high <= r) return seg[ind]; //(i)
	if (high < l || low > r) return INT_MIN; //(iii)

	//(ii)
	int mid = (low + high) / 2;

	//calling left child
	int left = query(2 * ind + 1, low, mid, l , r);

	//calling right child
	int right = query(2 * ind + 2, mid + 1, high, l, r);
	return max(left, right);

}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n ; i++) cin >> a[i];

	//index of root, starting range, ending range
	build(0, 0, n - 1);

	//running queries
	int q;
	cin >> q;
	while (q--) {
		int l, r;
		cin >> l >> r;
		cout << query(0 , 0, n - 1, l, r) << " ";
	}
}



//*****************Bipartite Graph*************


//*********** Binarry Indexed Tree(BIT) / Fenwick Tree*******

//used when we need to perform large number of queries in range of arrays
// check notes

/*
Question 1 Given array of size N and Q querries
Solve two type of quereies
Type1 : i x : replace ith index by value x
Type 2 : l r : find sum from l to r
Input :
N Q
N elemnts of array
Type i x / Type l r(Q lines)


Example :
5 4
3 4 5 6 3
2 2 4
1 2 6
2 2 4
2 1 5
Output : 
15
17
23


*/


#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
int bit[N];

void update(int i, int x){
	for(; i < N; i += (i&-i))
		bit[i] += x;
}

int sum(int i){
	int ans = 0;
	for(; i > 0; i -= (i&-i))
		ans += bit[i];
	return ans;
}

int main(){
	int n, q;
	cin >> n >> q;
	int a[n+10];
	for(int i = 1;i <= n; ++i){
		cin >> a[i];
		update(i, a[i]);
	}

	while(q--){
		int type;
		cin >> type;
		if(type == 1){
			int i, x;
			cin >> i >> x;
			update(i, x - a[i]);
			a[i] = x;
		}
		else{
			int l, r;
			cin >> l >> r;
			cout << sum(r) - sum(l-1) << endl;
		}
	}
}


