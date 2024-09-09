#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    cin>>n;
    map<ll, set<ll>> m;
    for(int i=0; i<n; ++i){
        ll x, t;
        cin>>x>>t;
        m[t].insert(x);
    }
    ll cur_x_min=0;
    ll cur_x_max=0;
    ll minnn=0;
    ll maxxx=0;
    ll res=0;
    for(auto g : m){
        ll minn=(*g.second.begin());
        ll maxx=(*g.second.rbegin());
        ll a=min(abs(cur_x_min-maxx)+minnn, abs(cur_x_max-maxx)+maxxx);
        ll b=min(abs(cur_x_min-minn)+minnn, abs(cur_x_max-minn)+maxxx);
        minnn=a+maxx-minn;
        maxxx=b+maxx-minn;
        cur_x_min=minn;
        cur_x_max=maxx;
    }
    res=min(abs(cur_x_min)+minnn, abs(cur_x_max)+maxxx);
    cout<<res;

    return 0;
}
