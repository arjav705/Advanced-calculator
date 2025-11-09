#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* -------- Utility Functions -------- */
void clear_screen() { printf("\033[2J\033[1;1H"); }
void set_color(int code) { printf("\033[%dm", code); }

void pause_screen() {
    printf("\n\nPress ENTER to continue...");
    getchar();
    getchar();
}

unsigned long long factorial(int n) {
    if (n < 0) return 0;
    unsigned long long f = 1;
    for (int i = 1; i <= n; i++) f *= i;
    return f;
}

/* -------- UI Components -------- */
void print_header() {
    set_color(36);
    printf("╔══════════════════════════════════════════════════╗\n");
    printf("║              ULTIMATE SCIENTIFIC CALC v6.0        ║\n");
    printf("╚══════════════════════════════════════════════════╝\n");
    set_color(0);
}

void print_menu() {
    set_color(33);
    printf("┌────────────────────────────── MENU ──────────────────────────────┐\n");
    printf("│  1.  Addition (+)             21. Inverse Sine (asin)           │\n");
    printf("│  2.  Subtraction (-)          22. Inverse Cosine (acos)         │\n");
    printf("│  3.  Multiplication (*)       23. Inverse Tangent (atan)        │\n");
    printf("│  4.  Division (/)             24. Hyperbolic Sine (sinh)        │\n");
    printf("│  5.  Power (x^y)              25. Hyperbolic Cosine (cosh)      │\n");
    printf("│  6.  Square Root (√x)         26. Hyperbolic Tangent (tanh)     │\n");
    printf("│  7.  Cube Root (∛x)           27. Inverse sinh (asinh)          │\n");
    printf("│  8.  Absolute Value (|x|)     28. Inverse cosh (acosh)          │\n");
    printf("│  9.  Modulus (fmod)           29. Inverse tanh (atanh)          │\n");
    printf("│ 10.  Factorial (n!)           30. Radians → Degrees             │\n");
    printf("│ 11.  Exponential (e^x)        31. Degrees → Radians             │\n");
    printf("│ 12.  Natural Log (ln)         32. Floor                         │\n");
    printf("│ 13.  Log Base10 (log10)       33. Ceil                          │\n");
    printf("│ 14.  Sine (sin)               34. Round                         │\n");
    printf("│ 15.  Cosine (cos)             35. Truncate (int part)           │\n");
    printf("│ 16.  Tangent (tan)            36. Min(x,y)                      │\n");
    printf("│ 17.  Mean of Two Numbers      37. Max(x,y)                      │\n");
    printf("│ 18.  Percentage (x of y)      38. Reciprocal (1/x)              │\n");
    printf("│ 19.  Square (x²)              39. Cube (x³)                     │\n");
    printf("│ 20.  Root Power (x^(1/y))     40. Exit                          │\n");
    printf("└──────────────────────────────────────────────────────────────────┘\n");
    set_color(0);
}

/* -------- Main Program -------- */
int main() {
    int choice;
    double num1, num2, result;

    while (1) {
        clear_screen();
        print_header();
        print_menu();

        set_color(35);
        printf("\nSelect an operation (1–40): ");
        set_color(0);
        scanf("%d", &choice);

        clear_screen();
        print_header();

        switch (choice) {
            case 1:
                printf("Enter first number: ");
                scanf("%lf", &num1);
                printf("Enter second number: ");
                scanf("%lf", &num2);
                result = num1 + num2;
                break;

            case 2:
                printf("Enter first number: ");
                scanf("%lf", &num1);
                printf("Enter second number: ");
                scanf("%lf", &num2);
                result = num1 - num2;
                break;

            case 3:
                printf("Enter first number: ");
                scanf("%lf", &num1);
                printf("Enter second number: ");
                scanf("%lf", &num2);
                result = num1 * num2;
                break;

            case 4:
                printf("Enter dividend: ");
                scanf("%lf", &num1);
                printf("Enter divisor: ");
                scanf("%lf", &num2);
                if (num2 == 0) {
                    set_color(31);
                    printf("\nError: Division by zero!");
                    set_color(0);
                    pause_screen();
                    continue;
                }
                result = num1 / num2;
                break;

            case 5:
                printf("Enter base: ");
                scanf("%lf", &num1);
                printf("Enter exponent: ");
                scanf("%lf", &num2);
                result = pow(num1, num2);
                break;

            case 6:
                printf("Enter number: ");
                scanf("%lf", &num1);
                result = (num1 < 0) ? NAN : sqrt(num1);
                break;

            case 7:
                printf("Enter number: ");
                scanf("%lf", &num1);
                result = cbrt(num1);
                break;

            case 8:
                printf("Enter number: ");
                scanf("%lf", &num1);
                result = fabs(num1);
                break;

            case 9:
                printf("Enter first number: ");
                scanf("%lf", &num1);
                printf("Enter second number: ");
                scanf("%lf", &num2);
                result = fmod(num1, num2);
                break;

            case 10: {
                int n;
                printf("Enter integer: ");
                scanf("%d", &n);
                if (n < 0) {
                    set_color(31);
                    printf("\nError: Negative number!");
                    set_color(0);
                    pause_screen();
                    continue;
                }
                unsigned long long f = factorial(n);
                set_color(32);
                printf("\n%d! = %llu", n, f);
                set_color(0);
                pause_screen();
                continue;
            }

            case 11:
                printf("Enter number: ");
                scanf("%lf", &num1);
                result = exp(num1);
                break;

            case 12:
                printf("Enter positive number: ");
                scanf("%lf", &num1);
                result = (num1 <= 0) ? NAN : log(num1);
                break;

            case 13:
                printf("Enter positive number: ");
                scanf("%lf", &num1);
                result = (num1 <= 0) ? NAN : log10(num1);
                break;

            case 14:
                printf("Enter angle (degrees): ");
                scanf("%lf", &num1);
                result = sin(num1 * M_PI / 180);
                break;

            case 15:
                printf("Enter angle (degrees): ");
                scanf("%lf", &num1);
                result = cos(num1 * M_PI / 180);
                break;

            case 16:
                printf("Enter angle (degrees): ");
                scanf("%lf", &num1);
                result = tan(num1 * M_PI / 180);
                break;

            case 17:
                printf("Enter first number: ");
                scanf("%lf", &num1);
                printf("Enter second number: ");
                scanf("%lf", &num2);
                result = (num1 + num2) / 2.0;
                break;

            case 18:
                printf("Enter value: ");
                scanf("%lf", &num1);
                printf("Enter total: ");
                scanf("%lf", &num2);
                result = (num2 == 0) ? NAN : (num1 / num2) * 100;
                break;

            case 19:
                printf("Enter number: ");
                scanf("%lf", &num1);
                result = num1 * num1;
                break;

            case 20:
                printf("Enter number: ");
                scanf("%lf", &num1);
                printf("Enter root value: ");
                scanf("%lf", &num2);
                result = pow(num1, 1.0 / num2);
                break;

            case 21:
                printf("Enter value (-1 to 1): ");
                scanf("%lf", &num1);
                result = asin(num1) * 180 / M_PI;
                break;

            case 22:
                printf("Enter value (-1 to 1): ");
                scanf("%lf", &num1);
                result = acos(num1) * 180 / M_PI;
                break;

            case 23:
                printf("Enter value: ");
                scanf("%lf", &num1);
                result = atan(num1) * 180 / M_PI;
                break;

            case 24:
                printf("Enter value: ");
                scanf("%lf", &num1);
                result = sinh(num1);
                break;

            case 25:
                printf("Enter value: ");
                scanf("%lf", &num1);
                result = cosh(num1);
                break;

            case 26:
                printf("Enter value: ");
                scanf("%lf", &num1);
                result = tanh(num1);
                break;

            case 27:
                printf("Enter value: ");
                scanf("%lf", &num1);
                result = asinh(num1);
                break;

            case 28:
                printf("Enter value >= 1: ");
                scanf("%lf", &num1);
                result = (num1 < 1) ? NAN : acosh(num1);
                break;

            case 29:
                printf("Enter value (-1 < x < 1): ");
                scanf("%lf", &num1);
                result = (fabs(num1) >= 1) ? NAN : atanh(num1);
                break;

            case 30:
                printf("Enter radians: ");
                scanf("%lf", &num1);
                result = num1 * 180 / M_PI;
                break;

            case 31:
                printf("Enter degrees: ");
                scanf("%lf", &num1);
                result = num1 * M_PI / 180;
                break;

            case 32:
                printf("Enter number: ");
                scanf("%lf", &num1);
                result = floor(num1);
                break;

            case 33:
                printf("Enter number: ");
                scanf("%lf", &num1);
                result = ceil(num1);
                break;

            case 34:
                printf("Enter number: ");
                scanf("%lf", &num1);
                result = round(num1);
                break;

            case 35:
                printf("Enter number: ");
                scanf("%lf", &num1);
                result = trunc(num1);
                break;

            case 36:
                printf("Enter first number: ");
                scanf("%lf", &num1);
                printf("Enter second number: ");
                scanf("%lf", &num2);
                result = fmin(num1, num2);
                break;

            case 37:
                printf("Enter first number: ");
                scanf("%lf", &num1);
                printf("Enter second number: ");
                scanf("%lf", &num2);
                result = fmax(num1, num2);
                break;

            case 38:
                printf("Enter number: ");
                scanf("%lf", &num1);
                if (num1 == 0) {
                    set_color(31);
                    printf("\nError: Division by zero!");
                    set_color(0);
                    pause_screen();
                    continue;
                }
                result = 1.0 / num1;
                break;

            case 39:
                printf("Enter number: ");
                scanf("%lf", &num1);
                result = num1 * num1 * num1;
                break;

            case 40:
                set_color(36);
                printf("\nThank you for using ULTIMATE SCIENTIFIC CALCULATOR v6.0!\n");
                set_color(0);
                return 0;

            default:
                set_color(31);
                printf("\nInvalid choice!");
                set_color(0);
                pause_screen();
                continue;
        }

        if (isnan(result)) {
            set_color(31);
            printf("\n\nMath Error or Invalid Input!");
        } else {
            set_color(32);
            printf("\n\nResult = %.10lf", result);
        }

        set_color(0);
        pause_screen();
    }
}
