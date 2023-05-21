#pragma once
#include "GroundTransport.h"
class Centavr :
    public GroundTransport
{
public:
    RACINGDYNAMICLIBRARY_API  Centavr(int speed, int dtbr, int duration, std::string transportName);
};

