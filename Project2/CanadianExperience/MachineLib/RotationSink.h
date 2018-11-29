#pragma once

class CRotationSource;
class CRotationSink
{
public:
	CRotationSink();
	/** \brief Copy constructor disabled */
	CRotationSink(const CRotationSink &) = delete;
	/** \brief Assignment operator disabled */
	void operator=(const CRotationSink &) = delete;
	virtual ~CRotationSink();
	/** \brief Add a source
	 * \param source The new source for this sink */
	void AddSource(CRotationSource * source) { mSource = source; };
	virtual void Rotate(double angle) = 0;

private:
	CRotationSource *mSource = nullptr;
};

