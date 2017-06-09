#pragma once
#include <string>
#include <vector>
#include "Config.h"
#include "Color.h"
#include <memory>

enum TRIANGLE_POINT { FIRST = 0, SECOND = 1, THIRD = 2 };

using point = std::pair<float, float>;
class IShape
{
public:
	virtual ~IShape() = default;
	virtual float GetArea() const = 0;

	virtual float GetPerimeter() const = 0;

	virtual Color GetLineColor() const = 0;
	virtual std::string GetDescription() const = 0;
	
	virtual std::string GetName() const = 0;
};