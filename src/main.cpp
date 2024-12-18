﻿
#include <vector>
#include <functional>
#include <iostream>
#include "candle.h"

//массив всех тестов, который мы заполняем в функции initTests
static std::vector<std::function<bool()>> tests;

// Тесты для метода body_contains
bool test_body_contains_1()
{
    std::cout << " test_body_contains_1";
    Candle candle{ 5.0, 10.0, 4.0, 10.0 };
    return candle.body_contains(6.0); // должно быть true
}

bool test_body_contains_2()
{
    std::cout << " test_body_contains_2";
    Candle candle{ 10.0, 10.0, 4.0, 5.0 };
    return candle.body_contains(6.0); // должно быть true
}

bool test_body_contains_3()
{
    std::cout << " test_body_contains_3";
    Candle candle{ 10.0, 10.0, 4.0, 5.0 };
    return !candle.body_contains(11.0); // должно быть false
}

// Тесты для метода contains
bool test_contains_1()
{
    std::cout << " test_contains_1";
    Candle candle{ 5.0, 10.0, 4.0, 10.0 };
    return candle.contains(6.0); // должно быть true
}

bool test_contains_2()
{
    std::cout << " test_contains_2";
    Candle candle{ 5.0, 10.0, 4.0, 10.0 };
    return !candle.contains(11.0); // должно быть false
}

bool test_contains_3()
{
    std::cout << " test_contains_3";
    Candle candle{ 5.0, 10.0, 4.0, 10.0 };
    return !candle.contains(3.0); // должно быть false
}


// Тесты для метода full_size
bool test_full_size_1()
{
    std::cout << " test_full_size_1";
    Candle candle{ 5.0, 10.0, 4.0, 7.0 };
    return candle.full_size() == 6; // должно быть 6.0
}

bool test_full_size_2()
{
    std::cout << " test_full_size_2";
    Candle candle{ 5.0, 5.0, 5.0, 5.0 };
    return candle.full_size() == 0; // должно быть 0.0
}

bool test_full_size_3()
{
    std::cout << " test_full_size_3";
    Candle candle{ 10.0, 4.0, 10.0, 7.0 };
    return candle.full_size() == 6; // должно быть 6.0
}

// Тесты для метода body_size
bool test_body_size_1()
{
    std::cout << " test_body_size_1";
    Candle candle{ 10.0, 10.0, 4.0, 5.0 };
    return candle.body_size() == 5; // должно быть 5.0
}

bool test_body_size_2()
{
    std::cout << " test_body_size_2";
    Candle candle{ 5.0, 10.0, 4.0, 5.0 };
    return candle.body_size() == 0; // должно быть 0.0
}

bool test_body_size_3()
{
    std::cout << " test_body_size_3";
    Candle candle{ 5.0, 5.0, 5.0, 10.0 };
    return candle.body_size() == 5; // должно быть 5.0
}

// Тесты для метода is_red 
bool test_is_red_1()
{
    std::cout << " test_is_red_1";
    Candle candle{ 10.0, 10.0, 4.0, 5.0 };
    return candle.is_red(); // должно быть true
}

bool test_is_red_2()
{
    std::cout << " test_is_red_2";
    Candle candle{ 5.0, 10.0, 4.0, 10.0 };
    return !candle.is_red(); // должно быть false
}

bool test_is_red_3()
{
    std::cout << " test_is_red_3";
    Candle candle{ 5.0, 10.0, 4.0, 5.0 };
    return !candle.is_red(); // должно быть false 
}

// Тесты для метода is_green
bool test_is_green_1()
{
    std::cout << " test_is_green_1";
    Candle candle{ 5.0, 10.0, 4.0, 10.0 };
    return candle.is_green(); // должно быть true
}

bool test_is_green_2()
{
    std::cout << " test_is_green_2";
    Candle candle{ 10.0, 10.0, 4.0, 5.0 };
    return !candle.is_green(); // должно быть false
}

bool test_is_green_3()
{
    std::cout << " test_is_green_3";
    Candle candle{ 5.0, 10.0, 4.0, 5.0 };
    return !candle.is_green(); // должно быть false
}


void initTests()
{
    // Тесты для body_contains
    tests.push_back(test_body_contains_1);
    tests.push_back(test_body_contains_2);
    tests.push_back(test_body_contains_3);

    // Тесты для contains
    tests.push_back(test_contains_1);
    tests.push_back(test_contains_2);
    tests.push_back(test_contains_3);
   
    // Тесты для full_size
    tests.push_back(test_full_size_1);
    tests.push_back(test_full_size_2);
    tests.push_back(test_full_size_3);

    // Тесты для body_size
    tests.push_back(test_body_size_1);
    tests.push_back(test_body_size_2);
    tests.push_back(test_body_size_3);

    // Тесты для  is_red
    tests.push_back(test_is_red_1);
    tests.push_back(test_is_red_2);
    tests.push_back(test_is_red_3);

    // Тесты для is_green 
    tests.push_back(test_is_green_1);
    tests.push_back(test_is_green_2);
    tests.push_back(test_is_green_3);
}

int launchTests()
{
    int total = 0;
    int passed = 0;

    for (const auto& test : tests)
    {
        std::cout << "test #" << (total + 1);

        if (test())
        {
            passed += 1;
            std::cout << " passed\n";
        }
        else
        {
            std::cout << " failed\n";
        }
        total += 1;
    }

    std::cout << "\ntests " << passed << "/" << total << " passed!" << std::endl;

    //0 = success
    return total - passed;
}

int main()
{
    initTests();
    return launchTests();
}
