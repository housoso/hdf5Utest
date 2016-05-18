
#include "test.h"
#include <iostream>
//=============================================================================
// @author: changyf
// @description: changyf
//=============================================================================
using namespace GC;

/**
 * Default implementation of cleanup method: do nothing
 */
extern pthread_mutex_t mutex;
eResult test::cleanup()
{
	return eResult_OK;
}
//
/**
 * Method called during configure phase and
 * should be used to configure usercode.
 */
eResult test::extraConfigure(const UserCodeConfig& config)
{
	return eResult_OK;
}
//
/**
 * Default implementation of run method: call preRun/step/postRun
 */
eResult test::run()
{
	cout<<"num is "<< num++ <<endl;
	eResult result = UserCodeBase::run();
	if(0 != pthread_mutex_lock(&mutex))
	{
		cout<<"run thread false"<<endl;
	}
	else
	{
		cout<<"inputtrg is "<< _ucDef->inputtrg <<endl;
		cout<<"input is "<< _ucDef->input <<endl;
		Threads::iInPutsw =_ucDef->inputtrg;
		Threads::strInputpath = _ucDef->input;
	}
	if(0 != pthread_mutex_unlock(&mutex))
	{
		cout<<"run thread release false"<<endl;
	}

//	vsTimestamp_t ts = 0;
//	_ucDef->inputReader->get(_ucDef->input,ts);
//	printf("input ts:%u\n",ts);

	return eResult_OK;
}
//
/**
 * Set user code definition object
 *
 */
eResult test::setUCDefinition(boost::shared_ptr<UCDefInterface> ucDef)
{
	eResult result = UserCodeBase::setUCDefinition(ucDef);
	return eResult_OK;
}
//
/**
 * Default implementation of start method: do nothing
 */
eResult test::start()
{
	pthread_t Hdf5t;
	int ret;
	pthread_mutex_init(&mutex, NULL);
	ret = pthread_create(&Hdf5t, NULL, Threads::Thread_start, NULL);

	if(ret !=0 )
	{
		cout<< "create HDF5 thread false!"<<endl;
		return eResult_UnkErr;
	}
	cout<<"start end"<<endl;
	return eResult_OK;
}
//
/**
 * Method executed periodically between 
 * the preRun and postRun methods
 * You can access to your input/output variables
 * through _ucDef
 * ex:
 * _ucDef->myOutputVar = 2 * _ucDef->myInputVar;
 */
eResult test::step()
{
//	cout<<"num is "<< num++ <<endl;
//	_ucDef->output = _ucDef->input;
//	cout<<"inputtrg is "<< _ucDef->inputtrg <<endl;
//	cout<<"output is "<< _ucDef->output.c_str() <<endl;
//	cout<<"input is "<< _ucDef->input.c_str() <<endl;

//	if(0!=_ucDef->inputtrg)
//	{
//		string FILEHDF5("/opt/gc/var/admin/");
//		if(_ucDef->input.empty())
//		{
//			return eResult_UnkErr;
//		}
//		FILEHDF5 += _ucDef->input;
//		GETHDFINFO stuGETHDFINFO;
//		stuGETHDFINFO.BisHdf5(FILEHDF5);
//		stuGETHDFINFO.GetmapData(mapData);
//		Disp(mapData);
//	}

	return eResult_OK;
}
//
/**
 * Default implementation of stop method: do nothing
 */
eResult test::stop()
{
	return eResult_OK;
}
//
//void test::Disp(const map<string, vector<UTESTDATA> >& mapData)
//{
//	if(mapData.begin() == mapData.end())
//	{Thread_start
//		cout << "mapData is empt" << endl;
//		return;
//	}
//
//	for(map<string, vector<UTESTDATA> >::const_iterator itemapData = mapData.begin();mapData.end() != itemapData; itemapData++)
//	{
//		for(vector<UTESTDATA>::const_iterator iteUTESTDATA = itemapData->second.begin(); itemapData->second.end() != iteUTESTDATA;iteUTESTDATA++)
//		{
//			cout <<"datavalue "<< iteUTESTDATA->m_datavalue << "  time "<< iteUTESTDATA->usTime <<endl;
//		}
//	}
//}
//
GC_USERCODE_EXPORT(Desctest, test)
