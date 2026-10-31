#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h> 
#include <locale.h>


double fa(double x)
{
    if (x <= 3.0) 
        return pow(x, 2) - 3 * x + 9;
    else
        return 1 / (pow(x, 3) + 3);
}

double fb(double x) {
    return x * exp(sin(pow(x, 2)));
}

float area_trapezoid(float a, float b, float h)
{
    return ((a + b) / 2) * h;
}

void draw_trapezoid(int top_base, int height)
{
    const int delta = height - 1;

    for (int row = 0; row < height; ++row)
    {
        for (int i = 0; i < delta - row; ++i)
            putchar(' ');

        int stars_in_row = top_base + 2 * row;
        for (int j = 0; j < stars_in_row; ++j)
            printf("*");

        printf("\n");
    }
}

void definition_trapezoid()
{
    puts("Равнобедренная трапеция — это четырёхугольник,\n"
        "две стороны которого параллельны друг другу\n"
        "(основания), а боковые стороны равны.");
}

int compare_trapeze(int m1, int h1, int m2, int h2)
{
    double s1 = (double)m1 * h1;
    double s2 = (double)m2 * h2;
    return (int)(s1 - s2); 
}

double cos_lib(double x) { return cos(x); }

double cos_n(double x, int n) {
    double term = 1;
    double sum = term;
    double sign = -1;

    for (int i = 1; i <= n; ++i) {
        term *= x * x;
        term /= (2 * i - 1);
        term /= (2 * i);

        sum += term * sign;
        sign *= -1;
    }
    return sum;
}

double cos_eps(double x, double eps) {
    double term = 1;
    double sum = term;
    double sign = -1;
    int k = 1;

    while (fabs(term) > eps) {
        term *= x * x;
        term /= (2 * k - 1);
        term /= (2 * k);

        sum += term * sign;
        sign *= -1;
        k++;
    }

    return sum;
}

int main(void)
{
    setlocale(LC_ALL, "ru_RU.UTF-8");

    // БЛОК 1: Работа с трапецией
    int choice;

    do 
    {
        puts("");
        puts("Выберите операцию:");
        puts("[1] Площадь");
        puts("[2] Определение");
        puts("[3] Нарисовать");
        puts("[4] Сравнить две трапеции");
        puts("[5] Выход к следующему заданию");

        printf("Ваш выбор: ");
        scanf("%d", &choice);
       
        switch (choice)
        {
        case 1:
            // ПЛОЩАДЬ
        {
            float base_a, base_b, height_f;
            printf("Длина меньшего основания: "); scanf("%f", &base_a);
            printf("Длина большего основания: "); scanf("%f", &base_b);
            printf("Высота: "); scanf("%f", &height_f);

            float area = area_trapezoid(base_a, base_b, height_f);
            printf("Площадь равна %.2f\n", area);
            break;
        }
        case 2:
            // ОПРЕДЕЛЕНИЕ
            definition_trapezoid();
            break;

        case 3:
            // РИСУНОК
        {
            int top_base_i, height_i;
            printf("Верхнее основание (целое число): "); scanf("%d", &top_base_i);
            printf("Высота (целое число): "); scanf("%d", &height_i);
            draw_trapezoid(top_base_i, height_i);
            break;
        }
        case 4:
            // СРАВНЕНИЕ ФИГУР
        {
            int m1, h1, m2, h2;

            printf("Параметры первой трапеции:\n");
            printf("Средняя линия (среднее арифметическое оснований): "); scanf("%d", &m1);
            printf("Высота: "); scanf("%d", &h1);

            printf("Параметры второй трапеции:\n");
            printf("Средняя линия: "); scanf("%d", &m2);
            printf("Высота: "); scanf("%d", &h2);

            int diff = compare_trapeze(m1, h1, m2, h2);
            printf("Разница площадей: %d\n", diff);
            break;
        }
        default:
            continue;
        }

    } while (choice != 5);

    double x;
    printf("\nВведите угол X (в радианах): ");
    scanf("%lf", &x);

    const int N = 5;
    const double EPS = 1e-7;

    printf("\nВычисление значения cos(%g):\n\n", x);
    printf("[1] Через стандартную библиотеку: %.9f\n", cos_lib(x));
    printf("[2] Через %d членов ряда: %.9f\n", N, cos_n(x, N));
    printf("[3] С точностью %.0e: %.9f\n", EPS, cos_eps(x, EPS));

    // БЛОК 3: Меню для функций F1 и F2
    printf("\nРабота с функциями F1(x) и F2(x)\n");

    double fx;
    printf("Введите значение аргумента x: ");
    scanf("%lf", &fx);

    printf("\n[1] Значение F1(x)=%.6f\n", fa(fx));
    printf("[2] Значение F2(x)=%.6f\n", fb(fx));
    printf("[3] Произведение F1(x)*F2(x)=%.6f\n", fa(fx) * fb(fx));
    printf("[4] Разность квадратов F1^2-F2^2=%.6f\n", pow(fa(fx), 2) - pow(fb(fx), 2));
    printf("[5] Удвоенная сумма 2*(F1+F2)=%.6f\n", 2 * (fa(fx) + fb(fx)));

    return 0;
}