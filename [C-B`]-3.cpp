#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    ll k;
    cin>>s;
    cin>>k;
    ll cnt_let=0;
    ll cnt_que=0;
    ll cnt_zv=0;
    for(char c : s){
        if(c=='*'){
            ++cnt_zv;
        }else if(c=='?'){
            ++cnt_que;
        }else{
            ++cnt_let;
        }
    }
    if(k<cnt_let-cnt_que-cnt_zv){
        cout<<"Impossible";
        return 0;
    }
    if(!cnt_zv && k>cnt_let){
        cout<<"Impossible";
        return 0;
    }
    string res="";
    s.push_back('a');
    for(int i=0; i<s.length()-1; ++i){
        if(s[i]=='?'){
            if(k>=cnt_let){
                res.push_back(s[i-1]);
                --cnt_que;
            }else{
                --cnt_let;
            }
        }else if(s[i]=='*'){
            if(k==cnt_let){
                res.push_back(s[i-1]);
                --cnt_zv;
            }else if(k<cnt_let){
                --cnt_let;
            }else{
                ll kol=k-cnt_let;
                res.push_back(s[i-1]);
                for(int j=0; j<kol; ++j){
                    res.push_back(s[i-1]);
                    ++cnt_let;
                }
            }
        }else{
            if(s[i+1]!='*' && s[i+1]!='?'){
                res.push_back(s[i]);
            }
        }
    }
    cout<<res;

    return 0;
}
