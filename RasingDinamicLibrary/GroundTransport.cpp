#include "GroundTransport.h"

GroundTransport::GroundTransport(int speed, int dtbr, int duration, std::string transportName)
	: AllTrsnsport("GroundTransport", speed, dtbr, duration, transportName) {}