#include <stdio.h>

int main() {
  char *filename;
  FILE *fd;
  int counter = 0;
  int lang_select_number;
  int dice_number;

  char buffer[100];
  char buffer_int[100];

  printf("Welcome this is some password generator use a dice pls xD,\n"
         "select a lang for the word then throw the dice 6 times as ur input\n"
         "lang_select_number\n");
  while (counter < 4) {
    printf("Escolha 1-portugues 2-ingles 3-italiano\n");
    fgets(buffer, sizeof(buffer), stdin);
    lang_select_number = atoi(buffer);

    switch (lang_select_number) {
    case 1:
      filename = "port.txt";
      break;
    case 2:
      filename = "eng.txt";
      break;
    case 3:
      filename = "ita.txt";
      break;
    default:
      printf("nenhum selecionado\n");
      return 0;
    }
    printf("digite o numero de ate 6 digitos que pegou no dado\n");

    fgets(buffer_int, sizeof(buffer_int), stdin);

    dice_number = atoi(buffer_int);

    dice_number = dice_number % 200000;

    fd = fopen(filename, "r");

    if (fd == NULL) {
      printf("Arquivo %s nao pode ser aberto\n", filename);
      return 1;
    }
    const unsigned MAX_LENGTH = 256;
    char BUFFER_FILE[MAX_LENGTH];
    int counter_lines = 0;
    while (fgets(BUFFER_FILE, MAX_LENGTH, fd)) {
      if (counter_lines == dice_number) {
        printf("chosen word was %s\n", BUFFER_FILE);
        break;
      } else {
        // printf("%s\n", filename);
        counter_lines++;
        continue;
      }
    }

    fclose(fd);
    counter++;
  }
  return 0;
}
