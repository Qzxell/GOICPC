#include<bits/stdc++.h>

using namespace std;

using ll = long long;

#define forn(i,n) for(int i=0 ;i<int(n);i++)
#define forsn(i,s,n) for(int i=int(s);i<int(n);i++)
#define dforn(i,n) for(int i=int(n)-1;i>=0;i--)
#define dforsn(i,s,n) for(int i=int(n)-1;i>=int(s);i--)

#define vi vector<int>
#define vl vector<ll>
#define ii pair<int,int>
#define vii vector<ii>
#define fi first
#define se second
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define sz(v) (int)(v).size()

struct FT{
    int n;
    vector<ll> ft;

    // CORRECCIÓN 1: El constructor debe llamarse igual que el struct (FT)
    FT(int nu): n(nu){
        ft.assign(n+1, 0); // assign es más limpio que resize
    }

    void clear() {
        fill(all(ft), 0);
    }

    ll query(int pos){
        ll ret = 0;
        while(pos > 0){ // Cuidado: pos debe ser > 0 para evitar bucle infinito si pos=0
            ret += ft[pos];
            pos -= (pos&-pos);
        }
        return ret;
    }
    
    ll query(int l,int r){
        if(l > r) return 0;
        return query(r) - query(l-1);
    }

    void add(int pos, int ad){
        while(pos <= n){
            ft[pos] += ad;
            pos += (pos&-pos);
        }
    }
};

void so(int test){
    int n;
    cin >> n;
    // Map ordena las llaves automáticamente
    map<int,vi> m;
    
    // Leemos y guardamos posiciones (1-based para el FT)
    forsn(i,1,n+1){
        int x;
        cin >> x;
        m[x].push_back(i);
    }

    vi suf(n+1,0), pre(n+1,0);
    FT ft(n);

    // PASADA 1: Valores de menor a mayor
    // Calculamos PRE: Cantidad de elementos MENORES (ya procesados) a la IZQUIERDA (índice < x)
    for(auto &[val, vec] : m){
        for(auto x : vec){
            // Consultamos cuantos elementos hay a la izquierda de x
            pre[x] = ft.query(x - 1); 
        }
        for(auto x : vec){
            ft.add(x, 1);
        }
    }

    // Limpiamos el FT para reusarlo
    ft.clear();

    // PASADA 2: Valores de mayor a menor (Reverse Iterator)
    // Calculamos SUF: Cantidad de elementos MAYORES (ya procesados) a la DERECHA (índice > x)
    for(auto it = m.rbegin(); it != m.rend(); it++){
        for(auto x : it->se){ // it->se es el vector de posiciones
            // Consultamos cuantos elementos hay a la derecha de x
            suf[x] = ft.query(x + 1, n);
        }
        for(auto x : it->se){
            ft.add(x, 1);
        }
    }

    ll ans = 0;
    forsn(i,1,n+1){
        // Esto cuenta tripletes i < j < k tal que v[i] < v[j] < v[k]
        // Si el problema era otro, ajusta los queries arriba.
        ans += pre[i] * 1ll * suf[i];
    }
    cout << ans << '\n';
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt = 1;
    // cin >> tt; // Descomenta si hay multitest
    int test = 1;
    while(tt--) so(test++);
    return 0;
}
