#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    ll d;
    cin >> n >> d;
    vector<ll> p(n);
    for (int i = 0; i < n; i++) cin >> p[i];
    sort(p.begin(), p.end());

    int lp = 0, rp = n - 1;
    int teamsFormed = 0;

    while (lp < rp) {
        ll k = d / p[rp] + 1;        
        if (lp + k - 1 <= rp) {      
            lp += k - 1;             
            rp--;                   
            teamsFormed++;
        } else {
            rp--;                 
        }
    }

    if (lp == rp && p[rp] > d) {
        teamsFormed++;
    }

    cout << teamsFormed << "\n";
    return 0;
}