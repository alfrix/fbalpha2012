/*************************************************************************

    Atari Slapstic decoding helper

**************************************************************************

    For more information on the slapstic, see slapstic.html, or go to
    http://www.aarongiles.com/slapstic.html

*************************************************************************/

#ifndef _BURN_DEVICES_SLAPSTIC_H
#define _BURN_DEVICES_SLAPSTIC_H

void SlapsticInit(INT32 chip);
void SlapsticReset(void);

INT32 SlapsticBank(void);
INT32 SlapsticTweak(INT32 offset);

void SlapsticScan(INT32 nAction);

#endif
