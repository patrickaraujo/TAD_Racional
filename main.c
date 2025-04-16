#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int numerador;
    int denominador;
} Racional;

Racional makerational(int a, int b) {
    if (b == 0) {
        printf("Erro: denominador não pode ser zero.\n");
        exit(1);
    }
    Racional r;
    r.numerador = a;
    r.denominador = b;
    return r;
}

Racional add(Racional a, Racional b) {
    Racional resultado;
    resultado.numerador = a.numerador * b.denominador + b.numerador * a.denominador;
    resultado.denominador = a.denominador * b.denominador;
    return resultado;
}

Racional mult(Racional a, Racional b) {
    Racional resultado;
    resultado.numerador = a.numerador * b.numerador;
    resultado.denominador = a.denominador * b.denominador;
    return resultado;
}

int equal(Racional a, Racional b) {
    return a.numerador * b.denominador == b.numerador * a.denominador;
}

int main() {
    Racional r1 = makerational(1, 2);
    Racional r2 = makerational(2, 4);

    Racional soma = add(r1, r2);
    Racional produto = mult(r1, r2);

    printf("Soma: %d/%d\n", soma.numerador, soma.denominador);
    printf("Produto: %d/%d\n", produto.numerador, produto.denominador);

    if (equal(r1, r2)) {
        printf("r1 e r2 são iguais\n");
    } else {
        printf("r1 e r2 são diferentes\n");
    }

    return 0;
}
