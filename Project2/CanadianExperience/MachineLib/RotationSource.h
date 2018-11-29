#pragma once
#include <memory>
#include <vector>

class CRotationSink;
class CRotationSource
{
public:
	CRotationSource();
	/** \brief Copy constructor disabled */
	CRotationSource(const CRotationSource &) = delete;
	/** \brief Assignment operator disabled */
	void operator=(const CRotationSource &) = delete;
	virtual ~CRotationSource();

	void AddSink(std::shared_ptr<CRotationSink> sink);
	void RotateSinks(double angle);

private:
	std::vector<std::shared_ptr<CRotationSink>> mSinks;
};

