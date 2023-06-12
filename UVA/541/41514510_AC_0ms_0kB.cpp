#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);// comment in case of interactive problem (endl)
//    freopen("word.in", "r", stdin);
//    freopen("word.out", "w", stdout);
    int n;
    while(cin >> n && n){
        vector<vector<int>> matrix(n, vector<int> (n, 0));
        vector<int> countR(n, 0); vector<int> countC(n, 0);
        int paritycountR = 0, paritycountC = 0;
        int r, c;
        int i, j;
        for (i = 0; i < n; ++i) {
            for (j = 0; j < n; ++j) {
                cin >> matrix[i][j];
            }
        }
        for (i = 0; i < n; ++i) {
            for (j = 0; j < n; ++j) {
                countR[i] += matrix[i][j];
                countC[i] += matrix[j][i];
            }
        }
        for (i = 0; i < n; ++i) {
            if (countR[i] & 1){
                paritycountR++;
                r = i;
            }
            if (countC[i] & 1){
                paritycountC++;
                c = i;
            }
        }
        if(paritycountR == 0 && paritycountC == 0)
            cout << "OK\n";
        else if (paritycountR == 1 && paritycountC == 1)
            cout << "Change bit (" << r+1 << "," << c+1 << ")\n";
        else
            cout << "Corrupt\n";
    }
}