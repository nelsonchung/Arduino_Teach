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

#ifndef Timer_h
#define Timer_h

#include <inttypes.h>
#include "Event.h"

#define MAX_NUMBER_OF_EVENTS (10)

#define TIMER_NOT_AN_EVENT (-2)
#define NO_TIMER_AVAILABLE (-1)

#define DEFAULT_ENABLE       1
#define DEFAULT_DELAYTIME    200
#define DEFAULT_LEDNUMBER    13
#define DEFAULT_TWINKLE      5 

class Led13Flash 
{

public:
    Led13Flash(void);
    Led13Flash(int lednumber, int delaytime, int twinkle);

    void start(void);
    void stop(void);
    void setlednumber(int lednumber);
    void setdelaytime(int delaytime);
    void settwinkletime(int twinkletime);
    void update(void);

protected:
    int m_led_number;
    int m_enable;
    int m_delaytime;
    int m_twinkletime;

};

#endif
