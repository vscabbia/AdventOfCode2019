#include <iostream>
using namespace std;
#include <math.h>
#include <cstdlib>
#include <fstream>

float calculaMassaIndividual(string massa) {
    float temp;
    float massaConvertida = 0;
    massaConvertida = stof(massa);
    temp = massaConvertida / 3;
    temp = floor(temp);
    temp = temp - 2;

    return temp;
}

int main() {
    string linha;
    float total = 0;
    ifstream file;
    file.open("base.txt");

    if (file.is_open()) {
        while (getline(file, linha)) {
            total += calculaMassaIndividual(linha);
        }

    } else {
        cout << "Não abriu";
    }

    printf("%.0f", total);

    return 0;
}

/* resolução completa com int

int calculaMassaIndividual(int massa){
    int temp;
    temp = massa/3;
    temp = floor(temp);
    temp = temp - 2;

    return temp;
}

int main()
{
  string linha;
  int total = 0;
  ifstream file;
  file.open("base.txt");
  



  if(file.is_open()){
      



    while (getline(file, linha)){
      int temp = stoi(linha);
      int somaModulo = 0;
      do{
        temp = calculaMassaIndividual(temp);
        if(temp > 0){
          somaModulo += temp;
        }
      }while(temp > 0);

      total += somaModulo;
    }
      



  }else{
    cout << "Não abriu";
  }

  cout << total;

  return 0;
}
*/