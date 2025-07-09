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
        ll n,m;
        cin >> n >> m;
        vector<ll> a(m);
        for(ll i=0; i<m; i++) cin >> a[i];
        sort(whole(a)); //houses will be sorted
        vector<ll> gaps;
        for(ll i=0; i<m-1; i++) {
            gaps.push_back(a[i+1] - a[i] - 1); //gap between every two consecutive infected
        }
        gaps.push_back((n - a[m-1]) + (a[0] - 1)); //circular gap 
        sort(whole(gaps), greater<ll>()); //will pick largest gap first 
        ll saved = 0, days = 0; //currently we are on day 0
        for(auto& gap : gaps) {
            //in every gap after each day 2 houses will be infected
            ll currgap = gap - 2*days;
            if(currgap > 0) {
                saved++;// save left extremity first
                currgap -= 2;
                if(currgap > 0) saved += currgap; //save right extremity and save all in range
                days += 2; //in every segment we need max 2 days
            }
        }
        //total - saved will be infected
        cout << (n - saved) << "\n";
    }
    return 0;
}