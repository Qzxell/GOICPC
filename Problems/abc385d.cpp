#include <bits/stdc++.h>

using namespace std;

using ii = pair<int,int>;
using vii = vector<ii>  ;
using vi = vector<long long>  ;
#define ln  '\n'
#define ll long long
#define pb push_back
#define fi first
#define se second
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define f(i, a, b)  for(ll i = (ll)a; i < (ll)b; i++)
#define fer(i, b, a)  for(ll i = (ll)a - 1; i >= (ll)b; i--)


void so(int test){
        ll n,m,X,Y;
        cin >> n >> m >> X >> Y;
        map<ll,set<int>> m_x;
        map<ll,set<int>> m_y;
        f(i,0,n){
                int x,y;
                cin >> x >> y;
                m_x[x].insert(y);
                m_y[y].insert(x);
        }
        set<ii> ans;
        f(i,0,m){
                char d;int C;
                cin >> d >> C;
                if(d == 'U'){
                        ll n_x = X, n_y = Y + C;
                        if(m_x.count(X)){
                                auto it1 = lower_bound(all(m_x[X]),Y);
                                while(it1 != m_x[X].end() and *it1 <= n_y){
                                        ans.insert({X,*it1});
                                        m_x[X].erase(*it1);
                                        m_y[*it1].erase(X);
                                        it1++;
                                }
                        }
                        Y = n_y;
                }
                if(d == 'D'){
                        ll n_x = X, n_y = Y - C;
                        if(m_x.count(X)){
                                auto it1 = lower_bound(all(m_x[X]),n_y);
                                while(it1 != m_x[X].end() and *it1 <= Y){
                                        ans.insert({X,*it1});
                                        m_x[X].erase(*it1);
                                        m_y[*it1].erase(X);
                                        it1++;
                                }
                        }
                        Y = n_y;
                }
                if(d == 'R'){
                        ll n_x = X+C, n_y = Y;
                        if(m_y.count(Y)){
                                auto it1 = lower_bound(all(m_y[Y]),X);
                                while(it1 != m_y[Y].end() and *it1 <= n_x){
                                        ans.insert({*it1,Y});
                                        m_y[Y].erase(*it1);
                                        m_x[*it1].erase(Y);
                                        it1++;
                                }
                        }
                        X = n_x;
                }
                if(d == 'L'){
                        ll n_x = X- C, n_y = Y ;
                        if(m_y.count(Y)){
                                auto it1 = lower_bound(all(m_y[Y]),n_x);
                                while(it1 != m_y[Y].end() and *it1 <= X){
                                        ans.insert({*it1,Y});
                                        m_y[Y].erase(*it1);
                                        m_x[*it1].erase(Y);
                                        it1++;
                                }
                        }
                        X = n_x;
                }
        }
        for(auto [a,b] : ans){
                cout << a << ' ' << b;
                cout << ln;
        }


        cout << X << ' ' << Y << ' ' << sz(ans);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int tt = 1;
	int test = 1;
	while (tt--){
		so(test++);
	}
	return 0;
}
