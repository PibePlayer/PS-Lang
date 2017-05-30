#ifndef _FUNCTIONS_HPP_
#define _FUNCTIONS_HPP_

#include <iostream>
#include <string>
#include <vector>
#include <map>

#include "structs.hpp"
#include "pslbase.hpp"

namespace psl{

  namespace functions{

    auto func = void function(std::string in){ std::cout << in; };

    void say(std::string& in, const std::map<std::string, std::string>& strings){

      if(psl::isStringLiteral(in))
        std::cout << in.substr(1, in.size - 1) << std::endl;

    }

  }

}

#endif
