#pragma once
#include "SolidShape.h"
#include "Point.h"

class CCircle final : public ISolidShape
{
public:
	CCircle(Point const &p1, float radius, Color const &edgeColor, Color const &fillColor);
	Color GetLineColor() const override;
	std::string GetDescription()const override;
	Color GetColor() const override;
	float GetPerimeter() const override;
	float GetRadius() const;

	Point GetPointCenter() const;

	std::string GetName() const override;
	float GetArea() const override;
private:
	Point m_pointCenter;
	float m_radius;

	Color m_edgeColor;
	Color m_fillColor;
};