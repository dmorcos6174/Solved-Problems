#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef long long ull;
typedef vector<ll> vi;

int n, T;
vector<vector<int>> g;

int dfs(int i) {
    if (!g[i].size()) return 1;

    vector<int> subvals(g[i].size());
    int c = 0;
    for (auto& subordinate : g[i]) {
        subvals[c++] = dfs(subordinate);
    }
    sort(subvals.begin(), subvals.end()); //sort is fucking stupid
    int sum = 0;
    for (int i = 0; i < ceil(T / 100.0 * subvals.size()); ++i) {
        sum += subvals[i];
    }
    return sum;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    while (cin >> n >> T && n && T) {
        g = vector<vector<int>>(n + 1);
        for (int i = 1; i <= n; ++i) {
            int boss;
            cin >> boss;
            g[boss].push_back(i);
        }
        cout << dfs(0) << endl;
    }
    return 0;
}
