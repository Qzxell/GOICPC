#include <bits/stdc++.h>
using namespace std;

// N máximo 20 para Bitmask
const int MAXN = 24;
int n;
int result[MAXN]; 
int memo[1 << MAXN]; // Tabla para guardar estados ya visitados (Memoization)

// mask: representa los números que ya hemos usado (bit 1 = usado)
// idx: la posición actual que estamos llenando (0 a n-1)
bool solve(int mask, int idx) {
    // Caso base: si llegamos al final, encontramos una permutación válida
    if (idx == n) return true;

    // Si ya calculamos este estado y vimos que no tiene solución, no repetimos
    if (memo[mask] != -1) return memo[mask];

    // Intentamos poner cada número 'v' (de 1 a n)
    for (int v = 1; v <= n; v++) {
        // Verificar si 'v' NO ha sido usado todavía
        if (!((mask >> (v - 1)) & 1)) {
            
            // LÓGICA DE PODA (PRUNING)
            // Calculamos el valor necesario 'target' para cumplir la condición XOR
            // v[j] ^ (idx+1) == v[i]  ->  target = v ^ (idx+1)
            // Necesitamos que 'target' esté disponible para usar en el futuro (j > idx)
            
            if (idx < n - 1) { // La última posición no requiere condición
                int target = v ^ (idx + 1);
                
                // Si el target se sale del rango 1..N, este camino es inválido
                if (target < 1 || target > n) continue;
                
                // Si el target YA fue usado (está en la mask), no podemos usarlo en el futuro
                if ((mask >> (target - 1)) & 1) continue;
            }

            // Si pasa las verificaciones, guardamos el número y avanzamos
            result[idx] = v;
            
            // Llamada recursiva marcando 'v' como usado en la máscara
            if (solve(mask | (1 << (v - 1)), idx + 1)) {
                return true; // Encontramos solución, retornamos éxito hacia arriba
            }
        }
    }

    // Si probamos todos los números y ninguno sirvió, este estado es fallido
    return memo[mask] = 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;

    // Inicializamos la memoria en -1
    memset(memo, -1, sizeof(memo));

    // Lanzamos la búsqueda desde máscara 0 (ningún número usado) y posición 0
    if (solve(0, 0)) {
        for (int i = 0; i < n; i++) cout << result[i] << (i == n - 1 ? "" : " ");
        cout << "\n";
    } else {
        cout << "No existe solución\n";
    }

    return 0;
}
