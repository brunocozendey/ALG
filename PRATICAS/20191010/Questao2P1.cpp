/* Neste exerc�cio voc� vai programar a Quest�o 2 da P1:
   dado s e um vetor com n elementos inteiros positivos, determinar
   a maior subsequencia consecutiva cuja soma seja menor ou igual a s.
*/
#include<iostream>
#include<cstdlib>
using namespace std;

int V[10000001], s, p, q, t, n, MAIORSUB=0, IMAIOR=0;

void Sequencia(){
int i = 0;
int j, sa;
int TAMSUB = 0;
int ISUB = 0;
int SOMA = 0;
MAIORSUB = 0;
IMAIOR = 0;

    while (i<=n-1){
        SOMA = SOMA + V[i];
        if (SOMA <= s){
            TAMSUB++;
            if (TAMSUB == 1) ISUB = i;
        }
        else{
            SOMA = 0;
            if (MAIORSUB <= TAMSUB){
                MAIORSUB = TAMSUB;
                IMAIOR = ISUB;
            }
            TAMSUB = 0;
            
        }
        i++;
    }   
    p = IMAIOR;
    q = IMAIOR+MAIORSUB-1;
}

int main(){
    int i;
	n=10000000;
    for(i=1; i<=n; i++) V[i]= rand()%7+1;
    cout<<"Sequencia: "; for (i=1; i<= min(n,100); i++) cout<<i<<"-"<<V[i]<<" ";  cout<<endl;
    while(true){
        s = 0;
    	cout<<"s = ";  cin>>s;
        Sequencia();
        // Imprima a sequencia pedida
        cout << "Maior sequencia: "<<"\n"<<"[";
        for(int k=IMAIOR; k<(IMAIOR+MAIORSUB); k++) cout<<V[k]<<" ";
        cout<<"]\n";
        cout<<"Desde "<<p<<" ateh "<<q<<endl;
    }
}
