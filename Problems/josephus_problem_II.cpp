#include <bits/stdc++.h>

using namespace std;

using ii = pair<int,int>;
using iii = pair<int,ii>;
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

/*
vi rec(int nn,int di){
        for(auto x : au){
                if(x < di)ret.pb(x);
                else{
                        int df1 = di,df2 = di+1;
                        int so = (x-df1)%(k);
                        int pa = ((x-df1)/k)*(k+1) + so + df2;
                        ret.pb(pa);
                }
        }
}
*/
void so(int test){
        cin >> n >> k;
        if(n == 1){
                cout << 1 <<ln;
                return;
        }
        if(k == 0){
                f(i,0,n)cout << i+1 << ' ';
                return;
        }
        stack<ii> st;
        int ind = k%n;
        st.push({n-1,ind});
        vi ans;
        while(true){
                ii ip = st.top();
                if(ip.fi == 0)break;
                int len = ip.fi+1;
                int ind = ip.se%len;

                int pro = (len - ind - 1)/(k+1) + 1;
                int l1,ind1;

                l1 = ip.fi - pro;
                ind1 =  k - (len - 1 - (ind + (pro-1)*(k+1)));

                st.push({l1,ind1});
        }
        while(!st.empty()){
                ii ip = st.top();
                st.pop();
                cout << ip.fi << ' ' << ip.se<<ln;
                if(ans.empty()){
                        ans.pb(0);
                        continue;
                }
                int di = ip.se% (ip.fi+1);
                int le = sz(ans);
                for(int i = 0;i < le;i++){
                        int x  = ans[i];
                        if(x < di)continue;
                        else{
                                int df1 = di,df2 = di+1;
                                int so = (x-df1)%(k);
                                int pa = ((x-df1)/k)*(k+1) + so + df1+1;
                                ans[i] = pa;
                        }
                }
                int gro = (ip.fi - di)/(k+1);
                int c= 0 ;
                for(int i = di + gro*(k+1); i >= 0 ; i -= k+1){
                        ans.pb(i);
                }
        }
        reverse(all(ans));
        f(i,0,sz(ans))cout << ans[i]+1 << ' ';

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
