#pragma once
#include "TableData.h"

#define MAX_GROUP_GATE   5
#define MAX_REGION_GROUP 20
#define MAX_REGION       20

#include <vector>
#include <map>
typedef std::vector<std::string>	ReginList;
typedef std::map<int, ReginList> ReginListMap;

extern std::string g_serverset;

// 代表一组服务器
class CServerGroupInfo : public CRawDataInfo
{
public:
    CServerGroupInfo()
    {
    	cValidGateCnt = 0;
	}

    char  szGateIP[MAX_GROUP_GATE][16];
	char  szRegion[16];
	char  cValidGateCnt;
};

class CServerSet : public CRawDataSet
{
public:
    static CServerSet* I() { return _Instance; }

    CServerSet(int nIDStart, int nIDCnt)
        :CRawDataSet(nIDStart, nIDCnt)
    {
        _Instance = this;
        _Init();

		memset( m_nCurGroupList, 0, sizeof(m_nCurGroupList) );
		memset( m_nCurGroupCnt, 0, sizeof(m_nCurGroupCnt) );

		std::ifstream in;
		in.open(g_serverset.c_str());

		for(int i = 0; i < MAX_REGION; i++)
			m_nCurGroupCnt[i] = 0;

		std::string strLine;
		char   szRegion[256] = { 0 };
		if(in.is_open())
		{
			m_nRegionCnt = 0;
			while(!in.eof())
			{
				in.getline( szRegion, sizeof(szRegion) );
				if( strlen(szRegion)==0 ) break;

				std::string strList[2];
				Util_ResolveTextLine(szRegion, strList, 2, ',');

				strcpy(m_szRegionName[m_nRegionCnt], strList[0].c_str());
				strcpy(m_szRegionID[m_nRegionCnt++], strList[1].c_str());

				if(m_nRegionCnt>=MAX_REGION) break;
			}
			in.close();
    	}
	}

public:

	int		m_nCurGroupList[MAX_REGION][MAX_REGION_GROUP]; // 放置当前选中的区里面的所有Group
	int		m_nCurGroupCnt[MAX_REGION];

	char    m_szRegionName[MAX_REGION][32];
	char    m_szRegionID[MAX_REGION][32];

	int     m_nRegionCnt;

protected:
    
	static CServerSet* _Instance; // 相当于单键, 把自己记住

    virtual CRawDataInfo* _CreateRawDataArray(int nCnt)
    {
        return new CServerGroupInfo[nCnt];
    }

    virtual void _DeleteRawDataArray()
    {
        delete[] (CServerGroupInfo*)_RawDataArray;
    }

    virtual int _GetRawDataInfoSize()
    {
        return sizeof(CServerGroupInfo);
    }

    virtual void*	_CreateNewRawData(CRawDataInfo *pInfo)
    {
        return NULL;
    }

    virtual void  _DeleteRawData(CRawDataInfo *pInfo)
    {
        SAFE_DELETE(pInfo->pData);
    }

    virtual BOOL _ReadRawDataInfo(CRawDataInfo *pRawDataInfo, std::vector<std::string> &ParamList)
    {   
        CServerGroupInfo *pInfo = (CServerGroupInfo*)pRawDataInfo;
        
		strcpy(pInfo->szRegion, ParamList[0].c_str());
		for(int i = 0; i < MAX_GROUP_GATE; i++) // 读入5个可能的gate ip
		{
			strcpy(pInfo->szGateIP[i], ParamList[i + 1].c_str());
			if(strcmp(pInfo->szGateIP[i], "0")==0)
			{
				break;
			}
			pInfo->cValidGateCnt++;
			
		}
		
		return TRUE;
    }

	virtual void _ProcessRawDataInfo(CRawDataInfo *pRawDataInfo)
	{
	    CServerGroupInfo *pInfo = (CServerGroupInfo*)pRawDataInfo;
    
		for (size_t i = 0; i < m_nRegionCnt; i++)
		{
			if (strcmp(m_szRegionName[i], pInfo->szRegion) == 0) // 区名符合
			{
				m_nCurGroupList[i][m_nCurGroupCnt[i]] = pInfo->nID;
				m_nCurGroupCnt[i]++;
				break;
			}
		}
	}
};

// 通过组编号, 取得组的GateIP信息
inline CServerGroupInfo* GetServerGroupInfo(int nGroupID)
{
    return (CServerGroupInfo*)CServerSet::I()->GetRawDataInfo(nGroupID);
}

// 通过组名字, 取得组的GateIP信息
inline CServerGroupInfo* GetServerGroupInfo(const char *pszGroupName)
{
    return (CServerGroupInfo*)CServerSet::I()->GetRawDataInfo(pszGroupName);
}

inline int GetCurServerGroupCnt(int nRegionNo)
{
	return CServerSet::I()->m_nCurGroupCnt[nRegionNo];
}

inline const char* GetCurServerGroupName(int nRegionNo, int nGroupNo)
{
	if(nGroupNo>=GetCurServerGroupCnt(nRegionNo)) return 0;

	int nNo = CServerSet::I()->m_nCurGroupList[nRegionNo][nGroupNo];
	return GetServerGroupInfo(nNo)->szDataName;
}

// 增加游戏区域信息 Michael Chen 2005-06-01
inline int GetRegionCnt()
{
	return CServerSet::I()->m_nRegionCnt;
}

inline const char* GetCurRegionName(int nRegionNo)
{
	if (nRegionNo < 0 && nRegionNo > GetRegionCnt())
		return 0;

	return CServerSet::I()->m_szRegionName[nRegionNo];
}

// 通过组编号, 选中一个GateIP
inline const char *SelectGroupIP(int nRegionNo, int nGroupNo)
{
	LG("connect", "Select Region %d Group %d\n", nRegionNo, nGroupNo);
	if(nGroupNo>=GetCurServerGroupCnt(nRegionNo)) 
	{
		LG("connect", g_oLangRec.GetString(387), GetCurServerGroupCnt(nRegionNo), nGroupNo);
		return 0;
	}

	int nNo = CServerSet::I()->m_nCurGroupList[nRegionNo][nGroupNo];
	CServerGroupInfo *pGroup = GetServerGroupInfo(nNo);
	if(!pGroup) 
	{
		LG("connect", "Group Not Found!\n");
		return NULL;
	}

	if(pGroup->cValidGateCnt==0) 
	{
		LG("connect", g_oLangRec.GetString(388));
		return NULL;
	}

	srand(GetTickCount());

	int nGateNo = rand()%(int)(pGroup->cValidGateCnt); 

	LG("connect", g_oLangRec.GetString(389), pGroup->szDataName, nGateNo, pGroup->szGateIP[nGateNo], pGroup->cValidGateCnt);

	return pGroup->szGateIP[nGateNo];
}
