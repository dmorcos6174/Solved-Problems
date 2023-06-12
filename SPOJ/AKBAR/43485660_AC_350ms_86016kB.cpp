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

int n, r, m;
vi vis;
vii adj;

struct node{
    int c, idx, s;
    node(){
        c = idx = s = 0;
    }
    node(int c1, int idx1, int s1){
        c = c1;
        idx = idx1;
        s = s1;
    }
};

void Dowork() {
    cin >> n >> r >> m;
    adj = vii(N);
    vis = vi(N, 0);
    for (int i = 0; i < r; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    //bfs
    queue<node> q;
    for (int i = 1; i <= m; ++i) {
        int c, s;
        cin >> c >> s;
        q.push(node(c, i, s));
    }
    bool flag = true;
    while(!q.empty()){
        node f = q.front();
        q.pop();
        if(vis[f.c]){
            if(vis[f.c] == f.idx){
                continue;
            }
            else{
                flag = false;
                break;
            }
        }
        vis[f.c] = f.idx;
        if(f.s == 0)
            continue;
        for (int i = 0; i < adj[f.c].size(); ++i) {
            q.push(node(adj[f.c][i], f.idx, f.s - 1));
        }
    }
    //
    for (int i = 1; i <= n; ++i) {
        if(vis[i] == 0)
            flag = false;
    }
    if(flag)
        cout <<"Yes\n";
    else
        cout <<"No\n";
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
    cin >> tt;
    while (tt--) {
        Dowork();
    }
    return 0;
}