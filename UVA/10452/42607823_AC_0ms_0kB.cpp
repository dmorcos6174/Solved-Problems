#include <bits/stdc++.h>

using namespace std;
#define ll long long

int m, n;
vector<string> input;
string sol = "IEHOVA#";
int solI = 0;
vector<string> x;

void recurse(string path, vector<string> &moves, int i, int j){// path = "" initially
    if(path == sol)
        return;
    if(i > 0 && input[i-1][j] == sol[solI]){
        solI++;
        path += input[i-1][j];
        moves.push_back("forth");
        recurse(path, moves, i - 1, j);//forth
    }
    else if(j > 0 && input[i][j-1] == sol[solI]){
        solI++;
        path += input[i][j-1];
        moves.push_back("left");
        recurse(path, moves, i, j-1);//left
    }
    else if(j < n-1 && input[i][j+1] == sol[solI]){
        solI++;
        path += input[i][j+1];
        moves.push_back("right");
        recurse(path, moves, i, j+1);//right
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
        cin >> m >> n;
        input = vector<string>(m);
        for (int i = 0; i < m; ++i) {
            cin >> input[i];
        }
        int start = INT_MAX;
        for (int i = 0; i < n; ++i) {
            if(input[m-1][i] == '@'){
                start = i;
                break;
            }
        }
        recurse("", x, m - 1, start);
        for (int i = 0; i < x.size(); ++i) {
            if(i < x.size() - 1)
                cout << x[i] << " ";
            else
                cout << x[i];
        }
        cout << "\n";
        solI = 0;
        x.clear();
    }
}