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

int dfs(vii &graph, vbb &vis, int i, int j, int n) {
    if (i >= graph.size() || i < 0 || j >= graph.size() || j < 0 || graph[i][j] != n)
        return 0;
    if (vis[i][j])
        return 0;
    vis[i][j] = true;
    int count = 1;
//    count += dfs(graph, vis, i + 1, j + 1);//bottom-right
//    count += dfs(graph, vis, i - 1, j - 1);//top-left
//    count += dfs(graph, vis, i + 1, j - 1);//bottom-left
//    count += dfs(graph, vis, i - 1, j + 1);//top-right
    count += dfs(graph, vis, i + 1, j, n);//bottom
    count += dfs(graph, vis, i - 1, j, n);//top
    count += dfs(graph, vis, i, j + 1, n);//right
    count += dfs(graph, vis, i, j - 1, n);//left
    return count;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int n;
    while (cin >> n && n) {
        vii graph(n, vi(n, n));
        vbb vis(n, vb(n, false));
        int fill = 1;
        cin.ignore();
        for (int i = 0; i < n - 1; ++i) {
            string s;
            getline(cin, s);
            stringstream ss(s);
            int I, J;
            while (ss >> I >> J)
                graph[I - 1][J - 1] = fill;
            fill++;
        }
        int ans = 0;
        bool flag = true;
        for (int k = 1; k <= n; ++k) {
            int maxAns = 0;
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    ans = dfs(graph, vis, i, j, k);
                    maxAns = max(maxAns, ans);
                }
            }
            if (maxAns != n) {
                cout << "wrong\n";
                flag = false;
                break;
            }
        }
        if(flag)
            cout << "good\n";
    }
}