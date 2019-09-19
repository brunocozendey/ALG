/* Neste exerc�cio voc� vai trabalhar com a Ordena��o por Distribui��o
1. Observe os algoritmos de tratamento das filas.
2. Observe que o algoritmo executa sempre 10 passos de ordena��o, mesmo que
   o maior n�mero seja pequeno.
3. Corrija o programa para s� fazer o n�mero de passos necess�rio.
*/
#include<iostream>
#include<stdlib.h>
using namespace std;

typedef struct no* lista;
typedef struct no{ int chave; lista prox;}no;          
typedef struct fila{ lista  f, r;}fila;

int n, maiorvalor = 0; fila filas[11];

void Imprime(int t){
    lista p;
    if (t == 1) cout <<"Situacao Inicial: " << endl;
    else if (t == 2) cout <<"Situacao Intermediaria: " << endl;
    else cout <<"Situacao Final: "<< endl;
    p = filas[10].f;
    while (p != NULL){
        cout << p->chave <<" ";  p = p->prox;
    }
    cout <<endl;
    cin.get();
}

int Digito (int d, int k){
    int i, j;
    j = k;
    for (i=1; i<=(d-1); i++) j = j/10;
    j = j%10;
    return j;
}

void Enfila (int nf, int k){
    lista p;
    p = new(no);  p->chave = k;  p->prox = NULL;
    if (filas[nf].r != NULL) filas[nf].r->prox = p;
    else                     filas[nf].f = p;
    filas[nf].r = p;
}

int Desenfila (int nf){
    int k; lista p;
    if (filas[nf].f != NULL){
        p = filas[nf].f; filas[nf].f = filas[nf].f->prox;
        if (filas[nf].f == NULL) filas[nf].r = NULL;
        k = p->chave;
        free(p);
    }
    else  k = -1;
    return k;
}

void Inicializa(){
    int i, k;
    int contaDigitos = 0, valor;    
    for (i=0; i<=10; i++){
        filas[i].f = NULL;
        filas[i].r = NULL;
    }
    cout <<"Elementos a ordenar: ";
    for (i=1; i<=n; i++){
        k = rand()%1000;   
        valor = k;
        contaDigitos = 0;
        if (valor == 0) contaDigitos = 1;
        else{
            while (valor != 0){
               contaDigitos = contaDigitos + 1;
               valor = valor / 10;
           }
        }
        
        maiorvalor = max(contaDigitos,maiorvalor);

        Enfila(10, k); cout<<k<<" ";
    }
    cout<< endl;
}

void Ordena(){
    int d, i, j, k, m;
    for (d=1; d<=maiorvalor; d++){
        for (i=1; i<=n; i++){
            k = Desenfila(10);  m = Digito (d, k);
            Enfila(m,k);
        }
        for (j=0; j<=9; j++)
            while (filas[j].f != NULL){
                k = Desenfila(j);
                Enfila(10,k);
            }
        Imprime(2);
    }
}

int main(){
    while(true){
        cout <<"Numero de elementos a ordenar: "; cin >> n;
        if (!n) break;
        Inicializa();
        Imprime(1);
        Ordena();
        Imprime(3);
    }    
    return 0;
}
