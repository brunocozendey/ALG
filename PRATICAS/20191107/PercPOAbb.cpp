/*Voc� vai trabalhar com �rvores bin�rias de busca.
  A �rvore � criada aleatoriamente.
  1. Programe o procedimento PercPos, recursivo.
  2. Desenhe a �rvore correspondente � sa�da mostrada.
*/
#include<iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;

typedef struct no* arv;  struct no{char c; arv ld,le;};
arv T, z;  int i, niv;   char c;
int V[100001];

void InicializaABB(void){
    z = new(no);  z->le = z;  z->ld = z;  T=z;
}
      
void InsereABB(char c){
	arv p,f;  
    z->c=c;  p=T;  f=T;
    while(p->c != c){
        f = p;
        if (c > p->c) p = p->ld;
        else          p = p->le; 
    }
    if (p != z);
    else {        
        p = new(no);  p->c=c;  p->le=z;  p->ld=z;
        if (z==T) T=p;
        else if (c > f->c) f->ld=p;
        else f->le=p;
    }
}
void PercPos(arv p){
    if (p != (NULL)){
      PercPos(p->le);
      PercPos(p->ld);
      cout << (p->c);
    }	
}

int main(){
    srand(time(NULL));
	while(true){
    	InicializaABB();
        for (i = 1; i <= 12; i++)
            InsereABB('A'+rand()%26);
        //PercPos(T);
        //cin.get();
    }
	return 0;
}
         


