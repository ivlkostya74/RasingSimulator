
#include "AllTrsnsport.h"


AllTrsnsport::AllTrsnsport(std::string type, int speed, int continuousMovementTime, int durationOfRest, std::string transportName)
	: type(type), speed(speed), continuousMovementTime(continuousMovementTime), durationOfRest(durationOfRest), transportName(transportName) {}

std::string AllTrsnsport::r_transportName() const
{
	return transportName;
}

std::string AllTrsnsport::r_type() const
{
	return type;
}

int AllTrsnsport::r_speed() const
{
	return speed;

}


int AllTrsnsport::r_continuousMovementTime() const
{
	return continuousMovementTime;
}

int AllTrsnsport::r_durationOfRest() const
{
	return durationOfRest;
}

