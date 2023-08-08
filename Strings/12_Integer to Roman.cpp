#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main()
{
  return 0;
}

// subtraction method
string intToRoman(int num)
{
  vector<pair<int, string>> valueSymbols{
      {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"}, {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"}, {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}};

  string roman = "";

  for (auto &[value, symbol] : valueSymbols)
  {
    if (num == 0)
      break;
    while (num >= value)
    {
      num -= value;
      roman += symbol;
    }
  }
  return roman;
}