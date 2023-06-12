#include <bits/stdc++.h>

using namespace std;
#define ll long long

ll n, m;
vector<ll> hotels;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    cin >> n >> m;
    hotels = vector<ll>(n);
    for (ll i = 0; i < n; ++i) {
        cin >> hotels[i];
    }
    vector<ll> cumm(n + 1);
    cumm[0] = 0;
    for (int i = 1; i <= n; ++i) {
        cumm[i] = cumm[i - 1] + hotels[i-1];
    }
    ll j = 1;
    ll ans = 0;
    for (ll i = 1; i <= n; ++i) {
        ll mx = 0;
        while (j <= n && cumm[j] - cumm[i-1] <= m){
            mx = cumm[j] - cumm[i-1];
            j++;
        }
        ans = max(ans, mx);
    }
    cout << ans;
}
