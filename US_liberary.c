#include "US_liberary.h"




void US_initi(void) {
     
    GIE = 1;
    PEIE = 1;
    RBIE = 1;
    RBIF = 0;
    
    TRISB0 = 0;
    LATB0 = 0;
    TRISB4 = 1;
    //TRISC = 0;
    //LATC = 0;

    TMR0 = 0;
    T08BIT = 0;
    T0CS = 0;
    PSA = 0;
    T0CONbits.T0PS = 7;
}

void US_get_distance(void) {

    while (!PORTBbits.RB4);
    TMR0ON = 1;
    while (PORTBbits.RB4);
    TMR0ON = 0;
    float x = TMR0 / 0.4352;
    TMR0 = 0;
    //float t = TMR0 * 0.5 * 256 / 1000000/2;
    // x(cm)= t* 340*100/10;

    if (x > 0 && x <= 5) { // 0-> 5 cm
        LATC0 = 1;
        LATC1 = 1;
        LATC2 = 1;
        LATC3 = 1;
    } else if (x > 5 && x <= 10) { // 5-> 10 cm
        LATC0 = 1;
        LATC1 = 1;
        LATC2 = 1;
        LATC3 = 0;
    } else if (x > 10 && x <= 15) { //10 -> 15 cm
        LATC0 = 1;
        LATC1 = 1;
        LATC2 = 0;
        LATC3 = 0;
    } else if (x > 15 && x <= 20) { //15 -> 20 cm 
        LATC0 = 1;
        LATC1 = 0;
        LATC2 = 0;
        LATC3 = 0;
    } else if (x > 20) { // > 20 cm
        LATC0 = 0;
        LATC1 = 0;
        LATC2 = 0;
        LATC3 = 0;
    }
}