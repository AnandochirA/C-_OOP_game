//Anand
//CS142
//Fall2023

#ifndef POWERUP_H
#define POWERUP_H

#include "circle.h"

class Powerup: public Circle
{
 public:
    enum {MAX_FRAMES_IN_ANIMATION = 60};

    Powerup () : framesLeftInAnimation_ (0) {}
    Powerup (const Powerup& c) : Circle (c),
	framesLeftInAnimation_ (c.framesLeftInAnimation_)
    {
	}

    Powerup (int x, int y, int theRadius, const char* txt="") : 
    Circle (x, y, theRadius, txt), framesLeftInAnimation_ (0)
    {
    } 

    Powerup& operator= (const Powerup& c) = delete;

    bool isAnimated     () const { return framesLeftInAnimation_ > 0; }
    void startAnimation () { framesLeftInAnimation_ = MAX_FRAMES_IN_ANIMATION; }

    virtual void animate() = 0;
    virtual int value() const { return -1; } //changed virtual
 protected:
    int framesLeftInAnimation_;	   //How many frames till animation is over?
};

#endif //POWERUP_H
