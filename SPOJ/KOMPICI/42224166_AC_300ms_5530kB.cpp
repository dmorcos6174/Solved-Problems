#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    ll pairs = 0;
    ll count[1024] = {0};
    for (int i = 0; i < n; ++i) {
        ll x;
        cin >> x;
        ll mask = 0;
        while (x > 0){
            int ind = x % 10;
            mask |= (1 << ind);
            x /= 10;
        }
        count[mask]++;
    }
    for (int i = 0; i < 1024; ++i) {
        for (int j = i+1; j < 1024; ++j) {
            if ((i & j) > 0)
                pairs += count[i] * count[j]; // 4, 104
        }
    }
    for (int i = 0; i < 1024; ++i) {
        if(count[i] > 1)
            pairs += (count[i] * (count[i] - 1)) / 2; //number of different combinations of same mask: 13, 31
    }
    cout << pairs << "\n";
}