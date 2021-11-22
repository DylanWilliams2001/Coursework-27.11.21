#include "meminfo.hpp"
#include "format.hpp"



int getMemTotal(int MemTotal){
  ifstream memInfoData("/proc/meminfo");
  string currentline;
  if(!memInfoData.is_open()){
    cerr << "Aborted"<< endl;
    exit(EXIT_FAILURE);
  }
  while(getline( memInfoData, currentline )){
    string search;
    stringstream linestream(currentline);
    getline(linestream, search, ' ');
    if(search == "MemTotal:"){
      linestream>>MemTotal;
      MemTotal = MemTotal/1024;
      return MemTotal;
    }
    
  }
return -1;
}

int getMemFree(int MemFree){
  ifstream memInfoData("/proc/meminfo");
  string currentline;
  if(!memInfoData.is_open()){
    cerr << "Aborted"<< endl;
    exit(EXIT_FAILURE);
  }
  while(getline( memInfoData, currentline )){
    string search;
    stringstream linestream(currentline);
    getline(linestream, search, ' ');
    if(search == "MemFree:"){
      linestream>>MemFree;
      MemFree = MemFree/1024;
      return MemFree;
    }
    
  }
return -1;
}

int getCachMem(int CachMem){
  ifstream memInfoData("/proc/meminfo");
  string currentline;
  if(!memInfoData.is_open()){
    cerr << "Aborted"<< endl;
    exit(EXIT_FAILURE);
  }
  while(getline( memInfoData, currentline )){
    string search;
    stringstream linestream(currentline);
    getline(linestream, search, ' ');
    if(search == "Cached:"){
      linestream>>CachMem;
      CachMem = CachMem/1024;
      return CachMem;
    }
    
  }
return -1;
}

int getBuffMem(int BuffMem){
  ifstream memInfoData("/proc/meminfo");
  string currentline;
  if(!memInfoData.is_open()){
    cerr << "Aborted"<< endl;
    exit(EXIT_FAILURE);
  }
  while(getline( memInfoData, currentline )){
    string search;
    stringstream linestream(currentline);
    getline(linestream, search, ' ');
    if(search == "Buffers:"){
      linestream>>BuffMem;
      BuffMem = BuffMem/1024;
      return BuffMem;
    }
    
  }
return -1;
}


void meminfo_output(){
  dashLine();
  int MemTotal;
  int MemFree;
  int CachMem;
  int BuffMem;
  ;
  cout << "MEMORY      Total: "<< getMemTotal(MemTotal)<<" Mb" << endl << "             Free: "<< getMemFree(MemFree)<<" Mb"  <<endl << "           Cached: "<< getCachMem(CachMem)<<" Mb"  <<endl << "         Buffered: " << getBuffMem(BuffMem) <<" Mb" << endl;

}
