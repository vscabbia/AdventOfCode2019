#include <fstream>
#include <iostream>
using namespace std;
#include <vector>

int resolver(int primeiro, int segundo, vector<int> x) {
    vector<int> lista = x;
    lista[1] = primeiro;
    lista[2] = segundo;
    int resultado = 0;

    for (int i = 0; lista[i] != 99;) {
        if (lista[i] == 1) {
            int soma = 0;
            soma = lista[lista[i + 1]] + lista[lista[i + 2]];
            lista[lista[i + 3]] = soma;
            i += 4;
        } else if (lista[i] == 2) {
            int mult = 0;
            mult = lista[lista[i + 1]] * lista[lista[i + 2]];
            lista[lista[i + 3]] = mult;
            i += 4;
        } else {
            i++;
        }
    }
    resultado = lista[0];

    return resultado;
}

int main() {
    ifstream file;
    string element;
    int elementConverted;
    vector<int> lista;
    int noun = 0;
    int verb = 0;

    file.open("base.txt");
    char divisor = ',';

    if (file.is_open()) {
        while (getline(file, element, divisor)) {
            elementConverted = stoi(element);
            lista.push_back(elementConverted);
        }
    } else {
        cout << "Error";
    }

    for (int noun = 0; noun <= 99; noun++) {
        for (int verb = 0; verb <= 99; verb++) {
            int resposta = 0;
            resposta = resolver(noun, verb, lista);
            if (resposta == 19690720) {
                cout << "noun: " << noun << endl << "verb: " << verb << endl;
                return 0;
            }
        }
    }
    // cout << resolver(12,2,lista);
}