#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);// comment in case of interactive problem (endl)
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
//    seive();
    int n;
    while(cin >> n && n != -1){
        long long x, y;
        long long num = 1, den = 1;
        for (int i = 0; i < n-1; ++i) {
            cin >> x >> y;
            num *= x;
            den *= y;
        }
        x = __gcd(num, den);
        cout << num/x << " " << den/x << "\n";
    }
}