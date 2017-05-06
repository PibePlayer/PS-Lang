#ifndef _repl_h_
#define _repl_h_

#include <iostream>
#include "pslbase.hpp"
#include <string>
#include <map>

struct repl{
  
  std::string inwords; std::string words;

  struct variables{
    std::map<std::string, int> integers;
  };
  
  void loop(){
    
    do{
      std::cout << "> ";
      std::getline(std::cin, inwords);
    
    }while(inwords != ":q");
    
  }
  
  repl(){}
  
};

#endif
