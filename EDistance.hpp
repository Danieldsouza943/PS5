// Copyright 2024 Daniel Dsouza
#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <map>
#include <memory>
#include <algorithm>

using std::endl;

class EDistance {
 private:
  std::vector<std::vector<int>> opt;
  std::string str1, str2;
  int xl, yl;
  void populateOpt();

 public:
    EDistance(std::string str1, std::string str2);
    static int penalty(char a, char b);
    static int min3(int a, int b, int c);
    int optDistance();
    std::string alignment();
};
