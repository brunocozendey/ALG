/*Este programa mostra a ordena��o pelo Mergesort, exibindo os 40 primeiros
   elementos em duas situa��es: vetor j� ordenado e vetor desordenado.
1. Implemente a fun��o Merge e conte o n�mero de compara��es.
2. Rode o  programa para n= 1000, 10000, 100000, 1000000, 10000000 e 
   100000000 e escrever em papel uma tabela contendo o n�mero de compara��es 
   efetuadas na ordena��o.*/
#include<iostream>
#include<cstdlib>
#include<algorithm> 
using namespace std;
int V[100000001], V1[50000001], V2[50000001], i, n;
long long int comp;

void Merge(int e, int m, int d){
int i,j,k;
    for (i=1; i <= m-e+1; i++){
        V1[i] = V[e+i-1];
        V2[i] = V[m+i];
    }
    V1[m-e+2] = max(V[m],V[d])+1;  
    V2[d-m+1] = V1[m-e+2];
    i = 1;
    j = 1;

    for (k = e; k<= d; k++){
        comp++;
        if (V1[i] < V2[j]){
            V[k] = V1[i];  
            i++;
        }
        else{
            V[k] < V2[j];  
            j++;
        }
    }
}

void MergeSort(int e, int d){
    int m;
    if (d > e){
        m = (e+d)/2;
        MergeSort(e,m);
        MergeSort(m+1,d);
        Merge(e,m,d);
    }
}
int main(){
    while(true){
        cout<<"n = ";  cin>>n;
        comp=0;
        for(i=1; i<=n; i++) V[i]= rand()%n;
        cout<<endl<<"Situacao inicial - primeiros 40 elementos:"<<endl;
        for(i=1; i<=40; i++) cout<<V[i]<<" ";  cout<<endl;
        MergeSort(1,n);
        cout<<endl<<"Situacao final - primeiros 40 elementos:"<<endl;
        for(i=1; i<=40; i++) cout<<V[i]<<" ";  cout<<endl;
        cout<<endl<<"Comparacoes efetuadas: "<<comp<<endl;
    }
    return 0;
}
