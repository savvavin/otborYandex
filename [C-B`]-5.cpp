#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    cin>>n;
    vector<ll> a(n);
    for(int i=0; i<n; ++i){
        cin>>a[i];
    }
    ll res=a[n-1];
    for(int i=0; i<n-1; ++i){
        if(a[i]>a[i+1]){
            res=a[i];
            break;
        }
    }
    vector<ll> ans;
    for(int i=0; i<n; ++i){
        if(a[i]!=res){
            ans.push_back(a[i]);
        }
    }
    for(auto x : ans){
        cout<<x<<" ";
    }

    return 0;
}
