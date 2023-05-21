#pragma once
#ifdef RACINGDYNAMICLIBRARY_EXPORTS
#define RACINGDYNAMICLIBRARY_API __declspec(dllexport)
#else
#define RACINGDYNAMICLIBRARY_API __declspec(dllimport)
#endif

#include "SpeedRasing.h"
#include "AirTransport.h"
#include "AllTrsnsport.h"
#include"BootsAllRaners.h"
#include"Broom.h"
#include"Camel.h"
#include"CarpetPlane.h"
#include"Centavr.h"
#include"Eagle.h"
#include"GroundTransport.h"
#include"SpeedCamel.h"
#include <vector>
#include <map>
#include <iostream>


class  SpeedRasing
{
private:
	std::vector<std::shared_ptr<AllTrsnsport>> vehicles = {
	 std::make_shared < BootsAllRaners>(6, 60, 10, "������-���������"),
	 std::make_shared < SpeedCamel>(40, 10, 5, "������� ��������"),
	 std::make_shared<Camel>(10, 30, 5, "�������"),
	 std::make_shared < Centavr>(15, 8, 2, "�������"),
	 std::make_shared < CarpetPlane>(10, "����� �������"),
	 std::make_shared < Eagle>(8, "����"),
	 std::make_shared < Broom>(20, "�����"),
	};

	std::vector<std::shared_ptr<AllTrsnsport>> regTransport;
	std::map<std::string, int> prizes;
	std::vector<std::pair<std::string, int>> s_prizes;

	int typeRace;
	int distance;

	void OutputRegisteredTransport();

	void OutputTransport(bool isAirVehicle);

	void CalculationOfRacePassing();
	void SortingMapContainer();
	void ClearingData();

public:

	void TransportRegistration();
	RACINGDYNAMICLIBRARY_API void StartOn();
	void RaceResults();
};


