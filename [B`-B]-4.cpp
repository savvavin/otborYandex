#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

bool checkpspp(string& s){
    ll op=0;
    ll cl=0;
    ll balance=0;
    bool flg=true;
    for(auto c : s){
        if(c=='('){
            ++balance;
        }else{
            if(balance==0){
                flg=false;
                break;
            }else{
                --balance;
            }
        }
    }
    if(balance!=0){
        flg=false;
    }
    return flg;
}

pair<ll, ll> left_right_balance(string& s){
    ll l=0, r=0;
    for(auto c : s) {
        if(c=='('){
            --r;
        }else{
            if(r==0){
                ++l;
            }else{
                ++r;
            }
        }
    }
    return {l, r};
}

ll balance(string& s){
    return count(s.begin(), s.end(), '(')-count(s.begin(), s.end(), ')');
}

bool cmp(tuple<ll, ll, pair<ll, ll>>& a, tuple<ll, ll, pair<ll, ll>>& b){
    return make_pair(get<2>(a).second, get<2>(a).first)<make_pair(get<2>(b).second, get<2>(b).first);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    cin>>n;
    vector<string> a(n);
    for(int i=0; i<n; ++i){
        cin>>a[i];
    }

    vector<tuple<ll, ll, pair<ll, ll>>> info;
    for(int i=0; i<n; ++i){
        info.push_back({i, balance(a[i]), left_right_balance(a[i])});
    }
    vector<tuple<ll, ll, pair<ll, ll>>> op_st, cl_st;
    for(const auto& p : info){
        if(get<1>(p)>=0){
            op_st.push_back(p);
        }else{
            cl_st.push_back(p);
        }
    }
    sort(op_st.begin(), op_st.end(), [](const auto& a, const auto& b){
        return get<2>(a)<get<2>(b);
    });
    sort(cl_st.begin(), cl_st.end(), cmp);
    vector<pair<ll, pair<ll, ll>>> sorted_bal;
    for(const auto& p : op_st){
        sorted_bal.push_back({get<0>(p), get<2>(p)});
    }
    for(const auto& p : cl_st){
        sorted_bal.push_back({get<0>(p), get<2>(p)});
    }
    string ans="";
    for(auto p : sorted_bal){
        ans+=a[p.first];
    }
    if(!checkpspp(ans)){
        cout<<-1;
        return 0;
    }
    for (auto& p : sorted_bal) {
        cout << p.first + 1 << " ";
    }

    return 0;
}
