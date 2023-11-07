#include <iostream>
#include "Temperature.h"


int main()
{
    Temperature tempCel = 21.3_deg;
    std::cout << tempCel << std::endl;
    tempCel.ConvertToFahrenheit();
    std::cout << tempCel << std::endl;
    tempCel.ConvertToCelsius();
    std::cout << tempCel << std::endl;

    tempCel.ConvertToFahrenheit();
    std::cout << tempCel << std::endl;
    tempCel.ConvertToKelvin();
    std::cout << tempCel << std::endl;
    tempCel.ConvertToFahrenheit();
    std::cout << tempCel << std::endl;

    std::cout << tempCel.GetCelsius() << std::endl;
    std::cout << tempCel << std::endl;

    Temperature tempFah = 87.0_f;
    std::cout << tempFah << std::endl;

    std::cout << tempFah.GetCelsius() << std::endl;
    
    tempFah.ConvertToKelvin();
    std::cout << tempFah << std::endl;

    std::cout << (45.0_deg - 300.0_K) << std::endl;

    Temperature tempCpy = tempFah;
    std::cout << tempCpy << std::endl;

    tempCpy = tempCel;
    std::cout << tempCpy << std::endl;
}