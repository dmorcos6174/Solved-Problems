#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);// comment in case of interactive problem (endl)
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    int n;
    cin >> n;
    vector<long long> cumm(n+1);
    vector<long long> square(n+1);
    for (int i = 1; i <= n; ++i) {
        cin >> cumm[i];
        square[i] = (cumm[i]*cumm[i]) + square[i-1];
        cumm[i] += cumm[i-1];
    }
    int q;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        int x, y;
        long long a, b, s;
        cin >> x >> y;
        a = cumm[y+1] - cumm[x];
        a *= a;
        b = square[y+1] - square[x];
        s = (a - b) / 2;
        cout << (b + s) << "\n";
    }
}