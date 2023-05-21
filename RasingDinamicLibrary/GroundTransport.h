#pragma once
#include "AllTrsnsport.h"
class GroundTransport :
    public AllTrsnsport
{
protected:
    RACINGDYNAMICLIBRARY_API   GroundTransport(int speed, int dtbr, int duration, std::string transportName);
};
