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

const int N = 200010;
const int LOG = 20;

ll n,h;
ll a[N];
int st[LOG][N];
int lg[N];

int pa_d[N];
int pa_i[N];

void build() {
	lg[1] = 0;
	forsn(i,2,n+2)
		lg[i] = lg[i/2] + 1;

    	for (int i = 0; i < n+2; i++)
		st[0][i] = i;


	forsn(j,1,LOG)
	for (int i = 0; i + (1 << j) <= n + 2; i++) 
	{
		int id1 = st[j-1][i];
		int id2 = st[j-1][i + (1<<(j-1))];
		if(a[id1] > a[id2])
			st[j][i] = id1;
		else st[j][i] = id2;
	}

	forn(i,n+2){
		forsn(j,i+1,n+2){
			if(a[j] > a[i]){
				pa_d[i] = j;
				break;
			}
		}
	}
	for(int i = n+1 ;i >= 0;i--){
		for(int j = i -1 ; j>= 0 ; j--){
			if(a[j] > a[i]){
				pa_i[i] = j;
				break;
			}
		}
	}
}

int query(int l, int r) {
	int j = lg[r - l + 1];
	int id1 = st[j][l];
	int id2 = st[j][r - (1<<j) + 1];
	return (a[id1] > a[id2]) ? id1 : id2;  
}

void so(int test){
	cin >> n >> h;

	vii ord;
	forsn(i,1,n+1){
		cin >> a[i];
		ord.push_back({a[i],i});
	}
	a[0] = a[n+1] = (1ll<<40) ;
	build();
	vl val_i(n+2,0);
	vl val_d(n+2,0);
	vl val(n+2,0);

	sort(rall(ord));
	auto cal = [&](int pos)->ll{
		int id_d = pa_d[pos];
		int id_i = pa_i[pos];
		ll dif = h - a[pos];
		val_i[pos] = dif*(pos-id_i) + val_i[id_i];
		val_d[pos] = dif*(id_d-pos) + val_d[id_d];
		return val_i[pos] + val_d[pos] - dif;
	};

	for(auto [hi,id] : ord)
		val[id] = cal(id);
	for(int i = 1; i <= n ;i++){
		//cout << pa_i[i] << ' ' << pa_d[i]<<'\n';
		//cout << val_i[i] << ' ' << val_d[i]<<'\n';
		//cout << val[i] << ' ';
	}
	ll ans = 0;
	for(int i = 1; i <= n ; i ++)
	for(int j = 1; j <= n ; j ++)
	{
		ll id_inter = query(i,j);
		ans = max(val[i] + val[j] - val[id_inter],ans);
	}

	cout << ans << '\n';

}
int main(){
        ios::sync_with_stdio(false);
        cin.tie(0);
        int tt = 1;
        int test = 1;
	cin >> tt;
        while(tt--) so(test++);
        return 0;
}

