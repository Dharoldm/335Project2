#include "stdafx.h"
#include "MachineDrawable.h"
#include "MachineFactory.h"
#include "Machine.h"

using namespace std;
using namespace Gdiplus;

CMachineDrawable::CMachineDrawable(const std::wstring &name) : CDrawable(name)
{
	CMachineFactory factory;
	mMachine = factory.CreateMachine();
}


CMachineDrawable::~CMachineDrawable()
{
}

void CMachineDrawable::Draw(Gdiplus::Graphics *graphics)
{
	mMachine->DrawMachine(graphics);
}

bool CMachineDrawable::HitTest(Gdiplus::Point pos)
{
	return false;
}
