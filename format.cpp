#include "format.hpp"

void ScreenClear(){
  cout << "\033[2J\033[1;1H"; // Clears the Screen
}

void dashLine(){
  cout << "---------------------------------------------------------------------------------------------" << endl;
}
