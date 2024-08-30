#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

vector<string> rotate(vector<string>& table){
    vector<string> res(table.size(), string(table.size(), '.'));
    for(int i=0; i<table.size(); ++i){
        for(int j=0; j<table.size(); ++j){
            res[j][table.size()-i-1]=table[i][j];
        }
    }
    return res;
}

vector<string> left(vector<string>& table){
    auto res=table;
    bool flg=true;
    while(flg){
        flg=true;
        for(int i=0; i<table.size(); ++i){
            if(res[i][0]=='#'){
                flg=false;
            }
        }
        if(flg){
            for(int i=0; i<table.size(); ++i){
                res[i]=res[i].substr(1)+".";
            }
        }
    }
    return res;
}

vector<string> up(vector<string>& table){
    auto res=table;
    while(res[0]==string(table.size(), '.')){
        for(int i=0; i<table.size()-1; ++i){
            res[i]=res[i+1];
        }
        res[table.size()-1]=string(table.size(), '.');
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    cin>>n;
    vector<string> ish(n);
    vector<string> ish2(n);
    for(int i=0; i<n; ++i){
        cin>>ish[i];
    }
    for(int i=0; i<n; ++i){
        cin>>ish2[i];
    }
    bool flg=false;
    for(int i=1; i<=4; ++i){
        ish=rotate(ish);
        vector<string> a=up(ish);
        vector<string> b=up(ish2);
        if(left(a)==left(b)){
            flg=true;
        }
    }
    cout<<(flg ? "YES" : "NO");

    return 0;
}
