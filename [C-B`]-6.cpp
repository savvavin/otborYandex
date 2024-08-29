#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

ll a, b, c;
ll a5(){
    ll x1=a/5;
    a-=5*x1;
    return x1;
}
ll a2b2(){
    ll x2=min(a/2, b/2);
    a-=2*x2;
    b-=2*x2;
    return x2;
}
ll b2c(){
    ll x3=min(b/2, c);
    b-=2*x3;
    c-=x3;
    return x3;
}
ll a3c(){
    ll x4=min(a/3, c);
    a-=3*x4;
    c-=x4;
    return x4;
}
ll ac2(){
    ll x5=min(a, c/2);
    a-=x5;
    c-=2*x5;
    return x5;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin>>t;
    while(t--){
        ll res=0;
        cin>>a>>b>>c;

        res+=b2c();
        res+=ac2();
        res+=a2b2();
        res+=a3c();
        res+=a5();

        cout<<res<<"\n";
    }

    return 0;
}
