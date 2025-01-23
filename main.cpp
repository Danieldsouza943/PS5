// Copyright 2024 Daniel Dsouza
#include <iostream>
#include <iomanip>
#include <string>
#include <SFML/System.hpp>
#include "EDistance.hpp"

using std::cout, std::cin, std::endl;

int main(int argc, char const *argv[]) {
    sf::Clock clock;
    std::string str1, str2;
    cin >> str1;
    cin >> str2;

    EDistance ed(str1, str2);

    cout << ed.alignment() << endl;

    sf::Time t = clock.getElapsedTime();

    cout << "Execution time: " << t.asSeconds() << " seconds" << endl;

    return 0;
}
