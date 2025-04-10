#include <iostream>
using namespace std;

struct No {
    int ano;
    No* proximo;
};

void adicionarAno(No*& inicio, int ano) {
    No* novo = new No{ano, nullptr};
    if (!inicio) inicio = novo;
    else {
        No* atual = inicio;
        while (atual->proximo) atual = atual->proximo;
        atual->proximo = novo;
    }
}

void imprimirLista(No* no) {
    cout << "\nAnos cadastrados:\n";
    while (no) {
        cout << no->ano << endl;
        no = no->proximo;
    }
}

void liberarLista(No* no) {
    while (no) {
        No* temp = no;
        no = no->proximo;
        delete temp;
    }
}

int main() {
    No* lista = nullptr;
    int ano;
    
    cout << "Digite o ano de inicio da sua turma de SI: ";
    cin >> ano;

    if (ano != 2024) {
        cout << "Ano inválido. O curso só pode iniciar em 2024.\n";
        return 1;
    }

    while (ano <= 2027) adicionarAno(lista, ano++);

    imprimirLista(lista);
    liberarLista(lista);
}
