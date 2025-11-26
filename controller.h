#include <systemc.h>
using namespace std;

SC_MODULE(controller){
    sc_in<bool> clk;
    sc_in<bool> res;

    // Ile osób w pokoju
    int c1, c2, c3, c4;

    // Poprzedni stan drzwi
    bool p1, p2, p3, p4;

    // Drzwi między pokojami
    sc_in<bool> cd1, cd2, cd3, cd4;

    // Wchodzi / wychodzi
    sc_in<bool> dir;

    // Światła w pokojach
    sc_out<bool> s1, s2, s3, s4;
    sc_out<bool> alarm;

    void operation();

    SC_CTOR(controller){
        SC_CTHREAD(operation, clk.pos());
        reset_signal_is(res, true);
    }
};
