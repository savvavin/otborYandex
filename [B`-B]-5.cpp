#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

bool cmp(pair<string, pair<ll, ll>>& a, pair<string, pair<ll, ll>>& b){
    return a.second.first>b.second.first;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin>>s;
    ll n=s.length();
    ll a=n*(n-1)/2;
    ll b=0;
    vector<ll> cnt(26, 0);
    for(int i=0; i<n; ++i){
      ++cnt[s[i]-'a'];
    }
    for(int i=0; i<26; ++i){
      b+=(cnt[i]*(cnt[i]-1)/2);
    }
    cout<<a-b+1;

    return 0;
}
