#include "stdafx.h"
#include "Component.h"

using namespace Gdiplus;

CComponent::CComponent()
{
}


CComponent::~CComponent()
{
}

void CComponent::Draw(Gdiplus::Graphics *graphics, Gdiplus::Point position)
{
	//TODO extrapolate component position based off machine position
	CPolygon::DrawPolygon(graphics, position.X+mPosition.X, position.Y+mPosition.Y);
}

void CComponent::SetPosition(int x, int y)
{
	mPosition = Point(x, y);
}