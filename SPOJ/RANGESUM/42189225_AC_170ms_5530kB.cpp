#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    deque<long long> deq(n, 0);
    for (int i = 0; i < n; ++i) {
        cin >> deq[i];
    }
    for (int i = n-2; i >= 0 ; --i) {
        deq[i] = deq[i] + deq[i+1];
    }
    int q;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        int op;
        cin >> op;
        if(op == 1){
            int l, r;
            cin >> l >> r;
            if(r == n)//r % 10
                cout << deq[l-1] << "\n";
            else{
                cout << deq[l-1] - deq[r] << "\n";
            }
        }
        else{
            long long temp;
            cin >> temp;
            deq.push_front(temp);
            deq[0] = deq[0] + deq[1];
            n++;
        }
    }
}