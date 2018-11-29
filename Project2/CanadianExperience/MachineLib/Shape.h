#pragma once
#include "Component.h"
#include "RotationSink.h"

class CPolygon;
class CShape : public CComponent, public CRotationSink
{
public:
	CShape();
	/** \brief Copy constructor disabled */
	CShape(const CShape &) = delete;
	/** \brief Assignment operator disabled */
	void operator=(const CShape &) = delete;
	virtual void Rotate(double angle);
	virtual ~CShape();
};

