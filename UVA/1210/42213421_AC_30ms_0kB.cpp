#include <bits/stdc++.h>
using namespace std;

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
    int s;
    while(cin >> s && s){
        int count = 0;
        for (int i = 0; i <= s; ++i) {
            int sum = 0;
            int j = i;
            while (primes[j] <= s){
                if(sum < s)
                    sum += primes[j];
                if(sum == s){
                    count++;
                    break;
                }
                j++;
            }
        }
        cout << count << "\n";
    }
}