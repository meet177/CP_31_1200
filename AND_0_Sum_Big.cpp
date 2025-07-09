#include <bits/stdc++.h>
using namespace std;

#define ll long long int
const ll INF = 1e18;
const ll M = 1e9 + 7;
#define PI acos(-1)

#define whole(x) (x).begin(), (x).end()

#define yes cout << "Yes\n"
#define no cout << "No\n"

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    ll t = 1;
    cin >> t;
    while(t--) {
        ll n,k;
        cin >> n >> k;
        //see at first put all elements equal to 2^(k-1) that is max element so now it has all bits on but sum is maximized so now we have to make & zero so that our sum should be as large as possible 
        //now what we can do is we have a number with k bits on and we have n numbers so we can make & zero by making all bits off only one time that is we can off any bit from any number but only one time
        //so now we have total k bits and n numbers so the first bit can be off in any of n numbers, then second can be also off in any of n numbers, and so on the number of ways we can make & zero will be n^k
        ll ans = 1;
        for(ll i=0; i<k; i++) ans = (ans * n) % M;
        cout << ans << '\n';  
    }
    return 0;
}