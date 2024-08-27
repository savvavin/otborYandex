#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string t;
    cin>>t;
    bool isN=false;
    bool isS=false;
    bool isW=false;
    bool isE=false;
    for(char c : t){
        if(c=='N'){
            isN=true;
        }else if(c=='S'){
            isS=true;
        }else if(c=='W'){
            isW=true;
        }else{
            isE=true;
        }
    }
    if(isN!=isS || isW!=isE){
        cout<<"No";
    }else{
        cout<<"Yes";
    }

    return 0;
}
