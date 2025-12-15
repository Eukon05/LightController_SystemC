#include "system.h"
#include <iostream>
using namespace std;

const char* visualisation = R"(
---------------------
|         |         |
|         |         |
CD1  %d   CD2   %d    |
|         |         |
|         |         |
---------------------
|         |         |
|         |         |
|    %d   CD3   %d   CD4
|         |         |
|         |         |
---------------------
)";


void SYSTEM::simulate(){
    int input = 0;

    while(true){
        cout << "\033[2J\033[1;1H"; // wyczyszczenie konsoli
        cout << "==KONTROLER SWIATLA==\n";

        printf(visualisation, s1_sig.read(), s2_sig.read(), s3_sig.read(), s4_sig.read());
        cout << "\nStatus alarmu: " << (alarm_sig.read() ? "WŁĄCZONY!" : "wyłączony") << endl;
        cout << "Kierunek przechodzenia: " << (dir_sig.read() ? "w prawo" : "w lewo") << endl << endl;

        cout << "1. Drzwi CD1\n";
        cout << "2. Drzwi CD2\n";
        cout << "3. Drzwi CD3\n";
        cout << "4. Drzwi CD4\n";
        cout << "9. Zmiana kierunku\n";
        cout << "0. RESET\n";
        cout << "Wpisz swoj wybor: ";

        cin >> input;

        switch(input){
            case 1:
            case 2:
            case 3:
            case 4: {
                channel->nb_write(input);
                wait();
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
    }
}
