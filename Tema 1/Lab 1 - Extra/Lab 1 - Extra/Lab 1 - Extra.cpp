#include "header.h"

int Sum(int a, int b) { return a + b; }
int Dif(int a, int b) { return a - b; }
int Mul(int a, int b) { return a * b; }
int Div(int a, int b) { return a / b; }

int main(int argc, char* argv[])
{
    char input[] = "---H***E+++L+++L///O---P+++O/+-**O---";
    func Operatori[6] = { &Mul, &Sum, NULL, &Dif, NULL, &Div };
    int S = 0, V;
    Content x = { 0, 0 };
    int idx;

    for (int i = 0; i < strlen(input); i++)
    {
        switch (input[i])
        {
        case '*': // INMULTIRE
            idx = 0;
            x.p1 = 3;
            x.p2 = 3;
            break;
        case '+': // SUMA
            idx = 1;
            x.p1 = 7;
            x.p2 = 5;
            break;
        case '-': // DIFERENTA
            idx = 3;
            x.p1 = 10;
            x.p2 = 1;
            break;
        case '/': // IMPARTIRE
            idx = 5;
            x.p1 = 8;
            x.p2 = 4;
            break;
        default:
            continue; // Skip characters that aren't operators
        }

        S = S + Operatori[idx](x.p1, x.p2);
    }

    // Using %d instead of %c to print an integer
    printf("S = %d\n", S);

    return 0;
}