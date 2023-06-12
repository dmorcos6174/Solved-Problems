#include <bits/stdc++.h>

using namespace std;
#define ll long long

int n, S;
vector<int> vec;

ll valid(int k){
    vector<ll> v(n);
    for (int i = 0; i < n; ++i) {
        v[i] = vec[i] + (i+1) * (ll)k;
    }
    sort(v.begin(), v.end());
    ll ans = 0;
    for (int i = 0; i < k; ++i) {
        ans += v[i];
    }
    return ans;
}
int bs(int s, int e) {
    while (s < e) {
        int mid = s + (e - s + 1) / 2;
        if (valid(mid) <= S) s = mid;
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
    cin >> n >> S;
    vec = vector<int>(n);
    for (int i = 0; i < n; ++i) {
        cin >> vec[i];
    }
    int k = bs(0, n);
    cout << k << " " << valid(k);
}
