#include "stdafx.h"
#include "Motor.h"
#include "Polygon.h"
#include "Shape.h"
#include "Component.h"
#include "RotationSink.h"

using namespace Gdiplus;
using namespace std;

CMotor::CMotor() : CComponent::CComponent()
{
	//mBody = make_shared<CPolygon>();
	//mBody->AddPoint(0, 0);
	//mBody->Rectangle(0, 0, 50, 50);
	//mBody->SetColor(Color(68, 114, 196));

	//mShaft = make_shared<CShape>();
	//mShaft->SetPosition(GetPosition().X, GetPosition().Y);
	//mShaft->AddPoint(40, 40);
	//mShaft->Circle(20);
	//mShaft->SetColor(Color::Black);
	
}


CMotor::~CMotor()
{
}

void CMotor::Draw(Gdiplus::Graphics *graphics, Gdiplus::Point position)
{
	mBody->DrawPolygon(graphics, position.X+GetPosition().X, position.Y+GetPosition().Y);
	mShaft->Draw(graphics, position);
}

void CMotor::SetTime(double time)
{
	//TODO This will be give a time based on the frame rate and curr frame
	// Then it will move it sinks baded on that
	mShaft->SetRotation(time);
	CRotationSource::RotateSinks(time);
}