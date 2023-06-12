#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);// comment in case of interactive problem (endl)
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    int n; bool flag = false;
    string temp1, temp2;
    cin >> n;
    vector<vector<string>> users;
    cin >> temp1 >> temp2;
    vector<string> tempVec;
    tempVec.push_back(temp1);
    tempVec.push_back(temp2);
    users.push_back(tempVec);
    for (int i = 1; i < n; ++i) {
        cin >> temp1 >> temp2;
        for (int j = 0; j < users.size(); ++j) {
            if (temp1 == users[j].back()){
                users[j].push_back(temp2);
                flag = true;
                break;
            }
        }
        if(!flag){
            vector<string> tempVec;
            tempVec.push_back(temp1);
            tempVec.push_back(temp2);
            users.push_back(tempVec);
        }
        flag = false;
    }
    cout << users.size() << "\n";
    for (int i = 0; i < users.size(); ++i) {
        cout << users[i].front() << " " << users[i].back() << "\n";
    }
}