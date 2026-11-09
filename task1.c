#include <stdio.h>
#include <windows.h>

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    double a;
    int N;

    printf("=== Завдання №1: Обчислення суми ряду ===\n");

    do {
        printf("Введіть значення a (a >= 0): ");
        if (scanf("%lf", &a) != 1 || a < 0) {
            printf("Помилка! Значення 'a' має бути числом >= 0.\n");
            while (getchar() != '\n');
        } else {
            break;
        }
    } while (1);

    do {
        printf("Введіть ціле значення N (N >= 1): ");
        if (scanf("%d", &N) != 1 || N < 1) {
            printf("Помилка! Значення 'N' має бути цілим числом >= 1.\n");
            while (getchar() != '\n');
        } else {
            break;
        }
    } while (1);

    double S = 1.0;
    double current_a_pow = 1.0;
    int sign = 1;

    for (int n = 1; n <= N; n++) {
        current_a_pow *= a;
        double term = sign * (current_a_pow / (a + n));
        S += term;
        sign = -sign;
    }

    printf("\nРезультат обчислення суми S = %.6lf\n", S);

    return 0;
}
