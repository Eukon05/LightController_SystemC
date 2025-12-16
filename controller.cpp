#include "controller.h"
using namespace std;

void controller::operation() {
    // Resetowanie
    c1 = 0;
    c2 = 0;
    c3 = 0;
    c4 = 0;

    s1.write(false);
    s2.write(false);
    s3.write(false);
    s4.write(false);
    alarm.write(false);

    co1.write(0);
    co2.write(0);
    co3.write(0);
    co4.write(0);

    wait();

    int qres = 0;
    // Pętla kontrolera
    while (true) {
        if(!channel->nb_read(qres)){
            wait();
            continue;
        }

        switch(qres){
            case 1: {
                if (dir){
                    c1++;
                }
                else {
                    c1--;
                }
                break;
            }
            case 2: {
                if (dir) {
                    c1--;
                    c2++;
                }
                else {
                    c2--;
                    c1++;
                }
                break;
            }
            case 3: {
                if (dir) {
                    c3--;
                    c4++;
                }
                else {
                    c4--;
                    c3++;
                }
                break;
            }
            case 4: {
                if (dir) {
                    c4--;
                }
                else {
                    c4++;
                }
                break;
            }
        }


        if (c1 > 0) s1.write(true); else if (c1 == 0) s1.write(false); else alarm.write(true);
        if (c2 > 0) s2.write(true); else if (c2 == 0) s2.write(false); else alarm.write(true);
        if (c3 > 0) s3.write(true); else if (c3 == 0) s3.write(false); else alarm.write(true);
        if (c4 > 0) s4.write(true); else if (c4 == 0) s4.write(false); else alarm.write(true);

        co1.write(c1);
        co2.write(c2);
        co3.write(c3);
        co4.write(c4);
        wait();
    }
}
