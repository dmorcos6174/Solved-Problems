#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);// comment in case of interactive problem (endl)
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    int n, x, ind;
    cin >> n >> x;
    vector<int> cumm(n+1, 0);
    for (int i = 1; i <= n; ++i) {
        cin >> cumm[i];
        if(cumm[i] > x)
            cumm[i] = 1;
        else if(cumm[i] == x)
            cumm[i] = 0, ind = i;
        else
            cumm[i] = -1;
        cumm[i] += cumm[i-1];
    }
    long long ans = 0;
    map<int, int> mp;
    for (int i = 0; i <= n; ++i) {
        if(i < ind)
            mp[cumm[i]]++;
        else{
            ans += mp[cumm[i]];
            ans += mp[cumm[i] - 1];
        }
    }
    cout << ans;
}