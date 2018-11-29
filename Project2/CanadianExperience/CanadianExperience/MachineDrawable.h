#pragma once
#include "Drawable.h"

class CMachine;
class CMachineDrawable : public CDrawable
{
public:
	/** \brief Default constructor disabled */
	CMachineDrawable() = delete;
	/** \brief Copy constructor disabled */
	CMachineDrawable(const CMachineDrawable &) = delete;
	/** \brief Assignment operator disabled */
	void operator=(const CMachineDrawable &) = delete;

	CMachineDrawable(const std::wstring &name);
	virtual ~CMachineDrawable();

	virtual void Draw(Gdiplus::Graphics *graphics) override;
	virtual bool HitTest(Gdiplus::Point pos) override;

private:
	std::shared_ptr<CMachine> mMachine;
};

