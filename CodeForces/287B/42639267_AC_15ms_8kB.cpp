#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long long ull;
typedef vector<ll> vi;

ll n, k;
ll ans = -1;

bool valid(ll x){
    ll temp = 1 + ((x+k) * (k-x+1))/2 - (k-x+1);
    if(temp >= n)
        return true;
    else
        return false;
}
//LAST TRUE
ll bs(ll s, ll e) {
    while (s <= e) {
        ll mid = s + (e - s + 1) / 2;
        if (valid(mid)){
            s = mid + 1;
            ans = mid;
        }
        else
            e = mid - 1;
    }
    return s;
}
////FIRST TRUE
//ll bs(ll s, ll e) {
//    while (s <= e) {
//        ll mid = (s + (e - s) / 2);
//        if (valid(mid)){
//            e = mid + 1;
//            ans = mid;
//        }
//        else
//            s = mid + 1;
//    }
//    return s;
//}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    cin >> n >> k;
    bs(2, k);
    if(ans == -1){
        cout << ans;
    }
    else if(n == 1){
        cout << 0;
    }
    else
        cout << k - ans + 1;
}