/******************************************************************
**	Project Satisfy 2021
**	Base Files: PKO/Corsair, Mothanna Files
**	All rights for code changes/edits/mods and Interface Changes to
**					Mothanna And Satisfy
*******************************************************************/
#pragma once
#include "TableData.h"
//#include "util.h"

constexpr auto Mount_MAXSIZE_NAME = 32; // mount name size;
constexpr auto MaxChatrcterx = 4;

class MountInfo : public CRawDataInfo {
public:
	int CharID{};                      //characterinfo id for future use 
	int ItemID{};                      //iteminfo id  for future use 
	char szName[Mount_MAXSIZE_NAME]{}; // mount name
	int mountBone[MaxChatrcterx]{};
	int MountHeight[MaxChatrcterx]{};
	int PoseID[MaxChatrcterx]{};
	int OffSetx[MaxChatrcterx]{};
	int OffSety[MaxChatrcterx]{};
	float Mountscale[MaxChatrcterx]{};

};


class MountHelper final : public CRawDataSet {
public:
	static MountHelper* I() { return _Instance; }

	MountHelper(const int nIDStart, const int nIDCnt, const int nCol = 128)
		: CRawDataSet(nIDStart, nIDCnt, nCol) {
		_Instance = this;
		_Init();
	}

	~MountHelper() = default;
	MountHelper& operator=(const MountHelper& other) = default; // Copy assignment
	MountHelper(MountHelper& copy) = default;                   // Copy constructor
	MountHelper(MountHelper&& move) = default;                  // Move constructor
	MountHelper& operator=(MountHelper&& moveas) = default;     // Move assignment
	//const char* ConvertResString(const char* str);

protected:
	static MountHelper* _Instance; // 锟洁当锟节碉拷锟斤拷, 锟斤拷锟皆硷拷锟斤拷住


	CRawDataInfo* _CreateRawDataArray(int nCnt) override {
		return new MountInfo[nCnt];
	}

	void _DeleteRawDataArray() override {
		delete[] reinterpret_cast<MountInfo*>(_RawDataArray);
	}

	int _GetRawDataInfoSize() override {
		return sizeof(MountInfo);
	}

	void* _CreateNewRawData(CRawDataInfo* pInfo) override {
		return nullptr;
	}

	void _DeleteRawData(CRawDataInfo* pInfo) override {
		SAFE_DELETE(pInfo->pData)
	}

	BOOL _ReadRawDataInfo(CRawDataInfo* pRawDataInfo, std::vector<std::string>& ParamList) override;
};


inline MountInfo* GetMountInfo(const int nTypeID) {
	return reinterpret_cast<MountInfo*>(MountHelper::I()->GetRawDataInfo(nTypeID));
}

inline MountInfo* GetMountInfoFromItemID(const int ItemID) {
	MountHelper* helper = MountHelper::I();
	for (int i = 0; i < helper->GetIDCnt(); i++)
		if (const auto pInfo = reinterpret_cast<MountInfo*>(helper->GetRawDataInfo(helper->GetIDStart() + i)); pInfo)
			if (pInfo->ItemID == ItemID)
				return pInfo;
	return nullptr;
}
