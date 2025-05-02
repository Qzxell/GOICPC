#include <bits/stdc++.h>

using namespace std;

using ii = pair<int,int>;
using vii = vector<ii>  ;
using vi = vector<int>  ;
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
        ii p,a,b,o;	
        cin >> p.fi >> p.se >> a.fi >> a.se >> b.fi >> b.se;
        o.fi = 0; o.se = 0;
        auto dis = [&](ii x, ii y)->double{
                return (sqrt((y.se - x.se)*(y.se - x.se) + (y.fi - x.fi)*(y.fi - x.fi)));
        };
        auto pertenece = [&](ii centro , ii punto,double radio) -> bool{
                auto [x,y] = punto;
                auto [o_x,o_y] = centro;
                if((o_x-x)*(o_x-x) + (o_y-y)*(o_y-y) <= radio*radio)return 1;
                return 0;
        };
        double eps = 1e-6;
        double dis_a_b = dis(a,b);
        auto veri = [&] (double radio)->bool{
                if(pertenece(a,o,radio) and pertenece(a,p,radio))return 1;
                if(pertenece(b,o,radio) and pertenece(b,p,radio))return 1;
                bool intersec = (2*radio >= dis_a_b);
                if(!intersec)return 0;
                if(pertenece(a,p,radio) and pertenece(b,o,radio))return 1;
                if(pertenece(a,o,radio) and pertenece(b,p,radio))return 1;
                return 0;
        };

        double lo = 1,lf = 10000000,mid;

        f(i,0,100){
                mid = (lo + lf)/2;
                if(veri(mid))lf = mid;
                else lo = mid + eps;
        }
        cout << lo << ln;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
        cout << fixed << setprecision(6);

	int tt = 1;
	cin >> tt;
	int test = 1;
	while (tt--){
		so(test++);
	}
	return 0;
}
