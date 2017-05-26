#pragma once
#include "vector"
class CCar
{
public:
	CCar();

	int GetSpeed() const;
	int GetStatus() const;
	int GetGear() const;
	bool IsTurnedOn() const;
	bool TurnOnEngine();
	bool TurnOffEngine();
	bool SetGear(int gear);
	bool SetSpeed(int speed);

private:
	enum State {MOVE_BACK, MOVE_FORWARD, STAND};

	State CarStatus() const;
	int m_speed;
	int m_gear;
	bool m_isEngine;
	bool m_moveBack;
	std::vector<std::pair<int, int>> m_restrictions;
};

