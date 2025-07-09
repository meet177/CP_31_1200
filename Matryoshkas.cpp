#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define IM INT_MAX
#define LLM LONG_LONG_MAX
#define ll long long int
#define pll pair<ll,ll>

#define vll vector<ll>
#define vpll vector<pll>
#define vb vector<bool>
#define vs vector<string>

#define vvll vector<vector<ll>>
#define vvpll vector<vector<pll>>
#define vvb vector<vector<bool>>
#define vvs vector<vector<string>>

#define f(i,a,b) for(ll i=a; i<b; ++i)
#define fr(i,a,b) for(ll i=a-1; i>=b; --i)
#define fa(v) for(auto& it : v)
#define ff first
#define ss second
#define whole(x) (x).begin(), (x).end()

#define yes cout << "Yes\n"
#define no cout << "No\n"
#define out1(x) cout << (x) << "\n"
#define out2(x,y) cout << (x) << " " << (y) << "\n"
#define out3(x,y,z) cout << (x) << " " << (y) << " " << (z) << "\n"

#define inarr(x) f(i,0,n) cin >> x[i];
#define outarr(x) f(i,0,n) cout << x[i] << " "; cout << "\n";

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
        map<ll,ll> cnt;
        set<ll> val;
        //we have to play around c and c+1 so what we are doing is that we just put both inside a set and when we traverse in set wherever we find any last = 0 that means we have to partition our sets from there because there is no (c+1) so we have to make new sets and it will be automatically covered by this last ptr
        while(n--) {
            ll a;
            cin >> a;
            cnt[a]++;
            val.insert(a);
            val.insert(a+1);
        }
        ll ans = 0, last = 0;
        for(auto& v : val) {
            ll curr = cnt[v];
            ans += max(0LL,curr-last);
            last = curr;
        }
        out1(ans);
    }
    return 0;
}