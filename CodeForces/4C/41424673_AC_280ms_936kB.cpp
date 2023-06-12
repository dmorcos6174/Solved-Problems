#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);// comment in case of interactive problem (endl)
//    freopen("word.in", "r", stdin);
//    freopen("word.out", "w", stdout);
    int n;
    string input;
    map<string, int> m;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> input;
        if (!m.count(input)){
            cout << "OK\n";
            m[input] = 1;
        }
        else{
            cout << input << m[input]++ << "\n";
        }
    }
}