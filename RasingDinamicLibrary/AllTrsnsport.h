

#pragma once
#ifdef RACINGDYNAMICLIBRARY_EXPORTS
#define RACINGDYNAMICLIBRARY_API __declspec(dllexport)
#else
#define RACINGDYNAMICLIBRARY_API __declspec(dllimport)
#endif
#include <string>
class AllTrsnsport
{
protected:
	std::string type;
	int speed;
	int continuousMovementTime;
	int durationOfRest;
	std::string transportName;

	RACINGDYNAMICLIBRARY_API	AllTrsnsport(std::string type, int speed,
		int continuousMovementTime, int durationOfRest, std::string transportName);

public:
	virtual ~AllTrsnsport() = default;


	std::string r_type() const;
	int r_speed() const;
	int r_continuousMovementTime() const;
	int r_durationOfRest() const;
	std::string r_transportName() const;

};

