#include <bits/stdc++.h>
using namespace std;

int n, T;
vector<vector<int>> g;

int partition(vector<int>& a, int l, int r) {
    int j = l;
    for (int i = l; i < r; ++i) if (a[i] <= a[r]) swap(a[i], a[j]), j++;
    swap(a[r], a[j]);
    return j;
}

void quickSelect(vector<int>& a, int l, int r, int k) {
    if (l >= r) return;
    int ran = rand() % (r - l + 1) + l;
    swap(a[ran], a[r]);
    int i = partition(a, l, r);
    if (i == k) return;
    if (i < k) quickSelect(a, i + 1, r, k);
    else quickSelect(a, l, i - 1, k);
}

int dfs(int i) {
    if (!g[i].size()) return 1;

    vector<int> subvals(g[i].size());
    int c = 0;
    for (auto& subordinate : g[i]) {
        subvals[c++] = dfs(subordinate);
    }
    int k = int(ceil(T / 100.0 * subvals.size()));
    quickSelect(subvals, 0, subvals.size() - 1, k - 1);
    int sum = 0;
    for (int i = 0; i < k; ++i) {
        sum += subvals[i];
    }
    return sum;
}

int main() {
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