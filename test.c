// make a calculator program
// input: 1 + 2
// output: 1 + 2 = 3
// input: 1 - 2
// output: 1 - 2 = -1
#include <stdio.h>

int main(void) {
    int a, b;
    char op;
    scanf("%d %c %d", &a, &op, &b);
    if (op == '+') {
        printf("%d + %d = %d\n", a, b, a + b);
    } else if (op == '-') {
        printf("%d - %d = %d\n", a, b, a - b);
    } else if (op == '*') {
        printf("%d * %d = %d\n", a, b, a * b);
    } else if (op == '/') {
        printf("%d / %d = %d\n", a, b, a / b);
    } else if (op == '%') {
        printf("%d %% %d = %d\n", a, b, a % b);
    } else {
        printf("Invalid operator\n");
    }
    return 0;
}