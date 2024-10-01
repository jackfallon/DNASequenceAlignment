// Copyright 2023 [John Fallon]
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <SFML/System.hpp>

class EditDistance {
 public:
        EditDistance(std::string newS1, std::string newS2);
        static int penalty(char a, char b);
        static int min(int a, int b, int c);
        int optDistance();
        std::string alignment();

 private:
        std::string s1;
        std::string s2;
        std::vector<std::vector<int>> opt;
};
