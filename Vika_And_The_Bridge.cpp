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
        int n, k;
        cin >> n >> k;
        vector<int>arr(n);
        for(int i=0; i<n; i++) cin >> arr[i];
        vector<int>max_diff(k+1,-1);
        vector<int>sec_max_diff(k+1,-1);
        vector<int>prev(k+1,-1);
        for(int i=0; i<n; i++) {
            int curr_diff = 0;
            if(prev[arr[i]] == -1) {
                curr_diff = i;
            }else {
                curr_diff = (i - prev[arr[i]] - 1);
            }
            prev[arr[i]] = i;
            if(curr_diff > max_diff[arr[i]]) {
                sec_max_diff[arr[i]] = max_diff[arr[i]];
                max_diff[arr[i]] = curr_diff;
            }else if(curr_diff > sec_max_diff[arr[i]]) {
                sec_max_diff[arr[i]] = curr_diff;
            }
        }
        for(int i=1; i<k+1; i++) {
            if(max_diff[i] != -1) {
                int curr_diff = (n - prev[i] - 1);
                if(curr_diff > max_diff[i]) {
                    sec_max_diff[i] = max_diff[i];
                    max_diff[i] = curr_diff;
                }else if(curr_diff > sec_max_diff[i]) {
                    sec_max_diff[i] = curr_diff;
                }
            }
        }
        int ans = INT_MAX;
        for(int i=1; i<k+1; i++) {
            if(max_diff[i] != -1) {
                int poss1 = (max_diff[i] >> 1);
                int poss2 = sec_max_diff[i];
                ans = min(ans,max(poss1,poss2));
            }
        }
        cout << ans << "\n";
    }
    return 0;
}