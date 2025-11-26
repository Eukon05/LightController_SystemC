#include "controller.h"
using namespace std;

void controller::operation() {
    // Resetowanie
    c1 = 0;
    c2 = 0;
    c3 = 0;
    c4 = 0;

    p1 = false;
    p2 = false;
    p3 = false;
    p4 = false;

    s1.write(false);
    s2.write(false);
    s3.write(false);
    s4.write(false);
    alarm.write(false);

    wait();

    // Pętla kontrolera
    while (true) {
        if (cd1.read() && !p1) {
            if (dir) c1++; else c1--;
        }
        p1 = cd1.read();

        if (cd2.read() && !p2) {
            if (dir) c2++; else c2--;
        }
        p2 = cd2.read();

        if (cd3.read() && !p3) {
            if (dir) c3++; else c3--;
        }
        p3 = cd3.read();

        if (cd4.read() && !p4) {
            if (dir) c4++; else c4--;
        }
        p4 = cd4.read();

        if (c1 > 0) s1.write(true); else if (c1 == 0) s1.write(false); else alarm.write(true);
        if (c2 > 0) s2.write(true); else if (c2 == 0) s2.write(false); else alarm.write(true);
        if (c3 > 0) s3.write(true); else if (c3 == 0) s3.write(false); else alarm.write(true);
        if (c4 > 0) s4.write(true); else if (c4 == 0) s4.write(false); else alarm.write(true);

        wait();
    }
}
