#include "psl.hpp"

int main(int argv, char** argc){

  if(argv == 1){

    repl REPL;

    psl::functions::func("Hola");

    REPL.loop();

  }//else{}

  return 0;
}
