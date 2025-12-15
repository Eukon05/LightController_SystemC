#include <systemc.h>
#include "controller.h"
using namespace std;

SC_MODULE(SYSTEM){
    controller* contr;
    DoorChannel* channel;

    sc_clock clk_sig;
    sc_signal<bool> res_sig;
    sc_signal<bool> dir_sig;
    sc_signal<bool> s1_sig, s2_sig, s3_sig, s4_sig;
    sc_signal<bool> alarm_sig;

    void simulate();

    SC_CTOR(SYSTEM) : clk_sig("clk_sig", 10, SC_NS){
        channel = new DoorChannel("door_channel");
        contr = new controller("contr");
        contr->clk(clk_sig);
        contr->res(res_sig);
        contr->dir(dir_sig);

        contr->channel(*channel);

        contr->s1(s1_sig);
        contr->s2(s2_sig);
        contr->s3(s3_sig);
        contr->s4(s4_sig);

        contr->alarm(alarm_sig);

        SC_CTHREAD(simulate, clk_sig);
    }

    ~SYSTEM(){
        delete contr;
    }
};
