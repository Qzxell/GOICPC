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

struct Vara {
    ii w1, w2;
    int d1, d2;

    Vara() : w1({0, 1}), w2({0, 1}), d1(0), d2(0) {} //  este es el default
    Vara(int a, int b, int c, int d)
        : w1({a, 1}), w2({c, 1}), d1(b), d2(d) {}
};

void so(int test){
        stack<Vara> qu;	
        ii fra1,fra2;
        int w1_,d1_,w2_,d2_;
        cin >> w1_ >> d1_ >> w2_ >> d2_;
        qu.push(Vara(w1_,d1_,w2_,d2_));
        Vara ul;
        bool yes = 1;
        while(!qu.empty()){
                Vara up_ = qu.top();
                if(up_.w1.fi == 0 or up_.w2.fi == 0){
                        cin >> w1_ >> d1_ >> w2_ >> d2_;
                        qu.push(Vara(w1_,d1_,w2_,d2_));
                        if(w1_ != 0 and w2_ != 0){
                                if(w1_ *d1_ != w2_*d2_)yes = 0;
                        }
                        continue;
                }
                ul = up_;
                qu.pop();
                if(qu.empty())break;
                int fx,fy;
                fx = (up_.d1+ up_.d2)*up_.w2.fi;
                fy = up_.d1*up_.w2.se;
                int di = __gcd(fx,fy);
                fra1 = {fx/di,fy/di};
                
                up_ = qu.top();
                if(up_.w1.fi == 0){
                        qu.top().w1 = fra1;
                        continue;
                }else if(up_.w2.fi == 0){
                        qu.top().w2 = fra1;
                        continue;
                }
        }
        int f1_n,f1_d;
        int f2_n,f2_d;
        f1_n = ul.w1.fi* ul.d1;
        f1_d = ul.w1.se;
        int ga = __gcd(f1_n,f1_d);
        f1_n /= ga;
        f1_d /= ga;
        f2_n = ul.w2.fi* ul.d2;
        f2_d = ul.w2.se;
        ga = __gcd(f2_n,f2_d);
        f2_n /= ga;
        f2_d /= ga;
        //cout << ul.w1.fi << ' ' <<  ul.w1.se;
        //cout << ln;
        //cout << ul.w2.fi << ' ' <<  ul.w2.se;
        //cout << ln;
        //cout << ul.d1 << ' ' <<  ul.d2;
        //cout << ln;
        //cout << f1_n << ' ' << f1_d << ' ' << f2_n << ' ' <<f2_d << ln;
        if(test > 1)cout << ln;
        if(f1_n == f2_n and f1_d == f2_d and yes){
                cout << "YES" << ln;
        }else cout << "NO" << ln;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int tt = 1;
	cin >> tt;
	int test = 1;
	while (tt--){
		so(test++);
	}
	return 0;
}
