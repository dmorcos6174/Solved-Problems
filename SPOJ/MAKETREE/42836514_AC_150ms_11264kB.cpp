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

int n, k;

void dfs(vii& adj, int v, vb& vis, stack<int>& hier){
    vis[v] = true;
    for (auto j = adj[v].begin(); j != adj[v].end() ; ++j) {
        if(!vis[*j])
            dfs(adj, *j, vis, hier);
    }
    hier.push(v);
}

stack<int> topSort(vii& adj){
    stack<int> hier;
    vb vis(n + 1, false);
    for (int i = 1; i <= n; ++i) {
        if(!vis[i]){
            dfs(adj, i, vis, hier);
        }
    }
    return hier;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    cin >> n >> k;
    vii adj(n + 1);
    for (int i = 1; i <= k; ++i) {
        int w;
        cin >> w;
        for (int j = 0; j < w; ++j) {
            int node;
            cin >> node;
            adj[i].push_back(node);
        }
    }
    stack<int> hier = topSort(adj);
    int ind = 0;
    vi ans(n + 1);
    while(!hier.empty()){
        ans[hier.top()] = ind;
        ind = hier.top();
        hier.pop();
    }
    for (int i = 1; i < ans.size(); ++i) {
        cout << ans[i] << "\n";
    }
}