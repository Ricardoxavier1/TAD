#include<iostream>

class Vetor{
    private:
        int* vet;
        int qtd;
        int tam;
    public:
        Vetor();
        ~Vetor();

        void desalocar();
        bool anexar(int elemento);
        bool inserir(int elemento, int posicao);
        bool substituir(int posicao, int novoElemento);
        int removerPorElemento(int elemento);
        bool removerPorPosicao(int posicao, int &removido);
        int tamanho();
        int buscarPorElemento(int elemento);
        int buscarPorPosicao(int posicao);
        void imprimir();
        bool toString();
};