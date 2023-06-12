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
    if(i >= graph.size() || i < 0 || j >= graph.size() || j < 0 || graph[i][j] == '1')
        return 0;
    if(vis[i][j])
        return 0;
    vis[i][j] = true;
    int count = 1;
//    count += dfs(graph, vis, i + 1, j + 1);//bottom-right
//    count += dfs(graph, vis, i - 1, j - 1);//top-left
//    count += dfs(graph, vis, i + 1, j - 1);//bottom-left
//    count += dfs(graph, vis, i - 1, j + 1);//top-right
    count += dfs(graph, vis, i + 1, j);//bottom
    count += dfs(graph, vis, i - 1, j);//top
    count += dfs(graph, vis, i, j + 1);//right
    count += dfs(graph, vis, i, j - 1);//left
    return count;
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
    cin.ignore();
    cin.ignore();
    while(t--){
        int I, J;
        cin >> I >> J;
        cin.ignore();
        vcc grid(99, vc(99, '1'));
//        vii graph(99, vi(99, INT_MAX));
        vbb vis(99, vb(99, false));
        vector<string> input;
        string s;
        while(getline(cin, s) && s != ""){
            input.push_back(s);
        }
        for (int i = 0; i < input.size(); ++i) {
            for (int j = 0; j < input[0].size(); ++j) {
                grid[i][j] = input[i][j];
            }
        }
        int ans = dfs(grid, vis, I-1, J-1);
        cout << ans << "\n";
        if(t > 0)
            cout << "\n";
    }
}