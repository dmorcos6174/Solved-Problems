#include <bits/stdc++.h>
using namespace std;
#define ll long long
 
vector<ll> getDivisors(ll n){
    vector<ll> ret;
    for(ll i=1; i<=n/i; i++){
        if(n % i == 0){
            ret.push_back(i);
            if(n != i * i)
                ret.push_back(n / i);
        }
    }
    return ret;
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ll t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        vector<ll> vec(n);
        for (ll i = 0; i < n; ++i) {
            cin >> vec[i];
        }
        sort(vec.begin(), vec.end());
        ll x = vec[0] * vec[n-1];
        vector<ll> divisors = getDivisors(x);
        sort(divisors.begin(), divisors.end());
        divisors.erase(divisors.begin());
        divisors.pop_back();
        if(vec == divisors)
            cout << x << "\n";
        else
            cout << -1 << "\n";
    }
}
//