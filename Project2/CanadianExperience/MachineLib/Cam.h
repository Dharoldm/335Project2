#pragma once
#include <vector>
#include "Component.h"


class CCam : public CComponent
{
public:
	/** \brief Default constructor disabled */
	CCam() = delete;
	/** \brief Copy constructor disabled */
	CCam(const CCam &) = delete;
	/** \brief Assignment operator disabled */
	void operator=(const CCam &) = delete;
	CCam(double radius, int pins);
	virtual ~CCam();
	void Build();
	void SetPinSize(double size) { mPinSize = size; }
	void AddPin(int pin) { mPins.push_back(pin); }

private:
	std::vector<int> mPins;
	double mRadius=1;
	int mSteps=1;
	double mPinSize=4;
};

