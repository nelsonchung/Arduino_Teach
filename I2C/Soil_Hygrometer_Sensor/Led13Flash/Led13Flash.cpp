/*
 *      This program is free software; you can redistribute it and/or modify
 *      it under the terms of the GNU General Public License as published by
 *      the Free Software Foundation; either version 2 of the License, or
 *      (at your option) any later version.
 *
 *      This program is distributed in the hope that it will be useful,
 *      but WITHOUT ANY WARRANTY; without even the implied warranty of
 *      MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *      GNU General Public License for more details.
 *
 *      You should have received a copy of the GNU General Public License
 *      along with this program; if not, write to the Free Software
 *      Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 *      MA 02110-1301, USA.
 */

/*  * * * * * * * * * * * * * * * * * * * * * * * * * * *
 Code by Simon Monk
 http://www.simonmonk.org
* * * * * * * * * * * * * * * * * * * * * * * * * * * * */

// For Arduino 1.0 and earlier
#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

#include "Led13Flash.h"

Led13Flash::Led13Flash(void){
    m_led_number = DEFAULT_LEDNUMBER;
    m_enable = DEFAULT_ENABLE;
    m_delaytime = DEFAULT_DELAYTIME;
    m_twinkletime = DEFAULT_TWINKLE;
}
Led13Flash::Led13Flash(int lednumber, int delaytime, int twinkletime){
    m_led_number = lednumber;
    m_enable = DEFAULT_ENABLE;
    m_delaytime = delaytime;
    m_twinkletime = DEFAULT_TWINKLE;
}

void Led13Flash::start(void){
    m_enable = 1;
}

void Led13Flash::stop(void){
    m_enable = 0;
}

void Led13Flash::setlednumber(int lednumber){
    m_led_number = lednumber;
}
void Led13Flash::setdelaytime(int delaytime){
    m_delaytime = delaytime;
}
void Led13Flash::settwinkletime(int twinkletime){
    m_twinkletime = twinkletime;
}

/*
void Led13Flash::update(void){
    digitalWrite(m_led_number, HIGH);
    if(m_enable){
        digitalWrite(m_led_number, HIGH);
        delay(m_delaytime);
        digitalWrite(m_led_number, LOW);
        delay(m_delaytime);
        digitalWrite(m_led_number, HIGH);
    }
    digitalWrite(m_led_number, HIGH);
}
*/
void Led13Flash::update(void){
    digitalWrite(m_led_number, HIGH);
    int cnt = 0;
    if(m_enable){
        for(cnt=0; cnt<m_twinkletime; cnt++){
            digitalWrite(m_led_number, HIGH);
            delay(m_delaytime);
            digitalWrite(m_led_number, LOW);
            delay(m_delaytime);
        }
    }
    digitalWrite(m_led_number, HIGH);
}
