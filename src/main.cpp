
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



void initTests()
{
    // Тесты для body_contains
    tests.push_back(test_body_contains_1);
    tests.push_back(test_body_contains_2);
    tests.push_back(test_body_contains_3);

   

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
