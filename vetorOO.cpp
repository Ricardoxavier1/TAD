#include<iostream>
#include<string>
#include "vetor.h"
using namespace std;
const int TAM = 5;

Vetor::Vetor() {
    this -> vet = new int[TAM];
    this -> qtd = 0;
    this -> tam = TAM;
};

Vetor::~Vetor(){
    delete this -> vet;
};

bool Vetor::anexar(int elemento){
    if(this -> qtd == this -> tam){
        int* aux = new int(this -> tam * 2);

        for(int i = 0; i < this -> qtd; i++){
            aux[i] = this -> vet[i];
        }

        delete this -> vet;
        this -> vet = aux;
        this -> tam *= 2;
    }

    this -> vet [this -> qtd] = elemento;
    this -> qtd++;

    return true;
};
bool Vetor::inserir(int elemento, int posicao){
    if(posicao < 0) return false;
    if(posicao > this -> tam) return false;

        for(int i = 0; i < this -> tam; i++){
            if(posicao == i){
                this -> vet[i] = elemento;
                this -> qtd++;
            }
            if(posicao > this -> qtd){
                this -> qtd++;
            }
    }

    return true;
};
bool Vetor::substituir(int posicao, int novoElemento){
    if(posicao < 0) return false;
    if(posicao > this -> qtd - 1) return false;

    for(int i = 0; i < this -> qtd; i++){
        if(posicao == i){
            this -> vet[i] = novoElemento;
        }
    }

    return true;  
};

bool Vetor::removerPorPosicao(int posicao, int &removido){
    if(posicao < 0) return false;
    if(posicao > this -> qtd - 1) return false;

    removido = this -> vet[posicao];

    for(int i = 0; i < this -> qtd; i++){
        this-> vet [i] = this -> vet [i+1];
    }
    this -> qtd--;


    return true;
};

int Vetor::removerPorElemento(int elemento){

    int elem;
    for (int i = 0; i < this -> qtd; i++){
        if(this -> vet[i] == elemento) {
           this -> vet[i] = 0;
           elem = this -> vet[i];
        };
    }
      return elem;
};

int Vetor::tamanho(){
    return this -> qtd;
};

int Vetor::buscarPorElemento(int elemento){
    
    int posicaoSaida;

    for(int i = 0; i < this -> qtd; i++){
        if(this -> vet[i] == elemento){
            posicaoSaida = i;
        }
    }
    return posicaoSaida;
};

int Vetor::buscarPorPosicao(int posicao){
    if(posicao < 0) return -1;
    if(posicao > this -> qtd - 1) return -1;

    int saidaElem;

    for(int i = 0; i < this -> qtd; i++){
        if(posicao == i){
            saidaElem = this -> vet[i];        
        }
    }
    return saidaElem;
};


void Vetor::imprimir(){
    cout << "[";

    for(int i = 0; i < this  -> qtd; i++){
        cout << this -> vet[i];
        if(i < this  -> qtd - 1) cout << ",";
    }

    cout << "]" << endl;
};

bool Vetor::toString(){

    string vetString;
    string conchete1 = "[";
    string conchete2 = "]";
    string virgula;
    string uniao;

    for(int i = 0; i < this -> tam; i++){
        char str[20];
        sprintf(str,"%d",this -> vet[i]);

        vetString.append(str);
        if(i < this  -> qtd - 1) {
            virgula = ",";
            vetString.append(virgula);
        }
    }
        uniao = conchete1+""+vetString+""+conchete2;
    
        cout << uniao << endl;
    
    return true;
};

int main(){
    Vetor* v1 = new Vetor();
    int a;
    v1 -> anexar(10);//0
    v1 -> anexar(20);//1
    v1 -> anexar(40);//2
    v1 -> inserir(13,3);//3
    v1 -> inserir(15,4);//4
    
    // v1 -> substituir(0,34);//1

    cout <<"Qtd de elementos   : "<<v1 -> tamanho() << endl;
    cout <<"Elemento da posicao: "<< v1 -> buscarPorPosicao(0) << endl;
    cout <<"Posicao do elemento: "<< v1 -> buscarPorElemento(20) << endl;

    // cout << v1 -> removerPorElemento (20) << endl;
    // v1 -> removerPorPosicao(1,a);
    v1 -> imprimir();
    v1 -> toString();
};

