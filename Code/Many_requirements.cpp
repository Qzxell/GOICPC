#include <bits/stdc++.h>

using namespace std;

using ii = pair<int,int>;
using vii = vector<ii>  ;
using viii = vector<pair<ii,int>>  ;
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
#define trace(...) fff(#__VA_ARGS__, __VA_ARGS__)
template<typename t> void fff(const char* x, t&& val1) { cout<<x<< " : "<<val1<<"\n";}
template<typename t1, typename... t2> void fff(const char* x, t1&& val1, t2&&... val2){
    const char* xd=strchr(x+1, ',');
    cout.write(x, xd-x)<<" : "<<val1<<" | ";
    fff(xd+1, val2...);
}

void so(int test){
        int n,m,q;	
        cin >> n >> m >> q;
        vi a(q); vi b(q); vi c(q); vi d(q);
        f(i,0,q)cin >> a[i] >> b[i] >> c[i] >> d[i];

        //ll c = 0;
        //f(i,1,11) f(j,i,11) f(k,j,11) f(l,k,11) f(p,l,11) f(q,p,11) f(r,q,11) f(s,r,11) f(t,s,11) f(u,t,11){
                                
                //trace(i,j,k,l,p,q,r,s,t,u);
        //}
        queue<vi> qu;
        vi ga = {1};
        qu.push(ga);
        int ans = 0;
        while(!qu.empty()){
                auto fr = qu.front();qu.pop();
                int ul = fr.back();
                int le = sz(fr);
                if(le == n){
                        int acu = 0;
                        f(i,0,q){
                                if(fr[b[i]-1] - fr[a[i]-1] != c[i])continue;
                                acu += d[i];
                        }
                        ans = max(ans,acu);
                        continue;
                }
                fr.push_back(0);
                f(i,ul,m+1){
                        fr[le] = i;
                        qu.push(fr);
                }
        }
        cout << ans ;

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
