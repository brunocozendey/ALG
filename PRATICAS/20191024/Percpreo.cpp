/*Você vai trabalhar com o percurso  pré-ordem  numa  árvore binária,
  versão não recursiva, usando uma pilha.
  Escreva, APENAS, o procedimento Percpre. Observe que oas operações
  PUSH e POP já estão implementadas, de forma simplificada.
  NÃO MODIFIQUE o restante do programa */
#include<iostream>
using namespace std;

typedef struct no* arv;
struct no{ int c;  arv le, ld; };
arv T,  Q[10000001], S[10000001]; int n, f, r, topo;

void EsvaziaPil(){
    topo=0;
}
void PUSH(arv p){
     if (p != NULL) S[++topo]=p;
}
arv POP(){
    arv p;
    p = S[topo--];
    return p;
}          
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
        if (i < n){
            i++;  r = new(no);  r->c=i;  r->le=r->ld=NULL;
            p->le=r;  Enfila(r);
        }
        p = Desenfila();
    }
}  
void PercPre(arv T){
    arv  p;
/*	esvazia Pilha
	PUSH(T)
	enquanto (topo != 0):
        p <- POP()
		escreve(p.c)
        PUSH(p.ld)
		PUSH(p.le)
*/
}
int main(){
    while (true){
        cout<<endl<<"Numero de nos: "; cin >> n;
        if (!n) break;
        CriaArv();
        PercPre(T);
    }
}
