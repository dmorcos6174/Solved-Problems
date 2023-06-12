#include <bits/stdc++.h>

using namespace std;
#define ll long long

ll n, m, k;

ll valid(ll l){
    ll count = 0;
    for (int i = 1; i <= n; ++i) {
        count += min(m,l/i);
    }
    return count;
}

ll bs(ll s, ll e) {
    while (s < e) {
        ll mid = (s + (e - s) / 2);
        if (valid(mid) >= k)
            e = mid;
        else s = mid + 1;
    }
    return s;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    cin >> n >> m >> k;
    ll ans = 0;
    ans = bs(1, n*m);
    cout << ans << "\n";
}