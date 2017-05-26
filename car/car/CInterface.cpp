#include "stdafx.h"
#include "CInterface.h"
#include <iostream>
#include <boost/algorithm/string.hpp>
#include <boost/algorithm/string/split.hpp>

using namespace std;

void CInterface::Help() const
{
	cout << "Commands for machine control:" << endl;	
	cout << "EngineOn - to switch on the engine" << endl;
	cout << "EngineOff - to switch off the engine " << endl;
	cout << "EXIT - to end the programm" << endl;
	cout << "Help - to display help" << endl;
	cout << "Info - to display information about the machine" << endl;
	cout << "SetSpeed X - to set the speed" << endl;
	cout << "SetGear X - to set the gear" << endl;
}

void CInterface::Info() const
{
	if (m_car->IsTurnedOn)
	{
		cout << "Engine is turn on" << endl;
	}
	else
	{
		cout << "Engine is turn off" << endl;
	}
	cout << "Car has the " << m_car->GetSpeed() << "speed" << endl;
	cout << "Car has the " << m_car->GetGear() << "gear" << endl;
	int Status = m_car->GetStatus();
	if (Status == -1)
	{
		cout << "The machine moves backward" << endl;
	}
	else if (Status == 0)
	{
		cout << "The machine stay" << endl;
	}
	else if (Status == 1)
	{
		cout << "The machine moves forward" << endl;
	}
}

bool CInterface::SetCommand()
{
	cout << "Please enter command" << endl;
	cout << ">>";
	string command;
	vector<string> instructions;
	getline(cin, command);
	boost::split(instructions, command, boost::is_any_of(" "));
	string nameCommand = instructions[0];
	if (nameCommand == "EXIT")
	{
		return false;
	}
	else if (nameCommand == "Help")
	{
		Help();
	}
	else if (nameCommand == "EngineOn")
	{
		if (!m_car->TurnOnEngine())
		{
			cout << "It is impossible to turn on the engine" << endl;
		}
	}
	else if (nameCommand == "EngineOff")
	{
		if (!m_car->TurnOffEngine())
		{
			cout << "It is impossible to turn off the engine" << endl;
		}
	}
	else if (nameCommand == "SetSpeed")
	{
		if (!m_car->SetSpeed(atoi(instructions[1].c_str())))
		{
			cout << "It is impossible to change the speed" << endl;
		}
	}
	else if (nameCommand == "SetGear")
	{
		if (!m_car->SetGear(atoi(instructions[1].c_str)))
		{
			cout << "It is impossible to shift gears" << endl;
		}
	}
	else if (nameCommand == "Info")
	{
		Info();
	}
	else
	{
		cout << "Entered unkown command" << endl;
	}
	return true;
}

