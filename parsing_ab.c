#include <stdio.h>
#include <stdlib.h>
#include "mpc.h"

#ifdef _WIN32

#include <string.h>
static char buffer[2048];

char* readline(char* prompt) {
  fputs(prompt, stdout);
  fgets(buffer, 2048, stdin);
  char* cpy = malloc(strlen(buffer) + 1);
  strcpy(cpy, buffer);
  cpy[strlen(cpy) - 1] = '\0';
  return cpy;
}

void add_history(char* unused) {}

#else
#include <editline/history.h>
#include <editline/readline.h>
#endif

int main(int argc, char** argv) {
  mpc_parser_t* Ab = mpc_new("ab");
  mpc_parser_t* Lispy = mpc_new("lispy");

  mpca_lang(MPCA_LANG_DEFAULT,
            "                     \
      ab      : /[ab]+/;          \
      lispy   : /^/ <ab> /$/ ;   \
      ",
            Ab, Lispy);

  puts("Lispy Version 0.0.0.0.1");
  puts("Press Ctrl+C to Exit\n");

  while (1) {
    char* input = readline("lispy>");
    add_history(input);

    mpc_result_t r;
    if (mpc_parse("<stdin>", input, Lispy, &r)) {
      mpc_ast_print(r.output);
      mpc_ast_delete(r.output);
    } else {
      mpc_err_print(r.error);
      mpc_err_delete(r.error);
    }

    free(input);
  }

  return 0;
}
