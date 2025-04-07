#include <bits/stdc++.h>

using namespace std;

using ii = pair<int,int>;
using vii = vector<ii>  ;
using vi = vector<int>  ;
#define ln  '\n'
#define ll long long
#define pb emplace_back
#define fi first
#define se second
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define f(i, a, b)  for(ll i = (ll)a; i < (ll)b; i++)
#define fer(i, b, a)  for(ll i = (ll)a - 1; i >= (ll)b; i--)

int n,k;	

vi rec(int nn,int di){
        if(nn == 1){
                di %= (nn+1);
                vi ga = {di,1-di};
                return ga;
        }
        di %= (nn+1);

        int c = 0;
        int dif = 0;
        vi ret;
        for(int i = di ; i <= nn; i +=k+1) {
                c++;
                ret.pb(i);
                dif = nn - i;
        }
        vi au = rec(nn - c, k- dif);
        for(auto x : au){
                if(x < di)ret.pb(x);
                else{
                        int df1 = di,df2 = di+1;
                        int so = (x-df1)%(k);
                        int pa = ((x-df1)/k)*(k+1) + so + df2;
                        ret.pb(pa);
                }
        }
        return ret;
}
void so(int test){
        cin >> n >> k;
        if(n == 1){
                cout << 1 <<ln;
                return;
        }
        if(k==0){
                f(i,0,n)cout << i+1 << ' ';
                return;
        }

        vi ans = rec(n-1,k);
        
        for(auto x : ans)cout << x+1 << ' ';
        cout << ln;

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
