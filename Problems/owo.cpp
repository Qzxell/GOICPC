#include <bits/stdc++.h>

using namespace std;

#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()
#define ln '\n'
#define ll long long
#define pb push_back
#define ii pair<int,int>
#define vii vector<ii>  
#define vi vector<int>  
#define fi first
#define se second
#define f(i, a, b) for(ll i = (ll)a; i < (ll)b; i++)
#define fer(i, b, a) for(ll i = (ll)a - 1; i >= (ll)b; i--)

void so(int test){
	int n = 1e5;
	set<int> ga[n];
	for(int i = 0 ; i < n ; i++){
		ga[i].insert(1);
		ga[i].insert(2);
		ga[i].insert(3);
		ga[i].insert(3);
	}
	quque<int>qu;
	auto BFS = [&](int root){
		qu.push(root);
		vi dis(n+1,-1);
		int len = 0;
		dis[root] = 0;
		while(!qu.empty()){
			int v = qu.front();
			qu.pop();
			for(int x : adj[v])if(vis[x] != -1){
				qu.push(x);
				dis[x] = len+1;
			}
			len++;
		}
		int mx_to = -1;
		int to = root;
		f(i,0,k){
			if (dis[kk[i]] > mx_to){
				mx_to = dis[kk[i]];
				to = kk[i];
			}
		}
		return to;
	};
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
