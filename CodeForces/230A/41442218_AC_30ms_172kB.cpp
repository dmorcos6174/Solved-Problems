#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);// comment in case of interactive problem (endl)
//    freopen("word.in", "r", stdin);
//    freopen("word.out", "w", stdout);
    int s, n, temp;
    bool flag = true;
    cin >> s >> n;
    vector<vector<int>> vec(n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 2; ++j) {
            cin >> temp;
            vec[i].push_back(temp);
        }
    }
    sort(vec.begin(), vec.end());
    for (int i = 0; i < n; ++i) {
        if (s > vec[i][0])
            s += vec[i][1];
        else{
            flag = false;
            break;
        }
    }
    if (flag == true) cout << "YES\n";
    else cout << "NO\n";
}