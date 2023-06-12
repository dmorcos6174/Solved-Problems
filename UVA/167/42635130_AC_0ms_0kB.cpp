#include <bits/stdc++.h>

using namespace std;
#define ll long long

const int MAX = 8;
vector<int> ithRowQueen(MAX);
bool visited_col[MAX], reverse_diag[2*MAX-1], diag[2*MAX-1], sols=0;
int points[MAX][MAX];
vector<vector<int>> sol;

void Queens8(int r){
    if(r == 8){
//        print();
//        ++sol;
        sol.push_back(ithRowQueen);
        return;
    }
    for(int c=0; c<8; c++) {
        if(!visited_col[c] && !reverse_diag[c+r] && !diag[MAX-1+c-r]){
            ithRowQueen[r] = c;
            visited_col[c] = reverse_diag[c+r] = diag[MAX-1+c-r] = 1;
            Queens8(r+1);
            visited_col[c] = reverse_diag[c+r] = diag[MAX-1+c-r] = 0;
        }
    }
}

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
        for (int i = 0; i < 8; ++i) {
            for (int j = 0; j < 8; ++j) {
                cin >> points[i][j];
            }
        }
        Queens8(0);
        int maxScore = 0;
        for (int i = 0; i < sol.size(); ++i) {
            int score = 0;
            int pi = 0;
            for (int j = 0; j < 8; ++j) {
//                points += ;
                score += points[pi][sol[i][j]];
                pi++;
            }
            maxScore = max(maxScore, score);
        }
        cout << right << setw(5) << maxScore << "\n";
    }
}