#include "uptime.hpp"
#include "format.hpp"
#include "stat.hpp"

void TimeFormat(int seconds){
  int hour = seconds / 3600;
  int minute = (seconds % 3600) / 60;
  seconds = seconds % 60;
  cout <<  hour << " Hours " << minute << " Minutes " << seconds <<" Seconds"<< endl;

}

void energy_Output(int active , int idle){
  int NumC;
  active = 60 * (active-idle/ getCPUNum(NumC) ) /(100000); //cpu num
  idle = 10 * idle /100000;
  
  dashLine();
  cout<< "ENERGY"<< setw(44) <<"In Active State: "<<active << " MJoules" <<endl;
  cout<< setw(50) <<"In Idle State: "<<idle<< " MJoules" << endl;
  dashLine();


}

void system_Time(){
  
  ifstream systemTimeInfo("/proc/uptime"); // open /proc/uptime and name

  if(!systemTimeInfo.is_open()){
    cerr << "Aborted"<< endl;
    exit(EXIT_FAILURE);
  }
  float active;
  float idle;
  systemTimeInfo >> active >> idle;
  systemTimeInfo.close();
  
  dashLine();
  cout <<"SYSTEM                 UP for ";
  TimeFormat(active); //pass by referance find
  cout <<"                     IDLE for ";
  TimeFormat(idle);
  
  energy_Output(active,idle);
  
}




