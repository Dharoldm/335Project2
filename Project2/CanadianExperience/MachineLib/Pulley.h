#pragma once
#include <memory>
#include <vector>
#include "Motor.h"
#include "RotationSink.h"
#include "RotationSource.h"

class CPulley : public CComponent, public CRotationSink, public CRotationSource
{
public:
	/** \brief Default constructor disabled */
	CPulley() = delete;
	/** \brief Copy constructor disabled */
	CPulley(const CPulley &) = delete;
	/** \brief Assignment operator disabled */
	void operator=(const CPulley &) = delete;

	CPulley(double radius);
	virtual ~CPulley();
	void Draw(Gdiplus::Graphics *graphics, Gdiplus::Point position) override;

	void SetSource(CPulley * source);
	void SetSink(std::shared_ptr<CPulley> sink);

	virtual void Rotate(double angle) override;

	double GetRadius() { return mRadius; }


private:
	CPulley * mSource = nullptr;
	std::vector<std::shared_ptr<CPulley>> mSinks;
	double mRadius = 0;
};

