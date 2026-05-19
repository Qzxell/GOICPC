#include<bits/stdc++.h>

using namespace std;

using ll = long long;

int n,k;
int N = 5e5 + 5;
int nex[N];
int vis[N];

void dfs(int nod){

}

void so(int test){
	cin >> n >> k;
	forns(i,1,n+1)
		cin >> nex[i];
	forns(i,1,n+1)if(!vis[i])
		dfs(i);
}

int main(){
        ios::sync_with_stdio(false);
        cin.tie(0);
        int tt = 1;
        int test = 1;
        while(tt--) so(test++);
        return 0;
}

