#include "stat.hpp"
#include "format.hpp"

//void numCores(){ 
//}

void open_file(){
  ifstream systemStat("/proc/stat");

  if(!systemStat.is_open()){
    cerr << "Aborted"<< endl;
    exit(EXIT_FAILURE);
  }
}
void close_flie(){}

int Interupts(int IntrNum){
  ifstream statData("/proc/stat");
  string currentline;
  if(!statData.is_open()){
    cerr << "Aborted"<< endl;
    exit(EXIT_FAILURE);
  }
  while(getline( statData, currentline )){
    string search;
    stringstream linestream(currentline);
    getline(linestream, search, ' ');
    if(search == "intr"){
      linestream>>IntrNum;
      IntrNum = IntrNum/1000000000;
      return IntrNum;
    }
    
  }
statData.close();
return -1 ;
}

int Context(int ctxtNum){
  ifstream statData("/proc/stat");
  string currentline;
  if(!statData.is_open()){
    cerr << "Aborted"<< endl;
    exit(EXIT_FAILURE);
  }
  while(getline( statData, currentline )){
    string search;
    stringstream linestream(currentline);
    getline(linestream, search, ' ');
    if(search == "intr"){
      linestream>>ctxtNum;
      ctxtNum = ctxtNum/1000000000;
      return ctxtNum;
    }
    
  }
return -1 ;
}

int Page(int PageRatio){
  ifstream statData("/proc/stat");
  string currentline;
  if(!statData.is_open()){
    cerr << "Aborted"<< endl;
    exit(EXIT_FAILURE);
  }
  while(getline( statData, currentline )){
    string search;
    stringstream linestream(currentline);
    getline(linestream, search, ' ');
    if(search == "Page"){
      int PageIn;
      int PageOut;
      linestream>>PageIn>>PageOut;
      PageRatio = PageIn/PageOut;
      return PageRatio;
    }
    
  }
statData.close();
return -1;
}
int Swap(int SwapRatio){
  ifstream statData("/proc/stat");
  string currentline;
  if(!statData.is_open()){
    cerr << "Aborted"<< endl;
    exit(EXIT_FAILURE);
  }
  while(getline( statData, currentline )){
    string search;
    stringstream linestream(currentline);
    getline(linestream, search, ' ');
    if(search == "swap"){
      int SwapIn;
      int SwapOut;
      linestream>> SwapIn >>SwapOut;
      SwapRatio = SwapIn/SwapOut;
      return SwapRatio;
    }
    
  }
  statData.close();
return -1;
}

int getCPUNum(int NumCor){
  ifstream statData("/proc/stat");
    string Currentline;
    if(!statData.is_open()){
      cerr << "Could not open file.... exitting..." << endl;
      exit(EXIT_FAILURE);
    }
    getline(statData, Currentline);
    while(getline(statData, Currentline)){
      stringstream linestream(Currentline);
      string token;
      getline(linestream, token, ' ');
      if(token[0] == 'c' && token[1] == 'p' && token[2] == 'u' && (token[3])){
        NumCor++;
      }

    }
    statData.close();
    return NumCor;
}

void getCPUInfo(){
    ifstream statData("/proc/stat");
    string Currentline;
    if(!statData.is_open()){
      cerr << "Could not open file.... exitting..." << endl;
      exit(EXIT_FAILURE);
    }
    //getline(statData, Currentline);
    int i=0;
    while(getline(statData, Currentline)){
      stringstream linestream(Currentline);
      string token;
      long long unsigned int userNumC;
      long long unsigned int niceNumC;
      long long unsigned int systemNumC;
      long long unsigned int idleNumC;
      float total;
      getline(linestream, token, ' ');
      if(token[0] == 'c' && token[1] == 'p' && token[2] == 'u' && (token[3])){
        i++;
        linestream >> userNumC >> niceNumC>> systemNumC >> idleNumC;
        total = userNumC + niceNumC + systemNumC + idleNumC;
        userNumC = userNumC/total * 100;
        niceNumC = niceNumC/total * 100;
        systemNumC = systemNumC/total * 100;
        idleNumC = idleNumC/total * 100;
        cout<<"CPU"<< i <<setw(19)<< userNumC << setw(20) << idleNumC <<setw(20)<< systemNumC <<setw(20)<< niceNumC <<endl;
      }

    }
    statData.close();
}



void interuptPage_info(){
  dashLine();
  int PageRatio;
  int SwapRatio;
  int IntrNum;
  int ctxtNum;
  cout << "Page in/out ratio: "<<Page(PageRatio)<< "                 Swap in/out ratio:"<<Swap(SwapRatio)<< endl;
  cout << "Interrupts serviced: "<< Interupts(IntrNum) <<" Billions       Context switch counts: "<< Context(ctxtNum) <<" billions"<< endl;

}

void CPU_output(){
  dashLine();
  int NumC;
  cout << "Total CPU Cores: " << getCPUNum(NumC) <<endl;
  dashLine();
  cout << "CPU" << setw(20) << "Busy" << setw(20) << "Idle" << setw(20) << "System" << setw(20) << "Nice" << endl;
  getCPUInfo();
}