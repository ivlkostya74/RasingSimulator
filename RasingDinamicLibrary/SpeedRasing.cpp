



#include "SpeedRasing.h"
#include <iostream> 
#include <string>
#include <algorithm>
#include <cstdlib>


void SpeedRasing::OutputTransport(bool isAirVehicle)
{
	if (isAirVehicle)
	{
		for (int i = 4; i < vehicles.size(); ++i)
		{
			std::cout << i - 3 << ". " << vehicles[i].get()->r_transportName() << std::endl;
		}
	}
	else
	{
		for (int i = 0; i < vehicles.size() - 3; ++i)
		{
			std::cout << i + 1 << ". " << vehicles[i].get()->r_transportName() << std::endl;
		}
	}
}

void SpeedRasing::SortingMapContainer()
{
	std::copy(prizes.begin(), prizes.end(),
		std::back_inserter<std::vector<std::pair<std::string, int>>>(s_prizes));

	std::sort(s_prizes.begin(), s_prizes.end(),
		[](const std::pair<std::string, int>& l, const std::pair<std::string, int>& r)
		{
			if (l.second != r.second)
			{
				return l.second < r.second;
			}

	return l.first < r.first;
		});
}

void SpeedRasing::OutputRegisteredTransport()
{
	std::cout << "����������� ����������: ";
	for (int i = 0; i < regTransport.size(); ++i)
	{
		std::cout << regTransport[i].get()->r_transportName() << (i < regTransport.size() - 1 ? ", " : "");
	}
	std::cout << std::endl;
}

void SpeedRasing::CalculationOfRacePassing()
{
	int timeRace = 0;

	int regTransSize = regTransport.size();
	int distanceRest = 0;
	int remains = 0;
	int stops = 0;
	int rest = 0;
	int movement = 0;
	for (int i = 0; i < regTransSize; ++i)
	{
		auto tr = regTransport[i];
		int speed = tr.get()->r_speed();
		int dtbr = tr.get()->r_continuousMovementTime();
		int duration = tr.get()->r_durationOfRest();



		if (tr.get()->r_type() == "GroundTransport")
		{
			distanceRest = speed * dtbr;
			stops = distance / distanceRest;

			if (distance != stops * distanceRest)
			{
				remains = distance - stops * distanceRest;
			}

			if (tr.get()->r_transportName() == "�������")
			{
				if (stops > 1)
				{
					rest = duration + (stops - 2) * 8;
				}
				else if (stops == 1)
				{
					rest = duration;
				}
				movement = stops * dtbr;

				double lastPush = 0;
				if (remains != 0)
				{
					lastPush = remains / speed;
					timeRace = rest + movement + lastPush;
				}
				else
				{
					timeRace = rest + movement;
				}
			}
			else if (tr.get()->r_transportName() == "������� ��������")
			{
				if (stops == 2)
				{
					rest = duration + 6.5;
				}
				else if (stops > 2)
				{
					rest = duration + 6.5 + (stops - 2) * 8;
				}
				else
				{
					rest = duration;
				}

				movement = stops * dtbr;

				double lastPush = 0;
				if (remains != 0)
				{
					lastPush = remains / speed;
					timeRace = rest + movement + lastPush;
				}
				else
				{
					timeRace = rest + movement;
				}
			}
			else if (tr.get()->r_transportName() == "�������")
			{
				if (stops > 0) rest = stops * duration;

				movement = stops * dtbr;

				double lastPush = 0;
				if (remains != 0)
				{
					lastPush = remains / speed;
					timeRace = rest + movement + lastPush;
				}
				else
				{
					timeRace = rest + movement;
				}
			}
			else if (tr.get()->r_transportName() == "������-���������")
			{
				if (stops == 1)
				{
					rest = duration;
				}
				else if (stops > 1)
				{
					rest = duration + (stops - 1) * 5;
				}
				movement = stops * dtbr;

				double lastPush = 0;
				if (remains != 0)
				{
					lastPush = remains / speed;
					timeRace = rest + movement + lastPush;
				}
				else
				{
					timeRace = rest + movement;
				}
			}
		}
		else if (tr.get()->r_type() == "AirTraansport")
		{
			if (tr.get()->r_transportName() == "����� �������")
			{
				if (distance < 1000)
				{
					timeRace = distance / speed;
				}
				else if (distance < 5000)
				{
					int newDistance = distance - (distance * 3 / 100);
					timeRace = newDistance / speed;
				}
				else if (distance < 10000)
				{
					int newDistance = distance - (distance * 10 / 100);
					timeRace = newDistance / speed;
				}
				else if (distance >= 100000)
				{
					int newDistance = distance - (distance * 5 / 100);
					timeRace = newDistance / speed;
				}
			}
			else if (tr.get()->r_transportName() == "����")
			{
				int newDistance = distance - (distance * 6 / 100);
				timeRace = newDistance / speed;
			}
			else if (tr.get()->r_transportName() == "�����")
			{
				int ratio = distance / 1000;
				int newDistance = distance - (distance * ratio / 100);
				timeRace = newDistance / speed;
			}
		}
		prizes[tr.get()->r_transportName()] = timeRace;
	}
	SortingMapContainer();
}

void SpeedRasing::ClearingData()
{
	regTransport.clear();
	prizes.clear();
	s_prizes.clear();
}

void SpeedRasing::StartOn()
{
	int value = 1;
	std::cout << "����� ���������� �� �����!" << std::endl;
	std::cout << "1. ����� ��� ��������� ����������" << std::endl;
	std::cout << "2. ��������� �����" << std::endl;
	std::cout << "3. ����� ��� �������� � ��������� �������" << std::endl;
	std::cout << "�������� ��� �����: ";
	std::cin >> typeRace;


	std::cout << "��������� ���������(������ ���� �������������): ";
	std::cin >> distance;
	system("cls");
	std::cout << "������ ���� �����������������  ������� 2 ����������" << std::endl;
	std::cout << "1. ����������� ����������" << std::endl;
	std::cout << "2. �����" << std::endl;
	std::cin >> value;

	system("CLS");

	switch (value)
	{
	case 1:
		TransportRegistration();
		break;

	case 2:
		break;


	default:
		break;
	}
}

void SpeedRasing::TransportRegistration()
{
	auto  bootsAllRaners = std::make_shared < BootsAllRaners>(6, 60, 10, "������-���������");
	auto  speedCamel = std::make_shared < SpeedCamel>(40, 10, 5, "������� ��������");
	auto camel = std::make_shared<Camel>(10, 30, 5, "�������");
	auto  centavr = std::make_shared < Centavr>(15, 8, 2, "�������");
	auto  carpetPlane = std::make_shared < CarpetPlane>(10, "����� �������");
	auto  eagle = std::make_shared < Eagle>(8, "����");
	auto  broom = std::make_shared < Broom>(20, "�����");


	//�������� �����
	if (typeRace == 1)
	{
		int value = 1;
		while (value != 0)
		{
			std::cout << "����� �� �������� �����������. ���������: " << distance << std::endl;

			//����� ������������������� ����������
			if (regTransport.size() != 0)
			{
				OutputRegisteredTransport();
			}
			//����� ����������
			OutputTransport(false);
			std::cout << "�������� ����������� ��� 0 ��� ��������� �����������: ";
			std::cin >> value;
			system("CLS");

			//��������� ���������� � ������ �����������
			switch (value)
			{
			case 1:
				regTransport.push_back(bootsAllRaners);
				break;

			case 2:
				regTransport.push_back(camel);
				break;

			case 3:
				regTransport.push_back(speedCamel);
				break;

			case 4:
				regTransport.push_back(centavr);
				break;

			case 0:
				break;

			default:
				break;
			}

			if (value != 0)
			{
				std::cout << regTransport.back().get()->r_transportName() << " �����������������!" << std::endl;
			}
		}
	}
	// ��������� �����
	else if (typeRace == 2)
	{
		int value = 1;
		while (value != 0)
		{
			std::cout << "��������� �����. �� ���������: " << distance << std::endl;

			//����� ������������������� ����������
			if (regTransport.size() != 0)
			{
				OutputRegisteredTransport();
			}
			//����� ����������
			OutputTransport(true);
			std::cout << "�������� ��������� ��� 0 ��� ��������� ����������� ";
			std::cin >> value;

			system("CLS");

			//��������� ���������� � ������ �����������
			switch (value)
			{
			case 1:
				regTransport.push_back(eagle);
				break;

			case 2:
				regTransport.push_back(broom);
				break;

			case 3:
				regTransport.push_back(carpetPlane);
				break;

			case 0:
				break;

			default:
				break;
			}
			if (value != 0)
			{
				std::cout << regTransport.back().get()->r_transportName() << " �����������������!" << std::endl;
			}
		}
	}

	// �������� � ��������� �����
	else if (typeRace == 3)
	{
		int value = 1;
		while (value != 0)
		{
			std::cout << "�������� ����� �� ���������: " << distance << std::endl;

			//����� ������������������� ����������
			if (regTransport.size() != 0)
			{
				OutputRegisteredTransport();
			}

			//����� ����������
			for (int i = 0; i < vehicles.size(); ++i)
			{
				std::cout << i + 1 << ". " << vehicles[i].get()->r_transportName() << std::endl;
			}
			std::cout << "�������� ��������� ��� 0 ��� ��������� ����������� ";
			std::cin >> value;

			system("CLS");

			//��������� ���������� � ������ �����������
			switch (value)
			{
			case 1:
				regTransport.push_back(bootsAllRaners);
				break;

			case 2:
				regTransport.push_back(camel);
				break;

			case 3:
				regTransport.push_back(speedCamel);
				break;

			case 4:
				regTransport.push_back(centavr);
				break;

			case 5:
				regTransport.push_back(eagle);
				break;

			case 6:
				regTransport.push_back(broom);
				break;

			case 7:
				regTransport.push_back(carpetPlane);
				break;

			case 0:
				break;

			default:
				break;
			}

			if (value != 0)
			{
				std::cout << regTransport.back().get()->r_transportName() << " �����������������!" << std::endl;
			}
		}
	}
	int choice = 0;
	std::cout << "1. ����������� ����������" << std::endl;
	std::cout << "2. ������ �����" << std::endl;
	std::cout << "��������� ��������: ";
	std::cin >> choice;

	system("CLS");

	switch (choice)
	{
	case 1:
		TransportRegistration();
		break;
	case 2:
		RaceResults();
		break;
	default:
		break;
	}
}

void SpeedRasing::RaceResults()
{
	std::cout << "��������� �����: " << std::endl;
	CalculationOfRacePassing();

	int viktoris = 1;
	for (auto const& pair : s_prizes)
	{
		std::cout << viktoris++ << ". ";
		std::cout << pair.first << "   �����: " << pair.second << std::endl;
	}

	std::cout << std::endl;

	int value = 0;
	std::cout << "1. ����� �����?" << std::endl;
	std::cout << "2. �����" << std::endl;
	std::cin >> value;

	switch (value)
	{
	case 1:
		ClearingData();
		system("cls");
		StartOn();
		break;

	case 2:
		break;

	default:
		break;
	}
}




