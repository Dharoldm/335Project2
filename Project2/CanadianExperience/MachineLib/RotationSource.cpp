#include "stdafx.h"
#include "RotationSource.h"
#include "RotationSink.h"


CRotationSource::CRotationSource()
{
}


CRotationSource::~CRotationSource()
{
}

/**
 * Adds a sink to this source
 * \param A sink this source will rotate
 */
void CRotationSource::AddSink(std::shared_ptr<CRotationSink> sink)
{
	mSinks.push_back(sink);
	sink->AddSource(this);
}

void CRotationSource::RotateSinks(double angle)
{
	for (auto sink : mSinks)
	{
		sink->Rotate(angle);
	}
}