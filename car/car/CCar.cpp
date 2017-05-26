#include "stdafx.h"
#include "CCar.h"
#include "iterator"
#include "iostream"


CCar::CCar()
	:m_speed(0)
	, m_gear(0)
	, m_isEngine(false)
	,  m_moveBack(false)
	, m_restrictions({ {0, 20}, 
	{ INT_MIN, INT_MAX },
	{ 0, 30 },
	{ 20, 50 },
	{ 30, 60 },
	{ 40, 90 },
	{ 50, 150 } })
{}

bool CCar::IsTurnedOn() const
{
	if (!m_isEngine)
	{
		return false;
	}
}

bool CCar::TurnOffEngine()
{
	if (m_isEngine && m_speed == 0 && m_gear == 0)
	{
		m_isEngine = false;
		return true;
	}
}

bool CCar::TurnOnEngine()
{
	if (!m_isEngine)
	{
		m_isEngine = true;
		m_speed = 0;
		m_gear = 0;
		return true;
	}
	return false;
}

bool CCar::SetGear(int gear)
{
	if ((m_gear < -1 || m_gear > 5) || (!m_isEngine && gear != 0))
	{
		return false;
	}
	if (m_gear == 0 && m_speed == 0)
	{
		m_moveBack = false;
	}
	if (gear == -1 && !m_moveBack && (m_gear == 0 || m_gear == 1) && m_speed == 0)
	{
		m_moveBack = true;
		m_gear = gear;
		return true;
	}
	if (m_gear == -1 && gear == 1 && m_moveBack && m_speed == 0)
	{
		m_moveBack = false;
		m_gear = gear;
		return true;
	}
	if (m_gear == -1 && gear == 0)
	{
		m_gear = gear;
		return true;
	}
	if (gear == 0)
	{
		m_gear = gear;
		return true;
	}
}

bool CCar::SetSpeed(int speed)
{
	if (m_isEngine && speed == 0)
	{
		return true;
	}
	if (m_isEngine)
	{
		if (m_gear == 0)
		{
			if (speed > m_speed)
			{
				return false;
			}
			m_speed = speed;
			return true;
		}
		else if (speed >= m_restrictions[m_gear + 1].first && speed <= m_restrictions[m_gear].second)
		{
			m_speed = speed;
			return true;
		}
	}
	return false;
}

CCar::State CCar::CarStatus() const
{
	if (m_speed == 0)
	{
		return State::STAND;
	}
	else if (m_speed != 0)
	{
		if (m_moveBack)
		{
			return State::MOVE_BACK;
		}
		else 
		{
			return State::MOVE_FORWARD;
		}
	}
}

int CCar::GetStatus() const
{
	auto state = CarStatus();
	if (state == MOVE_BACK)
	{
		return -1;
	}
	else if (state == MOVE_FORWARD)
	{
		return 1;
	}
	return 0;
}

int CCar::GetSpeed() const
{
	return m_speed;
}

int CCar::GetGear() const
{
	return m_gear;
}