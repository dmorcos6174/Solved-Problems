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

bool dfs(vcc &graph, vbb &vis, int i, int j, int waterlevel) {
    if(j > n-1)
        return true;
    if (i >= graph.size() || i < 0 || waterlevel >= j || j < 0 || graph[i][j] == 'X')
        return false;
    if (vis[i][j])
        return false;
    vis[i][j] = true;
    if (dfs(graph, vis, i + 1, j + k, waterlevel + 1)||
    dfs(graph, vis, i - 1, j + k, waterlevel + 1)||
    dfs(graph, vis, i, j + 1, waterlevel + 1)||
    dfs(graph, vis, i, j - 1, waterlevel + 1)){
        return true;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    cin >> n >> k;
    vector<string> input;
    string s;
    for (int i = 0; i < 2; ++i) {
        cin >> s;
        input.push_back(s);
    }
    int r = input.size(), c = input[0].size();
    vcc graph(r, vc(c));
    vbb vis(r, vb(c, false));
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            graph[i][j] = input[i][j];
        }
    }
    if(dfs(graph, vis, 0, 0, -1))
        cout << "YES";
    else
        cout << "NO";
}