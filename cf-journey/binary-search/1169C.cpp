#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll  = long long;

ll n,m;
vector<ll> a;

bool check(ll x) {
   ll floor =0;
   for (int i=0; i<n; i++) {
    ll start = a[i];
    ll reach = start +x;
    ll chosen;
    if (reach < m) {
        if (floor <= start) chosen = start;
        else if (floor <= reach) chosen = floor; 
        else return false;
    } else {
        ll overflow = reach - m;
        if (floor <= overflow) chosen = floor;
        else if (floor <= start) chosen = start;
        else chosen = floor;
    }
    floor = chosen;
   }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    a.resize(n);

    for (int i=0; i<n; i++) cin >> a[i];
    ll lo=0;
    ll hi=m-1;

    while (lo<hi){
        ll mid = lo + (hi-lo)/2 ;
        bool result = check(mid);
        if (result == true) {
            hi = mid;
        } else {lo = mid+1;}
    }
    cout << lo << "\n";
}