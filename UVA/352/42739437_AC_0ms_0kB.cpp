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

int dfs(vcc& graph, vbb& vis, int i, int j){
    if(i >= graph.size() || i < 0 || j >= graph.size() || j < 0 || graph[i][j] == '0')
        return 0;
    if(vis[i][j])
        return 0;
    vis[i][j] = true;
    dfs(graph, vis, i + 1, j + 1);
    dfs(graph, vis, i - 1, j - 1);
    dfs(graph, vis, i + 1, j - 1);
    dfs(graph, vis, i - 1, j + 1);
    dfs(graph, vis, i + 1, j);
    dfs(graph, vis, i - 1, j);
    dfs(graph, vis, i, j + 1);
    dfs(graph, vis, i, j - 1);
    return 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int n;
    int tt = 1;
    while (cin >> n) {
        int r = n, c = n;
        vcc graph(r, vc(c));
        vbb vis(r, vb(c, false));
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                cin >> graph[i][j];
            }
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                ans += dfs(graph, vis, i, j);
            }
        }
        cout << "Image number " << tt++ << " contains " << ans << " war eagles.\n";
    }
}