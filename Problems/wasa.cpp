#include <bits/stdc++.h>
using namespace std;
 
// Utilizaremos un valor INF para representar "infinito" en nuestro contexto poético.
const int INF = 1e9;
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        vector<int> a(n+1);
        for (int i = 1; i <= n; i++){
            cin >> a[i];
        }
        // Sea m = k/2: el número de subarreglos "pares" (las estrofas que darán vida a b)
        int m = k/2;
        // Para poder elegir S₂ adecuadamente (recordando que S₁ debe ser no–vacío),
        // la posición de inicio s para S₂ debe satisfacer:
        //      2 ≤ s ≤ U, donde U = n - 2*m + 2.
        int U = n - 2*m + 2;
 
        // Precomputamos F[s]: la longitud máxima L tal que, empezando en s, 
        // se tiene a[s] = 1, a[s+1] = 2, …, a[s+L-1] = L.
        // Esto lo calculamos de atrás hacia adelante para lograr eficiencia.
        vector<int> F(n+2, 0);
        for (int s = n; s >= 1; s--){
            if(a[s] == 1){
                if(s == n) F[s] = 1;
                else {
                    if(a[s+1] == 2)
                        F[s] = 1 + F[s+1];
                    else
                        F[s] = 1;
                }
            } else {
                F[s] = 0;
            }
        }
 
        // ans almacenará el mínimo costo que logremos (la mínima disonancia)
        int ans = INF;
 
        // Recorremos todos los posibles comienzos s de S₂, es decir, de 2 a U.
        for (int s = 2; s <= U; s++){
            int candidate = INF;
 
            // Opción A: Forzamos la disonancia dentro de S₂.
            // Si el primer elemento a[s] NO es 1, ya se rompe la armonía y el costo es 1.
            if(a[s] != 1){
                candidate = 1;
            } else {
                // a[s] es 1: contamos cuántas notas perfectas consecutivas tenemos
                // desde s – F[s] nos da ese número.
                // Pero debemos dejar espacio para los segmentos restantes.
                // La condición de factibilidad exige que s + L ≤ U.
                int L_possible = U - s;  // máximo L permitido para S₂
                int L_match = F[s];      // cuántas notas "en orden" se pueden encadenar
                if(L_match < L_possible && (s + L_match) <= U){
                    // Así, tomando L_match notas perfectas y forzando el error en la siguiente,
                    // el costo será L_match + 1.
                    candidate = min(candidate, L_match + 1);
                }
            }
 
            // Opción B: La partición en la que cada subarreglo par se toma de longitud 1.
            // Entonces, los elementos de b serán:
            //    b[1] = a[s], b[2] = a[s+2], …, b[m] = a[s+2*(m-1)]
            // Para que la partición sea válida, necesitamos s+2*(m-1) ≤ n.
            if(s + 2*(m - 1) <= n){
                int costB = m + 1; // Si todo sigue la "partitura", el costo sería m+1.
                // Tratamos según la paridad de s.
                if(s % 2 == 0){
                    // Sea s = 2*r. Entonces, b[i] proviene de la posición: 2*(r+i-1).
                    int r = s / 2;
                    for (int i = 1; i <= m; i++){
                        int pos = 2 * (r + i - 1);
                        if(pos > n){
                            costB = i;
                            break;
                        }
                        if(a[pos] != i){
                            costB = i;
                            break;
                        }
                    }
                } else {
                    // Sea s = 2*r + 1. Entonces, b[i] proviene de: 2*(r+i)-1.
                    int r = (s - 1) / 2;
                    for (int i = 1; i <= m; i++){
                        int pos = 2 * (r + i) - 1;
                        if(pos > n){
                            costB = i;
                            break;
                        }
                        if(a[pos] != i){
                            costB = i;
                            break;
                        }
                    }
                }
                candidate = min(candidate, costB);
            }
 
            ans = min(ans, candidate);
        }
 
        cout << ans << "\n";
    }
    return 0;
}
