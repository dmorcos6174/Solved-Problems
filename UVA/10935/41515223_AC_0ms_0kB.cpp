#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);// comment in case of interactive problem (endl)
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    int n;
    while(cin >> n && n){
        deque<int> deq;
        for (int i = 0; i < n; ++i) {
            deq.push_back(i+1);
        }
        cout << "Discarded cards:";
        while(deq.size() >= 2){
            if(deq.size() == 2)
                cout << " " << deq[0];
            else
                cout << " " << deq[0] << ",";
            deq.pop_front();
            deq.push_back(deq[0]);
            deq.pop_front();
        }
        cout << "\n";
        cout << "Remaining card: " << deq[0] << "\n";
    }
}