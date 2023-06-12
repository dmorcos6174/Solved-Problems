#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef long long ull;
typedef vector<ll> vi;
typedef vector<bool> vb;
typedef vector<char> vc;
typedef vector<vector<ll>> vii;
typedef vector<vector<bool>> vbb;
typedef vector<vector<char>> vcc;

void add_edge(vii& adj, int src, int dest){
    adj[src].push_back(dest);
    adj[src].push_back(src);
}

bool bfs(vii& adj, int src, int dest, int v, vi& pred, vi& dist){
    queue<int> q;
    vb vis(v, false);
    vis[src] = true;
    dist[src] = 0;
    q.push(src);
    while(!q.empty()){
        int front = q.front();
        q.pop();
        for (int i = 0; i < adj[front].size(); ++i) {
            if(!vis[adj[front][i]]){
                vis[adj[front][i]] = true;
                dist[adj[front][i]] = dist[front] + 1;
                pred[adj[front][i]] = front;
                q.push(adj[front][i]);
            }
            if(adj[front][i] == dest){
                return true;
            }
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vii adj(n);
        for (int i = 0; i < n; ++i) {
            int node, nc;
            cin >> node >> nc;
            for (int j = 0; j < nc; ++j) {
                int neigh;
                cin >> neigh;
                add_edge(adj, node, neigh);
            }
        }
        int src, dest;
        cin >> src >> dest;
        vi pred(n, -1), dist(n, INT_MAX);
        bfs(adj, src, dest, n, pred, dist);
        cout << src << " " << dest << " " << dist[dest] - 1 << "\n";
        if(t != 0)
            cout << "\n";
    }
}