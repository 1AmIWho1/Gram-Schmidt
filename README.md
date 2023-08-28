# Gram-Schmidt

## Zadání projektů
Implementujte v C++ Gram-Schmidtův a Modifikovaný Gram-Schmidtův ortogonalizační proces, který ortonormalizuje sloupce matice a použijte je k vyřešení soustavy lin. rovnic jakožto inverzní matice.

## Teorie

Cílem ortogonalizace je sestavit ortogonální báze $Q$ z vektorového prostoru $A$.

### Gram-Schmidtův proces
Nejpreve zvolíme $q_1 = a_1$ a předpokládejme, že můžeme představit vektor $a_k$ jako lineární kombinace vektoru z ortogonální báze $Q$.
$$a_k = \alpha_1q_1 + \alpha_2q_2 + ... + \alpha_kq_k$$
$$\alpha_kq_k = a_k - \alpha_1q_1 - \alpha_2q_2 - ... - \alpha_{k-1}q_{k-1}$$

Požadujeme, aby vektor $\alpha_kq_k$ byl ortogonální k již vypočteným vektorům $q_1,...,q_{k−1}$. Proto po přenásobení vektorem $q_i,\ i \in 1, 2,..., k − 1$ dostáváme:
$$0 = \alpha_k(q_k, q_i) = (a_k, q_i) - \alpha_1(q_1, q_i) - ... - \alpha_{k-1}(q_{k-1}, q_i)$$
$$0 = (a_k, q_i) - \alpha_i(q_i, q_i)$$

Pomoci vzorců $\alpha_i = \frac{(a_k, q_i)}{(q_i, q_i)}$ můžeme postupně najít koeficienty $\alpha_i,\ i \in 1,..., k-1$. Vektory $q_i,\ i \in 1, 2,..., k − 1$ již známé, takže můžeme najít $q_k$:
$$q_k = \frac{\alpha_kq_k}{||\alpha_kq_k||}$$

### Modifikovaný Gram-Schmidtův proces:
Nejprve zvolíme $q_1 = a_1$. Pro ortogonalizace $a_k$ zvolíme $q_k^0 = a_k$, a pomoci cyklu, v každé iterace kterého budeme vypočítat koeficent $\alpha = (q_k^{i-1}, q_i)$ a pak ihned použijeme jeho pro výpočet $q_k^i = q_k^{i-1} - \alpha q_i,\ i=1,..,k-1$.

Pro získání otronormalní báze podělíme každý vektor $q_i$ jeho délkou
$$q_i = \frac{q_i}{||q_i||}$$

## Použití ortogonalizace Grama-Schmidta pro řešení soustav lineárních rovnic

$$Ax = b$$
$$Ax - b = 0$$
$$a_{1,1}x_1 + a_{1,2}x_2 + ... + a_{1,n}x_n - b_1 = 0$$
$$a_{2,1}x_1 + a_{2,2}x_2 + ... + a_{2,n}x_n - b_2 = 0$$
$$...$$
$$a_{n,1}x_1 + a_{n,2}x_2 + ... + a_{3,n}x_n - b_n = 0$$


Definujeme vektor $z = (x_1, ..., x_n, 1)^T$ a vektory $g_i = (a_{i,1}, a_{i,2}, ..., a_{i,n}, -b_i),\ i = 1,...,n$ a zapíšeme předchozí systém jinak:
$$(g_1,z) = 0$$
$$(g_2,z) = 0$$
$$...$$
$$(g_n,z) = 0$$

Pro výpočet vektora, kolmého k vektoram $g_i, i = 1, ..., n$ k vektoram $g$ přidáme nenulový vektor $g_{n+1}$ a provedeme ortogonalizacni proces. Po němu dostaneme ortogonální vektory $q_i, i = 1, ..., n+1$, přičemž pro $q_{n+1}$ platí:
$$(g_1,q_{n+1}) = 0$$
$$(g_2,q_{n+1}) = 0$$
$$...$$
$$(g_n,q_{n+1}) = 0$$

Navíc potřebujeme $1$ jako poslední element vektora $q_{n+1}$ a proto vydělíme jeho posledním členem:
$$z = \frac{q_{n+1}}{q_{n+1,n+1}}$$

$$x = (z_1, z_2, ..., z_n)$$



