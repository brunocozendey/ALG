/*Voc� vai trabalhar com �rvores bin�rias de busca.
  Este programa mostra a cria��o de uma �rvore bin�ria de busca.
  A �rvore vai sendo criada e impressa.
  O exerc�cio � mudar a impress�o para in-ordem invertido da �rvore criada.
  Al�m disso, devem ser impressos '-' para indicar o n�vel de cada chave.
*/
#include<iostream>
using namespace std;

typedef struct no* arv;  struct no{char c;  arv ld,le;};
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
        if (c < p->c) p = p->ld;
        else          p = p->le; 
    }
    if (p != z) cout <<"Chave ja inserida."<<endl;
    else {          
        p = new(no);  p->c=c;  p->le=z;  p->ld=z;
        if (z==T) T=p;
        else if (c < f->c) f->ld=p;
        else f->le=p;
    }
}
void ImprimeABB(arv p, int niv){
    int i;
    if (p != z){
        ImprimeABB(p->le, niv+1);
        for (int k=1;k<=niv;k++){
            cout<<'-';
        }
        cout << p->c <<endl;
        ImprimeABB(p->ld, niv+1);
    }
}

int main(){
	while(true){
    InicializaABB();
        cout<<endl<<"Escreva 10 letras, uma em cada linha:"<<endl;
        for (i = 1; i <= 10; i++){
            cout<<"Letra: ";  cin >> c; InsereABB(c);
            ImprimeABB(T,0);
	    }
    }
	return 0;
}
         


