#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);// comment in case of interactive problem (endl)
//    freopen("word.in", "r", stdin);
//    freopen("word.out", "w", stdout);
    set<char> s;
    string input;
    getline(cin, input);
    input.pop_back();
    input.erase(0,1);
    for (int i = 0; i < input.length(); ++i) {
        if (input[i] == ',' || input[i] == ' ')
            continue;
        s.insert(input[i]);
    }
    cout << s.size() << "\n";
}