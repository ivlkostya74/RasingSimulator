#pragma once

#include "AirTransport.h"
class CarpetPlane :
    public AirTransport
{
public:
    RACINGDYNAMICLIBRARY_API CarpetPlane(int speed, std::string transportName);
};

