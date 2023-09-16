#include <iostream>
#include <omp.h>

using namespace std;

int calcularFactorial(int n) {
    int factorial = 1;
    for (int i = 2; i <= n; ++i) {
        factorial *= i;
    }
    return factorial;
}

void calcularSumatoriaFactorialesParalela(int limiteInferior, int limiteSuperior, int numHilos, int &resultado1) {
    resultado1 = 0;

    #pragma omp parallel num_threads(numHilos) reduction(+:resultado1)
    {
        int tid = omp_get_thread_num();
        int num_threads = omp_get_num_threads();

        int tamanoSubrango = (limiteSuperior - limiteInferior + 1 + num_threads - 1) / num_threads;
        int inicio = limiteInferior + tid * tamanoSubrango;
        int fin = min(inicio + tamanoSubrango - 1, limiteSuperior);

        for (int i = inicio; i <= fin; ++i) {
            resultado1 += calcularFactorial(i);
        }
    }
}

void calcularSumatoriaPotenciasCuadradasParalela(int limiteInferior, int limiteSuperior, int numHilos, int &resultado2) {
    resultado2 = 0;

    #pragma omp parallel num_threads(numHilos) reduction(+:resultado2)
    {
        int tid = omp_get_thread_num();
        int num_threads = omp_get_num_threads();

        int tamanoSubrango = (limiteSuperior - limiteInferior + 1 + num_threads - 1) / num_threads;
        int inicio = limiteInferior + tid * tamanoSubrango;
        int fin = min(inicio + tamanoSubrango - 1, limiteSuperior);

        for (int i = inicio; i <= fin; ++i) {
            resultado2 += i * i; // Calcula la potencia cuadrada y la suma
        }
    }
}

// Funciones para calcular sumatorias adicionales
void calcularSumatoriaCubosParalela(int limiteInferior, int limiteSuperior, int numHilos, int &resultado3) {
    resultado3 = 0;

    #pragma omp parallel num_threads(numHilos) reduction(+:resultado3)
    {
        int tid = omp_get_thread_num();
        int num_threads = omp_get_num_threads();

        int tamanoSubrango = (limiteSuperior - limiteInferior + 1 + num_threads - 1) / num_threads;
        int inicio = limiteInferior + tid * tamanoSubrango;
        int fin = min(inicio + tamanoSubrango - 1, limiteSuperior);

        for (int i = inicio; i <= fin; ++i) {
            resultado3 += i * i * i; // Calcula el cubo y la suma
        }
    }
}

void calcularSumatoriaParesParalela(int limiteInferior, int limiteSuperior, int numHilos, int &resultado4) {
    resultado4 = 0;

    #pragma omp parallel num_threads(numHilos) reduction(+:resultado4)
    {
        int tid = omp_get_thread_num();
        int num_threads = omp_get_num_threads();

        int tamanoSubrango = (limiteSuperior - limiteInferior + 1 + num_threads - 1) / num_threads;
        int inicio = limiteInferior + tid * tamanoSubrango;
        int fin = min(inicio + tamanoSubrango - 1, limiteSuperior);

        for (int i = inicio; i <= fin; ++i) {
            if (i % 2 == 0) {
                resultado4 += i; // Suma números pares
            }
        }
    }
}

void calcularSumatoriaImparesParalela(int limiteInferior, int limiteSuperior, int numHilos, int &resultado) {
    resultado = 0;

    #pragma omp parallel num_threads(numHilos) reduction(+:resultado)
    {
        int tid = omp_get_thread_num();
        int num_threads = omp_get_num_threads();

        int tamanoSubrango = (limiteSuperior - limiteInferior + 1 + num_threads - 1) / num_threads;
        int inicio = limiteInferior + tid * tamanoSubrango;
        int fin = min(inicio + tamanoSubrango - 1, limiteSuperior);

        for (int i = inicio; i <= fin; ++i) {
            if (i % 2 != 0) {
                resultado += i; // Suma números impares
            }
        }
    }
}

// Agrega aquí más funciones para calcular sumatorias adicionales de manera similar

int main() {
    int limiteInferior, limiteSuperior, resultado1 = 0, resultado2 = 0, resultado3 = 0, resultado4 = 0, resultado5 = 0;
    int numHilos;
    cout << "----------------------------------------" << endl;
    cout << "Bienvenidos a las sumatorias" << endl;
    cout << "----------------------------------------" << endl;
    cout << "SUMATORIAS A CALCULAR: " << endl;
    cout << "1. Sumatoria de factoriales" << endl;
    cout << "2. Sumatoria de potencias cuadradas" << endl;
    cout << "3. Sumatoria de cubos" << endl;
    cout << "4. Sumatoria de números pares" << endl;
    // Agrega aquí más opciones para sumatorias adicionales

    cout << "Ingrese el límite inferior: " << endl;
    cin >> limiteInferior;

    cout << "Ingrese el límite superior: ";
    cin >> limiteSuperior;

    cout << "Ingrese el número de hilos: ";
    cin >> numHilos;

    calcularSumatoriaFactorialesParalela(limiteInferior, limiteSuperior, numHilos, resultado1);
    calcularSumatoriaPotenciasCuadradasParalela(limiteInferior, limiteSuperior, numHilos, resultado2);
    // Llama a las funciones para calcular sumatorias adicionales
    calcularSumatoriaCubosParalela(limiteInferior, limiteSuperior, numHilos, resultado3);
    calcularSumatoriaParesParalela(limiteInferior, limiteSuperior, numHilos, resultado4);
    // Agrega aquí más llamadas a funciones para sumatorias adicionales
    calcularSumatoriaImparesParalela(limiteInferior, limiteSuperior, numHilos, resultado5);

    cout << "La sumatoria de factoriales de " << limiteInferior << " a " << limiteSuperior << " es: " << resultado1 << endl;
    cout << "La sumatoria de potencias cuadradas de " << limiteInferior << " a " << limiteSuperior << " es: " << resultado2 << endl;
    cout << "La sumatoria de cubos de " << limiteInferior << " a " << limiteSuperior << " es: " << resultado3 << endl;
    cout << "La sumatoria de números pares de " << limiteInferior << " a " << limiteSuperior << " es: " << resultado4 << endl;
    cout << "La sumatoria de números impares de " << limiteInferior << " a " << limiteSuperior << " es: " << resultado5 << endl;
    // Agrega aquí más impresiones para sumatorias adicionales

    return 0;
}






