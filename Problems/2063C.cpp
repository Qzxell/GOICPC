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
        int n;
        cin >> n;
        vi adj[n+1];
        vi deg(n+1,0);
        multiset<ii> ord;
        vii ga(n);
        f(i,0,n-1){
                int u,v;
                cin >> u >> v;
                ga[i] = {u,v};
                deg[u]++;
                deg[v]++;
                adj[u].pb(v);
                adj[v].pb(u);
        }
        f(i,1,n+1){
                ord.insert({deg[i],i});
        }
        stack<int> st;
        int ans = 0;
        f(i,0,n){
                ans = max({ans,deg[ga[i].fi] + deg[ga[i].se] - 2,0});
        }
        f(i,1,n+1){
                st.push(i);
                auto it = ord.find({deg[i],i});
                ord.erase(it);
                int va = deg[i];
                for(auto x : adj[i]){
                        auto it = ord.find({deg[x],x});
                        ord.erase(it);
                        st.push(x);
                }
                if(!ord.empty()){
                        auto it_ = ord.rbegin();
                        va += it_->first - 1;
                        ans = max(ans,va);
                }
                while(!st.empty()){
                        int fr = st.top();st.pop();
                        ord.insert({deg[fr],fr});
                }
        }
        cout << ans << ln;
}
/*
 * BURNOUT
 * cual es la solucion mas estupida?
 * cual es la solucion mas extrema?
*/
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
