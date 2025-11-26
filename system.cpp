#include "system.h"
#include <iostream>
using namespace std;

void SYSTEM::simulate(){
    int input = 0;

    while(true){
        cout << "==KONTROLER SWIATLA==\n";
        cout << "1. Drzwi CD1\n";
        cout << "2. Drzwi CD2\n";
        cout << "3. Drzwi CD3\n";
        cout << "4. Drzwi CD4\n";
        cout << "9. Zmiana kierunku\n";
        cout << "0. RESET\n";
        cout << "Wpisz swoj wybor: ";

        cin >> input;

        switch(input){
            case 1: {
                cd1_sig.write(true);
                wait();
                cd1_sig.write(false);
                break;
            }
            case 2: {
                cd2_sig.write(true);
                wait();
                cd2_sig.write(false);
                break;
            }
            case 3: {
                cd3_sig.write(true);
                wait();
                cd3_sig.write(false);
                break;
            }
            case 4: {
                cd4_sig.write(true);
                wait();
                cd4_sig.write(false);
                break;
            }
            case 9: {
                dir_sig.write(!dir_sig.read());
                wait();
                break;
            }
            case 0: {
                res_sig.write(true);
                wait();
                res_sig.write(false);
                break;
            }
        }

        wait(); // Odświeżenie wartości kontrolera
        cout << "\n\nS1: " << s1_sig.read() << " S2: " << s2_sig.read() << " S3: " << s3_sig.read() << " S4: " << s4_sig.read() << "\n";
        cout << "Alarm: " << alarm_sig.read() << "\n\n";
    }
}
