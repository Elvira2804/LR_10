#include <stdio.h>
#include <locale.h>
#include <math.h>

double f1(double x);
double f2(double x);

double sin_n(double x, int N);
double sin_eps(double x, double eps);

double sin_n_2(double x2, int n2);
double sin_eps_2(double x2, double eps2);

double area_figure(int H, int L1, int L2);
char z_3(int r, int c, int H, int L1, int L2, char sym);

int main() {

    setlocale(LC_ALL, "ru_RU.UTF-8");

    //Задание 1

    printf("Задание 1\n\n");

    double x;
    int choice;

    printf("Введите значение x: ");
    if (scanf("%lf", &x) != 1) {
        printf("Ошибка ввода!\n");
        return 1;
    }

    printf("\nМЕНЮ\n");
    printf("1) Вычислить f1(x)\n");
    printf("2) Вычислить f2(x)\n");
    printf("3) Вычислить произведение f1(x) * f2(x)\n");
    printf("4) Вычислить разность квадратов f1(x)^2 - f2(x)^2\n");
    printf("5) Вычислить удвоенную сумму 2 * (f1(x) + f2(x))\n");
    printf("6) Выполнить все расчеты вместе\n");

    printf("\nВыберите пункт меню (1-6): ");

    if (scanf("%d", &choice) != 1) {
        printf("Ошибка ввода пункта меню!\n");
        return 1;
    }

    printf("\n");

    double f1_value = f1(x);
    double f2_value = f2(x);

    switch (choice) {
    case 1:
        printf("f1(x) = %lf\n", f1_value);
        break;

    case 2:
        printf("f2(x) = %lf\n", f2_value);
        break;

    case 3:
        printf("Произведение f1(x) * f2(x) = %lf\n", f1_value * f2_value);
        break;

    case 4:
        printf("Разность квадратов f1(x)^2 - f2(x)^2 = %lf\n",
            f1_value * f1_value - f2_value * f2_value);
        break;

    case 5:
        printf("Удвоенная сумма 2 * (f1(x) + f2(x)) = %lf\n",
            2 * (f1_value + f2_value));
        break;

    case 6:
        printf("f1(x) = %lf\n", f1_value);
        printf("f2(x) = %lf\n", f2_value);
        printf("Произведение f1(x) * f2(x) = %lf\n", f1_value * f2_value);
        printf("Разность квадратов f1(x)^2 - f2(x)^2 = %lf\n", f1_value * f1_value - f2_value * f2_value);
        printf("Удвоенная сумма 2 * (f1(x) + f2(x)) = %lf\n", 2 * (f1_value + f2_value));
        break;

    default:
        printf("Неверный пункт меню!\n");
        break;
    }

    //Задание 2

    printf("\nЗадание 2\n");
    double x_sin, eps;

    //Ввод данных пользователем
    printf("Введите значение x (в радианах, например 0,79): ");
    if (scanf("%lf", &x_sin) != 1) {
        printf("Ошибка ввода x!\n");
        return 1;
    }

    printf("Введите точность eps (например, 1e-6): ");
    if (scanf(" %lf", &eps) != 1) {
        printf("Ошибка ввода eps!\n");
        return 1;
    }

    //Проверка точности eps > 0 перед вычислениями
    if (eps <= 0) {
        printf("Ошибка: точность eps должна быть строго больше 0!\n");
    }
    else {
        //Способ 1: Эталонное значение из стандартной библиотеки math.h 
        printf("СПОСОБ 1\n\n");
        double std_sin = sin(x_sin);
        printf("\nЭталонное значение sin(%.4lf) = %lf\n", x_sin, std_sin);

        //Способ 2: Отклонение от эталона
        printf("\nСПОСОБ 2\n\n");
        printf("\n%3s | %8s | %s\n", "N", "sin_N", "отклонение");
        printf("-----------------------------\n");

        for (int n = 1; n <= 20; n++) {
            double current_sin = sin_n(x_sin, n);
            double diff = current_sin - std_sin;
            printf("%3d | %8.4lf | %+e\n", n, current_sin, diff);
        }

        //Способ 3: Вычисление с заданной пользователем точностью eps
        printf("\nСПОСОБ 3\n\n");
        double eps_sin = sin_eps(x_sin, eps);
        printf("\nЗначение через sin_eps с точностью %e = %lf\n", eps, eps_sin);
    }

    //Задание 2.1

    printf("\nЗадание 2.1\n");

    double val_x;
    double val_eps;

    printf("Введите значение x (в радианах, например 0,79): ");
    if (scanf("%lf", &val_x) != 1) {
        printf("Ошибка ввода x!\n");
        return 1;
    }

    printf("Введите точность eps (например, 1e-6): ");
    if (scanf(" %lf", &val_eps) != 1) {
        printf("Ошибка ввода eps!\n");
        return 1;
    }

    //Проверка точности val_eps > 0 перед вычислениями
    if (val_eps <= 0) {
        printf("Ошибка: точность val_eps должна быть строго больше 0!\n");
    }
    else {
        double res_math = sin(val_x);

        printf("\nСПОСОБ 1\n");
        printf("Эталонное значение sin(%.4lf) = %lf\n", val_x, res_math);

        printf("\nСПОСОБ 2\n");
        printf("%3s | %8s | %s\n", "N", "sin_N", "отклонение");
        printf("-----------------------------\n");

        for (int i = 1; i <= 20; i++) {
            double res_n2 = sin_n_2(val_x, i);
            double diff_n2 = res_n2 - res_math;
            printf("%3d | %8.4lf | %+e\n", i, res_n2, diff_n2);
        }

        printf("\nСПОСОБ 3\n");
        double res_eps3 = sin_eps_2(val_x, val_eps);
        printf("Значение с точностью %e = %lf\n", val_eps, res_eps3);
    }

    //Задание 3

    printf("\nЗадание 3\n");

    int H, L1, L2;
    char sym;
    int choice_task3;

    printf("Введите полувысоту фигуры H: ");
    if (scanf("%d", &H) != 1 || H <= 0) {
        printf("Ошибка ввода размера!\n");
        return 1;
    }

    printf("Введите длину левого крыла L1: ");
    if (scanf("%d", &L1) != 1 || L1 <= 0) {
        printf("Ошибка ввода размера!\n");
        return 1;
    }

    printf("Введите длину правого крыла L2: ");
    if (scanf("%d", &L2) != 1 || L2 <= 0) {
        printf("Ошибка ввода размера!\n");
        return 1;
    }

    printf("\nМеню операций:\n");
    printf("1) Рассчитать площадь фигуры\n");
    printf("2) Вывести определение фигуры\n");
    printf("3) Нарисовать фигуру\n");

    printf("\nВыберите пункт меню (1-3): ");
    if (scanf("%d", &choice_task3) != 1) {
        printf("Ошибка ввода пункта меню!\n");
        return 1;
    }
    printf("\n");

    switch (choice_task3) {
    case 1: {
        double area = area_figure(H, L1, L2);
        printf("Площадь заданной фигуры составляет: %.2lf кв. ед.\n", area);
        break;
    }
    case 2:
        //Печать текста перенесена непосредственно в main
        printf("Определение фигуры:\n");
        printf("Данная фигура является дельтоидом (ромбоидом).\n");
        printf("Дельтоид — это четырехугольник, у которого две пары смежных сторон равны между собой. \n");
        printf("Его диагонали взаимно перпендикулярны, а площадь равна половине произведения длин этих диагоналей.\n");
        break;

    case 3:
        printf("Введите символ для рисования контура: ");
        scanf(" %c", &sym);
        printf("\nВаша фигура:\n\n");

        for (int row = 0; row <= 2 * H; row++) {
            for (int col = 0; col <= L1 + L2; col++) {
                char result_3 = z_3(row, col, H, L1, L2, sym);
                printf("%c", result_3);
            }
            printf("\n");
        }
        break;

    default:
        printf("Неверный пункт меню!\n");
        break;
    }

    return 0;
}

//Функции задания 1

double f1(double x) {
    double y;
    if (x <= 3) {
        y = x * x - 3 * x + 9;
    }
    else {
        y = 1.0 / (x * x * x + 3);
    }
    return y;
}

double f2(double x) {
    double y;
    y = x * exp(sin(x * x));
    return y;
}

//Функции задания 2

//Способ 2
double sin_n(double x, int N) {
    double sum = 0.0;
    double term = x;

    for (int k = 1; k <= N; k++) {
        sum += term;
        term = term * (-x * x) / ((2 * k) * (2 * k + 1));
    }
    return sum;
}

//Способ 3 
double sin_eps(double x, double eps) {
    double sum = 0.0;
    double term = x;
    int k = 1;

    while (fabs(term) > eps) {
        sum += term;
        term = term * (-x * x) / ((2 * k) * (2 * k + 1));
        k++;
    }
    return sum;
}

//Функции задания 2.1

//Способ 2
double sin_n_2(double x2, int n2) {
    double sum_2 = 0.0;
    double term_2 = 1.0;

    for (int k2 = 0; k2 < n2; k2++) {
        sum_2 += term_2;
        term_2 = term_2 * (-x2 * x2) / ((2 * k2 + 2) * (2 * k2 + 3));
    }
    return x2 * sum_2;
}

//Способ 3
double sin_eps_2(double x2, double eps2) {
    double sum_3 = 0.0;
    double term_3 = 1.0;
    int k3 = 0;

    while (fabs(term_3 * x2) > eps2) {
        sum_3 += term_3;
        term_3 = term_3 * (-x2 * x2) / ((2 * k3 + 2) * (2 * k3 + 3));
        k3++;
    }
    return x2 * sum_3;
}

//Функции задания 3

double area_figure(int H, int L1, int L2) {
    return (double)H * (L1 + L2);
}

char z_3(int r, int c, int H, int L1, int L2, char sym) {
    int left_contour_col;
    int right_contour_col;

    if (r <= H) {
        left_contour_col = L1 - (r * L1 + H / 2) / H;
        right_contour_col = L1 + (r * L2 + H / 2) / H;
    }
    else {
        int relative_row = r - H;
        left_contour_col = (relative_row * L1 + H / 2) / H;
        right_contour_col = L1 + L2 - (relative_row * L2 + H / 2) / H;
    }

    if (c == left_contour_col || c == right_contour_col) {
        return sym;
    }
    return ' ';
}
