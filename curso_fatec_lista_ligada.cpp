
#include <iostream>
using namespace std;


int main() {
    No* lista = NULL;
    int ano;

    cout << "Digite o ano de inicio do curso (deve ser 2024): ";
    cin >> ano;

    
    if (ano != 2024) {   // Segundo Semestre de 2024
        cout << "Ano inválido. O curso só pode iniciar em 2024.\n";
        return 1;
    }

    // Loop para adicionar anos até 2027
    while (ano <= 2027) {
        adicionarAno(lista, ano);
        if (ano == 2027) {
            cout << "\n Ano final (2027) atingido. Encerrando...\n";
            break;
        }
        ano++;
    }

    // Imprimir os anos cadastrados
    imprimirLista(lista);

    // Liberar memória
    while (lista != nullptr) {
        No* temp = lista;
        lista = lista->proximo;
        delete temp;
    }

    return 0;
}
