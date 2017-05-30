#ifndef _PSLBASE_HPP_
#define _PSLBASE_HPP_

#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <regex>
#include <map>

#include "structs.hpp"

#define ERROR      "0"
#define INTEGER    "1"
#define STRING     "2"
#define FUNCTION   "7"
#define DECLARERS  "8"
#define IDENTIFIER "9"

namespace psl{

  const std::string fkeywords[] = {"say", "exit"};
  const std::string dkeywords[] = {"int", "string", "bool", "char"};

  std::string getType(const std::string in){

    if(in == INTEGER){
      return "integer";
    }else if(in == STRING){
      return "string";
    }else if(in == FUNCTION){
      return "function";
    }else if(in == IDENTIFIER){
      return "identifier";
    }else if(in == ERROR){
      return "error";
    }

  return "";
  }

  std::vector<std::string> tokenize(const std::string& in, char c){

    std::vector<std::string> out;
    std::string tmp;

    bool quotes = false; bool brackets = false;

    for(uint i = 0; i < in.size(); i++){

      if(in[i] != c || brackets || quotes){

        tmp += in[i];

        if(in[i] == '\"'){
          quotes = !quotes;

        }else if(!quotes && in[i] == '('){
          brackets = true;

        }else if(!quotes && in[i] == ')'){
          brackets = false;
        }
      }else{

        if(tmp != ""){
          out.push_back(tmp);
          tmp = "";
        }
      }
    }
    if(tmp != ""){
      out.push_back(tmp);
      tmp = "";
    }
    return out;
  }

  int toInteger(std::string& in){

    std::stringstream tmp;
    int out;

    tmp << in; tmp >> out;
    return out;
  }

  int toInteger(std::string in){

    std::stringstream tmp;
    int out;

    tmp << in; tmp >> out;
    return out;
  }

  std::string toString(uint in){
    std::stringstream tmp;
    std::string out;

    tmp << in;
    tmp >> out;

    return out;
  }

  bool isIdentifier(const std::string& in){

    std::regex re("([A-Z]|[a-z]|[_])+");

    if(std::regex_match(in, re))
      return true;
    return false;
  }

  bool isInteger(const std::string& in){

    std::regex re("(\\+|-)?(\\d)+");

    if(std::regex_match(in, re))
      return true;
    return false;
  }

  bool isStringLiteral(const std::string& in){

    std::regex re("\"(.*)\"");

    if(std::regex_match(in, re))
      return true;
    return false;

  }

  bool isFunction(const std::string& in){

    for(uint i = 1; i < std::extent<decltype(psl::fkeywords)>::value; i++){
      std::regex re(psl::fkeywords[i] + "\\((.*)\\)");

      if(std::regex_match(in, re))
        return true;
    }
    return false;
  }

  bool isDeclaring(const std::string& in){
    for(uint i = 0; i < std::extent<decltype(psl::dkeywords)>::value; i++){
      std::regex re(psl::dkeywords[i]);

      if(std::regex_match(in, re))
        return true;
    }
    return false;
  }

  std::string execute(const std::string in){
    for(uint i = 0; i < std::extent<decltype(psl::fkeywords)>::value; i++){
      std::regex re(psl::fkeywords[i] + "\\((.*)\\)");

      if(std::regex_match(in, re)){}
    }
  }

  std::string evaluate(const std::string& input){

    std::string output = "8" + input;

    if(psl::isIdentifier(input))
      return IDENTIFIER + input;
    if(psl::isStringLiteral(input))
      return STRING + input.substr(1, input.size() - 2);
    if(psl::isInteger(input))
      return INTEGER + input;

    for(uint i = 0; i < std::extent<decltype(psl::fkeywords)>::value; i++){
      std::regex re(psl::fkeywords[i] + "\\((.*)\\)");

      if(std::regex_match(input, re))
        return FUNCTION + input;
    }

    return output;
  }

}
#endif
