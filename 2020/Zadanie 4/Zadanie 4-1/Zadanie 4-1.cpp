#include <iostream>
#include <fstream>
#include <array>
#include <string>

#define DATA_FILE "pary.txt" // przyklad pary 
#define DATA_SIZE 100

using namespace std;

bool isPrime(int number) {
    bool prime_flag = true;

    if (number > 1) {
        for (size_t i = 2; i < number; i++)
        {
            if (number % i == 0) {
                prime_flag = false;
            }
        }
    }
    else {
        prime_flag = false;
    }

    return prime_flag;
}

array<int, 2> goldbach(int number) {
    array<int, 2> result_numbers = { number };
    int p = 1, q = number - 1;

    if (number > 3 && number % 2 == 0) {
        while (!isPrime(p) || !isPrime(q)) {
            if (!isPrime(p) || !isPrime(q)) {
                p++;
                q--;
            }
        }
    }

    result_numbers = { p, q };

    return result_numbers;
}

int main()
{
    ifstream data(DATA_FILE);

    for (size_t i = 0; i < DATA_SIZE; i++)
    {
        int number;
        string text;

        data >> number >> text;

        if (number % 2 == 0) {
            array<int, 2> prime_sum = goldbach(number);

            cout << number << " " << prime_sum.at(0) << " " << prime_sum.at(1) << endl;
        }
    }

    return 0;
}