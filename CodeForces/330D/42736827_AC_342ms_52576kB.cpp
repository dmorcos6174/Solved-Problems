#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef long long ull;
typedef vector<ll> vi;
typedef vector<bool> vb;
typedef vector<vector<ll>> vii;
typedef vector<vector<bool>> vbb;

void bfs(vii& graph, vbb& vis, pair<int, int> e, int r, int c){
    queue<pair<int, int>> q;
    q.push(e);
    int level = 0;
    while(!q.empty()){
        int level_size = q.size();
        level++;
        while(level_size--){
            pair<int, int> cur = q.front();
            q.pop();
            if(vis[cur.first][cur.second])
                continue;
            graph[cur.first][cur.second] = level;
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
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int r, c;
    cin >> r >> c;
    vii graph(r, vi(c, INT_MAX));
    vii breeders;
    pair<int, int> s, e;
    vbb vis(r, vb(c, false));
    for (int i = 0; i < r; ++i) {
        string in;
        cin >> in;
        for (int j = 0; j < c; ++j) {
            if(in[j] == 'S')
                s.first = i, s.second = j;
            else if(in[j] == 'E')
                e.first = i, e.second = j;
            else if(in[j] == 'T')
                graph[i][j] = INT_MIN, vis[i][j] = true;
            else
                breeders.push_back({i, j, in[j] - '0'});
        }
    }
    bfs(graph, vis, e, r, c);
    int temp = graph[s.first][s.second];
    int ans = 0;
    for(auto& breeder : breeders){
        if(temp >= graph[breeder[0]][breeder[1]])
            ans += breeder[2];
    }
    cout << ans;
}
