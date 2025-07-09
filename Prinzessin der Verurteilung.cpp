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
        vector<bool> single(26,0);
        for(ll i=0; i<n; i++) single[s[i] - 'a'] = 1;
        bool found = 0;
        for(ll i=0; i<26; i++) {
            if(single[i] == 0) {
                found = 1;
                cout << (char)(i + 'a') << '\n';
                break;
            }
        }
        if(!found) {
            vector<bool> doubles(676,0);
            for(ll i=0; i<n-1; i++) {
                ll curr = 26*(s[i] - 'a') + (s[i+1] - 'a');
                doubles[curr] = 1;
            }
            for(ll i=0; i<676; i++) {
                //26*a + b
                if(doubles[i] == 0) {
                    found = 1;
                    ll a = i/26, b = i%26;
                    char ch_a = (char)(a + 'a');
                    char ch_b = (char)(b + 'a');
                    cout << ch_a << ch_b << "\n";
                    break;
                }
            }
        }
        if(!found) {
            vector<bool> triple(1001,0);
            for(ll i=0; i<n-2; i++) {
                ll curr = 676*(s[i] - 'a') + 26*(s[i+1] - 'a') + (s[i+2] - 'a');
                if(curr > 1000) continue;
                triple[curr] = 1;
            }
            for(ll i=0; i<1001; i++) {
                //676*a + 26*b + c
                if(triple[i] == 0) {
                    ll a = i/676, bc = i%676;
                    ll b = bc/26, c = bc%26;
                    char ch_a = (char)(a + 'a');
                    char ch_b = (char)(b + 'a');
                    char ch_c = (char)(c + 'a');
                    cout << ch_a << ch_b <<  ch_c << "\n";
                    break;
                }
            }
        }
    }
    return 0;
}