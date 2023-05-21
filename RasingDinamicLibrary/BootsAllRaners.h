#pragma once
#include"GroundTransport.h"
class BootsAllRaners :
    public GroundTransport
{
public:
    RACINGDYNAMICLIBRARY_API  BootsAllRaners(int speed, int dtbr, int duration, std::string transportName);
};