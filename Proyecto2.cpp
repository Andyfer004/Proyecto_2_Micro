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

int calcularFibonacci(int n) {
    if (n <= 0) return 0;
    if (n == 1) return 1;

    int a = 0, b = 1, c;
    int suma = 1;

    for (int i = 2; i <= n; ++i) {
        c = a + b;
        a = b;
        b = c;
    }

    return b; // Devuelve el último número de Fibonacci en lugar de la suma acumulativa
}

void calcularSumatoriaFibonacciParalela(int limiteInferior, int limiteSuperior, int numHilos, int &resultado6) {
    resultado6 = 0;

    #pragma omp parallel num_threads(numHilos) reduction(+:resultado6)
    {
        int tid = omp_get_thread_num();
        int num_threads = omp_get_num_threads();

        int tamanoSubrango = (limiteSuperior - limiteInferior + 1 + num_threads - 1) / num_threads;
        int inicio = limiteInferior + tid * tamanoSubrango;
        int fin = min(inicio + tamanoSubrango - 1, limiteSuperior);

        for (int i = inicio; i <= fin; ++i) {
            resultado6 += calcularFibonacci(i);
        }
    }
}

bool esPrimo(int n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;

    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }

    return true;
}

void calcularSumatoriaPrimosParalela(int limiteInferior, int limiteSuperior, int numHilos, int &resultado7) {
    resultado7 = 0;

    #pragma omp parallel num_threads(numHilos) reduction(+:resultado7)
    {
        int tid = omp_get_thread_num();
        int num_threads = omp_get_num_threads();

        int tamanoSubrango = (limiteSuperior - limiteInferior + 1 + num_threads - 1) / num_threads;
        int inicio = limiteInferior + tid * tamanoSubrango;
        int fin = min(inicio + tamanoSubrango - 1, limiteSuperior);

        for (int i = inicio; i <= fin; ++i) {
            if (esPrimo(i)) {
                resultado7 += i; // Suma números primos
            }
        }
    }
}

// Función para calcular la suma de números pares al cuadrado en un rango
void calcularSumatoriaParesAlCuadradoParalela(int limiteInferior, int limiteSuperior, int numHilos, int &resultado8) {
    resultado8 = 0;

    #pragma omp parallel num_threads(numHilos) reduction(+:resultado8)
    {
        int tid = omp_get_thread_num();
        int num_threads = omp_get_num_threads();

        int tamanoSubrango = (limiteSuperior - limiteInferior + 1 + num_threads - 1) / num_threads;
        int inicio = limiteInferior + tid * tamanoSubrango;
        int fin = min(inicio + tamanoSubrango - 1, limiteSuperior);

        for (int i = inicio; i <= fin; ++i) {
            if (i % 2 == 0) {
                resultado8 += i * i; // Suma el cuadrado de números pares
            }
        }
    }
}

// Función para calcular la suma de números impares al cubo en un rango
void calcularSumatoriaImparesAlCuboParalela(int limiteInferior, int limiteSuperior, int numHilos, int &resultado9) {
    resultado9 = 0;

    #pragma omp parallel num_threads(numHilos) reduction(+:resultado9)
    {
        int tid = omp_get_thread_num();
        int num_threads = omp_get_num_threads();

        int tamanoSubrango = (limiteSuperior - limiteInferior + 1 + num_threads - 1) / num_threads;
        int inicio = limiteInferior + tid * tamanoSubrango;
        int fin = min(inicio + tamanoSubrango - 1, limiteSuperior);

        for (int i = inicio; i <= fin; ++i) {
            if (i % 2 != 0) {
                resultado9 += i * i * i; // Suma el cubo de números impares
            }
        }
    }
}

// Función para calcular la suma de números pares al cubo en un rango
void calcularSumatoriaParesAlCuboParalela(int limiteInferior, int limiteSuperior, int numHilos, int &resultado10) {
    resultado10 = 0;

    #pragma omp parallel num_threads(numHilos) reduction(+:resultado10)
    {
        int tid = omp_get_thread_num();
        int num_threads = omp_get_num_threads();

        int tamanoSubrango = (limiteSuperior - limiteInferior + 1 + num_threads - 1) / num_threads;
        int inicio = limiteInferior + tid * tamanoSubrango;
        int fin = min(inicio + tamanoSubrango - 1, limiteSuperior);

        for (int i = inicio; i <= fin; ++i) {
            if (i % 2 == 0) {
                resultado10 += i * i * i; // Suma el cubo de números pares
            }
        }
    }
}

// Función para calcular la suma de números primos al cuadrado en un rango
void calcularSumatoriaPrimosAlCuadradoParalela(int limiteInferior, int limiteSuperior, int numHilos, int &resultado11) {
    resultado11 = 0;

    #pragma omp parallel num_threads(numHilos) reduction(+:resultado11)
    {
        int tid = omp_get_thread_num();
        int num_threads = omp_get_num_threads();

        int tamanoSubrango = (limiteSuperior - limiteInferior + 1 + num_threads - 1) / num_threads;
        int inicio = limiteInferior + tid * tamanoSubrango;
        int fin = min(inicio + tamanoSubrango - 1, limiteSuperior);

        for (int i = inicio; i <= fin; ++i) {
            if (esPrimo(i)) {
                resultado11 += i * i; // Suma el cuadrado de números primos
            }
        }
    }
}
// Función para calcular la suma de una secuencia aritmética en un rango
void calcularSumatoriaSecuenciaAritmeticaParalela(int limiteInferior, int limiteSuperior, int numHilos, int &resultado12) {
    resultado12 = 0;

    #pragma omp parallel num_threads(numHilos) reduction(+:resultado12)
    {
        int tid = omp_get_thread_num();
        int num_threads = omp_get_num_threads();

        int tamanoSubrango = (limiteSuperior - limiteInferior + 1 + num_threads - 1) / num_threads;
        int inicio = limiteInferior + tid * tamanoSubrango;
        int fin = min(inicio + tamanoSubrango - 1, limiteSuperior);

      
        for (int i = inicio; i <= fin; ++i) {
            resultado12 += i; // Suma de la secuencia aritmética
        }
    }
}




int main() {
    int limiteInferior, limiteSuperior, resultado1 = 0, resultado2 = 0, resultado3 = 0, resultado4 = 0, resultado5 = 0, resultado6 = 0, resultado7 = 0, resultado8 = 0, resultado9 = 0, resultado10 = 0, resultado11 = 0, resultados12 = 0;
    int numHilos;
    cout << "----------------------------------------" << endl;
    cout << "Bienvenidos a las sumatorias" << endl;
    cout << "----------------------------------------" << endl;
    cout << "SUMATORIAS A CALCULAR: " << endl;
    cout << "1. Sumatoria de factoriales" << endl;
    cout << "2. Sumatoria de potencias cuadradas" << endl;
    cout << "3. Sumatoria de cubos" << endl;
    cout << "4. Sumatoria de números pares" << endl;
    cout << "5. Sumatoria de impares" << endl;
    cout << "6. Sumatoria de fibonacci" << endl;
    cout << "7. Sumatoria de números primos" << endl;
    cout << "8. Sumatoria de números pares al cuadrado" << endl;
    cout << "9. Sumatoria de números impares al cubo" << endl;
    cout << "10. Sumatoria de números pares al cubo" << endl;
    cout << "11. Sumatoria de números primos al cuadrado" << endl;
    cout << "12. Sumatoria de una secuencia aritmética" << endl;
    // Agrega aquí más opciones para sumatorias adicionales

    cout << "Ingrese el límite inferior: " << endl;
    cin >> limiteInferior;

    cout << "Ingrese el límite superior: ";
    cin >> limiteSuperior;

    cout << "Ingrese el número de hilos: ";
    cin >> numHilos;

    calcularSumatoriaFactorialesParalela(limiteInferior, limiteSuperior, numHilos, resultado1);
    calcularSumatoriaPotenciasCuadradasParalela(limiteInferior, limiteSuperior, numHilos, resultado2);
    calcularSumatoriaCubosParalela(limiteInferior, limiteSuperior, numHilos, resultado3);
    calcularSumatoriaParesParalela(limiteInferior, limiteSuperior, numHilos, resultado4);
    calcularSumatoriaImparesParalela(limiteInferior, limiteSuperior, numHilos, resultado5);
    calcularSumatoriaFibonacciParalela(limiteInferior, limiteSuperior, numHilos, resultado6);
    calcularSumatoriaPrimosParalela(limiteInferior, limiteSuperior, numHilos, resultado7);
    calcularSumatoriaParesAlCuadradoParalela(limiteInferior, limiteSuperior, numHilos, resultado8);
    calcularSumatoriaImparesAlCuboParalela(limiteInferior, limiteSuperior, numHilos, resultado9);
    calcularSumatoriaParesAlCuboParalela(limiteInferior, limiteSuperior, numHilos, resultado10);
    calcularSumatoriaPrimosAlCuadradoParalela(limiteInferior, limiteSuperior, numHilos, resultado11);
    calcularSumatoriaSecuenciaAritmeticaParalela(limiteInferior, limiteSuperior, numHilos, resultados12);

    cout << "La sumatoria de factoriales de " << limiteInferior << " a " << limiteSuperior << " es: " << resultado1 << endl;
    cout << "La sumatoria de potencias cuadradas de " << limiteInferior << " a " << limiteSuperior << " es: " << resultado2 << endl;
    cout << "La sumatoria de cubos de " << limiteInferior << " a " << limiteSuperior << " es: " << resultado3 << endl;
    cout << "La sumatoria de números pares de " << limiteInferior << " a " << limiteSuperior << " es: " << resultado4 << endl;
    cout << "La sumatoria de números impares de " << limiteInferior << " a " << limiteSuperior << " es: " << resultado5 << endl;
    cout << "La sumatoria de fibonacci de " << limiteInferior << " a " << limiteSuperior << " es: " << resultado6 << endl;
    cout << "La sumatoria de números primos de " << limiteInferior << " a " << limiteSuperior << " es: " << resultado7 << endl;
    cout << "La sumatoria de números pares al cuadrado de " << limiteInferior << " a " << limiteSuperior << " es: " << resultado8 << endl;
    cout << "La sumatoria de números impares al cubo de " << limiteInferior << " a " << limiteSuperior << " es: " << resultado9 << endl;
    cout << "La sumatoria de números pares al cubo de " << limiteInferior << " a " << limiteSuperior << " es: " << resultado10 << endl;
    cout << "La sumatoria de números primos al cuadrado de " << limiteInferior << " a " << limiteSuperior << " es: " << resultado11 << endl;
    cout << "La sumatoria de una secuencia aritmética de " << limiteInferior << " a " << limiteSuperior << " es: " << resultados12 << endl;

    return 0;
}






