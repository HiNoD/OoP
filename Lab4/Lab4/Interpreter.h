#pragma once

#include "Cone.h"
#include "Cylinder.h"
#include "Parallelepiped.h"
#include "Sphere.h"
#include "Compound.h"

class CBodyFactory
{
public:
	std::unique_ptr<CBody> CreateBody(std::string const & name);
private:
	CCompound CreateCompound();
	double GetData(std::string const & type);

	unsigned nestingLevel = 0;
};

//TODO::::������� ���-�� ����
class CInterpreter
{
public:
	void SetBody(std::string const & name); 
	void DisplaySummaryInfo();

private:
	std::vector<std::unique_ptr<CBody>> m_bodies;
	CBodyFactory m_bodyFactory;
};

