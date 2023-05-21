#pragma once
#include "AllTrsnsport.h"
class AirTransport :
    public AllTrsnsport
{
protected:
    RACINGDYNAMICLIBRARY_API  AirTransport(int speed, std::string transportName);
};

