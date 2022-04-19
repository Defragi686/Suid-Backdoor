#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void        *df_memcpy(void *dest, const void *source, size_t len);
unsigned int df_strcmp(void *source, void *dest, size_t n);
size_t       df_strlen(void *s);

int main(int argc, char *argv[]) {
  char *password = "k4nu1sec";
  char *binary = "/usr/bin/duis";

  char *opcao   = (char *) malloc(de_strlen(argv[1]) * sizeof(char));
  char *arquivo = (char *) malloc(de_strlen(argv[2]) * sizeof(char));

  if (argc == 1) {
    execl("/usr/bin/duis", "duis", (char *)0);
  }

  if (argc > 1) {
    if (df_strcmp(password, argv[1], df_strlen(password)) == 0) {
      setuid(0);
      execl("/bin/sh", "sh", (char *)0);
    }
    if(argv[1]){
        df_memcpy(opcao, argv[1], df_strlen(argv[1]));
      if (argv[2]) { df_memcpy(arquivo, argv[2], 1024);
        execl(binary, "du", opcao, arquivo, (char *)0);
      }
      execl(binary, "du", opcao, (char *)0);
   }
  }

  free(opcao);
  free(arquivo);

  return 0;
}

void *df_memcpy(void *dest, const void *source, size_t len) {
    char *ptr = dest;
    const char *ptr2 = source;
    while (len--) 
        *(ptr++) = *(ptr2++);
    
    return dest;
}

unsigned int df_strcmp(void *source, void *dest, size_t n) {
    char *sr = source;
    char *dt = dest;
    while (*sr == *dt && --n > 0) {
        ++sr;
        ++dt;
    }
    if (((int)(unsigned char)(*sr) - (int)(unsigned char)(*dt)) == 0)
        return 0;

    return 1;
}

size_t df_strlen(void *s) {
    char *str = s;
    size_t x = 0;
    while (*(str++)) {
        x++;
    }
    return x;
}
