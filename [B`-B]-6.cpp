#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, m;
    cin>>n>>m;
    set<ll> plus, minus;
    ll k;
    cin>>k;
    for(int i=0; i<k; ++i){
        char t;
        cin>>t;
        if(t=='+'){
            ll s;
            cin>>s;
            plus.insert(s);
        }else{
            ll d;
            cin>>d;
            minus.insert(d);
        }
    }
    vector<ll> ss;
    vector<ll> dd;
    for(auto x : plus){
        ss.push_back(x);
    }
    for(auto x : minus){
        dd.push_back(x);
    }
    vector<ll> s_ev, s_od;
    for(auto x : ss){
        if(x%2==0){
            s_ev.push_back(x);
        }else{
            s_od.push_back(x);
        }
    }
    ll res_s=0;
    ll res_d=0;
    ll avg=n+m;
    for(auto x : ss){
        res_s+=min(min(n, m), (avg-abs(2*(x-1)-avg))/2);
    }
    for(auto x : dd){
        vector<ll>& sss=(x%2==0 ? s_ev : s_od);
        ll i_l=abs(x)+2;
        ll i_r=-abs(n-m-x)+n+m;
        ll c_l=lower_bound(sss.begin(), sss.end(), i_l)-sss.begin();
        ll c_r=upper_bound(sss.begin(), sss.end(), i_r)-sss.begin();
        ll g=min(min(n, m), (avg-abs(2*(m+x)-avg))/2);
        res_d+=g-(c_r-c_l);
    }
    cout<<res_s+res_d;

    return 0;
}
