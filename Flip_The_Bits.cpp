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
        //010101010101
        //100110011010
        ll n;
        cin >> n;
        string a,b;
        cin >> a >> b;
        vector<ll> pfzeroes(n,0);
        pfzeroes[0] = (a[0] == '0');
        for(ll i=1; i<n; i++) pfzeroes[i] = pfzeroes[i-1] + (a[i] == '0');
        bool flag = 1;
        ll flips = 0;
        for(ll i=n-1; i>=0; i--) {
            if(flips & 1) {
                if(a[i] == b[i]) {
                    ll zeroes = pfzeroes[i];
                    ll ones = (i + 1 - zeroes);
                    if(ones == zeroes) flips++;
                    else {
                        flag = 0;
                        break;
                    }
                }
            }else {
                if(a[i] != b[i]) {
                    ll zeroes = pfzeroes[i];
                    ll ones = (i + 1 - zeroes);
                    if(ones == zeroes) flips++;
                    else {
                        flag = 0;
                        break;
                    }
                }
            }
        }
        if(flag) yes;
        else no;
    }
    return 0;
}