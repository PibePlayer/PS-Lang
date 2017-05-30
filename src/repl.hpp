#ifndef _REPL_HPP_
#define _REPL_HPP_

#include <iostream>
#include "pslbase.hpp"
#include <string>
#include <map>

struct repl{

  std::string inwords; std::string words;

  void loop(){

    std::string type;
    std::string in;
    std::string words;

    do{
      std::cout << "> ";
      std::getline(std::cin, repl::inwords);

      if(repl::inwords != ""){
        if(psl::isDeclaring(psl::tokenize(inwords, ' ')[0])){
          std::cout << "is Declaring a " << psl::tokenize(inwords, ' ')[0] << std::endl;
        }else{

        in = psl::evaluate(inwords);
        type = in.substr(0, 1);
        words = in.substr(1, in.size() - 1);

        std::cout << words << " is an " << psl::getType(type) << std::endl;
      }

      }

    }while(repl::inwords != ":q" && repl::inwords != "\e");

  }

  repl(){}

};

#endif
