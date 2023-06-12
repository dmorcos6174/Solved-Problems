#include <bits/stdc++.h>

using namespace std;

//bool powerOfTwo(int n){
//    if (n == 0)
//        return false;
//    return (ceil(log2(n)) == floor(log2(n)));
//}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);// comment in case of interactive problem (endl)
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    int count = 0;
    int n;
    while(cin >> n && n){
        priority_queue<int, vector<int>, greater<int>> q;
        int cost = 0; int temp;
        for (int i = 0; i < n; ++i) {
            cin >> temp;
            q.push(temp);
        }
        int partCost = 0;
        while (q.size() > 1){
            partCost = q.top();
            q.pop();
            partCost += q.top();
            q.pop();
            cost += partCost;
            q.push(partCost);
        }
        cout << cost << "\n";
    }
}