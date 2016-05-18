/*
 * hdf.h
 *
 *  Created on: May 13, 2016
 *      Author: root
 */

#ifndef HDF_H_
#define HDF_H_
#include "hdf5.h"
#include <map>
#include <vector>
#include <string>
#include <iostream>
#include "basetype.h"
#include <stdio.h>
using namespace std;



typedef struct UTESTDATA
{
	int m_datavalue;
	UINT64 usTime;
	UTESTDATA() : m_datavalue(0), usTime(0)
	{}
}UTESTDATA;


class GETHDFINFO
{
public:
	void BisHdf5(string sAllFileName);
	void GetmapData(map<string, vector<UTESTDATA> >& mapDatatmp)
	{
		mapDatatmp.swap(mapData);
	}
	void Disp();
private:
	void GetHdfData(string sAllFileName);
	void GetDataset(hid_t file_id,string sGrpName,string sRootName = "");

private:
	map<string, vector<UTESTDATA> > mapData;
};

#endif /* HDF_H_ */
