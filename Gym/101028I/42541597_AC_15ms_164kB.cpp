#include <bits/stdc++.h>

using namespace std;
#define ll long long

ll n, k;
vector<ll> a;

ll valid(ll l){
    ll count = 1;
    ll cur = a[0];
    for (int i = 1; i < n; ++i) {
        if(a[i] - cur < l)
            continue;
        else{
            count++;
            cur = a[i];
        }
    }
    return count;
}

ll bs(ll s, ll e) {
    while (s < e) {
        ll mid = (s + (e - s) / 2);
        if (valid(mid) <= k)
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
    int t;
    cin >> t;
    while(t--){
        cin >> n >> k;
        a = vector<ll>(n);
        for (ll i = 0; i < n; ++i) {
            cin >> a[i];
        }
        ll ans = 0;
        ans = bs(1, a[n-1]);
        cout << ans << "\n";
    }
}