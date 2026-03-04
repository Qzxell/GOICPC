---
tags:
    - DP
    - Math
    - Atcoder
Level: 1500
Solved: true 
Idea_clave: 
MIstakes: 
resolve_again_obligatory: true
URL: 
---

## De que va el problema

- 

### Posibles solucion

# EDITORIAL

## 1.
Para construir GCD x solo si:
- $A_i$ es divisible por x
- A tiene por lo menos k elementos divisibles por x
La respuesta es el maximo entre dichos valores de x
## 2. Programacion Dinamica

### 2.1 Vector de frecuencia
Sea $s_n :=$ cantidad de veces que aparece n en $A$ -> $O(n+M)$,siendo M el elemento mayor de A
### 2.2 Calculo de multiplos
- definimos $t_n$ como lla cantidad de elementos de A que son multiplos de n
Para calcularlo, usamos 
$$t_d = \sum_{d|n}s_n$$
```c++
for (int d = 1; d <= M; d++) {
  for (int n = d; n <= M; n += d) {
    t[d] += s[n];
  }
}
```

Esto tiene un costo de $O(MlogM)$
## Calculo del mejor x

Definimos
- $u_n$ : el mejor x para cada $A_i$ = n
La relacion es la siguiente:
$$u_n=max\{d|n \text{ y } t_d >= K\}$$

```c++
for (int d = 1; d <= M; d++) {
  if (t[d] < K) continue;
  for (int n = d; n <= M; n += d) {
    u[n] = max(u[n], d);
  }
}

```
Finalmente para cada elemento de A, imprimimos $u[A_i]$ 
