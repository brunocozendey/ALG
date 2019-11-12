/*Voc� vai trabalhar com uma �rvore bin�ria que cont�m uma express�o aritm�tica.
  A �rvore j� est� criada e impressa. Voce deve:
  1. implementar apenas o procedimento Calcula,
     que calcula o valor da express�o aritm�tica correspondente � �rvore.*/
     // A folha serA sempre o operando
     //Converter char para inteiro o fazer valor do caracter menos o '0'
#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<time.h>
using namespace std;

typedef struct no* Arv;
struct no{ char c; Arv le,ld;};
Arv T;  int n, toti;

int Resultado (int a, int b, char op){
    if (op=='+') return a+b;
    else if (op =='-') return a-b;
    else if (op=='*') return a*b;
}

int Calcula(Arv p){
    int ve, vd; 
    if (((p->c -'0') >= 1) && ((p->c-'0')<=9)) // testa se p é folha
      return p->c - '0';
    else
      return Resultado(Calcula(p->le),Calcula(p->ld),p->c);

}

string PercInor(Arv p){
    if (((p->c -'0') >= 1) && ((p->c-'0')<=9))
        return string(1,p->c);
    else return "(" + PercInor(p->le)+ string(1,p->c)+PercInor(p->ld)+")"; 
/*  se p � folha: 
		retornar string(1, p->c);
    sen�o:
        retornar "(" + PercInor(p->le)+ string(1,p->c)+PercInor(p->ld)+")";  
*/
}
Arv CriaExpr(char tipono){
    int i,j;  char c;  Arv p;
    
    p = new(no); p->le = p->ld = NULL;
    if(tipono == 'F') p->c = (rand()%10) + '0';
    else{
        i = rand()%3 +1; toti++;
        if(i == 1)      p->c = '+';
        else if(i == 2) p->c = '-';
        else            p->c = '*';
        if(toti < n)    j = rand()%2;
        else            j = 0;
        if(!j)          c = 'F';
        else            c = 'I';
        p->le = CriaExpr(c);
        p->ld = CriaExpr(c);
    }
    return p; 
}

int main(){
    srand (time(NULL));
    n=10;
    while(true){
        toti = 0;
        T = CriaExpr('I');
        cout <<PercInor(T)+" = "<< Calcula(T) <<endl;
        cin.get();
    }
    return 0;
}
