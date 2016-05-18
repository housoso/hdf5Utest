/*
 * hdf.cc
 *
 *  Created on: May 13, 2016
 *      Author: root
 */

#include "hdf.h"
void GETHDFINFO::BisHdf5(string sAllFileName)
{
	if (0 > H5Fis_hdf5(sAllFileName.c_str()))
	{
		cout << "Hdf5 File is not ext" << endl;
		return;
	}
	GetHdfData(sAllFileName);
	return;
}

void GETHDFINFO::Disp()
{
		if(mapData.begin() == mapData.end())
		{
			cout << "mapData is empt" << endl;
			return;
		}

		for(map<string, vector<UTESTDATA> >::const_iterator itemapData = mapData.begin();mapData.end() != itemapData; itemapData++)
		{
			for(vector<UTESTDATA>::const_iterator iteUTESTDATA = itemapData->second.begin(); itemapData->second.end() != iteUTESTDATA;iteUTESTDATA++)
			{
				cout <<"datavalue "<< iteUTESTDATA->m_datavalue << "  time "<< iteUTESTDATA->usTime <<endl;
			}
		}
}

void GETHDFINFO::GetHdfData(string sAllFileName)
{
	H5O_info_t object_info;
	hid_t file_id = H5Fopen(sAllFileName.c_str(), H5F_ACC_RDONLY, H5P_DEFAULT);
	hsize_t num_obj;
	herr_t numtest = H5Gget_num_objs(file_id, &num_obj);
	for (hid_t usObjNum = 0; usObjNum < num_obj; usObjNum++)
	{
		char sObjName[50] = { 0 };
		size_t 	sizename = H5Lget_name_by_idx(file_id, ".", H5_INDEX_NAME, H5_ITER_NATIVE, (hsize_t)usObjNum, NULL, NULL, H5P_DEFAULT);
		(void)H5Lget_name_by_idx(file_id, ".", H5_INDEX_NAME, H5_ITER_NATIVE, (hsize_t)usObjNum, sObjName, sizename + 1, H5P_DEFAULT);
		herr_t ieoinfo = H5Oget_info_by_name(file_id, sObjName, &object_info, NULL);
		if (H5O_TYPE_DATASET == object_info.type)
		{
			//////////////////////////////////////////////////////////////////////////

		}
		else if (H5O_TYPE_GROUP == object_info.type)
		{
			GetDataset(file_id, sObjName);
		}

	}
	H5Fclose(file_id);
}

void GETHDFINFO::GetDataset(hid_t file_id, string sGrpName, string sRootName)
{
	H5O_info_t object_info;
	hid_t Obj_id = H5Gopen(file_id, sGrpName.c_str(), H5P_DEFAULT);
	hsize_t num_obj;
	herr_t numtest = H5Gget_num_objs(Obj_id, &num_obj);
	for (hid_t usObjNum = 0; usObjNum < num_obj; usObjNum++)
	{
		char sObjName[50] = { 0 };
		size_t 	sizename = H5Lget_name_by_idx(Obj_id, ".", H5_INDEX_NAME, H5_ITER_NATIVE, (hsize_t)usObjNum, NULL, NULL, H5P_DEFAULT);
		(void)H5Lget_name_by_idx(Obj_id, ".", H5_INDEX_NAME, H5_ITER_NATIVE, (hsize_t)usObjNum, sObjName, sizename + 1, H5P_DEFAULT);
		herr_t ieoinfo = H5Oget_info_by_name(Obj_id, sObjName, &object_info, NULL);

		if (H5O_TYPE_DATASET == object_info.type)
		{
			UTESTDATA dset_data[5000];
			hid_t dataset_id = H5Dopen2(Obj_id, sObjName, H5P_DEFAULT);
			hid_t s2_tid = H5Tcreate(H5T_COMPOUND, sizeof(UTESTDATA));
			H5Tinsert(s2_tid, "Value", HOFFSET(UTESTDATA, m_datavalue), H5T_NATIVE_INT);
			H5Tinsert(s2_tid, "Timestamp", HOFFSET(UTESTDATA, usTime), H5T_NATIVE_UINT64);
			H5Dread(dataset_id, s2_tid, H5S_ALL, H5S_ALL, H5P_DEFAULT, dset_data);
			hid_t dataspace = H5Dget_space(dataset_id);
			hsize_t dims, maxdims;
			(void)H5Sget_simple_extent_dims(dataspace, &dims, &maxdims);
			sRootName += sObjName;
			mapData[sRootName].insert(mapData[sRootName].end(), dset_data, dset_data + dims);
			(void)H5Dclose(dataset_id);
		}
		else if (H5O_TYPE_GROUP == object_info.type)
		{
			string sRoot(sRootName);
			sRoot += sObjName;
			sRoot += "\\";
			GetDataset(Obj_id, sObjName, sRoot);
		}
	}
	//H5Dclose(Obj_id);
}
