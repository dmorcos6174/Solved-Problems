#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef long long ull;
typedef vector<ll> vi;
typedef vector<bool> vb;
typedef vector<char> vc;
typedef vector<vector<ll>> vii;
typedef vector<vector<vector<ll>>> viii;
typedef vector<vector<bool>> vbb;
typedef vector<vector<char>> vcc;
typedef pair<ll, ll> pii;

const int N = 1e6+5;
//bool notprime[N + 5];
//vector<int> primes;
//void seive(){
//    notprime[0] = notprime[1] = 1;
//    for(int i=1; i<=N/i; i++){
//        if(notprime[i])
//            continue;
//        for(int j=i*i; j<=N; j+=i)
//            notprime[j] = 1;
//    }
//    for(int i=2; i<=N; i++)
//        if(!notprime[i])
//            primes.push_back(i);
//}

ll v, e, sum;
vi dur;
vii adj, invadj;
vb vis;

ll dfs(vii& adj, int i){
    if(vis[i])
        return 0;
    vis[i] = true;
    ll ret = dur[i];
    for (int j = 0; j < adj[i].size(); ++j) {
        ret += dfs(adj, adj[i][j]);
    }
    return ret;
}

void Dowork() {
    int tc = 1;
    while (cin >> v >> e && (v || e)){
        dur = vi(v);
        adj = vii(v);
        invadj = vii(v);
        sum = 0;
        for (int i = 0; i < v; ++i) {
            cin >> dur[i];
            sum += dur[i];
        }
        int x, y;
        for (int i = 0; i < e; ++i) {
            cin >> x >> y;
            adj[x-1].push_back(y-1);
            invadj[y-1].push_back(x-1);
        }
        int q;
        cin >> q;
        cout << "Case #" << tc++ << ":\n";
        while(q--){
            vis = vb(v, false);
            int query;
            cin >> query;
            ll mn = dfs(adj, query - 1) - dur[query - 1];
            vis = vb(v, false);
            ll mx = sum - dfs(invadj, query - 1);
            cout << abs(mx - mn) << "\n";
        }
        cout << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
//    seive();
    int tt = 1;
//    cin >> tt;
    while (tt--) {
        Dowork();
    }
    return 0;
}