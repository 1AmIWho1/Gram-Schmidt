# Gram-Schmidt

## Zadání projektů
Implementujte v C++ Gram-Schmidtův a Modifikovaný Gram-Schmidtův ortogonalizační proces, který ortonormalizuje sloupce matice a použijte je k vyřešení soustavy lin. rovnic jakožto inverzní matice.

## Teorie

Cilem ortogonalizace je sestavit otrogonalni baze $Q$ z vektoroveho prostoru $A$. 
### Gram-Schmidtův proces
Nejpreve zvolime $q_1 = a_1$ a předpokládejme, že můžeme představit vektor $a_k$ jako lineární kombinace vektoru z otrogonalni baze $Q$.
$$a_k = \alpha_1q_1 + \alpha_2q_2 + ... + \alpha_kq_k$$
$$\alpha_kq_k = a_k - \alpha_1q_1 - \alpha_2q_2 - ... - \alpha_{k-1}q_{k-1}$$

Požadujeme, aby vektor $\alpha_kq_k$ byl ortogonální k již vypočteným vektorům $q_1,...,q_{k−1}$. Proto po přenásobení vektorem $q_i,\ i \in 1, 2,..., k − 1$ dostáváme:
$$0 = \alpha_k(q_k, q_i) = (a_k, q_i) - \alpha_1(q_1, q_i) - ... - \alpha_{k-1}(q_{k-1}, q_i)$$
$$0 = (a_k, q_i) - \alpha_i(q_i, q_i)$$

Pomoci vzorcu $\alpha_i = \frac{(a_k, q_i)}{(q_i, q_i)}$ muzeme postupne najit koeficienty $\alpha_i,\ i \in 1,..., k-1$. Vektory $q_i,\ i \in 1, 2,..., k − 1$ jiz zname, takze muzeme najit $q_k$:
$$q_k = \frac{\alpha_kq_k}{||\alpha_kq_k||}$$

### Modifikovaný Gram-Schmidtův proces:
Nejprve zvolime $q_1 = a_1$. Pro ortogonalizace $a_k$ zvolime $q_k^0 = a_k$, a pomoci cyklu, v kazde iterace ktereho budeme spoctiat koeficent $\alpha = (q_k^{i-1}, q_i)$ a pak ihned pouzijeme jeho pro vypocet $q_k^i = q_k^{i-1} - \alpha q_i,\ i=1,..,k-1$.


Pro ziskani otronormalni baze podelime kazdy vektor $q_i$ jeho delkou
$$q_i = \frac{q_i}{||q_i||}$$

