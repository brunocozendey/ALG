/*Voc� vai trabalhar com o C�lculo de Fatorial de duas maneiras:
	a) com um algoritmo recursivo
	b) com um algoritmo que usa uma pilha para simular a recurs�o
1. Programe o procedimento FatPil
*/
#include<iostream>
using namespace std;

int n, S[20], topo;

int FatRec(int p){
    if (p <=1) return 1;
    else return p*FatRec(p-1);
}

void esvaziar(){
    topo=0;
}

void PUSH(int p){
    S[++topo]=p;
}

int POP(){
    int p = S[topo--];
    return p;
}  

int FatPil(int p){
    int i, f;
	esvaziar();  
	i = p;
	while (i > 0){
	    PUSH(i); 
		i--;
	}
	f = 1;
	while (topo > 0){
	    f =  f*POP();
	}
	return f;	

}
int main(){
    for (n=1; n<=12; n++){
    	cout<<endl;
        cout<<"Resultado de Fat("<<n<<") recursivo: "<<FatRec(n)<<endl;
        cout<<"Resultado de Fat("<<n<<") com pilha: "<<FatPil(n)<<endl;        
    }
    return 0;
}
