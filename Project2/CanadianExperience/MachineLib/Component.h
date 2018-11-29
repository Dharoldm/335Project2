#pragma once
#include "Polygon.h"
class CComponent : public CPolygon
{
public:

	CComponent();
	/** \brief Copy constructor disabled */
	CComponent(const CComponent &) = delete;
	/** \brief Assignment operator disabled */
	void operator=(const CComponent &) = delete;
	virtual ~CComponent();
	virtual void Draw(Gdiplus::Graphics *graphics, Gdiplus::Point position);
	void SetPosition(int x, int y);
	Gdiplus::Point GetPosition() { return mPosition; };

private:
	Gdiplus::Point mPosition;
};

