#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);// comment in case of interactive problem (endl)
//    freopen("word.in", "r", stdin);
//    freopen("word.out", "w", stdout);
    bool flag = false;
    string x = "qwertyuiop";
    string y = "asdfghjkl;";
    string z = "zxcvbnm,./";
    string direction;
    string input;
    cin >> direction;
    cin >> input;
    for (int i = 0; i < input.size(); ++i) {
        size_t index = x.find(input[i]);
        size_t index2 = y.find(input[i]);
        size_t index3 = z.find(input[i]);
        if (index != string::npos){
            if (direction == "L")
                cout << x[index + 1];
            else
                cout << x[index - 1];
        }
        if (index2 != string::npos){
            if (direction == "L")
                cout << y[index2 + 1];
            else
                cout << y[index2 - 1];
        }
        if (index3 != string::npos){
            if (direction == "L")
                cout << z[index3 + 1];
            else
                cout << z[index3 - 1];
        }

    }
}