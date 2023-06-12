#include <bits/stdc++.h>

using namespace std;
#define ll long long

int n, m;
vector<string> words;
vector<string> rules;
string digits = "0123456789";
int di = 0;
int ri = 0;
//int rj = 0;
int wi = 0;
int rl = 0;

void recurse(string word, int rj){
    if(rj == rl){
        cout << word << '\n';
    }
    if(rules[ri][rj] == '#'){
        word += words[wi];
        recurse(word, rj+1);
    }
    else if(rules[ri][rj] == '0'){
        for (int i = 0; i < digits.size(); ++i) {
            word += digits[i];
            recurse(word, rj+1);
            word.pop_back();
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
    while(cin >> n){
        words = vector<string>(n);
        for (int i = 0; i < n; ++i) {
            cin >> words[i];
        }
        cin >> m;
        rules = vector<string>(m);
        for (int i = 0; i < m; ++i) {
            cin >> rules[i];
        }
        cout << "--\n";
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                rl = rules[j].size();
                recurse("", 0);
                di = 0;
                ri = 0;
//                rj = 0;
            }
            wi++;
        }
        wi = 0;
    }
}