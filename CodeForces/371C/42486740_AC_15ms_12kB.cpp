#include <bits/stdc++.h>

using namespace std;
#define ll long long

ll nb, ns, nc, pb, ps, pc, money, rb = 0, rs = 0, rc = 0;
ll valid(ll x){
    ll cost = max((ll)0, rb*x - nb)*pb + max((ll)0, rs*x - ns)*ps + max((ll)0, rc*x - nc)*pc;
    return cost;
}

ll bs(ll s, ll e) {
    while (s < e) {
        ll mid = s + (e - s + 1) / 2;
        if (valid(mid) <= money) s = mid;
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
    string recipe;
    cin >> recipe;
    cin >> nb >> ns >> nc >> pb >> ps >> pc >> money;
    for (ll i = 0; i < recipe.size(); ++i) {
        if(recipe[i] == 'B')
            rb++;
        else if(recipe[i] == 'S')
            rs++;
        else
            rc++;
    }
    ll ans = 0;
//    while((nb - rb >= 0) && (ns - rs >= 0) && (nc - rc >= 0)){
//        ans++;
//    }
    ans += bs(0, 1e14);
    cout << ans;
}
