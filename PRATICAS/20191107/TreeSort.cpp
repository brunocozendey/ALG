#include<stdio.h>
#include<stdlib.h>
#include<time.h>

/*Voc� vai trabalhar com o m�todo de ordena��o Treesort.
A ideia � ler os n n�meros, criar uma ABB e depois percorr�-la in-ordem.
1. Entenda o programa e rode o programa como ele est�.
2. Modifique a ordena��o para ela ficar em ordem decrescente.
3. Rode o programa para n = 10, 100, 1000, 10000, 10000, anotando os tempos.
4. Rode o programa para n de 100000 a 1000000, de 50000 em 50000, anotando os tempos.
5. Verifique o efeito nos tempos quando se varia o par�metro para 1000, 100000 e 10000000.
   Explique o resultado. */

typedef struct no* arv;
struct no{
    int c; arv le,ld;
};

int i,j,cont,n,parametro;
arv T,z;
int V[1000001];
long start_time, end_time, elapsed;

void InicializaABB();
void CopiaABB(arv p);
void InsereABB(int k);

int main(){
    
    srand (time(NULL));
    InicializaABB();
    parametro = 100;
    printf("Numero de elementos a serem gerados: ");    scanf("%d%*c",&n);
    for(i = 1;i<=n;i++) V[i] = rand()%parametro;
    if(n > 20)  j = 20;
    else        j = n;
    //Vetor inicial
    start_time = clock();
    printf("Situa��o inicial: ");    for(i = 1;i <= j;i++)   printf("%d ",V[i]);
    puts("");
    for(i = 1;i<=n;i++) InsereABB(V[i]);
    cont = 0; CopiaABB(T);
    puts("");
    //Vetor final
    start_time = clock();
    printf("Situa��o final: ");    for(i = 1;i <= j;i++)   printf("%d ",V[i]);
    elapsed = (end_time - start_time) / CLOCKS_PER_SEC * 1000;
    printf("%i", elapsed);
    puts("");
    scanf("%*c");
}

void InicializaABB(){
    z = (arv)malloc(sizeof(no));    z->le = z->ld = T = z;
}

void CopiaABB(arv p){
    if(p!=z){
        CopiaABB(p->le);
        V[++cont] = p->c;
        CopiaABB(p->ld);
    }
}
void InsereABB(int k){
    arv p,f;
    z->c = k; p = f = T;
    while(p!=z){
        f = p;
        if(k >= p->c)   p = p->le;
        else            p = p->ld;    
    }
     p = (arv)malloc(sizeof(no));   p->c = k;    p->le = p->ld =  z; 
     if(T == z)             T = p;
     else if(k >= f->c)     f->le = p;
     else                   f->ld = p;  
}
