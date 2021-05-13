// Exercicio6_QuickSort.cpp : Este arquivo contém a função 'main'. A execução do programa começa e termina ali.
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
int HoarePartition(std::vector<T>& v, int l, int r) {
    int p = v[l]; // o pivo p começa com o primeiro elemeto do subarray
    int i = l;
    int j = r + 1;
    do {
       do {
           i++;
       } while (v[i] >= p);// Por que vale a pena interromper as varreduras depois de encontrar um elemento igual ao pivô? Porque isso tende a produzir divisões mais uniformes para matrizes com muitas duplicatas, o que torna a execução do algoritmo mais rápido
       do {
           j--;//right-to-left scan, encontra elementos maiores que o pivo p
       } while (v[j] <= p);
       std::swap(v[i], v[j]);
    } while (i >= j); // se os índices de varredura cruzaram ou para na mesma posição, ou seja, i>= j, teremos particionado o subarray depois de trocar o pivô com A [j]:
    std::swap(v[i], v[j]); /// desfaz a ultima troca
    std::swap(v[l], v[j]);

   return j;
}

template <typename T>
int lomutoPartition(std::vector<T>& v, int l, int r) {
    int p = v[l];
    int s = l;
    for (int i = l + 1; i <= r; i++) {
        if (v[i] < p) {
            s = s + 1;
            std::swap(v[s], v[i]);
        }
    }

    std::swap(v[l], v[s]);

    return s;

}

template <typename T>
void QuickSort(std::vector<T>& v, int l, int r) {
    if (l < r) {
        int s = lomutoPartition(v, l, r);
        //int s = HoarePartition(v, l, r);
        QuickSort(v, l, s - 1);
        QuickSort(v, s + 1, r);
    }
}

int main()
{
    //Exemplo com entrada de inteiros:
    std::vector<int> vector_in = { 15,15,7,55,23,24,10,11,8,19,50 };

    std::cout << "Vetor desordenado: ";
    print_vector(vector_in);
    QuickSort(vector_in, 0 , vector_in.size() - 1);
    std::cout << "Vetor ordenado: ";
    print_vector(vector_in);
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
