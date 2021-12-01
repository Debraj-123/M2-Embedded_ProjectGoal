/**
 * @file SeatHeatingApp.c
 * 
 */

#include "Activity_1.h"
#include "Activity_2.h"
#include "Activity_3.h"
#include "Activity_4.h"

int main(void)
{
    uint16_t temp;
    
    while(1)
    {
        if(activity1_LED()==1) //Check if both the switches are pressed
        {
           
            TurnLED_ON();//Turn LED ON
            temp=activity2_GetADC(); //Get the ADC value
            activity3_PWM(temp); //PWM output based on temperature
		    activity4_USARTWrite(temp); //To Serial monitor to print Temperature
            

        }
        else  //in all other cases
        {
            TurnLED_OFF();//Turn LED OFF
		    _delay_ms(200);
        }

    }
    return 0;
}