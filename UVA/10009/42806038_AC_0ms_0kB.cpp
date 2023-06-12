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

bool bfs(unordered_map<char, vector<char>>& adj, char src, char dest, int v, unordered_map<char, char>& pred){
    queue<char> q;
//    vb vis(v, false);
    unordered_map<char, bool> vis;
    vis[src] = true;
//    dist[src] = 0;
    q.push(src);
    while(!q.empty()){
        char front = q.front();
        q.pop();
        for (int i = 0; i < adj[front].size(); ++i) {
            if(!vis[adj[front][i]]){
                vis[adj[front][i]] = true;
//                dist[adj[front][i]] = dist[front] + 1;
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

void add_edge(unordered_map<char, vector<char>>& adj, char src, char dest){
    adj[src].push_back(dest);
    adj[dest].push_back(src);
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
        int m, n;
        cin >> m >> n;
//        vii adj(n);
        unordered_map<char, vector<char>> adj;
        for (int i = 0; i < m; ++i) {
            string s, e;
            cin >> s >> e;
            add_edge(adj, s[0], e[0]);
        }

        for (int i = 0; i < n; ++i) {
            string src, dest;
            cin >> src >> dest;
            unordered_map<char, char> pred;
            bfs(adj, src[0], dest[0], adj.size(), pred);
            vc path;
            char c = dest[0];
            path.push_back(c);
            while(pred.count(c) != 0){
                path.push_back(pred[c]);
                c = pred[c];
            }
            for (int j = path.size()-1; j >= 0; --j) {
                cout << path[j];
            }
            cout << "\n";
            path.clear();
        }
        if(t != 0)
            cout << "\n";
    }
}