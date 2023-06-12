#include <bits/stdc++.h>
using namespace std;
#define ll long long

map<ll, ll> getFactors(ll n){
    map<ll, ll> mp;
    for(ll i=2; i<=n/i; i++){
        while(n % i == 0){
            mp[i]++;
            n /= i;
        }
    }
    if(n != 1){
        mp[n]++;
    }
    return mp;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ll x;
    while (cin >> x && x){
        bool flag = false;
        if(x < 0)
            flag = true;
        x = abs(x);
        map<ll, ll> factors = getFactors(x);
        ll ans = 0;
        for (auto it : factors) {
            ans = __gcd(it.second, ans);
        }
        if(flag){
            while(ans % 2 == 0)
                ans /= 2;
        }
        cout << ans << "\n";
    }
}