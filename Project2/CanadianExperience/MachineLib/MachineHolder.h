#pragma once
#include "Machine.h"
class CMachineActual;
class CMachineHolder : public CMachine
{
public:
	CMachineHolder();
	virtual ~CMachineHolder();
	void DrawMachine(Gdiplus::Graphics *graphics) override;
	void SetMachineFrame(int frame) override;
	void SetSpeed(double speed) override;
	void SetMachineNumber(int machine) override;
	int GetMachineNumber() override;
	void SetLocation(int x, int y) override;
	void SetFrameRate(double rate) override;

private:
	int mMachineNumber = 1;
	std::shared_ptr<CMachineActual> mMachine;
};

