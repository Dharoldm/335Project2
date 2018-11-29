#pragma once
#include <memory>

class CMachineActual;
class CMachineOneFactory
{
public:
	CMachineOneFactory();
	/** \brief Copy constructor disabled */
	CMachineOneFactory(const CMachineOneFactory &) = delete;
	/** \brief Assignment operator disabled */
	void operator=(const CMachineOneFactory &) = delete;
	virtual ~CMachineOneFactory();
	std::shared_ptr<CMachineActual> CreateMachineOne();
};

