// Copyright 2024 Daniel Dsouza
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <string>
#include <SFML/System.hpp>
#include "EDistance.hpp"

#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Main
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(test_cost) {
    std::ifstream file("test.txt");
    std::string str1, str2;
    file >> str1;
    file >> str2;
    EDistance ed(str1, str2);

    BOOST_CHECK_EQUAL(ed.optDistance(), 0);
}

BOOST_AUTO_TEST_CASE(test_cut_ends) {
    EDistance ed("ABCD", "CBC");

    std::string alignment = ed.alignment();
    std::stringstream ss(alignment);
    std::string line;

    std::getline(ss, line);
    BOOST_CHECK_EQUAL(line, "A C 1");

    std::getline(ss, line);
    BOOST_CHECK_EQUAL(line, "B B 0");

    std::getline(ss, line);
    BOOST_CHECK_EQUAL(line, "C C 0");

    std::getline(ss, line);
    BOOST_CHECK_EQUAL(line, "D - 2");
}

BOOST_AUTO_TEST_CASE(test_penalty) {
    BOOST_CHECK_EQUAL(EDistance::penalty('A', 'A'), 0);
    BOOST_CHECK_EQUAL(EDistance::penalty('A', 'B'), 1);
    BOOST_CHECK_EQUAL(EDistance::penalty('A', '$'), 1);
}

BOOST_AUTO_TEST_CASE(test_min3) {
    BOOST_CHECK_EQUAL(EDistance::min3(1, 2, 3), 1);
    BOOST_CHECK_EQUAL(EDistance::min3(4, 3, 2), 2);
    BOOST_CHECK_EQUAL(EDistance::min3(2, 1, 5), 1);
}
