#include <systemc.h>
#include "channel.h"
using namespace std;

SC_MODULE(controller){
    sc_in<bool> clk;
    sc_in<bool> res;

    // Ile osób w pokoju
    int c1, c2, c3, c4;

    // Kolejka komunikatów
    sc_port<DoorEventIf> channel;

    // Wchodzi / wychodzi
    sc_in<bool> dir;

    // Światła w pokojach
    sc_out<bool> s1, s2, s3, s4;
    sc_out<bool> alarm;

    // Wyjście ile osób w pokoju
    sc_out<int> co1, co2, co3, co4;

    void operation();

    SC_CTOR(controller){
        SC_CTHREAD(operation, clk.pos());
        reset_signal_is(res, true);
    }
};
