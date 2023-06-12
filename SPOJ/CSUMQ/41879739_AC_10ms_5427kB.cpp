#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);// comment in case of interactive problem (endl)
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    int n;
    cin >> n;
    vector<int> vec(n+1, 0);
    for (int i = 1; i <= n; ++i) {
        cin >> vec[i];
        vec[i] += vec[i-1];
    }
    int q, l, r;
    cin >> q;
    while(q--){
        cin >> l >> r;
        cout << vec[r+1] - vec[l] << "\n";
    }
}