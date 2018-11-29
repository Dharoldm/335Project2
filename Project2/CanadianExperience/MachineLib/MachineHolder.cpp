#include "stdafx.h"
#include "MachineHolder.h"
#include "Machine.h"
#include "MachineOneFactory.h"
#include "MachineActual.h"

using namespace std;

CMachineHolder::CMachineHolder() : CMachine()
{
	auto factory = make_shared<CMachineOneFactory>();
	mMachine = factory->CreateMachineOne();
	mMachine->SetLocation(40, 40);
}


CMachineHolder::~CMachineHolder()
{
}

void CMachineHolder::DrawMachine(Gdiplus::Graphics *graphics)
{
	mMachine->DrawMachine(graphics);
}
void CMachineHolder::SetMachineFrame(int frame)
{
	mMachine->SetMachineFrame(frame);
}
void CMachineHolder::SetSpeed(double speed)
{
	mMachine->SetSpeed(speed);
}
void CMachineHolder::SetMachineNumber(int machine)
{
	CMachine::SetMachineNumber(machine);
}
int CMachineHolder::GetMachineNumber()
{
	return mMachineNumber;
}
void CMachineHolder::SetLocation(int x, int y)
{
	mMachine->SetLocation(x, y);
}
void CMachineHolder::SetFrameRate(double rate)
{
	mMachine->SetFrameRate(rate);
}