#pragma once
#include "VolumeBody.h"

class CCylinder final : public CVolumeBody
{
public:
	CCylinder(double density, double radius, double height);
	double GetVolume() const override;
};

