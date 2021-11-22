//#include <iostream>
//#include <cstdlib>
//#include <string>
//#include <fstream>
//#include <ctime>
#include <unistd.h>

#include "meminfo.hpp"
#include "format.hpp"
#include "stat.hpp"
#include "uptime.hpp"

using namespace std;

int main() {
  while (true){
    ScreenClear(); //Calls Screen clean
    CPU_output();
    interuptPage_info();
    meminfo_output();
    system_Time(); //Gets system up and idle times
    //energy_Output();
    usleep(500000); //500ms wait 
  }

}


// Reformat Tabbing
// make better
