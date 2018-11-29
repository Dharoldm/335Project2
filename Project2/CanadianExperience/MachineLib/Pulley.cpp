#include "stdafx.h"
#include <math.h>
#include "Pulley.h"
#include "Polygon.h"


using namespace Gdiplus;

CPulley::CPulley(double radius)
{
	mRadius = radius;
	Circle(mRadius);
}


CPulley::~CPulley()
{
}

void CPulley::Draw(Graphics *graphics, Point position)
{
	auto saveSM = graphics->GetSmoothingMode();
	graphics->SetSmoothingMode(SmoothingMode::SmoothingModeHighQuality);
	Pen linePen(Color::Black, 2);
	for (auto sink : mSinks)
	{
		double y = position.Y + sink->GetPosition().Y - position.Y+GetPosition().Y;
		double x = position.X + sink->GetPosition().X - position.X + GetPosition().X;
		double distance = sqrt(pow(x, 2) + pow(y, 2));
		double theta = atan2(position.Y + sink->GetPosition().Y - position.Y + GetPosition().Y, position.X + sink->GetPosition().X - position.X + GetPosition().X);
		//graphics->DrawLine(&linePen, position+GetPosition(), position+sink->GetPosition());
		double radius = ((double)sink->GetRadius()-3) -((double)mRadius-3);
		double prephi = (radius / distance);
		double phi = asin(prephi);
		//First Line
		double b = theta + phi + (M_PI / 2);
		Point p1 = GetPosition() + Point(mRadius*cos(b), mRadius*sin(b));
		Point p2 = sink->GetPosition() + Point(sink->GetRadius()*cos(b), sink->GetRadius()*sin(b));
		graphics->DrawLine(&linePen, position+p1, position + p2);
		//Second Line
		b = theta - phi - (M_PI / 2);
		p1 = GetPosition() + Point(mRadius*cos(b), mRadius*sin(b));
		p2 = sink->GetPosition() + Point(sink->GetRadius()*cos(b), sink->GetRadius()*sin(b));
		graphics->DrawLine(&linePen, position + p1, position + p2);
	}
	graphics->SetSmoothingMode(saveSM);
	CComponent::Draw(graphics, position);
}

void CPulley::SetSource(CPulley * source)
{
	mSource = source;
}
void CPulley::SetSink(std::shared_ptr<CPulley> sink)
{
	mSinks.push_back(sink);
	sink->SetSource(this);
}

void CPulley::Rotate(double angle)
{
	SetRotation(angle);
	for (auto pulley : mSinks)
	{
		pulley->Rotate(angle*(double)(mRadius/pulley->GetRadius()));
	}
	CRotationSource::RotateSinks(angle);
}