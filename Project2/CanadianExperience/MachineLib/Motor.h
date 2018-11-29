#pragma once
#include "Component.h"
#include "RotationSource.h"

class CPolygon;
class CShape;
class CMotor : public CComponent, public CRotationSource
{
public:
	CMotor();
	/** \brief Copy constructor disabled */
	CMotor(const CMotor &) = delete;
	/** \brief Assignment operator disabled */
	void operator=(const CMotor &) = delete;
	virtual ~CMotor();
	void SetTime(double time);
	void Draw(Gdiplus::Graphics *graphics, Gdiplus::Point position) override;
	void SetBody(std::shared_ptr<CPolygon> body) { mBody = body; }
	void SetShaft(std::shared_ptr<CShape> shaft) { mShaft = shaft; }

private:
	std::shared_ptr<CPolygon> mBody = nullptr;
	std::shared_ptr<CShape> mShaft = nullptr;
};

