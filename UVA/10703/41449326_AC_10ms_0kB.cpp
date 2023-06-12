#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);// comment in case of interactive problem (endl)
//    freopen("word.in", "r", stdin);
//    freopen("word.out", "w", stdout);
    int w, h, n;
    int x1, y1, x2, y2;
    while (cin >> w >> h >> n){
        if (w == 0 && h == 0 && n == 0)
            break;
        vector<vector<bool>> vec(w+1, vector<bool> (h+1, false));
        int empty = 0;
        for (int ind = 0; ind < n; ++ind) {
            cin >> x1 >> y1 >> x2 >> y2;
            if(x1 > x2) swap(x1, x2);
            if(y1 > y2) swap(y1, y2);
            for (int i = x1; i <= x2; ++i) {
                for (int j = y1; j <= y2; ++j) {
                    vec[i][j] = true;
                }
            }
        }
        for (int i = 1; i <= w; ++i) {
            for (int j = 1; j <= h; ++j) {
                if(!vec[i][j])
                    empty++;
            }
        }
        if (empty == 0) cout << "There is no empty spots.\n";
        else if (empty == 1) cout << "There is one empty spot.\n";
        else cout << "There are "<< empty <<" empty spots.\n";
    }
}