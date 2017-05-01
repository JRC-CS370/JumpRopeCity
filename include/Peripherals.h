#include <iostream>
#include "miniat/miniat.h"
#include "Player.h"


#ifndef PERIPHERALS_H
#define PERIPHERALS_H

void peripherals_cleanup();

    /*
    This function will deal with the cleanup and removal of data from
    the peripherals.

    Arguments: nothing
    Returns: nothing
    */


void peripherals_clock(miniat *m, Player &p, Map &theMap);

    /*
    Peripherals_clock deals with everything to do with the peripherals. It
    deals with the STORing and LOADing from the peripheral pins.

    Arguments: miniat *m
    Returns: nothing
    */


#endif
