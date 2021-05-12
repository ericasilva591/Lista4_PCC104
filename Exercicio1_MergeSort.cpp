// Exercicio1_MergeSort.cpp : Este arquivo contém a função 'main'. A execução do programa começa e termina ali.
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
void Merge(std::vector<T>& b, std::vector<T>& c, std::vector<T>& a) {
    int i = 0;
    int j = 0;
    int k = 0;
    int p = b.size();
    int q = c.size();
    while (i < p && j < q) {
        if (b[i] <= c[j]) { 
            a[k] = b[i];
            i += 1;
         }
        else {
            a[k] = c[j];
            j += 1;
        }
        k += 1;
        if (i == p) {
            int aux = k;
            for (int t = j; t < q; t++) {
                a[aux] = c[t];
                aux += 1;
            }
        }
        else {
            int aux = k;
            for (int t = i; t < p; t++) {
                a[aux] = b[t];
                aux += 1;
            }
        }
    }
}

template <typename T>
void MergeSort(std::vector<T>& a) {
    if (a.size() > 1){
        std::vector<T> b;
        std::vector<T> c;
        int n = a.size() / 2;
        for (int i = 0; i < n; i++) {
            b.push_back(a[i]);
        }
        for (int j = n; j < a.size(); j++) {
            c.push_back(a[j]);
        }
        MergeSort(b);
        MergeSort(c);
        Merge(b, c, a);
    }
}

int main()
{
    //Exemplo com entrada de inteiros:
    std::vector<int> vector_in = { 15,7,55,23,24,10,11,8,19,50 };
    
    //std::vector<std::string> vector_in = {"E", "X", "A", "M", "P", "L", "E"};

    //Exemplo com entrada de string:
    //std::vector<std::string> vector_in = { "gadf","eadf","etdf","hfaf","naw","zqdd","raf","fbf","zaf","ado" };

    //Exemplo com entrada de double:
    //std::vector<float> vector_in = { 11.4,312.54,34.0,2.3,6.75,89.4,23.5,5.65,65.4,8.43 };

    std::cout << "Vetor nao ordenado: ";
    print_vector(vector_in);
    MergeSort(vector_in);
    std::cout << "Vetor ordenado por Merge Sort: ";
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
