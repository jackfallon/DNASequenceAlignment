// Copyright 2023 [John Fallon]
#include "EditDistance.hpp"

EditDistance::EditDistance(std::string newS1, std::string newS2) {
    s1 = newS1;
    s2 = newS2;
    std::vector<std::vector<int>> temp(s1.size() + 1, std::vector<int>(s2.size() + 1, 0));
    opt = temp;

    for (size_t i = 0; i < s1.size(); i++) {
        opt[i][s2.size()] = 2 * (s1.size() - i);
    }
    for (size_t j = 0; j < s2.size(); j++) {
        opt[s1.size()][j] = 2 * (s2.size() - j);
    }
}

int EditDistance::penalty(char a, char b) {
    if (a == b) {
        return 0;
    } else {
        return 1;
    }
}

int EditDistance::min(int a, int b, int c) {
    if (a < b && a < c) {
        return a;
    } else if (b < a && b < c) {
        return b;
    } else {
        return c;
    }
}

int EditDistance::optDistance() {
    for (size_t i = s1.size() - 1; i < s1.size(); i--) {
        for (size_t j = s2.size() - 1; j < s2.size(); j--) {
            opt[i][j] =
                    min(opt[i+1][j+1] + penalty(s1[i], s2[j]), opt[i+1][j] + 2, opt[i][j+1] + 2);
        }
    }
    return opt[0][0];
}

std::string EditDistance::alignment() {
    std::string output;
    size_t i = 0;
    size_t j = 0;

    while (i < opt.size() - 1 || j < opt[0].size() - 1) {
        if (s1[i] == s2[j]
            && opt[i][j] == opt[i+1][j+1]
            && i < opt.size() - 1
            && j < opt[0].size() - 1) {
            output += s1[i];
            output += " ";
            output += s2[j];
            output += " 0";
            output += "\n";
            i++;
            j++;
        } else if (s1[i] != s2[j]
                && opt[i][j] == opt[i+1][j+1] + 1
                && i < opt.size() - 1 && j < opt[0].size() - 1) {
            output += s1[i];
            output += " ";
            output += s2[j];
            output += " 1";
            output += "\n";
            i++;
            j++;
        } else if (opt[i][j] == opt[i+1][j] + 2 && i < opt.size() - 1) {
            output += s1[i];
            output += " - 2";
            output += "\n";
            i++;
        } else if (opt[i][j] == opt[i][j+1] + 2 && j < opt[0].size() - 1) {
            output += "- ";
            output += s2[j];
            output += " 2";
            output += "\n";
            j++;
        }
    }
    return output;
}
