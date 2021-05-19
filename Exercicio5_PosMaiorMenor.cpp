// Exercicio5_PosMaiorMenor.cpp : Este arquivo contém a função 'main'. A execução do programa começa e termina ali.
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

//-----------------------Min e Max por Brute Force-----------------------
template <typename T>
void BFMinMax(std::vector<T>& v, std::vector<T>& minmax) {
    T min = v[0];
    T max = v[0];
    int index_min = 0;
    int index_max = 0;

    if (v.size() == 1) {
        minmax[0] = index_min;
        minmax[1] = index_max;
    }
    else {
        for (int i = 1; i < v.size(); i++) {
            if (v[i] > max) {
                max = v[i];
                index_max = i;
            }
            else if (v[i] < min) {
                min = v[i];
                index_min = i;
            }

        }
    }

    minmax[0] = index_min;
    minmax[1] = index_max;

}

//-----------------------Min e Max por Decrease and Conquer-----------------------
template <typename T>
int DCMax(int n, std::vector<T>& v) {
    if (n == 1)
        return 0;
    else {
        int max;
        max = DCMax(n - 1, v);
        if (v[max] > v[n - 1]) return max;
        else return n - 1;
    }

}

template <typename T>
int DCMin(int n, std::vector<T>& v) {
    if (n == 1)
        return 0;
    else {
        int min;
        min = DCMin(n - 1, v);
        if (v[min] < v[n - 1]) return min;
        else return n - 1;
    }

}

//-----------------------Min e Max por Divide and Conquer-----------------------
template <typename T>
void DCMinMax(std::vector<T>& v, int l, int r, std::vector<T>& minmax) {
    if (l == r) {
        minmax[0] = l;
        minmax[1] = r;
    }
    else if (r - l == 1) { //vetor de dois elementos caso base T(2) = 1
        if (v[l] < v[r]) {
            minmax[0] = l;
            minmax[1] = r;
        }
        else {
            minmax[0] = r;
            minmax[1] = l;
        }
    }
    else if (r - l > 1) {
        std::vector<int> minmax2 = { 0,0 };

        DCMinMax(v, l, std::floor((r + l) / 2), minmax);
        DCMinMax(v, std::floor((r + l) / 2) + 1, r, minmax2);

        minmax[0] = (v[minmax[0]] < v[minmax2[0]] ? minmax[0] : minmax2[0]);
        minmax[1] = (v[minmax[1]] > v[minmax2[1]] ? minmax[1] : minmax2[1]);

    }
}

//-----------------------Min e Max por fastMinMax-----------------------
template <typename T>
void fastMinMax(std::vector<T>& v, std::vector<T>& minmax_index) {
    std::vector<T> minmax = { v[0],v[0] };

    //verificar se v tem número par ou impar de elementos
    bool impar = false;
    T aux = 0;
    if (v.size() % 2 == 1) {
        aux = v[v.size() - 1]; //recebe o ultimo elemento do vetor
        v.pop_back(); //apaga o ultimo elemento do vetor.
        impar = true;
    }

    for (int i = 0; i < v.size() - 1; i += 2)
    {
        if (v[i] < v[i + 1]) {
            if (v[i] < minmax[0]) {//v[i] é menor que v[i+1]. Então verifica se v[i] é menor do que minmax[0]. se sim, atualiza minmax[0].
                minmax[0] = v[i];
                minmax_index[0] = i;
            }
            if (v[i + 1] > minmax[1]) {//v[i] é menor que v[i+1]. Então verifica se v[i +1] é maor do que minmax[1]. se sim, atualiza minmax[1].
                minmax[1] = v[i + 1];
                minmax_index[1] = i + 1;
            }
        }
        else if (v[i] > v[i + 1]) {
            if (v[i] > minmax[1]) {//v[i] é maior que v[i+1]. Então verifica se v[i] é maior do que minmax[1]. se sim, atualiza minmax[1].
                minmax[1] = v[i];
                minmax_index[1] = i;
            }
            if (v[i + 1] < minmax[0]) {//v[i] é maior que v[i+1]. Então verifica se v[i +1 ] é menor do que minmax[0]. se sim, atualiza minmax[0].
                minmax[0] = v[i + 1];
                minmax_index[0] = i + 1;
            }
        }

    }

    if (impar) { // verifica se o ultimo elemento é o menor ou maior e apaga o ultimo elemento copiado
        v.push_back(aux); //re-insere o elemento no vetor
        if (minmax[0] > aux) {//verifica se o aux é maior ou menor que os valores armazenados em minmax
            minmax[0] = aux;
            minmax_index[0] = v.size() - 1;
        }
        if (minmax[1] < aux) {
            minmax[1] = aux;
            print_vector(minmax);
            minmax_index[1] = v.size() - 1;
        }
        
    }
}


int main()
{
    //Exemplo com entrada de inteiros:
    std::vector<int> vector_in = { 150,7,55,23,24,10,11,8,19,50,67,10,3};
    std::cout << "Vetor de entrada: ";
    print_vector(vector_in);

    std::vector<int> minmax_indexBF = { 0,0 };
    BFMinMax(vector_in, minmax_indexBF);
    std::cout << "Index Min BruteForce: " << minmax_indexBF[0] << std::endl;
    std::cout << "Index Max BruteForce: " << minmax_indexBF[1] << std::endl;

    std::cout << std::endl;

    std::cout << "Index Min DecreaseConquer: " << DCMin(vector_in.size(), vector_in) << std::endl;
    std::cout << "Index Max DecreaseConquer: " << DCMax(vector_in.size(), vector_in) << std::endl;

    std::cout << std::endl;

    std::vector<int> minmax_indexDC = { 0,0 };
    DCMinMax(vector_in, 0, vector_in.size() - 1, minmax_indexDC);

    std::cout << "Index Min DivideConquer: " << minmax_indexDC[0] << std::endl;
    std::cout << "Index Max DivideConquer: " << minmax_indexDC[1] << std::endl;

    std::cout << std::endl;

    std::vector<int> minmax_indexfast = { 0,0 };
    fastMinMax(vector_in, minmax_indexfast);

    std::cout << "Index Min FastMinMax: " << minmax_indexfast[0] << std::endl;
    std::cout << "Index Max FastMinMax: " << minmax_indexfast[1] << std::endl;



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
