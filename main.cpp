#include<systemc.h>
#include "system.h"
using namespace std;

int sc_main(int argc, char* argv[]){
    SYSTEM* sys = new SYSTEM("sys");
    sc_start();
    return 0;
}
