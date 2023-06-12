#include <bits/stdc++.h>

using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);// comment in case of interactive problem (endl)
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    long long ans = 0;
    for (long long x = 1; x <= 2e9; x *= 2) {
        map<int, int> map;
        for (int i = 0; i < n; ++i) {
            int aj = x - a[i];
            ans += map[aj];
            map[a[i]]++;
        }
    }
    cout << ans << "\n";
}