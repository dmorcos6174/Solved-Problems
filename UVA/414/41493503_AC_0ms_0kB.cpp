#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);// comment in case of interactive problem (endl)
//    freopen("word.in", "r", stdin);
//    freopen("word.out", "w", stdout);
    int n;
    while(cin >> n && n){
        cin.ignore();
        string input;
        vector<int> b(n);
        int minBlank = INT_MAX;
        int count;
        for (int i = 0; i < n; ++i) {
            count = 0;
            getline(cin, input);
            for (int j = 0; j < input.size(); ++j) {
                if (input[j] != 'X') count++;
            }
            b[i] = count;
            minBlank = min(minBlank, count);
        }
        int output = 0;
        for (int i = 0; i < n; ++i) {
            output += b[i] - minBlank ;
        }
        cout << output << "\n";
    }
}