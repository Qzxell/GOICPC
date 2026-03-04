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
        vi A(n);
        vi ans(n);

        priority_queue<int,vi,greater<int>> pq;	
        f(i,0,n)cin >> A[i];
        f(i,0,n){
                while(!pq.empty()){
                        int fr = pq.top();
                        if(fr - i + 1 <= 0 )pq.pop();
                        else break;
                }
                int add  = A[i] + sz(pq);
                pq.push(add + i);
                ans[i] = max(0ll,add - (n-1-i));
        }
        f(i,0,n)cout << ans[i] << ' ' ;

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
