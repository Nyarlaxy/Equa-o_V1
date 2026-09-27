#include <stdio.h>

// Função para eu descobrir a maldita da raiz quadrada
float raizQuadrada(float numero) {
    float aproximacao;
    int i;

    if (numero == 0.0f) {
        return 0.0f;
    }
    aproximacao = numero / 2.0f;

    // 50 repeticoes para chegar um valor aproximado nisso ae
    for (i = 0; i < 50; i++) {
        aproximacao = (aproximacao + numero / aproximacao) / 2.0f;
    }

    return aproximacao;
}
// Limpador de buffer ( peguei da net esse para aplicar )
void limparBufferEntrada(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {
    }
}

void resolverPrimeiroGrau(void) {
    int a, b;
    float x;

    printf("\n=== Resolucao passo-a-passo: Equacao do Primeiro Grau ===\n");
    printf("Forma: ax + b = 0\n");

    printf("Digite o valor de a: ");
    scanf("%d", &a);
    printf("Digite o valor de b: ");
    scanf("%d", &b);

    printf("\nEquacao informada: %d x + (%d) = 0\n", a, b);

    printf("\nPassos:\n");
    printf("1) Escreva a equacao: (%d) x + (%d) = 0\n", a, b);

    if (a == 0) {
        printf("2) Como a = 0, a equacao nao e do primeiro grau (ou nao tem\n");
        printf("   coeficiente x). Nao e possivel isolar x.\n");
        if (b == 0) {
            printf("   Como b tambem e 0, qualquer valor de x satisfaz a equacao.\n");
            printf("Solucao: infinitas solucoes (0 = 0)\n");
        } else {
            printf("   Como b != 0, a equacao (%d) = 0 e falsa.\n", b);
            printf("Solucao: nao existe solucao\n");
        }
        return;
    }

    printf("2) Isolar o termo com x: (%d) x = - (%d)\n", a, b);
    printf("   ou: %d x = %d\n", a, -b);
    printf("3) Dividir ambos os lados por a: x = (%d) / (%d)\n", -b, a);

    x = (float)(-b) / (float)a;

    printf("4) Calculo: x = %.2f\n", x);
    printf("\nSolucao: x = %.2f\n", x);
}

void resolverSegundoGrau(void) {
    int a, b, c;
    int bb, quatroac, delta;
    int denom;

    printf("\n=== Resolucao passo-a-passo: Equacao do Segundo Grau ===\n");
    printf("Forma: a x^2 + b x + c = 0\n");

    printf("Digite o valor de a: ");
    scanf("%d", &a);
    printf("Digite o valor de b: ");
    scanf("%d", &b);
    printf("Digite o valor de c: ");
    scanf("%d", &c);

    printf("\nEquacao informada: %d x^2 + %d x + %d = 0\n", a, b, c);

    if (a == 0) {
        printf("\nComo a = 0, esta nao e uma equacao do segundo grau.\n");
        return;
    }

    printf("\nPassos:\n");
    printf("1) Calcular o discriminante: Delta = b^2 - 4*a*c\n");

    bb = b * b;
    quatroac = 4 * a * c;

    printf("   - b^2 = (%d)^2 = %d\n", b, bb);
    printf("   - 4*a*c = 4 * (%d) * (%d) = %d\n", a, c, quatroac);

    delta = bb - quatroac;
    printf("   => Delta = %d - %d = %d\n", bb, quatroac, delta);

    denom = 2 * a;

    if (delta > 0) {
        /* raizQuadrada recebe float; convertemos o int delta explicitamente */
        float raizDelta = raizQuadrada((float)delta);
        float x1 = (-b + raizDelta) / denom;
        float x2 = (-b - raizDelta) / denom;

        printf("\n2) Como Delta > 0, existem duas raizes reais.\n");
        printf("   - raiz(Delta) = raiz(%d) = %.2f\n", delta, raizDelta);
        printf("   - Denominador 2a = 2 * (%d) = %d\n", a, denom);

        printf("\n3) Calculo de x1:\n");
        printf("   x1 = (-b + raiz(Delta)) / (2a)\n");
        printf("      = (%d + %.2f) / %.2f\n", -b, raizDelta, denom);
        printf("      = %.2f / %d\n", -b + raizDelta, denom);
        printf("      = %.2f\n", x1);

        printf("\n4) Calculo de x2:\n");
        printf("   x2 = (-b - raiz(Delta)) / (2a)\n");
        printf("      = (%d - %.2f) / %d\n", -b, raizDelta, denom);
        printf("      = %.2f / %d\n", -b - raizDelta, denom);
        printf("      = %.2f\n", x2);

        printf("\nSolucoes reais: x1 = %g ; x2 = %.2f\n", x1, x2);

    } else if (delta == 0) {
        float x = (float)(-b) / (float)denom;

        printf("\n2) Como Delta = 0, existe uma unica raiz real (raiz dupla).\n");
        printf("   - Denominador 2a = 2 * (%d) = %d\n", a, denom);

        printf("\n3) Calculo de x:\n");
        printf("   x = -b / (2a)\n");
        printf("     = (%d) / %d\n", -b, denom);
        printf("     = %g\n", x);

        printf("\nSolucao real (raiz dupla): x = %.2f\n", x);

    } else {
        float raizNegDelta = raizQuadrada((float)(-delta));
        float parteReal = (float)(-b) / (float)denom;
        float parteImag = raizNegDelta / denom;

        printf("\n2) Como Delta < 0, nao existem raizes reais.");
    }
}
int main(void) {
    int opcao;
    int continuar = 1;

    while (continuar) {
        printf("\n=== MENU PRINCIPAL ===\n");
        printf("1 - Resolver equacao do primeiro grau (mostrar passos)\n");
        printf("2 - Resolver equacao do segundo grau (mostrar passos)\n");
        printf("0 - Sair\n");
        printf("Escolha uma opcao: ");

        if (scanf("%d", &opcao) != 1) {
            printf("\nEntrada invalida. Tente novamente.\n");
            limparBufferEntrada();
            continue;
        }

        switch (opcao) {
            case 1:
                resolverPrimeiroGrau();
                break;
            case 2:
                resolverSegundoGrau();
                break;
            case 0:
                printf("\nSaindo...\n");
                continuar = 0;
                break;
            default:
                printf("\nOpcao invalida. Tente novamente.\n");
                break;
        }
    }

    return 0;
}
