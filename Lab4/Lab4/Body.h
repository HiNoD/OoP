#pragma once

class CBody
{
public:
	CBody(const std::string & type, double density);

	virtual double GetDensity() const = 0;
	virtual double GetVolume() const = 0;
	virtual double GetMass() const = 0;
	std::string ToString() const;

protected:
	virtual void AppendProperties(std::ostream & strm) const = 0;
	double m_density = 0;

private:
	std::string m_type;
};