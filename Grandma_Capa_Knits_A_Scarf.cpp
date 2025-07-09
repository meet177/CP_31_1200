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
        ll n;
        cin >> n;
        string s;
        cin >> s;
        ll ans = INF;
        for(ll x=0; x<26; x++) {
            char ch = (char)(x + 'a');
            ll curr = 0;
            ll i=0, j = n-1;
            while(i <= j) {
                if(s[i] != s[j]) {
                    if(s[i] == ch) {i++; curr++;}
                    else if(s[j] == ch) {j--; curr++;}
                    else break; 
                }else {
                    i++;
                    j--;
                }
            }
            //palindrome possible
            if(i > j) {
                ans = min(ans, curr);
            }
        }
        if(ans == INF) cout << -1 << "\n";
        else cout << ans << "\n";
    }
    return 0;
}