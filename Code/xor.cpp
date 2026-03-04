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
        int n,u,r;
        cin >> n >> u >> r;
        vi a(n),b(n),k(n),p(n);
        f(i,0,n)cin >> a[i];
        f(i,0,n)cin >> b[i];
        f(i,0,n)cin >> k[i];
        f(i,0,n)cin >> p[i];
        queue<ii> qu;
        qu.push({0,1});
        qu.push({1,1});
        ll ans = -1e18;
        while(!qu.empty()){
                auto [mask,len]= qu.front();qu.pop();
                if((u-len)%2==0){
                        vi cur = a;
                        vi temp(n);
                        f(i,0,len){
                                if((mask>>i)&1){
                                        f(i,0,n)cur[i] ^= b[i];
                                }else{
                                        f(i,0,n)temp[i] = cur[p[i]-1]+r;
                                        swap(temp,cur);
                                }
                        }
                        ll acu = 0;
                        f(i,0,n){
                                acu += k[i]*cur[i];
                        }
                        ans = max(ans,acu);
                        if(len == u)continue;
                }
                if((mask>>(len-1))&1){
                        qu.push({mask,len+1});
                }else{
                        qu.push({mask,len+1});
                        qu.push({mask+(1<<len),len+1});
                }
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
