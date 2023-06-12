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

void bfs(vcc& grid, vii& graph, vbb& vis, pair<int, int> e, int r, int c){
    queue<pair<int, int>> q;
    q.push(e);
    int level = 0;
    vis = vbb(400, vb(400, false));
    while(!q.empty()){
        int level_size = q.size();
        while(level_size--){
            pair<int, int> cur = q.front();
            q.pop();
            if(grid[cur.first][cur.second] == '#')
                vis[cur.first][cur.second] = true;
            if(vis[cur.first][cur.second])
                continue;
            graph[cur.first][cur.second] = max((ll)level, graph[cur.first][cur.second]);
            vis[cur.first][cur.second] = true;
            if(cur.first + 1 < r)
                q.emplace(cur.first + 1, cur.second);
            if(cur.first - 1 >= 0)
                q.emplace(cur.first - 1, cur.second);
            if(cur.second + 1 < c)
                q.emplace(cur.first, cur.second + 1);
            if(cur.second - 1 >= 0){
                q.emplace(cur.first, cur.second - 1);
            }
        }
        level++;
    }
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
        int n, m;
        cin >> m >> n;
        vii graph(400, vi(400, 0));
        vcc grid(400, vc(400,'0'));
        vbb vis(400, vb(400, false));
        pair<int, int> ankur, anuja, jyoti;
        for (int i = 100; i < m + 100; ++i) {
            for (int j = 100; j < n + 100; ++j) {
                cin >> grid[i][j];
                if(grid[i][j] == '1')
                    ankur = {i, j};
                else if(grid[i][j] == '2')
                    anuja = {i, j};
                else if(grid[i][j] == '3')
                    jyoti = {i, j};
                else if(grid[i][j] == '#')
                    vis[i][j] = true;
            }
        }
        bfs(grid, graph, vis, ankur, 400, 400);
        bfs(grid, graph, vis, anuja, 400, 400);
        bfs(grid, graph, vis, jyoti, 400, 400);
        int mini = INT_MAX;
        for (int i = 0; i < 400; ++i) {
            for (int j = 0; j < 400; ++j) {
                pair<int, int> node = {i, j};
                if(graph[node.first][node.second] == 0)
                    continue;
                int dist1 = graph[node.first][node.second];
                mini = min(dist1, mini);
            }
        }
        cout << mini << "\n";
    }
}