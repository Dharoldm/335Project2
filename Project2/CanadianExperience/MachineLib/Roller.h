#pragma once
#include "Component.h"
class CRoller : public CComponent
{
public:
	CRoller();
	/** \brief Copy constructor disabled */
	CRoller(const CRoller &) = delete;
	/** \brief Assignment operator disabled */
	void operator=(const CRoller &) = delete;
	virtual ~CRoller();
};

