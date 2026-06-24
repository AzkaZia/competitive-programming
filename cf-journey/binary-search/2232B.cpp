#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll  = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<ll> a(n), outArray(n);
        for (int i=0;i<n;i++) cin >> a[i];

        ll currSum = 0;
        ll runningMin = LLONG_MAX;
        for (int i=0; i<n; i++) {
            currSum += a[i];
            runningMin = min(runningMin, currSum/(i+1));
            outArray[i] = runningMin;
        }
        for (int i=0;i<n;i++) cout << outArray[i] << " ";
        cout << "\n";
    }

}