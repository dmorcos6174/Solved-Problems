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
typedef pair<int, int> pii;

map<pii, bool> vis;
int a, b, c;

int bfs(pii state){
    queue<pii> q;
    int level = 0;
    q.push(state);
    while(!q.empty()){
        int level_size = q.size();
        while(level_size--){
            pii node = q.front();
            q.pop();
            if(vis[node])
                continue;
            if(node.first == c || node.second == c)
                return level;
            vis[node] = true;
            q.emplace(node.first, 0);//empty first
            q.emplace(0, node.second);//empty second
            q.emplace(a, node.second);//fill first
            q.emplace(node.first, b);//fill second
            q.emplace(max(node.first - b + node.second, 0), min(node.first + node.second, b));//pour first into second
            q.emplace(min(node.first + node.second, a), max(node.second - a + node.first, 0));//pour second into first
        }
        level++;
    }
    return -1;
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
    while (t--) {
        cin >> a >> b >> c;
        if(c%__gcd(a,b)!=0){
            cout<< -1 <<endl;
        }
        else if(a < c && b < c)
            cout << -1 << "\n";
        else{
            vis.clear();
            cout << bfs({0,0}) << "\n";
        }
    }
}