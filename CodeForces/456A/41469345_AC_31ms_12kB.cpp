#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);// comment in case of interactive problem (endl)
//    freopen("word.in", "r", stdin);
//    freopen("word.out", "w", stdout);
    int n;
    int a,b;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a >> b;
        if (a != b){
            cout<< "Happy Alex\n";
            return 0;
        }
    }
    cout << "Poor Alex\n";
    return 0;
}