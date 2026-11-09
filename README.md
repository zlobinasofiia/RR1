РОЗРАХУНКОВА РОБОТА

Завдання №1

<img width="715" height="242" alt="Знімок екрана 2026-11-09 175051" src="https://github.com/user-attachments/assets/021374c0-24cb-45fc-a32c-227090e2ddab" />

У цій частині програми оголошуємо змінні для збереження введених значень ``a ``, ``N`` та результату обчислення суми ``S``. Початкове значення суми дорівнює 1.0 відповідно до формули із завдання. Змінну power використовуємо для обчислення степеня ``$a^n$м`` без функції ``pow()``, а ``sign`` — для зміни знака доданків. 
  ````
  int N;
  double a, S = 1.0;
  double power = 1.0;
  int sign = 1;
  ```` 
Далі просимо користувача ввести значення ``a`` та ``N``. Також перевіряємо, чи є вводені значення допустимими за умовою ``(a >= 0, N >= 1)``. 
  ````
  printf("Введіть a (a >= 0): ");
  if (scanf("%lf", &a) != 1 || a < 0) {
    printf("Некоректне значення a!\n");
    return 1;
  }

  printf("Введіть N (N >= 1): ");
  if (scanf("%d", &N) != 1 || N < 1) {
    printf("Некоректне значення N!\n");
    return 1;
  }
  ````
Виконуємо цикл від ``$n = 1$ до $N$`` для накопичення суми ряду. На кожному кроці множимо ``power`` на ``a``, обчислюємо доданок ``term`` та додаємо його до ``S`` з урахуванням знака ``sign``.
  ````
  for (int n = 1; n <= N; n++) {
      power *= a; // a^n
      double term = sign * (power / (a + n));
      S += term;
      sign = -sign; // Зміна знака для наступного члена
  }

  printf("\nРезультат суми S = %.6lf\n", S);
  ````
Результат виконанної роботи

<img width="598" height="182" alt="Знімок екрана 2026-11-09 183218" src="https://github.com/user-attachments/assets/d2ac1223-200d-4fa8-b1f6-a96911d65d6f" />

Завдання №2

<img width="697" height="252" alt="Знімок екрана 2026-11-09 175128" src="https://github.com/user-attachments/assets/bfd4f4d3-96ad-4c65-8e2f-00f1ad4d24b2" />

Спочатку оголошуємо окрему функцію ``sortColumns`` для обробки матриці. Вона приймає початкову матрицю ``A`` копіює її елементи в ``B`` (щоб ``A`` залишилася без змін) та сортує стовпці матриці ``B`` методом бульбашки.
  ````
  void sortColumns(double A[MAX_N][MAX_N], double B[MAX_N][MAX_N], int N) {
    // Копіюємо A в B
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            B[i][j] = A[i][j];
        }
    }

    // Сортуємо кожен стовпець j за зростанням
    for (int j = 0; j < N; j++) {
        for (int step = 0; step < N - 1; step++) {
            for (int i = 0; i < N - 1 - step; i++) {
                if (B[i][j] > B[i + 1][j]) {
                    double temp = B[i][j];
                    B[i][j] = B[i + 1][j];
                    B[i + 1][j] = temp;
                }
            }
        }
    }
  }
  ````
Для красивого та зручного виведення матриць ``A`` та ``B`` на екран створимо окрему допоміжну функцію ``printMatrix``.
  ````
  void printMatrix(const char *name, double matrix[MAX_N][MAX_N], int N) {
    printf("\nМатриця %s (%dx%d):\n", name, N, N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%8.2lf ", matrix[i][j]);
        }
        printf("\n");
    }
  }
  ````
У головній функції main зчитуємо розмірність ``$N$``, заповнюємо матрицю ``$A$`` з клавіатури, викликаємо функцію сортування та виводимо обидві матриці.
  ````
  int N;
  double A[MAX_N][MAX_N], B[MAX_N][MAX_N];

  printf("Введіть розмірність N: ");
  scanf("%d", &N);

  // Зчитування елементів
  for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
          printf("A[%d][%d] = ", i, j);
          scanf("%lf", &A[i][j]);
      }
  }

  sortColumns(A, B, N);
  printMatrix("A", A, N);
  printMatrix("B", B, N);
  ````
Результат виконаної роботи

<img width="607" height="298" alt="Знімок екрана 2026-11-09 183447" src="https://github.com/user-attachments/assets/4d413469-1175-4bef-8613-e54bbd47fec9" />
