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


template <typename T>
void posmaior(std::vector<T>& v, int l, int r, T& max_index) {
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
        T max2 = 0;

        posmaior(v, l, std::floor((r + l) / 2), max_index);
        posmaior(v, std::floor((r + l) / 2) + 1, r, max2);

        max_index = (v[max_index] < v[max2] ? max2 : max_index);

    }

}

int main()
{
    //Exemplo com entrada de inteiros:
    std::vector<int> vector_in = { 15,7,55,23,24,10,11,8,76,19,50, 7 };
    int max_index = 0;

    std::cout << "Vetor de entrada: ";
    print_vector(vector_in);
    posmaior(vector_in, 0, vector_in.size() - 1, max_index);
    std::cout << " Indice do maior elemento eh:" << max_index;

   
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
