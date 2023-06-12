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

int n;
vii adj;
vector <pii> soldaten;
vi vis;

bool bfs(const pii &sol, int sign) {
    queue <pii> q;
    q.push({sol.first - 1, 0});
    while (!q.empty()) {
        pii curr = q.front();
        q.pop();
        if (curr.second > sol.second) continue;
        if (vis[curr.first] != -1) {
            if (vis[curr.first] == sign) continue;
            else return true;
        }
        vis[curr.first] = sign;
        for(auto i : adj[curr.first]) {
            q.push({i, curr.second + 1});
        }
    }
    return false;
}

void Dowork(){
    int r, m;
    cin >> n >> r >> m;
    adj.clear();
    vis.clear();
    soldaten.clear();
    adj.resize(n);
    vis.resize(n, -1);
    soldaten.resize(m);
    while (r--) {
        int x , y;
        cin >> x >> y;
        adj[x - 1].push_back(y - 1);
        adj[y - 1].push_back(x - 1);
    }
    for (int i = 0; i < m; ++i) {
        cin >> soldaten[i].first >> soldaten[i].second;
    }
    for (int i = 0; i < m; i++) {
        if (bfs(soldaten[i], i)) {
            cout << "No\n";
            return;
        }
    }
    for (int i = 0 ; i < n; i++) {
        if (vis[i] == -1) {
            cout << "No\n";
            return;
        }
    }
    cout << "Yes\n";
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
        Dowork();
    }
    return 0;
}