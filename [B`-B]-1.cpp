#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    ll n, m, d;
    cin>>n>>m>>d;
    vector<ll> s(n);
    vector<pair<ll, ll>> p(n);
    for(int i=0; i<n; ++i){
        cin>>s[i];
        p[i]={s[i], i};
    }
    sort(p.begin(), p.end());
    ll l=0;
    ll r=0;
    ll res=1;
    ll cur_d=d;
    ll cur_res=1;
    while(r<n){
        if(p[r+1].first==p[r].first) {
            if (p[r + 1].second - p[r].second - 1 <= cur_d) {
                ++cur_res;
                cur_d-=p[r+1].second-p[r].second-1;
                ++r;
                res=max(res, cur_res);
            }else{
                ++l;
                --cur_res;
                cur_d=min(d, cur_d+p[l].second-p[l-1].second-1);
                if(r<l){
                    r=l;
                    cur_res=1;
                }
            }
        }else{
            res=max(res, cur_res);
            cur_d=d;
            cur_res=1;
            ++r;
            l=r;
        }
    }

    cout<<res;

    return 0;
}
