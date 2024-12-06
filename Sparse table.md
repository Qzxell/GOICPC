**Tabla Dispersa¶**  

La Tabla Dispersa es una estructura de datos que permite responder consultas sobre rangos. Puede responder la mayoría de las consultas sobre rangos en  
$O(\log n)$ , pero su verdadero poder radica en responder consultas de rango mínimo (o equivalentes consultas de rango máximo). Para esas consultas, puede calcular la respuesta en  
$O(1)$  tiempo.

El único inconveniente de esta estructura de datos es que solo se puede usar en arreglos inmutables. Esto significa que el arreglo no puede modificarse entre dos consultas. Si cualquier elemento del arreglo cambia, toda la estructura de datos debe recomputarse.

**Intuición¶**  

Cualquier número no negativo puede ser representado de manera única como una suma de potencias decrecientes de dos. Esto es solo una variante de la representación binaria de un número. Por ejemplo,  
$13 = (1101)_2 = 8 + 4 + 1$ . Para un número  
$x$ , puede haber como máximo  
$\lceil \log_2 x \rceil$  sumandos.

Siguiendo el mismo razonamiento, cualquier intervalo puede ser representado de manera única como una unión de intervalos con longitudes que son potencias decrecientes de dos. Por ejemplo,  
$[2, 14] = [2, 9] \cup [10, 13] \cup [14, 14]$ , donde el intervalo completo tiene longitud 13, y los intervalos individuales tienen longitudes de 8, 4 y 1, respectivamente. Y también aquí, la unión consiste en como máximo  
$\lceil \log_2(\text{longitud del intervalo}) \rceil$  intervalos.

La idea principal detrás de las Tablas Dispersas es precomputar todas las respuestas para consultas de rangos con longitud de potencia de dos. Luego, una consulta de rango diferente puede ser respondida dividiendo el rango en rangos con longitudes de potencia de dos, buscando las respuestas precomputadas y combinándolas para obtener una respuesta completa.

**Precomputación¶**  
Usaremos un arreglo bidimensional para almacenar las respuestas de las consultas precomputadas.  
$\text{st}[i][j]$  almacenará la respuesta para el rango  
$[j, j + 2^i - 1]$  de longitud  
$2^i$ . El tamaño del arreglo bidimensional será  
$(K + 1) \times \text{MAXN}$ , donde  
$\text{MAXN}$  es la longitud más grande posible de un arreglo.  
$\text{K}$  debe satisfacer  
$\text{K} \ge \lfloor \log_2 \text{MAXN} \rfloor$ , porque  
$2^{\lfloor \log_2 \text{MAXN} \rfloor}$  es el rango de mayor potencia de dos que necesitamos soportar. Para arreglos con longitudes razonables ( 
$\le 10^7$  elementos),  
$K = 25$  es un buen valor.

La dimensión  
$\text{MAXN}$  es secundaria para permitir accesos consecutivos a la memoria (amigables con la caché).

```cpp
int st[K + 1][MAXN];
```

Debido a que el rango   $[j, j + 2^i - 1]$  de longitud   $2^i$  se divide bien en los rangos   $[j, j + 2^{i - 1} - 1]$  y   $[j + 2^{i - 1}, j + 2^i - 1]$ , ambos de longitud   $2^{i - 1}$ , podemos generar la tabla eficientemente usando programación dinámica:

```cpp
std::copy(array.begin(), array.end(), st[0]);

for (int i = 1; i <= K; i++)
    for (int j = 0; j + (1 << i) <= N; j++)
        st[i][j] = f(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
```
La función   $f$  dependerá del tipo de consulta. Para consultas de suma de rango, calculará la suma; para consultas de mínimo de rango, calculará el mínimo.

La complejidad temporal de la precomputación es   $O(\text{N} \log \text{N})$ .

Consultas de Suma de Rango¶
Para este tipo de consultas, queremos encontrar la suma de todos los valores en un rango. Por lo tanto, la definición natural de la función   $f$  es   $f(x, y) = x + y$ . Podemos construir la estructura de datos con:

```cpp
long long st[K + 1][MAXN];

std::copy(array.begin(), array.end(), st[0]);

for (int i = 1; i <= K; i++)
    for (int j = 0; j + (1 << i) <= N; j++)
        st[i][j] = st[i - 1][j] + st[i - 1][j + (1 << (i - 1))];
```
Para responder a la consulta de suma para el rango   $[L, R]$ , iteramos sobre todas las potencias de dos, comenzando por la más grande. Tan pronto como una potencia de dos   $2^i$  sea menor o igual a la longitud del rango (  $= R - L + 1$ ), procesamos la primera parte del rango   $[L, L + 2^i - 1]$ , y continuamos con el rango restante   $[L + 2^i, R]$ .

```cpp
long long sum = 0;
for (int i = K; i >= 0; i--) {
    if ((1 << i) <= R - L + 1) {
        sum += st[i][L];
        L += 1 << i;
    }
}
```
La complejidad temporal de una consulta de suma de rango es   $O(K) = O(\log \text{MAXN})$ .
