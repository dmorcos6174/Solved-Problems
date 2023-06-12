#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 1e6;
bool notprime[N + 5];
vector<int> primes;
void seive(){
    notprime[0] = notprime[1] = 1;
    for(int i=1; i<=N/i; i++){
        if(notprime[i])
            continue;
        for(int j=i*i; j<=N; j+=i)
            notprime[j] = 1;
    }
    for(int i=2; i<=N; i++)
        if(!notprime[i])
            primes.push_back(i);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    seive();
    string n;
    while(cin >> n && n!= "0"){
        int digits[255];
        int MAX = 0;
        for (int i = 0; i < n.size(); ++i) {
            digits[i] = n[i] - '0';
        }
        for (int i = 0; i < n.size(); ++i) {
            int mx = 0;
            for (int j = i; j < n.size(); ++j) {
                mx = mx * 10 + digits[j];
                if(mx > 100000)
                    break;
                if(notprime[mx] == false)
                    MAX = max(MAX, mx);
            }
        }
        cout << MAX << "\n";
    }
}