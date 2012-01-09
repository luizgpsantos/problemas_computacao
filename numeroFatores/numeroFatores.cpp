#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

class NumeroFatores {

    private:
    vector<int> primos;

    // Calcula os números primos menores que a raiz
    // do maior número que será fatorado.
    vector<int> crivoEratosthenes(int maiorNumero) {
        vector<int> listaPrimos;
        vector<bool> ehComposto(maiorNumero + 1);
        int raizMaiorNumero = (int)sqrt((double)maiorNumero);
        for (int i = 2; i <= raizMaiorNumero; i++) {
            if (!ehComposto[i]) {
                listaPrimos.push_back(i);
                    for (int j = i * i; j <= maiorNumero; j += i)
                        ehComposto[j] = true;
            }
        }
        for (int i = raizMaiorNumero + 1; i <= maiorNumero; i++) {
            if (!ehComposto[i]) {
                listaPrimos.push_back(i);
            }
        }
        
        return listaPrimos;
    } 

    public:
    NumeroFatores() {
        primos = crivoEratosthenes(1000000);
    }
    
    // Calcula a quantidade de fatores primos distintos
    // de um determinado número.
    int numeroFatores(int numero) {
        vector<int> resultado;
        vector<bool> aux(numero/2 + 1);

        int contador = 0;

        int k = 0;
        int divisor;
        int quociente;
        int resto;

        while(numero > 1) {
            divisor = primos[k];
            quociente = floor(numero / divisor);
            resto = numero % divisor;
                
            if(resto == 0) {
                if(!aux[divisor]){
                    resultado.push_back(divisor);
                    contador++;
                    aux[divisor] = true;
                }
                numero = quociente;
            } else {
                if(quociente > divisor) {
                    k++;
                } else {
                    if(!aux[numero]){
                        resultado.push_back(numero);
                        contador++;
                        aux[numero] = true;
                    } 
                    break;
                }
            }
        }
        return contador;
    }
};

// Calcula a quantidade de fatores primos para os números
// digitados na entrada padão até que se digite 0.
int main() {
    NumeroFatores n;
    int a;
    scanf ("%d", &a);
    while (a != 0){
        cout << a << " : " << n.numeroFatores(a) << endl;
        scanf ("%d", &a);
    }
    return 0;
}
