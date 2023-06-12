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
typedef pair<ll , ll > pii;

int n, m, k;

bool dfs(vcc& graph, vbb& vis, int i, int j, int curI, int curJ, int count){
    if(i >= graph.size() || i < 0 || j >= graph.size() || j < 0 || graph[i][j] == '*' || vis[i][j])//out of bounds
        return false;
    if((i == curI && j == curJ) && !(count >= k))
        return false;
    if((i == curI && j == curJ) && (count >= k))
        return true;

    vis[i][j] = true;
//    count += dfs(graph, vis, i + 1, j + 1);//bottom-right
//    count += dfs(graph, vis, i - 1, j - 1);//top-left
//    count += dfs(graph, vis, i + 1, j - 1);//bottom-left
//    count += dfs(graph, vis, i - 1, j + 1);//top-right
    if(dfs(graph, vis, i + 1, j, curI, curJ, count++))//bottom
        return true;
    if(dfs(graph, vis, i - 1, j, curI, curJ, count++))//top
        return true;
    if(dfs(graph, vis, i, j + 1, curI, curJ, count++))//right
        return true;
    if(dfs(graph, vis, i, j - 1, curI, curJ, count++))//left
        return true;

    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    cin >> n >> m >> k;
    vcc graph(n, vc(m, '.'));
    vbb vis(n, vb(m, false));
    int si, sj;
    cin >> si >> sj;
    si--;sj--;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> graph[i][j];
        }
    }
    int mx = 0;
    bool m1 = dfs(graph, vis, si-1, sj, si, sj, 1);
    bool m2 = dfs(graph, vis, si+1, sj, si, sj, 1);
    bool m3 = dfs(graph, vis, si, sj-1, si, sj, 1);
    bool m4 = dfs(graph, vis, si, sj+1, si, sj, 1);
//    mx = max({m1, m2, m3, m4});
    if(m1 || m2 || m3 || m4)
        cout << "YES";
    else
        cout << "NO";
}