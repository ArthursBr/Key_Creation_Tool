#include <iostream>
#include <string>
using namespace std;

void exibirOpcao(char &op);
string cifrar(string texto, int x);
string decifrar(string texto, int x);

int main() {
    char opcao;
    int chave;
    string textoPrimario, textoCifrado;

    exibirOpcao(opcao);
    while ((opcao == '1') || (opcao == '2')) {
        switch (opcao) {
            case '1': // Cifrar texto
                cout << "Informe o texto: ";
                cin.ignore(); // Limpa o buffer antes de pegar a string completa
                getline(cin, textoPrimario);
                
                cout << "Defina a chave: ";
                cin >> chave;

                textoCifrado = cifrar(textoPrimario, chave);
                cout << "Texto Cifrado: " << textoCifrado << endl;
                break;

            case '2': // Decifrar texto
                cout << "Informe o texto cifrado: ";
                cin.ignore();
                getline(cin, textoCifrado);

                cout << "Defina a chave: ";
                cin >> chave;

                textoPrimario = decifrar(textoCifrado, chave);
                cout << "Texto Decifrado: \n" << textoPrimario << endl;
                break;

            default:
                cout << "Opção inválida. Tente novamente\n";
        }
        cin.ignore();
        exibirOpcao(opcao);
    }

    return 0;
}

void exibirOpcao(char &op) {
    cout << "\n========= Cifra de Cesar =========\n"
         << " [1] Cifrar texto \n"
         << " [2] Decifrar texto \n"
         << "==================================\n"
         << " [x] Pressionar qualquer tecla p/ sair \n"
         << "==================================\n> ";
    cin >> op;
}
string cifrar(string texto, int x) {
    string resultado = "";
    
    for (char c : texto) {
        if (isupper(c)) {
            resultado += char((c - 'A' + x) % 26 + 'A');
        }
        else if (islower(c)) {
            resultado += char((c - 'a' + x) % 26 + 'a');
        }
        else {
            resultado += c;
        }
    }
    
    return resultado;
}
string decifrar(string texto, int x) {
    return cifrar(texto, 26 - x); // Reutiliza a função de cifrar invertendo a chave
}
