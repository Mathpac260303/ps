#include <stdio.h>

#include <math.h>


int main() {

  int ordem, i, j;

  printf("Digite a ordem do quadrado magico:\n");
  scanf("%d", & ordem);
  getchar();

  while (ordem < 2 || ordem > 10) {

    printf("A ordem tem que estar entre 2 e 10, escolha outro valor:\n");
    scanf("%d", & ordem);
    getchar();

  }

  printf("Digite os elementos da matriz:\n");

  int elemento[ordem][ordem];

  for (i = 0; i < ordem; i++) {
    for (j = 0; j < ordem; j++) {

      scanf("%d", & elemento[i][j]);
      getchar();

    }
  }

  int somareferencia = 0, somal[ordem], somac[ordem], somadp = 0, somads = 0, flag = 0;

  for (i = 0; i < ordem; i++) {
    somareferencia = somareferencia + elemento[0][i];
  }

  for (i = 0; i < ordem; i++) {
    somal[i] = 0;
    somac[i] = 0;
  }

  for (i = 0; i < ordem; i++) {
    for (j = 0; j < ordem; j++) {

      somal[i] = somal[i] + elemento[i][j];
      somac[j] = somac[j] + elemento[i][j];

      if (i == j) {
        somadp = somadp + elemento[i][j];
      }

      if (i == ordem - 1 - j) {
        somads = somads + elemento[i][j];
      }

    }
  }

  for (i = 0; i < ordem; i++) {

    if (somal[i] != somareferencia || somac[i] != somareferencia) {
      flag = 1;
    }

  }

  if (somadp != somareferencia || somads != somareferencia) {

    flag = 1;

  }

  if (flag == 1) {

    printf("A matriz nao eh um quadrado magico\nResultado da soma = -1");

  } else {

    printf("Matriz\n");

    for (i = 0; i < ordem; i++) {
      for (j = 0; j < ordem; j++) {

        printf("%d ", elemento[i][j]);

      }
      printf("\n");
    }
    printf("Resultado da soma = %d", somareferencia);
  }

  return (0);
}
