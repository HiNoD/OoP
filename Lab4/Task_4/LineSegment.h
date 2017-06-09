#pragma once
#include "Shape.h"
#include "Point.h"

class CLineSegment final : public IShape
{
public:
	CLineSegment(Point const &p1, Point const &p2, Color const &color);

	float GetLength() const;

	Point GetFirstPoint() const;

	float GetAngle() const;


	float GetPerimeter() const override;
	float GetArea() const override;
	Color GetLineColor() const override;
	std::string GetDescription() const override;
	std::string GetName() const override;
private:
	Point m_firstPoint;
	Point m_secondPoint;
	Color m_color;
};