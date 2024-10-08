---
tags:
  - Original
---

# Introduction to Dynamic Programming

La esencia de la programacion dinamica es evitar la calculacion repetida.  A menudo se pude resolver e implementar mas sencilla con recursion y memoizacion a esto se le conoce con programacion dinamica top-down.

Uno de los ejemplos mas conocidos es fibonaci. La formula recursica es $f(n) = f(n-1) + f(n-2)$ donde $n \ge 2$ and $f(0)=0$ and $f(1)=1$. In C++, esto se representa de la siguiente forma:

```cpp
int f(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    return f(n - 1) + f(n - 2);
}
```

El tiempo de ejecución de esta función recursiva es exponencial, aproximadamente $O(2^n)$, ya que una llamada a la función ($f(n)$) resulta en 2 llamadas a funciones de tamaño similar ($f(n-1)$ y $f(n-2)$).

### **Acelerando Fibonacci con Programación Dinámica (Memoización)**

Nuestro codigo es exponecial, para aumentar la velocidad, reconocemos que el número de subproblemas es solo $O(n)$. Es decir, para calcular $f(n)$ solo necesitamos conocer $f(n-1), f(n-2), \dots ,f(0)$. Por lo tanto, en lugar de recalcular estos subproblemas, los resolvemos una vez y luego guardamos el resultado en una tabla de búsqueda. Las llamadas posteriores usarán esta tabla de búsqueda y devolverán un resultado inmediatamente, eliminando así el trabajo exponencial.

Cada llamada recursiva verificará una tabla de búsqueda para ver si el valor ha sido calculado. Esto se hace en tiempo $O(1)$. Si ya lo hemos calculado, devolvemos el resultado; de lo contrario, calculamos la función de manera normal. El tiempo total de ejecución es $O(n)$. ¡Esta es una mejora enorme sobre nuestro algoritmo anterior de tiempo exponencial!

```cpp
const int MAXN = 100;
bool found[MAXN];
int memo[MAXN];

int f(int n) {
    if (found[n]) return memo[n];
    if (n == 0) return 0;
    if (n == 1) return 1;

    found[n] = true;
    return memo[n] = f(n - 1) + f(n - 2);
}
```



```cpp
Copy code
unordered_map<int, int> memo;
int f(int n) {
    if (memo.count(n)) return memo[n];
    if (n == 0) return 0;
    if (n == 1) return 1;

    return memo[n] = f(n - 1) + f(n - 2);
}
```
O de manera análoga:

```cpp
map<int, int> memo;
int f(int n) {
    if (memo.count(n)) return memo[n];
    if (n == 0) return 0;
    if (n == 1) return 1;

    return memo[n] = f(n - 1) + f(n - 2);
}
```
Ambas opciones serán casi siempre más lentas que la versión basada en arrays para una función recursiva memoizada genérica. Estas formas alternativas de guardar estados son principalmente útiles cuando se guardan vectores o cadenas de texto como parte del espacio de estados.

La forma de analizar el tiempo de ejecución de una función recursiva memoizada es:

trabajo por subproblema ∗ numero de subproblemas 

Usar un árbol binario de búsqueda (map en C++) para guardar estados resultará técnicamente en $O(n \log n)$ ya que cada búsqueda e inserción tomará $O(\log n)$ de trabajo y con $O(n)$ subproblemas únicos tenemos $O(n \log n)$ de tiempo.

Este enfoque se llama top-down, ya que podemos llamar a la función con un valor de consulta y el cálculo comienza desde arriba (valor consultado) hasta abajo (casos base de la recursión), y hace atajos mediante memoización en el camino.

## **Programación Dinámica Bottom-up**

Una vez encontrada la solucion recursiva es generalmenta facil pasar a este tipo de solucion.

Para crear un enfoque bottom-up para los números de Fibonacci, inicializamos los casos base en un array. Luego, simplemente usamos la definición recursiva en el array:

```cpp
const int MAXN = 100;
int fib[MAXN];

int f(int n) {
    fib[0] = 0;
    fib[1] = 1;
    for (int i = 2; i <= n; i++) fib[i] = fib[i - 1] + fib[i - 2];

    return fib[n];
}
```

Por supuesto, tal como está escrito, esto es un poco tonto por dos razones: Primero, hacemos trabajo repetido si llamamos a la función más de una vez. Segundo, solo necesitamos usar los dos valores anteriores para calcular el elemento actual. Por lo tanto, podemos reducir nuestra memoria de $O(n)$ a $O(1)$.

Un ejemplo de una solución de programación dinámica bottom-up para Fibonacci que usa $O(1)$ podría ser:

```cpp
const int MAX_SAVE = 3;
int fib[MAX_SAVE];

int f(int n) {
    fib[0] = 0;
    fib[1] = 1;
    for (int i = 2; i <= n; i++)
        fib[i % MAX_SAVE] = fib[(i - 1) % MAX_SAVE] + fib[(i - 2) % MAX_SAVE];

    return fib[n % MAX_SAVE];
}
```
Observa que hemos cambiado la constante de MAXN a MAX_SAVE. Esto se debe a que el número total de elementos a los que necesitamos acceder es solo 3. Ya no escala con el tamaño de la entrada y, por definición, es memoria $O(1)$. Además, usamos un truco común (usar el operador módulo) para mantener solo los valores que necesitamos.

Eso es todo. Estos son los conceptos básicos de la programación dinámica: No repitas el trabajo que ya has hecho.

Uno de los trucos para mejorar en programación dinámica es estudiar algunos de los ejemplos clásicos.

### Problemas Clásicos de Programación Dinámica
| Name                                           | Description/Example                                                                                                                                                                                                            |
| ---------------------------------------------- | -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| 0-1 knapsack                                   | Given $W$, $N$, and $N$ items with weights $w_i$ and values $v_i$, what is the maximum $\sum_{i=1}^{k} v_i$ for each subset of items of size $k$ ($1 \le k \le N$) while ensuring $\sum_{i=1}^{k} w_i \le W$?                  |
| Subset Sum                                     | Given $N$ integers and $T$, determine whether there exists a subset of the given set whose elements sum up to the $T$.                                                                                                         |
| Longest Increasing Subsequence                 | You are given an array containing $N$ integers. Your task is to determine the LCS in the array, i.e., LCS where every element is larger than the previous one.                                                                 |
| Counting all possible paths in a matrix.       | Given $N$ and $M$, count all possible distinct paths from $(1,1)$ to $(N, M)$, where each step is either from $(i,j)$ to $(i+1,j)$ or $(i,j+1)$.                                                                               |
| Longest Common Subsequence                     | You are given strings $s$ and $t$. Find the length of the longest string that is a subsequence of both $s$ and $t$.                                                                                                            |
| Longest Path in a Directed Acyclic Graph (DAG) | Finding the longest path in Directed Acyclic Graph (DAG).                                                                                                                                                                      |
| Longest Palindromic Subsequence                | Finding the Longest Palindromic Subsequence (LPS) of a given string.                                                                                                                                                           |
| Rod Cutting                                    | Given a rod of length $n$ units, Given an integer array cuts where cuts[i] denotes a position you should perform a cut at. The cost of one cut is the length of the rod to be cut. What is the minimum total cost of the cuts. |
| Edit Distance                                  | The edit distance between two strings is the minimum number of operations required to transform one string into the other. Operations are ["Add", "Remove", "Replace"]                                                         |

## Related Topics
* Bitmask Dynamic Programming
* Digit Dynamic Programming
* Dynamic Programming on Trees

Of course, the most important trick is to practice.

## Practice Problems
* [LeetCode - 1137. N-th Tribonacci Number](https://leetcode.com/problems/n-th-tribonacci-number/description/)
* [LeetCode - 118. Pascal's Triangle](https://leetcode.com/problems/pascals-triangle/description/)
* [LeetCode - 1025. Divisor Game](https://leetcode.com/problems/divisor-game/description/)
* [Codeforces - Zuma](https://codeforces.com/problemset/problem/607/b)
* [LeetCode - 221. Maximal Square](https://leetcode.com/problems/maximal-square/description/)
* [LeetCode - 1039. Minimum Score Triangulation of Polygon](https://leetcode.com/problems/minimum-score-triangulation-of-polygon/description/)

## Dp Contests
* [Atcoder - Educational DP Contest](https://atcoder.jp/contests/dp/tasks)
* [CSES - Dynamic Programming](https://cses.fi/problemset/list/)

