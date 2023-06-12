#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);// comment in case of interactive problem (endl)
//    freopen("word.in", "r", stdin);
//    freopen("word.out", "w", stdout);
    int n, p, q, j;
    bool freq[n+1];
    cin >> n;
    cin >> p;
    for (int i = 0; i < p; ++i) {
        cin >> j;
        freq[j] = true;
    }
    cin >> q;
    for (int i = 0; i < q; ++i) {
        cin >> j;
        freq[j] = true;
    }
    for (int i = 1; i <= n; ++i) {
        if(freq[i] == false){
            cout << "Oh, my keyboard!\n";
            return 0;
        }
    }
    cout << "I become the guy.\n";
}