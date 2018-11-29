#pragma once
class CMovementSink
{
public:
	CMovementSink();
	/** \brief Copy constructor disabled */
	CMovementSink(const CMovementSink &) = delete;
	/** \brief Assignment operator disabled */
	void operator=(const CMovementSink &) = delete;
	virtual ~CMovementSink();
};

