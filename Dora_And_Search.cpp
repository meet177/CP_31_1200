#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define pb push_back
#define mp make_pair
#define vll vector<ll>
#define vvll vector<vector<ll>>
#define vs vector<string>
#define vp vector<pair<ll,ll>>

#define f(i,a,b) for(ll i=a; i<b; ++i)
#define fr(i,a,b) for(ll i=a-1; i>=b; --i)
#define fa(v) for(auto& it : v)
#define ff first
#define ss second
#define whole(x) (x).begin(), (x).end()

#define yes cout << "Yes\n"
#define no cout << "No\n"
#define out(x) cout << (x) << "\n"

const ll M = 1e9 + 7;

void setupIO() {
    ios_base::sync_with_stdio(false); //disables the sync between ios and stdio
    cin.tie(0); //untie cin and cout
    cout.tie(0); //optional
}

int main() {
    setupIO();
    ll t;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;
        vll v(n);
        f(i,0,n) cin >> v[i];
        ll i = 0, j = n-1;
        ll mini = 1, maxi = n;
        while(i < j) {
            if(v[i] == mini) {
                ++mini;
                ++i;
            }else if(v[i] == maxi) {
                --maxi;
                ++i;
            }else if(v[j] == mini) {
                ++mini;
                --j;
            }else if(v[j] == maxi) {
                --maxi;
                --j;
            }else {
                break;
            }
        }
        if(i < j) {
            cout << i+1 << " " << j+1 << "\n";
        }else {
            cout << -1 << "\n";
        }
    }
    return 0;
}