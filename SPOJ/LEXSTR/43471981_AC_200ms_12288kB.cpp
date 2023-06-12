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

const int N = 1e5+5;
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

int m;
vb vis;
vii adj;

void dfs(string& s, vi& visIdx, vc& visChar, int i){
    if(vis[i])
        return;
    vis[i] = true;
    visIdx.push_back(i);
    visChar.push_back(s[i]);
    for (int j = 0; j < adj[i].size(); ++j) {
        dfs(s, visIdx, visChar, adj[i][j]);
    }
}

void Dowork() {
    string s;
    cin >> s;
    adj = vii(N);
    vis = vb(N, false);
    cin >> m;
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for (int i = 0; i < s.size(); ++i) {
        vi visIdx;
        vc visChar;
        dfs(s, visIdx, visChar, i);
        sort(visIdx.begin(), visIdx.end());
        sort(visChar.begin(), visChar.end());
        for (int j = 0; j < visIdx.size(); ++j) {
            s[visIdx[j]] = visChar[j];
        }
    }
    cout << s << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
//    seive();
    int t = 1;
    cin >> t;
    while (t--) {
        Dowork();
    }
    return 0;
}