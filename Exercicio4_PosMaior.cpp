// Exercicio4_PosMaior.cpp : Este arquivo contém a função 'main'. A execução do programa começa e termina ali.
//

#include <iostream>
#include <vector>

template <typename T>
void print_vector(std::vector<T>& v) {//função para imprimir um vetor
    for (auto i = v.begin(); i != v.end(); i++) {
        std::cout << *i << " ";
    }
    std::cout << std::endl;
}


//----------------------- Max por Divide and Conquer-----------------------
template <typename T>
void DCmax(std::vector<T>& v, int l, int r, int& max_index) {
    if (l == r) {
        max_index = l;
    }
    else if (r - l == 1) { //vetor de dois elementos caso base T(2) = 1
        if (v[l] < v[r]) {
            max_index = r;
        }
        else {
            max_index = l;
        }
    }
    else if (r - l > 1) {
        int max2 = 0;

        DCmax(v, l, std::floor((r + l) / 2), max_index);
        DCmax(v, std::floor((r + l) / 2) + 1, r, max2);

        max_index = (v[max_index] < v[max2] ? max2 : max_index);

    }

}


//----------------------- Max por Brute Force-----------------------
template <typename T>
void BFmax(std::vector<T>& v, int& max_index) {
    T max = v[0];

    if (v.size() == 1) {
        max_index = 0;
    }
    else {
        for (int i = 1; i < v.size(); i++) {
            if (v[i] > max) {
                max = v[i];
                max_index = i;
            }

        }
    }

}


int main()
{
    //Exemplo com entrada de inteiros:
    std::vector<int> vector_in = { 15,79,55,23,24,100,11,8,76,19,50, 7 };
    int max_indexDC = 0;
    int max_indexBF = 0;

    std::cout << "Vetor de entrada: ";
    print_vector(vector_in);

    std::cout << std::endl;

    DCmax(vector_in, 0, vector_in.size() - 1, max_indexDC);
    std::cout << " Indice do maior elemento por DC eh:" << max_indexDC;

    std::cout << std::endl;

    BFmax(vector_in, max_indexBF);
    std::cout << " Indice do maior elemento por BF eh:" << max_indexBF;
   
}
// Executar programa: Ctrl + F5 ou Menu Depurar > Iniciar Sem Depuração
// Depurar programa: F5 ou menu Depurar > Iniciar Depuração

// Dicas para Começar: 
//   1. Use a janela do Gerenciador de Soluções para adicionar/gerenciar arquivos
//   2. Use a janela do Team Explorer para conectar-se ao controle do código-fonte
//   3. Use a janela de Saída para ver mensagens de saída do build e outras mensagens
//   4. Use a janela Lista de Erros para exibir erros
//   5. Ir Para o Projeto > Adicionar Novo Item para criar novos arquivos de código, ou Projeto > Adicionar Item Existente para adicionar arquivos de código existentes ao projeto
//   6. No futuro, para abrir este projeto novamente, vá para Arquivo > Abrir > Projeto e selecione o arquivo. sln
