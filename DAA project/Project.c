
#include <stdio.h>
#include <math.h>

#define EPS 1e-9

int main() {
    double a, b, c, k, d;

    printf("Extended Master Theorem\n");
    printf("-----------------------\n");

    printf("Enter a (number of subproblems): ");
    scanf("%lf", &a);

    printf("Enter b (division factor): ");
    scanf("%lf", &b);

    printf("Enter c (polynomial exponent): ");
    scanf("%lf", &c);

    printf("Enter k (logarithmic exponent): ");
    scanf("%lf", &k);

    if (a < 1 || b <= 1) {
        printf("Invalid input! Require a >= 1 and b > 1.\n");
        return 1;
    }

    d = log(a) / log(b);

    printf("\nCalculated d = log_b(a) = %.4f\n", d);

    printf("\nRecurrence: T(n) = aT(n/b) + "
           "Theta(n^c * (log n)^k)\n");

    if (c < d - EPS) {
        printf("\nCase 1: Recursive work dominates.\n");
        printf("Time Complexity: Theta(n^%.4f)\n", d);
    }
    else if (fabs(c - d) <= EPS) {
        printf("\nCase 2: Polynomial exponents are equal.\n");

        if (k > -1 + EPS) {
            printf("Time Complexity: Theta(n^%.4f "
                   "* (log n)^%.4f)\n", d, k + 1);
        }
        else if (fabs(k + 1) <= EPS) {
            printf("Time Complexity: Theta(n^%.4f "
                   "* log(log n))\n", d);
        }
        else {
            printf("Time Complexity: Theta(n^%.4f)\n", d);
        }
    }
    else {
        printf("\nCase 3: Non-recursive work dominates.\n");
        printf("Time Complexity: Theta(n^%.4f "
               "* (log n)^%.4f)\n", c, k);
    }

    return 0;
}
