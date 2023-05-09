
//NOTES:
// a2ra l-comments 3shan fe 7gat ktbaha mohma..
// fe 7gat zay l delay bta3 l moateer we aslob sho3lha lma t2abel obstkels m7taga a3dlha lma agrb..
// tsrof l brnamg lma kol sensor y2ra 7aga odamoo tmam kolohm sh3aleen sa7 >> ely a3dlo bs sho3`l l moater..


#include <stdio.h>
#include <stdlib.h>
#include"US_liberary.h"
#include "PWM.h"

float x;

void interrupt US() {

    if (RBIF) {

        if (PORTBbits.RB4) {
            TMR0ON = 1;
        } else if (!PORTBbits.RB4) {
            TMR0ON = 0;
            x = TMR0 / 0.4352;
            TMR0 = 0;
            //float t = TMR0 * 0.5 * 256 / 1000000/2;
            // x(cm)= t* 340*100/10;       
          //  if (x > 0 && x <= 10) { // 0-> 10 cm
                if ((!PORTBbits.RB5) && (PORTBbits.RB6)) { //tmam asht3lt //FE OBSKL MN L YMEEN
                    
                    pwm_set_duty(250);
                    pwm_start();
                    
                    LATA0 = 1;
                    LATA1 = 0;
                    LATB2 = 0;
                    LATB3 = 0;
                    
                    RBIF = 0; // ASHOOF HSHYLHA HYA WE A5WATHA WALA ASEBHA >> LMA AS3`L  3RBYA
                
                } else if ((PORTBbits.RB5) && (!PORTBbits.RB6)) { //tmam asht3lt //FE OBSKL MN L SHEMAL
                   
                    pwm_set_duty(250);
                    pwm_start();
                    
                    LATA0 = 0;
                    LATA1 = 0;
                    LATB2 = 1;
                    LATB3 = 0;
                    
                    RBIF = 0; // ASHOOF HSHYLHA HYA WE A5WATHA WALA ASEBHA >> LMA AS3`L  3RBYA
                
                } else if ((!PORTBbits.RB5) && (!PORTBbits.RB6)) { //tmam ash3lt //FE OBSKL MN L SHEMAL WE L YMEEN
                    
                    pwm_set_duty(0);
                    pwm_start();
                    
                    LATA0 = 0;
                    LATA1 = 0;
                    LATB2 = 0;
                    LATB3 = 0;
                    for(int i=0;i<10;i++)
                        __delay_ms(50);
                    
                    pwm_set_duty(250);
                    pwm_start();
                    
                    LATA0 = 1;
                    LATA1 = 0;
                    LATB2 = 0;
                    LATB3 = 1;
                    
                     for(int i=0;i<25;i++) // l moda de tt3dl lma ash3`l l 3rbya we agrb
                        __delay_ms(50);
                    
                    RBIF = 0; // ASHOOF HSHYLHA HYA WE A5WATHA WALA ASEBHA >> LMA AS3`L  3RBYA
                
                } else { //tmam asht3lt // FE OBSTKL MN ODAM BS MFEESH 7AGA YMEEN WALA SHEMAL 
                   
                    pwm_set_duty(250);
                    pwm_start();
                    
                    LATA0 = 0;
                    LATA1 = 0;
                    LATB2 = 1;
                    LATB3 = 0;
                    
                    RBIF = 0; // ASHOOF HSHYLHA HYA WE A5WATHA WALA ASEBHA >> LMA AS3`L  3RBYA
                }
            //}
        }
        RBIF = 0;
    }
}

void main() {

    OSCCON = 0x76;

    pwm_init();
    US_initi();

    TRISB5 = 1;
    TRISB6 = 1;

    //RIGHT MOTOR
    TRISA0 = 0; // FORWORD
    TRISA1 = 0;
    LATA0 = 0;
    LATA1 = 0;
    //LEFT MOTOR
    TRISB2 = 0; // FORWORD
    TRISB3 = 0;
    LATB2 = 0;
    LATB3 = 0;

    while (1) {

        pwm_set_duty(500);
        pwm_start();
        LATA0 = 1;
        LATA1 = 0;
        LATB2 = 1;
        LATB3 = 0;

        LATB0 = 1;
        __delay_ms(10);
        LATB0 = 0;
    }
}

