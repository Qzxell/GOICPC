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

int inf = 1e9;

void so(int test){
        int n,a,b,c;
        cin >> n >> a >> b >> c;
        vi v(n);
        f(i,0,n)cin >> v[i];
        int mas = (1<<(n));

        ll ans = inf;
        auto pul = [&](int mask){
                int num = 0;
                f(i,0,n+1)if((mask>>i)&1){
                        num += v[i];
                }
                return num;
        };
        auto bum =[&](int aa,int bb,int cc){
                f(i,0,9)if(((aa>>i)&1) + ((bb>>i)&1) + ((cc>>i)&1) >= 2)return false;
                return true;
        };
        auto cont = [&](int num){
                int c = 0;
                f(i,0,9)if((num>>i)&1)c++;
                return c;
        };
        f(i,0,mas) f(j,0,mas) f(k,0,mas)if(bum(i,j,k)){
                if(i == 0 or j == 0 or k == 0)continue; 
                ll punt = (cont(i)-1)*10;
                punt += (cont(j)-1)*10;
                punt += (cont(k)-1)*10;
                int nu1,nu2,nu3;
                nu1 = pul(i);
                nu2 = pul(j);
                nu3 = pul(k);
                punt += abs(a-nu1) + abs(b-nu2) + abs(c-nu3);
                ans = min(punt,ans);
        }
        
        cout << ans << ln;
        	

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
