#include "stdafx.h"
#include "Shape.h"


CShape::CShape()
{
}


CShape::~CShape()
{
}

void CShape::Rotate(double angle)
{
	CPolygon::SetRotation(angle);
}