#include "psl.hpp"

int main(int argv, char** argc){

  if(argv == 1){

    repl REPL;
    REPL.loop();

  }//else{}

  return 0;
}
