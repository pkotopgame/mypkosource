/******************************************************************
**	Project Satisfy 2021
**	Base Files: PKO/Corsair, Mothanna Files
**	All rights for code changes/edits/mods and Interface Changes to
**					Mothanna And Satisfy
*******************************************************************/
#pragma once
//#include <array>
//#include <CommFunc.h>
//#include "TableData.h"
//#include "MPRender.h"
//#include "filters.h"
//#include "files.h"
//#include <fstream>

///
#include <unordered_map>

#include "MPRender.h"

#pragma warning(disable: 4275)

class MINDPOWER_API MPTexInfo  {
public:
	MPTexInfo() = default;
	~MPTexInfo() = default;
	MPTexInfo& operator=(const MPTexInfo& other) = default;	   // Copy assignment
	explicit MPTexInfo(MPTexInfo& copy) = default;			   // Copy constructor
	MPTexInfo(MPTexInfo&& move) = default;					   // Move constructor
	MPTexInfo& operator=(MPTexInfo&& moveas) = default;		   // Move assignment
	BYTE bAlpha{0};
	BYTE btMipmap{5};
	short sWidth{0};
	short sHeight{0};
	BOOL bExist{TRUE};
	//dwLastUseTick
	DWORD dwLastUseTick{0};
	char szDataName[72]{""};
	lwITex* LwtxtData{nullptr};
	bool ItsSkillIcon{false};//just i want release icons but keep skills icons 
};

#pragma pack(push,__Data_Align)
#pragma pack(1)

struct STGAHeader {
	unsigned char id_len;
	unsigned char cm_type;
	unsigned char type;
	unsigned short cm_start;
	unsigned short cm_len;
	unsigned char cm_bits;
	unsigned short xorg;
	unsigned short yorg;
	unsigned short width;
	unsigned short height;
	unsigned char bpp;
	unsigned char flags;
};

#pragma pack(pop,__Data_Align)
class MINDPOWER_API NewMPTexSet final {
public:
	NewMPTexSet& operator=(const NewMPTexSet& other) = default; // Copy assignment
	explicit NewMPTexSet(NewMPTexSet& copy) = default;			// Copy constructor
	NewMPTexSet(NewMPTexSet&& move) = default;					// Move constructor
	NewMPTexSet& operator=(NewMPTexSet&& moveas) = default;		// Move assignment
	~NewMPTexSet() = default;
	static NewMPTexSet* Instance() { return Instancex; }

	explicit NewMPTexSet() {
		Instancex = this;
	}
	auto& GetTexMapData() { return MPtexSet; }
	auto& GetMPtexSetNameAndKeys() { return MPtexSetNameAndKeys; }
	static BOOL IsAlphaTGA(const char* pFileBuf) {
		STGAHeader header{};
		memcpy(&header, pFileBuf, sizeof(STGAHeader));
		return header.bpp == 32;
	}

	[[nodiscard]] BOOL IsAlphaTexture(int nID) const;
	void ReloadAllTexture();

	void SetTextureLevel(const DWORD nLevel);

	[[nodiscard]] auto GetTextureLevel() const { return _nTextureLevel; }

	MPTexInfo* CreateNewTextInfo(int ID, const std::string& texName);
	void DeleteTextInfo(int ID);

	[[nodiscard]] auto GetMPtexSetSize() const { return MPtexSet.size(); }
	void TextureDynamicRelease(BOOL EditorMode);
	static BOOL IsFull();

	[[nodiscard]] lwITex* CreateNewRlwITex(int ID);
	void DeleteRlwITex(int ID);
	int GetTextureID(const char* pszDataName);
	[[nodiscard]] int GenerateMapKeyByName(const std::string& pszDataName) const;
	void ReleaseUnusedIcons();
protected:
	std::unordered_map<int, MPTexInfo*> MPtexSet{}; //we store the map data itself and generate a key depends in size 
	std::unordered_map<std::string, int> MPtexSetNameAndKeys{}; // we store texture name and their key to use when texture called by id 
	DWORD ReleaseInterval{10000};
	static NewMPTexSet* Instancex;
	DWORD _nTextureLevel{D3DX_DEFAULT};
};

// inline functions where all codes called over source

inline lwITex* GetTexByID(const int nID) {
	if (NewMPTexSet::Instance()->GetTexMapData().contains(nID)) {
		if (NewMPTexSet::Instance()->GetTexMapData()[nID]) {
			NewMPTexSet::Instance()->GetTexMapData()[nID] ->dwLastUseTick = GetTickCount();//update last use ticks for dynamic release 
			if (NewMPTexSet::Instance()->GetTexMapData()[nID]->LwtxtData) {
				return NewMPTexSet::Instance()->GetTexMapData()[nID]->LwtxtData;
			}
			return NewMPTexSet::Instance()->CreateNewRlwITex(nID);
		}
	}
	return nullptr;
}
inline lwITex* GetTexByName(const char* pszDataName) {
	if (NewMPTexSet::Instance()->GetMPtexSetNameAndKeys().contains(pszDataName)) {
		if (const auto& IDkey = NewMPTexSet::Instance()->GetMPtexSetNameAndKeys()[pszDataName]; NewMPTexSet::Instance()->GetTexMapData().contains(IDkey)) {
			NewMPTexSet::Instance()->GetTexMapData()[IDkey]->dwLastUseTick = GetTickCount();
			if (NewMPTexSet::Instance()->GetTexMapData()[IDkey]->LwtxtData) {
				return NewMPTexSet::Instance()->GetTexMapData()[IDkey]->LwtxtData;
			}
			return NewMPTexSet::Instance()->CreateNewRlwITex(static_cast<int>(IDkey));
		}
	}

	return nullptr;
}
inline IDirect3DTextureX* GetTextureByID(const int nID) // 通过ID取得Texture表面
{
	const auto tex = GetTexByID(nID);
	return tex ? tex->GetTex() : nullptr;
}

inline SIZE GetTextureSizeByID(const int nID) {
	SIZE sz = {0, 0};
	if (const auto tex = GetTexByID(nID); tex) {
		lwTexInfo info{};
		tex->GetTexInfo(&info);
		sz.cx = info.width;
		sz.cy = info.height;
	}

	return sz;
}
inline int GetTextureID(const char* pszDataName) {
	if (NewMPTexSet::Instance() != nullptr) {
		// if not found  create new texture
		return NewMPTexSet::Instance()->GetTextureID(pszDataName);
	}

	// by default return -1 to skip
	return -1;
}
inline MPTexInfo* GetTextureInfo(const int nID) {

	if (NewMPTexSet::Instance() != nullptr) {
		if (NewMPTexSet::Instance()->GetTexMapData().contains(nID)) {
			const auto& mpinfo = NewMPTexSet::Instance()->GetTexMapData().at(nID);
			mpinfo->dwLastUseTick = GetTickCount();
			return mpinfo;
		}
	}
	// LG("textureidret", "does return nullptr %d\n,", nID);
	return nullptr;
}

inline BOOL IsAlphaTexture(const int nID) {
	auto&& pInfo = GetTextureInfo(nID);
	if (!pInfo)
		return FALSE;
	return pInfo->bAlpha == 1;
}

inline BOOL IsTextureExist(const char* pszDataName) {
	if (NewMPTexSet::Instance() != nullptr) {
		if (NewMPTexSet::Instance()->GetMPtexSetNameAndKeys().contains(pszDataName))
			return TRUE;
		if (Util_IsFileExist(pszDataName)) {
			return TRUE;
		}
		return FALSE;
	}

	return FALSE;
}

inline void SetTextureAsSkillIcon(bool Isit, const std::string& TexName) {
	if (NewMPTexSet::Instance() != nullptr) {
		if (NewMPTexSet::Instance()->GetMPtexSetNameAndKeys().contains(TexName)) {
			try {
				if (const auto& mpinfo = NewMPTexSet::Instance()->GetTexMapData().at(NewMPTexSet::Instance()->GetMPtexSetNameAndKeys()[TexName]))
					mpinfo->ItsSkillIcon = true;

			} catch (const std::out_of_range& oor) {
				// it suppose to never happen but if its, throw exception
				LG("SetTextureAsSkillIcon", "Out of range index for id %s: %s\n", TexName.c_str(), oor.what());
			}
		}
	}
}

#pragma warning(default: 4275)
