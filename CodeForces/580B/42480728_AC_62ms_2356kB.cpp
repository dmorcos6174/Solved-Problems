#include <bits/stdc++.h>

using namespace std;
#define ll long long

ll n, d;
vector<pair<ll, ll>> money_ff;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    cin >> n >> d;
    money_ff = vector<pair<ll, ll>>(n);
    for (ll i = 0; i < n; ++i) {
        cin >> money_ff[i].first >> money_ff[i].second;
    }
    sort(money_ff.begin(), money_ff.end());
    vector<ll> cumff(n+1);
//    cumff[0] = money_ff[0].second;
    cumff[0] = 0;
    for (int i = 1; i <= n; ++i) {
        cumff[i] = cumff[i-1] + money_ff[i-1].second;
    }
    ll j = 0;
    ll ans = 0;
    for (ll i = 0; i < n; ++i) {
        ll mx = 0;
        while (j < n && money_ff[j].first - money_ff[i].first < d){
            mx = cumff[j+1] - cumff[i];
            j++;
        }
        ans = max(ans, mx);
    }
    cout << ans;
}
