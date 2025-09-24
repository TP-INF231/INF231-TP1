
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


double *alloc_vector(int n) {
    return (double*)malloc(sizeof(double)*n);
}

/* Allouer dynamiquement une matrice (2D : rows x cols) */
double **alloc_matrix(int rows, int cols) {
    double **M = (double**)malloc(sizeof(double*)*rows);
    for (int i=0;i<rows;i++) M[i] = (double*)malloc(sizeof(double)*cols);
    return M;
}

/* Libérer la mémoire d’une matrice */
void free_matrix(double **M, int rows) {
    for (int i=0;i<rows;i++) free(M[i]);
    free(M);
}


/* 1. Somme de matrices A + B */
double **matrix_sum(double **A, double **B, int rows, int cols) {
    double **R = alloc_matrix(rows, cols); // matrice résultat
    for (int i=0;i<rows;i++)
        for (int j=0;j<cols;j++)
            R[i][j] = A[i][j] + B[i][j]; // addition élément par élément
    return R;
}

/* 2. Produit de matrices A (r1 x c1) * B (r2 x c2) */
double **matrix_product(double **A, int r1, int c1, double **B, int r2, int c2) {
    if (c1 != r2) return NULL; // condition : colonnes de A == lignes de B
    double **R = alloc_matrix(r1, c2); // matrice résultat (r1 x c2)
    for (int i=0;i<r1;i++) {
        for (int j=0;j<c2;j++) {
            double s = 0.0;
            for (int k=0;k<c1;k++) s += A[i][k] * B[k][j]; // somme produit
            R[i][j] = s;
        }
    }
    return R;
}

/* 3. Recherche séquentielle (lineaire) dans un tableau */
int sequential_search(double *arr, int n, double key) {
    for (int i=0;i<n;i++)
        if (arr[i] == key) return i; // retourne l’indice si trouvé
    return -1; // sinon -1
}

/* 4. Multiplication a × b en utilisant seulement +1 */
long multiply_using_only_increment_positive(int a, int b) {
    if (a <= 0 || b <= 0) return 0; // on demande a,b > 0
    long result = 0;
    // On effectue result++ exactement a*b fois
    for (int i=0;i<b;i++) {
        for (int j=0;j<a;j++) {
            result++; // unique opération autorisée
        }
    }
    return result;
}

/* 5. Tester si un tableau est trié (croissant non strict) */
int is_sorted_ascending(double *arr, int n) {
    for (int i=1;i<n;i++)
        if (arr[i] < arr[i-1]) return 0; // si un élément casse l’ordre
    return 1; // sinon c’est trié
}

/* 6. Médiane d’un tableau */
int cmp_double(const void *a, const void *b) {
    double da = *(const double*)a;
    double db = *(const double*)b;
    if (da < db) return -1;
    if (da > db) return 1;
    return 0;
}

double median(double *arr, int n) {
    if (n <= 0) return 0.0;
    // Copier le tableau pour ne pas modifier l’original
    double *copy = (double*)malloc(sizeof(double)*n);
    memcpy(copy, arr, sizeof(double)*n);
    // Tri croissant
    qsort(copy, n, sizeof(double), cmp_double);
    double med;
    if (n % 2 == 1) med = copy[n/2]; // impair → valeur centrale
    else med = (copy[n/2 - 1] + copy[n/2]) / 2.0; // pair → moyenne
    free(copy);
    return med;
}

/* 7. Inverser un tableau (in-place) */
void reverse_array(double *arr, int n) {
    int i=0, j=n-1;
    while (i<j) {
        double t = arr[i]; arr[i] = arr[j]; arr[j] = t; // échange
        i++; j--;
    }
}

/* 8. Produit vectoriel (cross product) pour vecteurs 3D */
double *cross_product_3d(double *v, double *w) {
    double *r = alloc_vector(3); // vecteur résultat
    r[0] = v[1]*w[2] - v[2]*w[1];
    r[1] = v[2]*w[0] - v[0]*w[2];
    r[2] = v[0]*w[1] - v[1]*w[0];
    return r;
}

/* 9. Produit vecteur × matrice (1xn * nxm = 1xm) */
double *vector_times_matrix(double *v, int n, double **M, int r, int c) {
    if (n != r) return NULL; // dimensions incompatibles
    double *res = alloc_vector(c);
    for (int j=0;j<c;j++) {
        double s = 0.0;
        for (int i=0;i<n;i++) s += v[i] * M[i][j]; // somme produit
        res[j] = s;
    }
    return res;
}


/* Saisie d’une matrice */
void input_matrix(double **M, int rows, int cols) {
    for (int i=0;i<rows;i++)
        for (int j=0;j<cols;j++) {
            printf("Entrez M[%d][%d] : ", i, j);
            scanf("%lf", &M[i][j]);
        }
}

/* Affichage d’une matrice */
void print_matrix(double **M, int rows, int cols) {
    for (int i=0;i<rows;i++) {
        for (int j=0;j<cols;j++) printf("%8.3f ", M[i][j]);
        printf("\n");
    }
}

/* Saisie d’un vecteur */
void input_vector(double *v, int n) {
    for (int i=0;i<n;i++) {
        printf("Entrez v[%d] : ", i);
        scanf("%lf", &v[i]);
    }
}

/* Affichage d’un vecteur */
void print_vector(double *v, int n) {
    for (int i=0;i<n;i++) printf("%8.3f ", v[i]);
    printf("\n");
}

/* Petite pause après chaque opération */
void pause_and_flush() {
    printf("Appuyez sur Entrée pour continuer...");
    getchar(); getchar();
}


int main() {
    int choix = 0;
    while (1) {
        // Affichage du menu principal
        printf("\n--- MENU : Structures de données en C ---\n");
        printf("1. Somme de matrices\n");
        printf("2. Produit de matrices\n");
        printf("3. Recherche séquentielle dans un tableau\n");
        printf("4. Multiplication a x b (a,b>0) en utilisant exclusivement +1\n");
        printf("5. Tester si un tableau est trié (croissant)\n");
        printf("6. Médiane d'un tableau\n");
        printf("7. Inverser un tableau\n");
        printf("8. Produit vectoriel (3D)\n");
        printf("9. Produit vecteur (1xn) x matrice (nxm)\n");
        printf("0. Quitter\n");
        printf("Choix : ");
        scanf("%d", &choix);

        // Quitter
        if (choix == 0) break;

        // Chaque option appelle la fonction correspondante
        if (choix == 1) {
            int r,c;
            printf("Dimensions (rows cols) : ");
            scanf("%d %d", &r, &c);
            double **A = alloc_matrix(r,c);
            double **B = alloc_matrix(r,c);
            printf("Saisie matrice A:\n"); input_matrix(A,r,c);
            printf("Saisie matrice B:\n"); input_matrix(B,r,c);
            double **S = matrix_sum(A,B,r,c);
            printf("A + B =\n"); print_matrix(S,r,c);
            free_matrix(A,r); free_matrix(B,r); free_matrix(S,r);
            pause_and_flush();
        } 
        else if (choix == 2) {
            int r1,c1,r2,c2;
            printf("Dimensions A (rows cols) : "); scanf("%d %d", &r1, &c1);
            printf("Dimensions B (rows cols) : "); scanf("%d %d", &r2, &c2);
            double **A = alloc_matrix(r1,c1);
            double **B = alloc_matrix(r2,c2);
            printf("Saisie A:\n"); input_matrix(A,r1,c1);
            printf("Saisie B:\n"); input_matrix(B,r2,c2);
            double **P = matrix_product(A,r1,c1,B,r2,c2);
            if (!P) printf("Produit impossible : colonnes de A != lignes de B\n");
            else { printf("A * B =\n"); print_matrix(P,r1,c2); free_matrix(P,r1); }
            free_matrix(A,r1); free_matrix(B,r2);
            pause_and_flush();
        } 
        else if (choix == 3) {
            int n;
            printf("Taille du tableau : "); scanf("%d", &n);
            double *arr = alloc_vector(n);
            input_vector(arr,n);
            double key;
            printf("Valeur à chercher : "); scanf("%lf", &key);
            int idx = sequential_search(arr,n,key);
            if (idx >= 0) printf("Trouvé à l'indice %d (0-based)\n", idx);
            else printf("Non trouvé\n");
            free(arr);
            pause_and_flush();
        } 
        else if (choix == 4) {
            int a,b;
            printf("Entrez a et b (entiers >0) : "); scanf("%d %d", &a, &b);
            if (a <= 0 || b <= 0) printf("a et b doivent être > 0\n");
            else {
                long prod = multiply_using_only_increment_positive(a,b);
                printf("%d x %d (par incréments) = %ld\n", a, b, prod);
            }
            pause_and_flush();
        } 
        else if (choix == 5) {
            int n; printf("Taille du tableau : "); scanf("%d", &n);
            double *arr = alloc_vector(n); input_vector(arr,n);
            if (is_sorted_ascending(arr,n)) printf("Le tableau est trié.\n");
            else printf("Le tableau n'est pas trié.\n");
            free(arr);
            pause_and_flush();
        } 
        else if (choix == 6) {
            int n; printf("Taille du tableau : "); scanf("%d", &n);
            double *arr = alloc_vector(n); input_vector(arr,n);
            double med = median(arr,n);
            printf("Médiane = %g\n", med);
            free(arr);
            pause_and_flush();
        } 
        else if (choix == 7) {
            int n; printf("Taille du tableau : "); scanf("%d", &n);
            double *arr = alloc_vector(n); input_vector(arr,n);
            reverse_array(arr,n);
            printf("Tableau inversé :\n"); print_vector(arr,n);
            free(arr);
            pause_and_flush();
        } 
        else if (choix == 8) {
            printf("Produit vectoriel v x w (3D)\n");
            double *v = alloc_vector(3), *w = alloc_vector(3);
            printf("Saisie v:\n"); input_vector(v,3);
            printf("Saisie w:\n"); input_vector(w,3);
            double *r = cross_product_3d(v,w);
            printf("v x w = "); print_vector(r,3);
            free(v); free(w); free(r);
            pause_and_flush();
        } 
        else if (choix == 9) {
            int n,m;
            printf("Entrez n (taille vecteur) et m (colonnes matrice) : ");
            scanf("%d %d", &n, &m);
            double *v = alloc_vector(n);
            printf("Saisie vecteur v (1 x %d):\n", n); input_vector(v,n);
            double **M = alloc_matrix(n,m);
            printf("Saisie matrice M (%d x %d):\n", n, m); input_matrix(M,n,m);
            double *res = vector_times_matrix(v,n,M,n,m);
            if (!res) printf("Dimensions incompatibles\n");
            else { printf("v x M = "); print_vector(res,m); free(res); }
            free(v); free_matrix(M,n);
            pause_and_flush();
        } 
        else {
            printf("Choix invalide\n");
            pause_and_flush();
        }
    }

    printf("Au revoir.\n");
    return 0;
}