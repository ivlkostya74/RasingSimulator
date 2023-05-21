#pragma once
#include "GroundTransport.h"
class SpeedCamel :
    public GroundTransport
{
public:
    RACINGDYNAMICLIBRARY_API SpeedCamel(int speed, int dtbr, int duration, std::string transportName);
};
