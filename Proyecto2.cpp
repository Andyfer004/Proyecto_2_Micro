/*--------------------------------------------------------
* UNIVERSIDAD DEL VALLE DE GUATEMALA
* FACULTAD DE INGENIERÍA
* DEPARTAMENTO DE CIENCIA DE LA COMPUTACIÓN
* CC3086 Programación de microprocesadores
* Proyecto 2: Temario 7 - Operaciones matemáticas extensas
* 
* Proyecto2.cpp
* Original: Using OpenMP
* Modificado por: 
* Andy Fuentes 22944
* Sergio Orellana 221122
* Rodrigo Mancilla 22611
* Brandon Reyes 22992
* Fecha: 16/09/2023
* Descripción: Cálculo de 12 sumatorias con sus respectivos límites y utilizar paralelismo para obtener el resultado de las
* mismas e imprimir en pantalla el aviso de que el cálculo ha terminado. Presentar un reporte del tiempo que se necesitó para obtener cada resultado.
* --------------------------------------------------------*/

// Se incluyen las librerías necesarias
#include <iostream>
#include <omp.h>
#include <chrono>
#include <string>
#include <time.h>
#include <cctype>

// Se utiliza el espacio de nombres std
using namespace std;

// Función para calcular el factorial de un número
long long calcularFactorial(long long n) {
    long long factorial = 1;
    for (long long i = 2; i <= n; ++i) {
        factorial *= i;
    }
    return factorial;
}

// *Primera sumatoria: Sumatoria de factoriales*
// Función para calcular la suma de factoriales en un rango determinado por el usuario
void calcularSumatoriaFactorialesParalela(long long limiteInferior, long long limiteSuperior, long long numHilos, long long &resultado1) {
    resultado1 = 0;

    // Se crea un bloque paralelo con el número de hilos especificado por el usuario
    #pragma omp parallel num_threads(numHilos) reduction(+:resultado1)
    {
        // Se obtiene el id del hilo y el número de hilos
        long long tid = omp_get_thread_num();
        long long num_threads = omp_get_num_threads();

        // Se calcula el tamaño del subrango de cada hilo, el subrango sirve para dividir el rango de la sumatoria en partes iguales
        long long tamanoSubrango = (limiteSuperior - limiteInferior + 1 + num_threads - 1) / num_threads;
        // Se calcula el inicio y el fin del subrango de cada hilo
        long long inicio = limiteInferior + tid * tamanoSubrango;
        long long fin = min(inicio + tamanoSubrango - 1, limiteSuperior);

        // Se calcula la sumatoria de factoriales en el subrango de cada hilo
        for (long long i = inicio; i <= fin; ++i) {
            long long factorial_i = calcularFactorial(i);
            // El critical section sirve para evitar que dos hilos modifiquen la variable resultado1 al mismo tiempo
            #pragma omp critical
            resultado1 += factorial_i;
        }
    }
}

// *Segunda sumatoria: Sumatoria de potencias cuadradas*
// Función para calcular la suma de potencias cuadradas en un rango determinado por el usuario
void calcularSumatoriaPotenciasCuadradasParalela(long long limiteInferior, long long limiteSuperior, long long numHilos, long long &resultado2) {
    resultado2 = 0;

    #pragma omp parallel num_threads(numHilos) reduction(+:resultado2)
    {
        long long tid = omp_get_thread_num();
        long long num_threads = omp_get_num_threads();

        long long tamanoSubrango = (limiteSuperior - limiteInferior + 1 + num_threads - 1) / num_threads;
        long long inicio = limiteInferior + tid * tamanoSubrango;
        long long fin = min(inicio + tamanoSubrango - 1, limiteSuperior);

        for (long long i = inicio; i <= fin; ++i) {
            resultado2 += i * i; // Calcula la potencia cuadrada y la suma
        }
    }
}

// *Tercera sumatoria: Sumatoria de cubos*
// Función para calcular la suma de cubos en un rango determinado por el usuario
void calcularSumatoriaCubosParalela(long long limiteInferior, long long limiteSuperior, long long numHilos, long long &resultado3) {
    resultado3 = 0;

    // Se crea un bloque paralelo con el número de hilos especificado por el usuario
    #pragma omp parallel num_threads(numHilos) reduction(+:resultado3)
    {
        // Se obtiene el id del hilo y el número de hilos
        long long tid = omp_get_thread_num();
        long long num_threads = omp_get_num_threads();

        // Se calcula el tamaño del subrango de cada hilo, el subrango sirve para dividir el rango de la sumatoria en partes iguales
        long long tamanoSubrango = (limiteSuperior - limiteInferior + 1 + num_threads - 1) / num_threads;
        // Se calcula el inicio y el fin del subrango de cada hilo
        long long inicio = limiteInferior + tid * tamanoSubrango;
        long long fin = min(inicio + tamanoSubrango - 1, limiteSuperior);

        // Se calcula la sumatoria de cubos en el subrango de cada hilo
        for (long long i = inicio; i <= fin; ++i) {
            resultado3 += i * i * i; // Calcula el cubo y la suma
        }
    }
}

// *Cuarta sumatoria: Sumatoria de números pares*
// Función para calcular la suma de números pares en un rango determinado por el usuario
void calcularSumatoriaParesParalela(long long limiteInferior, long long limiteSuperior, long long numHilos, long long &resultado4) {
    resultado4 = 0;

    // Se crea un bloque paralelo con el número de hilos especificado por el usuario
    #pragma omp parallel num_threads(numHilos) reduction(+:resultado4)
    {
        // Se obtiene el id del hilo y el número de hilos
        long long tid = omp_get_thread_num();
        long long num_threads = omp_get_num_threads();

        // Se calcula el tamaño del subrango de cada hilo, el subrango sirve para dividir el rango de la sumatoria en partes iguales
        long long tamanoSubrango = (limiteSuperior - limiteInferior + 1 + num_threads - 1) / num_threads;
        // Se calcula el inicio y el fin del subrango de cada hilo
        long long inicio = limiteInferior + tid * tamanoSubrango;
        long long fin = min(inicio + tamanoSubrango - 1, limiteSuperior);

        // Se calcula la sumatoria de números pares en el subrango de cada hilo
        for (long long i = inicio; i <= fin; ++i) {
            if (i % 2 == 0) {
                resultado4 += i; // Suma números pares
            }
        }
    }
}

// *Qulong longa sumatoria: Sumatoria de impares*
// Función para calcular la suma de números impares en un rango determinado por el usuario
void calcularSumatoriaImparesParalela(long long limiteInferior, long long limiteSuperior, long long numHilos, long long &resultado5) {
    resultado5 = 0;

    // Se crea un bloque paralelo con el número de hilos especificado por el usuario
    #pragma omp parallel num_threads(numHilos) reduction(+:resultado5)
    {
        // Se obtiene el id del hilo y el número de hilos
        long long tid = omp_get_thread_num();
        long long num_threads = omp_get_num_threads();

        // Se calcula el tamaño del subrango de cada hilo, el subrango sirve para dividir el rango de la sumatoria en partes iguales
        long long tamanoSubrango = (limiteSuperior - limiteInferior + 1 + num_threads - 1) / num_threads;
        // Se calcula el inicio y el fin del subrango de cada hilo
        long long inicio = limiteInferior + tid * tamanoSubrango;
        long long fin = min(inicio + tamanoSubrango - 1, limiteSuperior);

        // Se calcula la sumatoria de números impares en el subrango de cada hilo
        for (long long i = inicio; i <= fin; ++i) {
            if (i % 2 != 0) {
                resultado5 += i; // Suma números impares
            }
        }
    }
}

// Función para calcular la serie de Fibonacci
long long calcularFibonacci(long long n) {
    if (n <= 0) return 0;
    if (n == 1) return 1;

    long long a = 0, b = 1, c;
    long long suma = 1;

    for (long long i = 2; i <= n; ++i) {
        c = a + b;
        a = b;
        b = c;
    }

    return b; // Devuelve el último número de Fibonacci en lugar de la suma acumulativa
}

// *Sexta sumatoria: Sumatoria de fibonacci*
// Función para calcular la suma de fibonacci en un rango determinado por el usuario
void calcularSumatoriaFibonacciParalela(long long limiteInferior, long long limiteSuperior, long long numHilos, long long &resultado6) {
    resultado6 = 0;

    // Se crea un bloque paralelo con el número de hilos especificado por el usuario
    #pragma omp parallel num_threads(numHilos) reduction(+:resultado6)
    {
        // Se obtiene el id del hilo y el número de hilos
        long long tid = omp_get_thread_num();
        long long num_threads = omp_get_num_threads();

        // Se calcula el tamaño del subrango de cada hilo, el subrango sirve para dividir el rango de la sumatoria en partes iguales
        long long tamanoSubrango = (limiteSuperior - limiteInferior + 1 + num_threads - 1) / num_threads;
        // Se calcula el inicio y el fin del subrango de cada hilo
        long long inicio = limiteInferior + tid * tamanoSubrango;
        long long fin = min(inicio + tamanoSubrango - 1, limiteSuperior);

        // Se calcula la sumatoria de fibonacci en el subrango de cada hilo
        for (long long i = inicio; i <= fin; ++i) {
            resultado6 += calcularFibonacci(i);
        }
    }
}

// Función para determinar si un número es primo
bool esPrimo(long long n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;

    for (long long i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }

    return true;
}

// *Séptima sumatoria: Sumatoria de números primos*
// Función para calcular la suma de números primos en un rango determinado por el usuario
void calcularSumatoriaPrimosParalela(long long limiteInferior, long long limiteSuperior, long long numHilos, long long &resultado7) {
    resultado7 = 0;

    // Se crea un bloque paralelo con el número de hilos especificado por el usuario
    #pragma omp parallel num_threads(numHilos) reduction(+:resultado7)
    {
        // Se obtiene el id del hilo y el número de hilos
        long long tid = omp_get_thread_num();
        long long num_threads = omp_get_num_threads();

        // Se calcula el tamaño del subrango de cada hilo, el subrango sirve para dividir el rango de la sumatoria en partes iguales
        long long tamanoSubrango = (limiteSuperior - limiteInferior + 1 + num_threads - 1) / num_threads;
        // Se calcula el inicio y el fin del subrango de cada hilo
        long long inicio = limiteInferior + tid * tamanoSubrango;
        long long fin = min(inicio + tamanoSubrango - 1, limiteSuperior);

        // Se calcula la sumatoria de números primos en el subrango de cada hilo
        for (long long i = inicio; i <= fin; ++i) {
            if (esPrimo(i)) {
                resultado7 += i; // Suma números primos
            }
        }
    }
}

// *Octava sumatoria: Sumatoria de números pares al cuadrado*
// Función para calcular la suma de números pares al cuadrado en un rango determinado por el usuario
void calcularSumatoriaParesAlCuadradoParalela(long long limiteInferior, long long limiteSuperior, long long numHilos, long long &resultado8) {
    resultado8 = 0;

    // Se crea un bloque paralelo con el número de hilos especificado por el usuario
    #pragma omp parallel num_threads(numHilos) reduction(+:resultado8)
    {
        // Se obtiene el id del hilo y el número de hilos
        long long tid = omp_get_thread_num();
        long long num_threads = omp_get_num_threads();

        // Se calcula el tamaño del subrango de cada hilo, el subrango sirve para dividir el rango de la sumatoria en partes iguales
        long long tamanoSubrango = (limiteSuperior - limiteInferior + 1 + num_threads - 1) / num_threads;
        // Se calcula el inicio y el fin del subrango de cada hilo
        long long inicio = limiteInferior + tid * tamanoSubrango;
        long long fin = min(inicio + tamanoSubrango - 1, limiteSuperior);

        // Se calcula la sumatoria de números pares al cuadrado en el subrango de cada hilo
        for (long long i = inicio; i <= fin; ++i) {
            if (i % 2 == 0) {
                resultado8 += i * i; // Suma el cuadrado de números pares
            }
        }
    }
}

// *Novena sumatoria: Sumatoria de números impares al cubo*
// Función para calcular la suma de números impares al cubo en un rango determinado por el usuario
void calcularSumatoriaImparesAlCuboParalela(long long limiteInferior, long long limiteSuperior, long long numHilos, long long &resultado9) {
    resultado9 = 0;

    // Se crea un bloque paralelo con el número de hilos especificado por el usuario
    #pragma omp parallel num_threads(numHilos) reduction(+:resultado9)
    {
        // Se obtiene el id del hilo y el número de hilos
        long long tid = omp_get_thread_num();
        long long num_threads = omp_get_num_threads();

        // Se calcula el tamaño del subrango de cada hilo, el subrango sirve para dividir el rango de la sumatoria en partes iguales
        long long tamanoSubrango = (limiteSuperior - limiteInferior + 1 + num_threads - 1) / num_threads;
        // Se calcula el inicio y el fin del subrango de cada hilo
        long long inicio = limiteInferior + tid * tamanoSubrango;
        long long fin = min(inicio + tamanoSubrango - 1, limiteSuperior);
        
        // Se calcula la sumatoria de números impares al cubo en el subrango de cada hilo
        for (long long i = inicio; i <= fin; ++i) {
            if (i % 2 != 0) {
                resultado9 += i * i * i; // Suma el cubo de números impares
            }
        }
    }
}

// *Décima sumatoria: Sumatoria de números pares al cubo*
// Función para calcular la suma de números pares al cubo en un rango determinado por el usuario
void calcularSumatoriaParesAlCuboParalela(long long limiteInferior, long long limiteSuperior, long long numHilos, long long &resultado10) {
    resultado10 = 0;

    // Se crea un bloque paralelo con el número de hilos especificado por el usuario
    #pragma omp parallel num_threads(numHilos) reduction(+:resultado10)
    {
        // Se obtiene el id del hilo y el número de hilos
        long long tid = omp_get_thread_num();
        long long num_threads = omp_get_num_threads();

        // Se calcula el tamaño del subrango de cada hilo, el subrango sirve para dividir el rango de la sumatoria en partes iguales
        long long tamanoSubrango = (limiteSuperior - limiteInferior + 1 + num_threads - 1) / num_threads;
        // Se calcula el inicio y el fin del subrango de cada hilo
        long long inicio = limiteInferior + tid * tamanoSubrango;
        long long fin = min(inicio + tamanoSubrango - 1, limiteSuperior);

        // Se calcula la sumatoria de números pares al cubo en el subrango de cada hilo
        for (long long i = inicio; i <= fin; ++i) {
            if (i % 2 == 0) {
                resultado10 += i * i * i; // Suma el cubo de números pares
            }
        }
    }
}

// *Undécima sumatoria: Sumatoria de números primos al cuadrado*
// Función para calcular la suma de números primos al cuadrado en un rango determinado por el usuario
void calcularSumatoriaPrimosAlCuadradoParalela(long long limiteInferior, long long limiteSuperior, long long numHilos, long long &resultado11) {
    resultado11 = 0;

    // Se crea un bloque paralelo con el número de hilos especificado por el usuario
    #pragma omp parallel num_threads(numHilos) reduction(+:resultado11)
    {
        // Se obtiene el id del hilo y el número de hilos
        long long tid = omp_get_thread_num();
        long long num_threads = omp_get_num_threads();

        // Se calcula el tamaño del subrango de cada hilo, el subrango sirve para dividir el rango de la sumatoria en partes iguales
        long long tamanoSubrango = (limiteSuperior - limiteInferior + 1 + num_threads - 1) / num_threads;
        // Se calcula el inicio y el fin del subrango de cada hilo
        long long inicio = limiteInferior + tid * tamanoSubrango;
        long long fin = min(inicio + tamanoSubrango - 1, limiteSuperior);

        // Se calcula la sumatoria de números primos al cuadrado en el subrango de cada hilo
        for (long long i = inicio; i <= fin; ++i) {
            if (esPrimo(i)) {
                resultado11 += i * i; // Suma el cuadrado de números primos
            }
        }
    }
}

// *Duodécima sumatoria: Sumatoria de una secuencia aritmética*
// Función para calcular la suma de una secuencia aritmética en un rango determinado por el usuario
void calcularSumatoriaSecuenciaAritmeticaParalela(long long limiteInferior, long long limiteSuperior, long long numHilos, long long &resultado12) {
    resultado12 = 0;

    // Se crea un bloque paralelo con el número de hilos especificado por el usuario
    #pragma omp parallel num_threads(numHilos) reduction(+:resultado12)
    {
        // Se obtiene el id del hilo y el número de hilos
        long long tid = omp_get_thread_num();
        long long num_threads = omp_get_num_threads();

        // Se calcula el tamaño del subrango de cada hilo, el subrango sirve para dividir el rango de la secuencia en partes iguales
        long long tamanoSubrango = (limiteSuperior - limiteInferior + 1 + num_threads - 1) / num_threads;
        // Se calcula el inicio y el fin del subrango de cada hilo
        long long inicio = limiteInferior + tid * tamanoSubrango;
        long long fin = min(inicio + tamanoSubrango - 1, limiteSuperior);

        // Se calcula la sumatoria de una secuencia aritmética en el subrango de cada hilo
        for (long long i = inicio; i <= fin; ++i) {
            resultado12 += i; // Suma de la secuencia aritmética
        }
    }
}

// Función para verificar que la entrada sea un número entero
int obtenerNumeroEntero() {
    int numero;
    bool entradaValida = false;
    do {
        // Obtiene la entrada del usuario
        string entrada;
        cin >> entrada;
        entradaValida = true;
        // Verifica que cada caracter de la entrada sea un dígito
        for (char c : entrada) {
            // Si no es un dígito, se marca la entrada como inválida y se muestra un mensaje de error
            if (!isdigit(c)) {
                entradaValida = false;
                cout << "Entrada no válida. Ingrese un número entero: ";
                break;
            }
        }
        // Si la entrada es válida, se convierte a un int
        if (entradaValida) {
            //stoi convierte un string a un int
            numero = stoi(entrada);
        }
        // Se repite el ciclo hasta que la entrada sea válida
    } while (!entradaValida);
    
    return numero;
}


// Funciones para encontrar el menor y el mayor de los resultados
long long encontrarMenor(long long a, long long b) {
    // Si a es menor que b, devuelve a, de lo contrario devuelve b
    return (a < b) ? a : b;
}

long long encontrarMayor(long long a, long long b) {
    // Si a es mayor que b, devuelve a, de lo contrario devuelve b
    return (a > b) ? a : b;
}

// Función principal
int main() {
    // Se declaran las variables necesarias
    long long limiteInferior, limiteSuperior, resultado1 = 0, resultado2 = 0, resultado3 = 0, resultado4 = 0, resultado5 = 0, resultado6 = 0, resultado7 = 0, resultado8 = 0, resultado9 = 0, resultado10 = 0, resultado11 = 0, resultados12 = 0;
    long long numHilos;

    // Se imprimen los mensajes de bienvenida y las sumatorias a calcular
    cout << endl;
    cout << "----------------------------------------" << endl;
    cout << "Bienvenidos a las Operaciones matemáticas extensas." << endl;
    cout << "----------------------------------------" << endl;
    cout << endl;
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
    cout << endl;

    // Se piden los límites superior e inferior de las sumatorias

    cout << "Ingrese el límite inferior: " << endl;
    limiteInferior = obtenerNumeroEntero();
    cout << endl;

    cout << "Ingrese el límite superior: " << endl;
    limiteSuperior = obtenerNumeroEntero();
    cout << endl;

    // Se pide el número de hilos
    cout << "Ingrese el número de hilos: ";
    numHilos = obtenerNumeroEntero();
    cout << endl;

    // Se calcula el tiempo de ejecución de cada sumatoria

    auto start_time_factoriales = chrono::high_resolution_clock::now();
    calcularSumatoriaFactorialesParalela(limiteInferior, limiteSuperior, numHilos, resultado1);
    auto end_time_factoriales = chrono::high_resolution_clock::now();

    auto start_time_potencias_cuadradas = chrono::high_resolution_clock::now();
    calcularSumatoriaPotenciasCuadradasParalela(limiteInferior, limiteSuperior, numHilos, resultado2);
    auto end_time_potencias_cuadradas = chrono::high_resolution_clock::now();


    auto start_time_cubos = chrono::high_resolution_clock::now();
    calcularSumatoriaCubosParalela(limiteInferior, limiteSuperior, numHilos, resultado3);
    auto end_time_cubos = chrono::high_resolution_clock::now();

    auto start_time_pares = chrono::high_resolution_clock::now();
    calcularSumatoriaParesParalela(limiteInferior, limiteSuperior, numHilos, resultado4);
    auto end_time_pares = chrono::high_resolution_clock::now();

    auto start_time_impares = chrono::high_resolution_clock::now();
    calcularSumatoriaImparesParalela(limiteInferior, limiteSuperior, numHilos, resultado5);
    auto end_time_impares = chrono::high_resolution_clock::now();

    auto start_time_fibonacci = chrono::high_resolution_clock::now();
    calcularSumatoriaFibonacciParalela(limiteInferior, limiteSuperior, numHilos, resultado6);
    auto end_time_fibonacci = chrono::high_resolution_clock::now();

    auto start_time_primos = chrono::high_resolution_clock::now();
    calcularSumatoriaPrimosParalela(limiteInferior, limiteSuperior, numHilos, resultado7);
    auto end_time_primos = chrono::high_resolution_clock::now();
    
    auto start_time_pares_cuadrado = chrono::high_resolution_clock::now();
    calcularSumatoriaParesAlCuadradoParalela(limiteInferior, limiteSuperior, numHilos, resultado8);
    auto end_time_pares_cuadrado = chrono::high_resolution_clock::now();

    auto start_time_impares_cubo = chrono::high_resolution_clock::now();
    calcularSumatoriaImparesAlCuboParalela(limiteInferior, limiteSuperior, numHilos, resultado9);
    auto end_time_impares_cubo = chrono::high_resolution_clock::now();

    auto start_time_pares_cubo = chrono::high_resolution_clock::now();
    calcularSumatoriaParesAlCuboParalela(limiteInferior, limiteSuperior, numHilos, resultado10);
    auto end_time_pares_cubo = chrono::high_resolution_clock::now();

    auto start_time_primos_cuadrado = chrono::high_resolution_clock::now();
    calcularSumatoriaPrimosAlCuadradoParalela(limiteInferior, limiteSuperior, numHilos, resultado11);
    auto end_time_primos_cuadrado = chrono::high_resolution_clock::now();

    auto start_time_secuencia_aritmetica = chrono::high_resolution_clock::now();
    calcularSumatoriaSecuenciaAritmeticaParalela(limiteInferior, limiteSuperior, numHilos, resultados12);
    auto end_time_secuencia_aritmetica = chrono::high_resolution_clock::now();

    // Se espera a que todos los hilos terminen de calcular sus sumatorias
    #pragma omp barrier

   // Se calcula el tiempo de ejecución de cada sumatoria
    double elapsed_time_factoriales = chrono::duration_cast<chrono::nanoseconds>(end_time_factoriales - start_time_factoriales).count();
    double duration_potencias_cuadradas = chrono::duration_cast<chrono::nanoseconds>(end_time_potencias_cuadradas - start_time_potencias_cuadradas).count();
    double duration_cubos = chrono::duration_cast<chrono::nanoseconds>(end_time_cubos - start_time_cubos).count();
    double duration_pares = chrono::duration_cast<chrono::nanoseconds>(end_time_pares - start_time_pares).count();
    double duration_impares = chrono::duration_cast<chrono::nanoseconds>(end_time_impares - start_time_impares).count();
    double duration_fibonacci = chrono::duration_cast<chrono::nanoseconds>(end_time_fibonacci - start_time_fibonacci).count();
    double duration_primos = chrono::duration_cast<chrono::nanoseconds> (end_time_primos - start_time_primos).count();
    double duration_pares_cuadrado =chrono::duration_cast<chrono::nanoseconds> (end_time_pares_cuadrado - start_time_pares_cuadrado).count();
    double duration_impares_cubo =chrono::duration_cast<chrono::nanoseconds> (end_time_impares_cubo - start_time_impares_cubo).count();
    double duration_pares_cubo = chrono::duration_cast<chrono::nanoseconds>(end_time_pares_cubo - start_time_pares_cubo).count();
    double duration_primos_cuadrado = chrono::duration_cast<chrono::nanoseconds>(end_time_primos_cuadrado - start_time_primos_cuadrado).count();
    double duration_secuencia_aritmetica =chrono::duration_cast<chrono::nanoseconds> (end_time_secuencia_aritmetica - start_time_secuencia_aritmetica).count();

    // Se espera a que todos los hilos terminen de calcular sus sumatorias
    #pragma omp barrier

    // Se imprimen los avisos o mensajes de todos los calculos terminados

    cout << "La sumatoria de factoriales de " << limiteInferior << " a " << limiteSuperior << " es: " << resultado1 << endl;
    cout << "Tiempo de cálculo de factoriales: " << elapsed_time_factoriales << "nanosegundos" << endl;
    cout << endl;
    cout << "La sumatoria de potencias cuadradas de " << limiteInferior << " a " << limiteSuperior << " es: " << resultado2 << endl;
    cout << "Tiempo de cálculo de potencias cuadradas: " << duration_potencias_cuadradas << " nanosegundos" << endl;
    cout << endl;
    cout << "La sumatoria de cubos de " << limiteInferior << " a " << limiteSuperior << " es: " << resultado3 << endl;
    cout << "Tiempo de cálculo de cubos: " << duration_cubos << " nanosegundos" << endl;
    cout << endl;
    cout << "La sumatoria de números pares de " << limiteInferior << " a " << limiteSuperior << " es: " << resultado4 << endl;
    cout << "Tiempo de cálculo de números pares: " << duration_pares << " nanosegundos" << endl;
    cout << endl;
    cout << "La sumatoria de números impares de " << limiteInferior << " a " << limiteSuperior << " es: " << resultado5 << endl;
    cout << "Tiempo de cálculo de números impares: " << duration_impares << " nanosegundos" << endl;
    cout << endl;
    cout << "La sumatoria de fibonacci de " << limiteInferior << " a " << limiteSuperior << " es: " << resultado6 << endl;
    cout << "Tiempo de cálculo de fibonacci: " << duration_fibonacci << " microsegundos" << endl;
    cout << endl;
    cout << "La sumatoria de números primos de " << limiteInferior << " a " << limiteSuperior << " es: " << resultado7 << endl;
    cout << "Tiempo de cálculo de números primos: " << duration_primos << " nanosegundos" << endl;
    cout << endl;
    cout << "La sumatoria de números pares al cuadrado de " << limiteInferior << " a " << limiteSuperior << " es: " << resultado8 << endl;
    cout << "Tiempo de cálculo de números pares al cuadrado: " << duration_pares_cuadrado << " nanosegundos" << endl;
    cout << endl;
    cout << "La sumatoria de números impares al cubo de " << limiteInferior << " a " << limiteSuperior << " es: " << resultado9 << endl;
    cout << "Tiempo de cálculo de números impares al cubo: " << duration_impares_cubo << " nanosegundos" << endl;
    cout << endl;
    cout << "La sumatoria de números pares al cubo de " << limiteInferior << " a " << limiteSuperior << " es: " << resultado10 << endl;
    cout << "Tiempo de cálculo de números pares al cubo: " << duration_pares_cubo << " nanosegundos" << endl;
    cout << endl;
    cout << "La sumatoria de números primos al cuadrado de " << limiteInferior << " a " << limiteSuperior << " es: " << resultado11 << endl;
    cout << "Tiempo de cálculo de números primos al cuadrado: " << duration_primos_cuadrado << " nanosegundos" << endl;
    cout << endl;
    cout << "La sumatoria de una secuencia aritmética de " << limiteInferior << " a " << limiteSuperior << " es: " << resultados12 << endl;
    cout << "Tiempo de cálculo de una secuencia aritmética: " << duration_secuencia_aritmetica << " nanosegundos" << endl;
    cout << endl;
    long long sumaResultados = resultado1 + resultado2 + resultado3 + resultado4 + resultado5 +
                          resultado6 + resultado7 + resultado8 + resultado9 + resultado10 +
                          resultado11 + resultados12;

    // Calcular el promedio
    double promedio = static_cast<double>(sumaResultados) / 12.0;

    // Imprimir el promedio
    cout << "El promedio de las sumatorias es: " << promedio << endl;


    // Se calcula el mayor de las sumatorias
    long long mayor = resultado1;

    mayor = encontrarMayor(mayor, resultado2);
    mayor = encontrarMayor(mayor, resultado3);
    mayor = encontrarMayor(mayor, resultado4);
    mayor = encontrarMayor(mayor, resultado5);
    mayor = encontrarMayor(mayor, resultado6);
    mayor = encontrarMayor(mayor, resultado7);
    mayor = encontrarMayor(mayor, resultado8);
    mayor = encontrarMayor(mayor, resultado9);
    mayor = encontrarMayor(mayor, resultado10);
    mayor = encontrarMayor(mayor, resultado11);
    mayor = encontrarMayor(mayor, resultados12);

    // Se imprime el mayor de las sumatorias
    cout <<endl;
    cout << "El mayor de los resultados es: " << mayor << endl;
    cout << endl;

    // Se calcula el menor de las sumatorias
    long long menor = resultado1;

    menor = encontrarMenor(menor, resultado2);
    menor = encontrarMenor(menor, resultado3);
    menor = encontrarMenor(menor, resultado4);
    menor = encontrarMenor(menor, resultado5);
    menor = encontrarMenor(menor, resultado6);
    menor = encontrarMenor(menor, resultado7);
    menor = encontrarMenor(menor, resultado8);
    menor = encontrarMenor(menor, resultado9);
    menor = encontrarMenor(menor, resultado10);
    menor = encontrarMenor(menor, resultado11);
    menor = encontrarMenor(menor, resultados12);

    // Se imprime el menor de las sumatorias
    cout << "El menor de los resultados es: " << menor << endl;
    return 0;
}