#pragma once
#include <vector>
#include <memory>

class CComponent;
class CMotor;
class CMachineActual
{
public:
	CMachineActual();
	virtual ~CMachineActual();
	/** \brief Copy constructor disabled */
	CMachineActual(const CMachineActual &) = delete;
	/** \brief Assignment operator disabled */
	void operator=(const CMachineActual &) = delete;

	void DrawMachine(Gdiplus::Graphics *graphics);
	void SetMachineFrame(int frame);
	void SetLocation(int x, int y);
	void SetFrameRate(double rate);
	void SetSpeed(double speed) { mSpeed = speed; };
	void AddComponent(std::shared_ptr<CComponent> component);
	void AddMotor(std::shared_ptr<CMotor> motor);


private:
	int mFrameRate =30;
	double mSpeed = 1;
	Gdiplus::Point mPosition = Gdiplus::Point(0,0);
	std::vector<std::shared_ptr<CComponent>> mComponents;
	std::shared_ptr<CMotor> mMotor = nullptr;
};

