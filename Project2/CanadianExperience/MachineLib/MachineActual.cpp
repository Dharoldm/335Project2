#include "stdafx.h"
#include "MachineActual.h"
#include "Component.h"
#include "Motor.h"

using namespace Gdiplus;

CMachineActual::CMachineActual()
{
}


CMachineActual::~CMachineActual()
{
}

void CMachineActual::DrawMachine(Gdiplus::Graphics *graphics)
{
	for (auto component : mComponents)
	{
		component->Draw(graphics, mPosition);
	}
}

void CMachineActual::SetMachineFrame(int frame)
{
	//TODO call motor set time which will be able to move the stuff
	double time = (double)frame / (double)mFrameRate*mSpeed;
	mMotor->SetTime(time);
}

void CMachineActual::SetLocation(int x, int y)
{
	mPosition = Point(x, y);
}

void CMachineActual::SetFrameRate(double rate)
{
	mFrameRate = rate;
}

void CMachineActual::AddComponent(std::shared_ptr<CComponent> component)
{
	mComponents.push_back(component);
}

void CMachineActual::AddMotor(std::shared_ptr<CMotor> motor)
{
	mMotor = motor;
	AddComponent(motor);
}