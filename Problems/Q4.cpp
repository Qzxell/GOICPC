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
	// idea 1
	contar la primera y ultima aparicion de k elementos distintos, depues con una monotic queue encuentro el primer menor y primer mayro a mi derecha.

		Entonces para cada i -> tengo los k distintos y su frecuencia contada con un binary search, o en O(1) preguntando por el indice en su coleccion.
		para un i + 1 -> funcionaria como un sliding widonw
	// contradiciones idea 1:
	si tengo i entonces solo me preocupo por i + m*k
	y con una tabla de frecuencias puedo sacar el numero de distintos elementos, solo seria eso y un sliding widow
	- lei mal, no te piden con exactamente m*k elementos sino que cada elemento distinto tenga por lo menos m elementos de ese tipo
	// idea 2
	con una tabla de frecuencias puedo sacar el numero de distintos elementos, solo seria eso y un sliding widow
	- lei mal, no te piden con exactamente m*k elementos sino que cada elemento distinto tenga por lo menos m elementos de ese tipo
	entonces quiza si sea nesesacion el fenwick, nnahh
	dos tablas de frecuencia
	int n,k,m;
	cin >> n >> k >> m;
	vi nums(n),compres;
	forn(i,n)cin >> nums[i];
	compres = nums;
	sort(all(nums));
	nums.erase(unique(all(nums)),nums.end());
	for(auto &x : nums)
		x = lower_bound(all(nums),x) - nums.begin();
	int tot = *max_element(all(nums)) + 1;
	vi fre(tot,0);
	int dist = 0;
	forn(i,min(k*m,n)){
		if(fre[nums[i]] == 0)
			dist++;
		fre[nums[i]]++;
	}
	int r = k*m - 1;
	forn(l,n){
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

