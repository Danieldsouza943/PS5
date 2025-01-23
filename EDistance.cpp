// Copyright 2024 Daniel Dsouza
#include "EDistance.hpp"

EDistance::EDistance(std::string _str1, std::string _str2) : str1(_str1), str2(_str2) {
    xl = str1.size();
    yl = str2.size();
    opt.resize(xl + 1, std::vector<int>(yl + 1, 0));
}

void EDistance::populateOpt() {
    for (size_t i = xl; i > 0; i--) {
        opt[i - 1][yl] = opt[i][yl] + 2;
    }

    for (size_t i = yl; i > 0; i--) {
        opt[xl][i - 1] = opt[xl][i] + 2;
    }

    for (int i = xl - 1; i >= 0; i--) {
        for (int j = yl - 1; j >= 0; j--) {
            opt[i][j] = min3(opt[i + 1][j + 1] + penalty(str1[i], str2[j]),
                             opt[i][j + 1] + 2,
                             opt[i + 1][j] + 2);
        }
    }
}

int EDistance::penalty(char a, char b) {
    if (a == b)
        return 0;
    else
        return 1;
}

int EDistance::min3(int a, int b, int c) {
    if (a < b)
        return (a < c)? a : c;
    else
        return (b < c)? b : c;
}

int EDistance::optDistance() {
    populateOpt();
    return opt[0][0];
}

std::string EDistance::alignment() {
    int i = 0, j = 0;
    int optDist = optDistance();
    // optDistance();

    std::stringstream align;
    std::cout << "Edit distance : " << optDist << std::endl;

    while (i < xl || j < yl) {
        if (i < xl && j < yl && opt[i][j] == opt[i + 1][j + 1] + penalty(str1[i], str2[j])) {
            align << str1[i] << " " << str2[j] << " " << penalty(str1[i], str2[j]) << "\n";
            i++;
            j++;
        } else if (j < yl && opt[i][j] == opt[i][j + 1] + 2) {
            align << "-" << " " << str2[j] << " " << 2 << "\n";
            j++;
        } else if (i < xl && opt[i][j] == opt[i + 1][j] + 2) {
            align << str1[i] << " " << "-" << " " << 2 << "\n";
            i++;
        }
    }
    align << "\n";

    return align.str();
}
