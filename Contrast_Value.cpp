#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define whole(x) (x).begin(), (x).end()

const int M = 1e9 + 7;

void setupIO() {
    ios::sync_with_stdio(0);
    cin.tie(0);
}

int main() {
    setupIO();
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int>a(n);
        for(int i=0; i<n; i++) cin >> a[i];
        //see observe one thing that is if we have
        //(a[i-1] > a[i] > a[i+1]) || (a[i-1] < a[i] < a[i+1]) so what we have is that
        //|a[i]-a[i+1]| + |a[i]-a[i+1]| = |a[i-1]+a[i-2]|
        //so we can remove a[i] and contrast will not change
        int can_remove = 0;
        for(int i=1; i<n-1; i++) {
            if((a[i-1]>=a[i] && a[i+1]<=a[i]) || (a[i-1]<=a[i] && a[i+1]>=a[i])) {
                can_remove++;
                a[i] = a[i-1];
            }
        }
        if((n == 1) || (a[n-1] == a[n-2])) {
            cout << 1 << "\n";
            continue;
        }
        cout << n - can_remove << "\n";
    }
    return 0;
}