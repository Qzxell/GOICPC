---
rating: 
fecha_intento: 
estado: #resuelto
---

# El problema es :

Dado un x < M, M <= 1e9, n <= 1e18
Quiero hallar: $$1 + x + x^2 + x^3... + x^n$$
modulo M, pero M no es necesariamente primo

## La Intuición (Explicado a un niño)

Si M fuera primo entonces bastaba con

$$x^{n+1} - 1 \cdot Inv(x+1)$$


Como no es primo, se me viene matrices, y viendolo como un numero en base x

$$F(i) = F(i-1) \cdot x + 1$$

$$F(i+1) = F(i) \cdot x + 1$$
$$F(i+2) = F(i+1) \cdot x + 1$$

$$
\begin{pmatrix}
f(i) & 1 \\
f(i+1) & 1 \\
\end{pmatrix} \cdot
\begin{pmatrix}
x & 0 \\
1 & 1 \\
\end{pmatrix} = 
\begin{pmatrix}
f(i+1) & 1 \\
f(i+2) & 1 \\
\end{pmatrix}
$$




## Mi Bloqueo (¿Por qué no me sale?)

---
## El "Aja" (la idea clave)


[[abc293_E.cpp]]
