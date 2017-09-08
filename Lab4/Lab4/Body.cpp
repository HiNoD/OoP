#include "stdafx.h"
#include "Body.h"

CBody::CBody(const std::string & type, double density)
	: m_density(density)
	, m_type(type)
{
}

std::string CBody::ToString()const
{
	std::ostringstream strm;
	strm << m_type << ":" << std::endl << std::setprecision(10)
		<< "\tdensity = " << GetDensity() << std::endl
		<< "\tvolume = " << GetVolume() << std::endl
		<< "\tmass = " << GetMass() << std::endl;
	AppendProperties(strm);
	return strm.str();
}