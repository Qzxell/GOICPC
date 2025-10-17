#include<bits/stdc++.h>

using namespace std;

#define f(i,a,n) for(int (i) = (a) ; (i) < (n) ; (i)++) 
#define vi vector<int>
#define ll long long
#define pb push_back
#define ln '\n'

map<ll,ll> m;
map<ll,vector<ll>> m_;
map<int,int> Uw;
void so(){
        set<ll> s;
        int q;
        cin >> q;
        f(i,0,q){
                char op;
                cin >> op;
                ll nu;
                cin >> nu;
                if(op == '+'){
                        s.insert(nu);
                        ll fin = nu;
                        auto it = s.lower_bound(fin);
                        while(it != s.end() and *it == fin){
                                fin += nu;
                                it = s.lower_bound(fin);
                        }
                        m[nu] = fin;
                        m_[fin].pb(nu);
                        if(m_.count(nu)){
                                for (auto nu_prev :m_[nu]) {
                                        ll fin = nu;
                                        auto it = s.lower_bound(fin);
                                        while(it != s.end() and *it == fin){
                                                fin += nu_prev;
                                                it = s.lower_bound(fin);
                                        }
                                        m[nu_prev] = fin;
                                        m_[fin].pb(nu_prev);
                                }
                        }
                        continue;
                }
                if(s.count(nu) > 0){
                        cout << m[nu] << ln;
                }else{
                        cout << nu << ln;
                }
        }
}

int main(){
        ios::sync_with_stdio(false);
        cin.tie(0);
        int tt = 1;
        while(tt--)so();
        return 0;
}
