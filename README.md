Description du projet :

Structures de données et opérations en C


Objectif du projet

L’objectif de ce projet est d’implémenter en langage C un ensemble d’algorithmes classiques liés aux tableaux, vecteurs et matrices, afin de manipuler efficacement les structures de données numériques.
Le programme propose une interface textuelle (menu) permettant à l’utilisateur de choisir une opération, de saisir ses données, et d’obtenir directement le résultat calculé.

 Fonctionnalités principales
 

Le programme gère les opérations suivantes :


1. Somme de matrices

Entrée : deux matrices de même taille.

Sortie : une matrice contenant la somme élément par élément.


2. Produit de matrices

Entrée : une matrice A (taille r1 × c1) et une matrice B (taille r2 × c2).

Condition : c1 = r2.

Sortie : matrice résultat (taille r1 × c2).


3. Recherche séquentielle dans un tableau

Parcours du tableau élément par élément.

Retourne l’indice de la première occurrence recherchée ou -1 si absente.


4. Multiplication de deux entiers positifs (a × b)

Particularité : implémentée uniquement avec l’opérateur +1.

Simulation de la multiplication via des incréments successifs (boucles imbriquées).


5. Vérification si un tableau est trié

Analyse du tableau élément par élément.

Vérifie si l’ordre est croissant non strict (chaque élément ≥ au précédent).


6. Calcul de la médiane d’un tableau

Trie une copie du tableau.

Si n impair : élément central.

Si n pair : moyenne des deux éléments centraux.


7. Inversion d’un tableau

Réarrangement des éléments en ordre inverse.

Effectué in-place (sans nouvelle allocation mémoire).


8. Produit vectoriel (cross product)

Entre deux vecteurs 3D.

Résultat : un vecteur 3D perpendiculaire aux deux vecteurs d’entrée.


9. Produit vecteur × matrice

Vecteur ligne (1 × n) multiplié par une matrice (n × m).

Résultat : un vecteur ligne (1 × m).



Le projet est organisé en plusieurs parties dans un seul fichier C :

1. Utilitaires

Fonctions d’allocation/libération de vecteurs et matrices dynamiques.


2. Algorithmes de calcul

Chaque opération (somme, produit, tri, etc.) est implémentée dans une fonction séparée.


3. Entrée/Sortie

Fonctions pour saisir et afficher matrices et vecteurs.



4. Programme principal (main)

Affiche un menu interactif.

Exécute les fonctions en fonction du choix de l’utilisateur.

Boucle jusqu’à ce que l’utilisateur quitte.
