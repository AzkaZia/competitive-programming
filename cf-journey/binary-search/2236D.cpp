#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
using ll  = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n,k;
        cin >> n >> k;
        vector<int> a(n);
        map<int,int> mp;
        for (int i=0; i<n;i++) { 
            cin >> a[i];
            mp[a[i]]++;    
        }
        sort(a.begin(),a.end());
    
    }
}