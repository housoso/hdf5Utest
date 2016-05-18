
#ifndef TESTUCDEF_H_
#define TESTUCDEF_H_

#include <modules/uc/UCDefInterface.h>
#include <modules/uc/UserCodeBase.h>
#include <Vs.h>
#include <log/Log.h>

class testUCDef: public GC::UCDefInterface
{
private:
	GC::UserCodeBase *_uc;
public:
	/**
		INPUTS
	**/
	std::auto_ptr<GC::OpaqueReader>inputReader;
	vsOpaque_t input;
	long long inputTS;
	std::auto_ptr<GC::IntegerReader>inputtrgReader;
	long inputtrg;
	long long inputtrgTS;
	/**
		OUTPUTS
	**/
	std::auto_ptr<GC::OpaqueWriter>outputWriter;
	vsOpaque_t output;
	std::auto_ptr<GC::IntegerWriter>outputtrgWriter;
	long outputtrg;
public:
	testUCDef(GC::UserCodeBase *uc) :inputtrg(0), outputtrg(0),_uc(uc)
	{
	}

	std::string getName()
	{
		return "test";
	}

	/// @return UC log level
	LOG::Logger::LogLevel getLogLevel() const {
		return _uc->getLogLevel();
	}

	eResult initialize()
	{
		/**
			Init inputs variables
		**/
		VARIABLE_CONTROLLER()->importVariable(_uc->local("input"),GC::VS::OPAQUE);
		inputReader = std::auto_ptr<GC::OpaqueReader>(
			VARIABLE_CONTROLLER()->createOpaqueReader(_uc->local("input")));
		if(inputReader.get() == 0) return eResult_UnkErr;
		VARIABLE_CONTROLLER()->importVariable(_uc->local("inputtrg"),GC::VS::INTEGER);
		inputtrgReader = std::auto_ptr<GC::IntegerReader>(
			VARIABLE_CONTROLLER()->createIntegerReader(_uc->local("inputtrg")));
		if(inputtrgReader.get() == 0) return eResult_UnkErr;

		/**
			Init outputs variables
		**/
		VARIABLE_CONTROLLER()->importVariable(_uc->local("output"),GC::VS::OPAQUE);
		outputWriter = std::auto_ptr<GC::OpaqueWriter>(
			VARIABLE_CONTROLLER()->createOpaqueWriter(_uc->local("output")));
		if(outputWriter.get() == 0) return eResult_UnkErr;
		VARIABLE_CONTROLLER()->importVariable(_uc->local("outputtrg"),GC::VS::INTEGER);
		outputtrgWriter = std::auto_ptr<GC::IntegerWriter>(
			VARIABLE_CONTROLLER()->createIntegerWriter(_uc->local("outputtrg")));
		if(outputtrgWriter.get() == 0) return eResult_UnkErr;
		return eResult_OK;
	}
	eResult preRun()
	{
		int ReturnValue;
		ReturnValue = inputReader->get(input, inputTS);
		if( ReturnValue != GC::VS::Ok)
		{
			gcLogModuleDebug("Can't read variable \"input\", return error code: %d",ReturnValue );
		}
		ReturnValue = inputtrgReader->get(inputtrg, inputtrgTS);
		if( ReturnValue != GC::VS::Ok)
		{
			gcLogModuleDebug("Can't read variable \"inputtrg\", return error code: %d",ReturnValue );
		}
		return eResult_OK;
	}
	eResult postRun()
	{
		int ReturnValue;
		ReturnValue = outputWriter->set(output);
		if( ReturnValue != GC::VS::Ok)
		{
			gcLogModuleDebug("Can't write variable \"output\", return error code: %d",ReturnValue );
		}
		ReturnValue = outputtrgWriter->set(outputtrg);
		if( ReturnValue != GC::VS::Ok)
		{
			gcLogModuleDebug("Can't write variable \"outputtrg\", return error code: %d",ReturnValue );
		}
		return eResult_OK;
	}
};

#endif /* TESTUCDEF_H_ */
