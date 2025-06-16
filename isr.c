/*
 * File:   isr.c
 * Author: Sindhu M
 * Desc: MicroWave Oven
 * Created on 8 February, 2025, 10:01 AM
 */

#include <xc.h>
#include "main.h"

extern int min, sec;

void __interrupt() isr(void)
{
    static unsigned int count = 0;
    
    if (TMR2IF == 1)
    {
        if (++count == 1250)
        {
                count = 0;
            if(sec > 0)
            {
                sec--;
            }
            else if(sec == 0 && min > 0)
            {
                min--;
                sec = 59;                
            }
        }        
        TMR2IF = 0;
    }
}