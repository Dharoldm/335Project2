#include "stdafx.h"
#include "Cam.h"
const int SubSteps = 3;


CCam::CCam(double radius, int pins)
{
	mRadius = radius;
	mSteps = pins;
}


CCam::~CCam()
{
}

void CCam::Build()
{
	for (int i = 0; i < mSteps * SubSteps; i++)
	{
		double angle = 2 * M_PI * i / double(mSteps * SubSteps);
		double radius = mRadius;

		for (auto pin : mPins)
		{
			if (pin * SubSteps == i || pin * SubSteps == (i - 1))
			{
				radius = mRadius + mPinSize;
				break;
			}
		}

		AddPoint(radius * cos(angle), radius * -sin(angle));
	}
}