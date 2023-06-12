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

const int N = 1000;
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

int n, m;
vii adj;

bool isCyclicUtil(int v, vb& vis, vb& recStack) {
    if (vis[v] == false) {
        vis[v] = true;
        recStack[v] = true;
        for (auto i = adj[v].begin(); i != adj[v].end(); ++i) {
            if (!vis[*i]
                && isCyclicUtil(*i, vis, recStack))
                return true;
            else if (recStack[*i])
                return true;
        }
    }
    recStack[v] = false;
    return false;
}

bool isCyclic() {
    vb vis(n + 1, false);
    vb recStack(n + 1, false);
    for (int i = 1; i <= n; ++i) {
        if (!vis[i] && isCyclicUtil(i, vis, recStack))
            return true;
    }
    return false;
}

void dfs(vii &adj, int v, vb &vis, stack<int> &hier) {
    vis[v] = true;
    for (auto j = adj[v].begin(); j != adj[v].end(); ++j) {
        if (!vis[*j])
            dfs(adj, *j, vis, hier);
    }
    hier.push(v);
}

stack<int> topSort(vii &adj) {
    stack<int> hier;
    vb vis(n + 1, false);
    for (int i = 1; i <= n; ++i) {
        if (!vis[i]) {
            dfs(adj, i, vis, hier);
        }
    }
    return hier;
}

void Dowork() {
    cin >> n >> m;
    adj = vii(n + 1);
    for (int i = 0; i < m; ++i) {
        ll a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }
    if (isCyclic()) {
        cout << -1 << "\n";
    } else {
        stack<int> hier = topSort(adj);
        vi path;
        while (!hier.empty()) {
            int front = hier.top();
            hier.pop();
            path.push_back(front);
        }
        for (int i = 0; i < path.size(); i++) {
            cout << path[i] << " ";
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
    cin >> tt;
    while (tt--) {
        Dowork();
    }
    return 0;
}