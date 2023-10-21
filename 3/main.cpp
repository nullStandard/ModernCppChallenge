// it's better to use gcd to implement lcm,
// using std::accumulate for multiple input numbers

#include <iostream>
#include <map>
#include <algorithm>

using InputNumber = unsigned int;
using LastMultiple = unsigned int;

using Multiple = LastMultiple;
using OccuranceTimes = unsigned int;


int main()
{
   std::map<InputNumber, LastMultiple> inputMultiples;
   std::map<Multiple, OccuranceTimes> countMultiples;

   // user can add element as much as they want.
   // Do not forget to end the input with Ctrl+D
   int inputInt;
   while(std::cin >> inputInt)
      inputMultiples[inputInt] = inputInt;

   for(const auto &p : inputMultiples)
      std::cout << p.first << ": " << p.second << std::endl;
   
   bool LCMisFound = false;
   std::map<Multiple, OccuranceTimes>::iterator it;
   while(!LCMisFound)
   {
      for(auto& [key, value]: inputMultiples)
      {
         auto check = [&value](const auto& pair)
         {
            return pair.first == value;
         };
         if(std::find_if(countMultiples.begin(), countMultiples.end(), check) == countMultiples.end())
         {
            countMultiples[value] = 1;
         }
         else
         {
            countMultiples[value]++;
         }

         auto isLCM = [&inputMultiples](const std::pair<Multiple, OccuranceTimes> pair)
         {
            return pair.second == inputMultiples.size(); 
         };
         it = std::find_if(countMultiples.begin(), countMultiples.end(), isLCM);
         if(it != countMultiples.end())
         {
            LCMisFound = true;
            break;
         }
         value += key;
      }
   }

   std::cout << "LCM of " << std::flush;
   for(const auto& p: inputMultiples)
      std::cout << p.first << ", " << std::flush;
   
   std::cout << "is " << it->first << std::endl;

   return 0;
}