/******************************************************************
**	Project Satisfy 2021
**	Base Files: PKO/Corsair, Mothanna Files
**	All rights for code changes/edits/mods and Interface Changes to
**					Mothanna And Satisfy
*******************************************************************/
#include "stdafx.h"
#include "MountInfo.h"

MountHelper* MountHelper::_Instance = nullptr;

BOOL MountHelper::_ReadRawDataInfo(CRawDataInfo* pRawDataInfo, std::vector<std::string>& ParamList) {
	if (ParamList.empty())
		return FALSE;

	const auto pInfo = static_cast<MountInfo*>(pRawDataInfo);

	int m = 0, n = 0;
	std::string strLine;

	_tcsncpy_s(pInfo->szName, pInfo->szDataName, Mount_MAXSIZE_NAME);
	pInfo->szName[Mount_MAXSIZE_NAME - 1] = _TEXT('\0'); // mount name

	pInfo->ItemID = Str2Int(ParamList[m++]); // mount item info id
	pInfo->CharID = Str2Int(ParamList[m++]); // mount character info id

	for (int i = 0; i < MaxChatrcterx; i++) {
		std::string strList[6];
		Util_ResolveTextLine(ParamList[m++].c_str(), strList, 6, ',');
		pInfo->mountBone[i] = Str2Int(strList[0]);    // mount bone id
		pInfo->PoseID[i] = Str2Int(strList[1]);       // mount pose id
		pInfo->OffSetx[i] = Str2Int(strList[2]);      // mount x
		pInfo->OffSety[i] = Str2Int(strList[3]);      // mount y
		pInfo->MountHeight[i] = Str2Int(strList[4]);  // mount highest
		pInfo->Mountscale[i] = Str2Float(strList[5]); // mount scale
	}

	return TRUE;
}
