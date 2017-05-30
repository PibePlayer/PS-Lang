#ifndef _STRUCTS_HPP_
#define _STRUCTS_HPP_

#include <string>
#include <map>

namespace psl{

struct VARS{

  std::map<std::string, std::string> strings;
  std::map<std::string, int> integers;
  std::map<std::string, bool> booleans;

};

}

#endif
