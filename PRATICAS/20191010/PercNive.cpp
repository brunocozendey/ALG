/*Voc� vai trabalhar   com   o  percurso em  n�vel  numa  �rvore bin�ria.
1. Observe que o procedimento CriaArv uma �rvore completa contendo os n�meros 1 a n.
2. Escreva o procedimento PercNiv, SEM MODIFICAR o restante do programa. Voc� deve
   imprimir o conte�do dos n�s visitados. Observe que os procedimentos para 
   tratamento da fila j� est�o programados.
3. Observe que a impress�o n�o mostra os dados ordenados.
   Modifique a cria��o da �rvore para que isso ocorra.*/
#include<iostream>
#include<cstdlib>
using namespace std;

typedef struct no* arv;
typedef struct no{ int c;  arv le, ld; }no;
arv T,  Q[100001];  int nc, n, f, r;

void EsvaziaFil(){
    f=r=0;
}
void Enfila(arv p){
    if (p != NULL){
        Q[++r] = p;
        if (f==0) f = 1;
    }
}
arv Desenfila(){
    arv p;
    p = Q[f];
    if (f == r) EsvaziaFil();
    else f++;
    return p;
}
void CriaArv(){
    arv p,r; int i;
    EsvaziaFil();
    T = new(no);  i=1;  T->c=i;  T->le = T->ld = NULL; Enfila(T);
    while (f != 0){
        p=Q[f];
        if (i < n){
            i++;  r = new(no);  r->c=i;  r->le= r->ld = NULL;
            p->ld=r;  Enfila(r);
        }
        if (i > n){
            i++;  r = new(no);  r->c=i;  r->le=r->ld=NULL;
            p->le=r;  Enfila(r);
        }
        p = Desenfila();
    }
}
   
void PercNiv(){
    arv p;
//Algoritmo de busca em n�vel:
	EsvaziaFil(); 
	Enfila(T); //Estava antes
	while (f > 0){
        p = Q[f];
        cout << p->c <<" ";
        Enfila(p->le);
        Enfila(p->ld);
        p = Desenfila();
    }
}
int main(){
    nc=10;
    while(nc--){
        cout<<endl<<"Numero de nos: "; cin >> n;
        CriaArv();
        PercNiv();
    }
}
