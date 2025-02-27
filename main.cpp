#include <iostream>
#include <string>
using namespace std;

int main()
{
    string textoPrimario, textoCifrado = "";
    cout << "Informe o texto: " << endl;
    getline(cin, textoPrimario);

    int chave;
    cout << "Defina a chave: " << endl;
    cin >> chave;

    for(char c : textoPrimario)
    {
        if(isupper(c)){
            textoCifrado += char(int(c + chave - 'A')  % 26 + 'A');
        }
        else if (islower(c)) 
        {
            textoCifrado += char(int(c + chave - 'a') % 26 + 'a');
        }
        else 
        {
            textoCifrado += c;
        }
    }
    cout << "Texto Cifrado: \n" << textoCifrado << endl;

    return 0;
}
