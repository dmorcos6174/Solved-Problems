#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);// comment in case of interactive problem (endl)
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    string temp1;
    string word;
    int m, n, temp2;
    cin >> m >> n;
    map<string, int> map;
    for (int i = 0; i < m; ++i) {
        cin >> temp1;
        cin >> temp2;
        map[temp1] = temp2;
    }
    for (int i = 0; i < n; ++i) {
        int value = 0;
        while (cin >> word && word != "."){
            auto iter = map.find(word);
            if(iter != map.end())
                value += iter->second;
        }
        cout << value << "\n";
    }
}