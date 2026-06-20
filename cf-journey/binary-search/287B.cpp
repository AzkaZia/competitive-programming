#include <iostream>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, k;
    cin >> n >> k;

    if (n == 1) { cout << 0 << endl; return 0; }

    ll S = n - 1;

    if (k * (k - 1) / 2 < S) { cout << -1 << endl; return 0; }

    ll lo = 1, hi = k - 1;
    while (lo < hi) {
        ll mid = lo + (hi - lo) / 2;
        ll gain = mid * (2 * k - mid - 1) / 2;
        if (gain >= S) hi = mid;
        else            lo = mid + 1;
    }

    cout << lo << endl;
    return 0;
}