#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, k;
    cin>>n>>k;
    vector<ll> ost(k);
    ll res=0;
    for(int i=1; i<=n; ++i){
        ++ost[i%k];
    }
    for(ll a=0; a<k; ++a){
        ll b=(k-a)%k;
        ll c=(k-b)%k;
        if((a+b)%k==0 && (b+c)%k==0 && (a+c)%k==0){
            res+=(ost[a]*ost[b]*ost[c]);
        }
    }
    cout<<res;

    return 0;
}
