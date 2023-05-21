#pragma once
#include "GroundTransport.h"
class Camel :
    public GroundTransport
{
public:
    RACINGDYNAMICLIBRARY_API Camel(int speed, int dtbr, int duration, std::string transportName);
};

