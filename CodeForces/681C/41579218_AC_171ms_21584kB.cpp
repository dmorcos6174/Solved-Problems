#include <bits/stdc++.h>

using namespace std;




int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);// comment in case of interactive problem (endl)
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    int n;
    cin >> n;
    priority_queue <int, vector<int>, greater<int> > q;
    vector <pair<string, int>> vec;
    string temp1; int temp2;
    for (int i = 0; i < n; ++i) {
        cin >> temp1;
        if (temp1 == "insert"){
            cin >> temp2;
            q.push(temp2);
            vec.emplace_back(temp1, temp2);
        }
        else if (temp1 == "getMin"){
            cin >> temp2;
            if (!q.empty()){
                while(temp2 > q.top() && !q.empty()){
                    vec.emplace_back("removeMin", q.top());
                    q.pop();
                }
                if (q.top() > temp2 || q.empty()){
                    q.push(temp2);
                    vec.emplace_back("insert", temp2);
                }
                vec.emplace_back("getMin", temp2);
            }
            else{
                q.push(temp2);
                vec.emplace_back("insert", temp2);
                vec.emplace_back("getMin", temp2);
            }
        }
        else{
            if (q.empty())
                vec.emplace_back("insert", 0);
            else
                q.pop();
            vec.emplace_back(temp1, 0);
        }
    }
    cout << vec.size() << "\n";
    for (int i = 0; i < vec.size(); ++i) {
        if(vec[i].first == "removeMin")
            cout << vec[i].first << "\n";
        else
            cout << vec[i].first << " " << vec[i].second << "\n";
    }
}