#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define whole(x) (x).begin(), (x).end()

const int M = 1e9 + 7;

void setupIO() {
    ios::sync_with_stdio(0);
    cin.tie(0);
}

vector<int> get_best3(vector<int>& a) {
    int m1 = -1, m2 = -1, m3 = -1;
    int n = a.size();
    for(int i=0; i<n; i++) {
        if(m1 == -1 || a[i] > a[m1]) {
            m3 = m2;
            m2 = m1;
            m1 = i;
        }else if(m2 == -1 || a[i] > a[m2]) {
            m3 = m2;
            m2 = i;
        }else if(m3 == -1 || a[i] > a[m3]) {
            m3 = i;
        }
    }
    return {m1, m2, m3};
}
int main() {
    setupIO();
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int>a(n), b(n), c(n);
        for(int i=0; i<n; i++) cin >> a[i];
        for(int i=0; i<n; i++) cin >> b[i];
        for(int i=0; i<n; i++) cin >> c[i];
        //what we have to do here is we have to take the best 3 values that we can take from each array because in that only we will be able to find our maximized answer so we are getting three maximum here and remember the approach of finding three maximum in linear time and avoid sorting whole array then we are just checking the conditions and finding the maximum answer for all possible cases
        vector<int>best1 = get_best3(a);
        vector<int>best2 = get_best3(b);
        vector<int>best3 = get_best3(c);
        int ans = 0;
        for(int i=0; i<3; i++) {
            for(int j=0; j<3; j++) {
                for(int k=0; k<3; k++) {
                    if(best1[i] != best2[j]  && best1[i] != best3[k] && best2[j] != best3[k]) {
                        ans = max(ans, a[best1[i]] + b[best2[j]] + c[best3[k]]);
                    }
                }
            }
        }
        cout << ans << "\n";
    }
    return 0;
}