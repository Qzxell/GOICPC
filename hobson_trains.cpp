#include<bits/stdc++.h>

using namespace std;

using ll = long long;

#define all(v) (v).begin(),(v).end()
#define sz(v) (int)(v).size()


const int N = 5e5 + 25;

const int LG = __lg(N) + 4;
int B[N][LG];

vector<int> G[N];// grafo invertido
bool cicle[N];// esta en el ciclo ?
vector<vector<int>> payasos;//grupo de payasos
vector<vector<int>> dif;


int S[N];// S[i] : cantidad de nodos que alcanzan con k pasos
int D[N];// dis del payso leder a nod
int ans[N];

int leder[N];// que payaso es mi leder
int position[N];
int grupo[N];// en que grupo de payasos esta


int n,k;

int subir(int u, int clim){
	int ind = 0;
	int cur = u;
	while(clim > 0){
		if(clim&1)
			cur = B[cur][ind];
		clim >>= 1;
		ind++;
	}
	return cur;
}

void init(){
	for(int i = 1 ; i < LG;i++)
		for(int u = 1 ; u <= n ; u++)
			B[u][i] = B[B[u][i-1]][i-1];
	for(int i = 1; i <= n ; i++)
		S[subir(i,k)]++;
}

void detection(){
	for(int i = 1;  i <= n ; i++){
		int fi = subir(i, n + 5);
		if(cicle[fi])continue;

		vector<int> anillo;
		for(;;){
			if(cicle[fi]) break;
			anillo.push_back(fi);
			cicle[fi] = 1;
			fi = B[fi][0];
		}
		for(int j = 0 ; j < sz(anillo); j++){
			position[anillo[j]] = j;
			grupo[anillo[j]] = sz(payasos);
		}
		vector<int> uwu(sz(anillo),0);
		dif.push_back(uwu);
		payasos.push_back(anillo);
	}
}

int DFS(int u){
	int ret = 1;
	for(auto son : G[u])if(!cicle[son]){
		D[son] = D[u] + 1;
		leder[son] = leder[u];
		ret += DFS(son) - S[son];
	}
	return ans[u] = ret;
}

void so(int test){
	cin >> n >> k;
	for(int i = 1; i <= n ; i++){
		cin >> B[i][0];
		G[B[i][0]].push_back(i);
	}
	init();
	detection();

	for(auto anillo : payasos){
		for(auto x : anillo){
			leder[x] = x;
			DFS(x);
		}
	}

	for(int i = 1; i <= n ;i++){
		int mi_led = leder[i];
		int deep = D[i];
		int posi = position[mi_led];
		int grupito = grupo[mi_led];

		int tamano = sz(dif[grupito]);
		int lon = k - deep + 1;
		if(lon < 0)continue;

		if(k - deep >= tamano){
			dif[grupito][0]++;
			continue;
		}
		dif[grupito][posi]++;
		if(posi + lon < tamano){
			dif[grupito][posi + lon]--;
		}else{
			int sob = lon - (tamano - posi);
			dif[grupito][0]++;
			dif[grupito][sob]--;
		}
	}

	int uwu = 0;
	for(auto anillo : payasos){
		for(int i = 1 ; i < sz(anillo) ;i++){
			dif[uwu][i] += dif[uwu][i-1];
		}
		for(int i = 0 ; i < sz(anillo) ;i++){
			int x = anillo[i];
			ans[x] = dif[uwu][i];
		}
		uwu++;
	}
	for(int i = 1; i <= n ;i++){
		cout << ans[i] << '\n';
	}
}

int main(){
        ios::sync_with_stdio(false);
        cin.tie(0);
        int tt = 1;
        int test = 1;
        while(tt--) so(test++);
        return 0;
}

