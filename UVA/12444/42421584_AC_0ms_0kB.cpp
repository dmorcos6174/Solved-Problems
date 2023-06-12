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
    int t;
    cin >> t;
    while(t--){
        int c, d;
        cin >> c >> d;
        if((c & d) != c){
            cout << -1 << "\n";
            continue;
        }
        int m1 = 0, m2 = 0;
        for (int i = 0; i < 32; ++i) {
            if ((d >> i) & 1 && !(c >> i & 1))
                m1 = 1 << i;
        }
        m2 = ~m1;

        int b = c | (d & m1);
        int a = c | (d & m2);
        cout << a << " " << b << "\n";
    }
}