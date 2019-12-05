#include <iostream>
using namespace std;

bool validaNumero(int num) {
    string convertido = to_string(num);

    if (convertido[5] >= convertido[4] && convertido[4] >= convertido[3] &&
        convertido[3] >= convertido[2] && convertido[2] >= convertido[1] &&
        convertido[1] >= convertido[0]) {
        for (int num = 0; num <= 9; num++) {
            int contadorTeste = 0;
            for (int i = 0; i < 6; i++) {
                if (num == (convertido[i] - '0')) {
                    contadorTeste++;
                }
            }

            if (contadorTeste == 2) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    int resposta = 0;

    for (int i = 353096; i <= 843212; i++) {
        if (validaNumero(i)) {
            resposta++;
        }
    }

    cout << resposta;
}
