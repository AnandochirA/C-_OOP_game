//Anand
//CS142
//Fall2023

#ifndef FLASHYPOWERUP_H
#define FLASHYPOWERUP_H

#include "powerup.h"

class FlashyPowerup: public Powerup
{
 public:
    enum {FRAMES_PER_COLOR = 10, MAX_COLORS=6};
    //should multiply to get Powerup::MAX_FRAMES_IN_ANIMATION = 60

    FlashyPowerup () : Powerup () 
    {
        colors_[0] = colors_[2] = colors_[4] = BLACK;
        colors_[1] = colors_[3] = colors_[5] = WHITE;
    }
	
    FlashyPowerup (const FlashyPowerup& c) = delete;

    FlashyPowerup (int x, int y, int theRadius, const char* txt="") : 
    Powerup (x, y, theRadius, txt) 
    {
        colors_[0] = colors_[2] = colors_[4] = BLACK;
        colors_[1] = colors_[3] = colors_[5] = WHITE;
    } 

    FlashyPowerup& operator= (const FlashyPowerup& c) = delete;

    void animate() override; //Added override
    int value () const override { return 5; } //Added override
 private:
    SSDL_Color colors_ [MAX_COLORS]; 
};

#endif
