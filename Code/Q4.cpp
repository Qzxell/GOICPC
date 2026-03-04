#include<bits/stdc++.h>

using namespace std;

using ll = long long;

#define forn(i,n) for(int i=0 ;i<int(n);i++)
#define forsn(i,s,n) for(int i=int(s);i<int(n);i++)

#define vi vector<int>
#define vl vector<ll>
#define ii pair<int,int>
#define vii vector<ii>
#define fi first
#define se second
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define sz(v) (int)(v).size()

void so(int test){
	int n,k,m;
	cin >> n >> k >> m;
	vi nums(n);
	forn(i,n)cin >> nums[i];
	const int N = 2e5 + 5;
	vi fre(N,0);
	vi fre1(N,0);

	int r = -1,r1 = -1;
	int cnt = 0,cnt1 = 0;

	int gru = 0;
	ll ans = 0;

	forn(i,n){
		if(i > 0){
			if(fre[nums[i-1]] == m)gru--;
			if(fre[nums[i-1]] == 1)
				cnt--;
			fre[nums[i-1]]--;
			if(fre1[nums[i-1]] == 1)
				cnt1--;
			fre1[nums[i-1]]--;
		}
		while(r+1 < n and cnt + (fre[nums[r+1]] == 0) <= k){
			if(cnt == k)break;
			r++;
			fre[nums[r]]++;
			if(fre[nums[r]] == m)gru++;
			if(fre[nums[r]] == 1)
				cnt++;
			if(cnt == k)
				break;
		}
		while(r1+1 < n and cnt1 + (fre1[nums[r1+1]] == 0) <= k){
			r1++;
			fre1[nums[r1]]++;
			if(fre1[nums[r1]] == 1)cnt1++;
		}
		cout << r << ' ' << r1 << " grupos : " << gru << '\n';
		if(cnt1 < k)continue;
		bool ok = 0;
		for(;r <= r1;r++){
			if(gru == k){
				ok = 1;
				break;
			}
			if(r == r1)break;
			if(fre[nums[r+1]] == 0){
				cnt++;
			}
			fre[nums[r+1]]++;
			if(fre[nums[r+1]] == m)gru++;
		}
		if(ok){
			cout <<'\t' << r << ' ' << r1 << '\n';
			ans += r1 - r + 1;
		}
	}
	cout << ans << '\n';
}

int main(){
        ios::sync_with_stdio(false);
        cin.tie(0);
        int tt = 1;
        int test = 1;
        while(tt--) so(test++);
        return 0;
}


