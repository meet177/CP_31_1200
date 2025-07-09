#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define ll long long int
#define INF 1e9 + 10
#define pll pair<ll,ll>

#define vll vector<ll>
#define vpll vector<pll>
#define vb vector<bool>
#define vs vector<string>

#define f(i,a,b) for(ll i=a; i<b; ++i)
#define fr(i,a,b) for(ll i=a-1; i>=b; --i)
#define ff first
#define ss second
#define whole(x) (x).begin(), (x).end()

#define yes cout << "Yes\n"
#define no cout << "No\n"
#define out1(x) cout << (x) << "\n"
#define out2(x,y) cout << (x) << " " << (y) << "\n"
#define out3(x,y,z) cout << (x) << " " << (y) << " " << (z) << "\n"

const ll M = 1e9 + 7;

ll modAdd(ll a, ll b) { return ((a % M + b % M) % M); }
ll modSub(ll a, ll b) { return ((a % M - b % M + M) % M); }
ll modMul(ll a, ll b) { return ((a % M) * (b % M)) % M; }
ll modPow(ll a, ll b) {
    ll ans = 1;
    while(b) {
        if(b & 1) ans = modMul(ans, a);
        a = modMul(a, a);
        b >>= 1;
    }
    return ans;
}
ll modInv(ll a) { return modPow(a, M - 2); } // If M is prime

void solve() {
    ll n, q; cin >> n >> q;
    vll a(n);
    f(i,0,n) cin >> a[i];
    //1 2 2 5
    vll pfsum(n);
    pfsum[0] = a[0];
    f(i,1,n)  pfsum[i] = pfsum[i-1] + a[i];
    f(i,1,n) {
        a[i] = max(a[i], a[i-1]);
    }
    //this will be sorted non decreasing 
    while(q--) {
        ll v;
        cin >> v;
        auto it = upper_bound(whole(a), v);
        ll ind = it - a.begin();
        if(ind == 0) cout << 0 << " ";
        else cout << pfsum[ind-1] << " ";
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    ll t = 1;
    cin >> t;
    f(i,0,t) solve();
    return 0;
}