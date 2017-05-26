#pragma once
#include <memory>
#include "CCar.h"

class CInterface
{
public:
	bool SetCommand();
private:
	void Help() const;
	void Info() const;
	std::shared_ptr<CCar> m_car = std::make_shared<CCar>();
};