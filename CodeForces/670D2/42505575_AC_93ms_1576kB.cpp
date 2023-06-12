#include <bits/stdc++.h>

using namespace std;
#define ll long long

ll n, k;
vector<ll> a;
vector<ll> b;

ll valid(ll x){
    ll cost = 0;
    for (int i = 0; i < n; ++i) {
        cost += max((ll)0, a[i]*x - b[i]);
        if(cost > k){
            break;
        }
    }
    return cost;
}

ll bs(ll s, ll e) {
    while (s < e) {
        ll mid = s + (e - s + 1) / 2;
        if (valid(mid) <= k)
            s = mid;
        else e = mid - 1;
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
    cin >> n >> k;
    a = vector<ll>(n);
    b = vector<ll>(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }
    ll ans = 0;
    ans += bs(0, 1e10);
    cout << ans;
}