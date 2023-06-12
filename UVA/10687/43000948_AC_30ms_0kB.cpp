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


ll distance(pii a, pii b)
{
    return (b.first - a.first) * (b.first - a.first) + (b.second - a.second) * (b.second - a.second);
}

void dfs(vii& graph, vb& vis, ll s){
    if(vis[s])
        return;
    vis[s] = true;
    for (ll i = 0; i < graph[s].size(); ++i) {
        dfs(graph, vis, graph[s][i]);
    }
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ll n;
    while (cin >> n && n){
        vector<pii> stations(n);
        vb vis(n, false);
        vii graph(n);
        for (ll i = 0; i < n; ++i) {
            cin >> stations[i].first >> stations[i].second;
        }
        if(n < 4){
            cout << "All stations are reachable.\n";
            continue;
        }
        pii dispatch = stations[0];
        sort(stations.begin(), stations.end());
//        for (ll i = 0; i < n; ++i) {
//            cout << stations[i].first << " " << stations[i].second << " . ";
//        }
//        cout << "\n";
        for (ll i = 0; i < n; ++i) {
            pii nearest = {LONG_LONG_MAX, 0}, secnearest = {LONG_LONG_MAX, 0};
            for (ll j = 0; j < n; ++j) {
                if(i != j){
                    ll d = distance(stations[i], stations[j]);
                    if (d < secnearest.first){
                        secnearest.first = d;
                        secnearest.second = j;
                    }
                    if (secnearest.first < nearest.first){
                        swap(nearest, secnearest);
                    }
                }
            }
            graph[i].push_back(nearest.second);
            graph[i].push_back(secnearest.second);
        }
        ll s = 0;
        for (ll i = 0; i < n; ++i) {
            if(stations[i] == dispatch){
                s = i;
                break;
            }
        }
        dfs(graph, vis, s);
        bool ans = true;
        for (ll i = 0; i < n; ++i) {
            ans &= vis[i];
        }
        if (ans)
            cout << "All stations are reachable.\n";
        else
            cout << "There are stations that are unreachable.\n";
    }
}