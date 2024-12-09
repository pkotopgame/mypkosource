/******************************************************************
**	Project Satisfy 2021
**	Base Files: PKO/Corsair, Mothanna Files
**	All rights for code changes/edits/mods and Interface Changes to
**					Mothanna And Satisfy
*******************************************************************/
//#include "stdafx.h"
#include "stdafx.h"
#include "MPTextureSet.h"
#include "ranges"
#include "CommFunc.h"
// make our own custom hash code to turn it into int 
int NewMPTexSet::GenerateMapKeyByName(const std::string& pszDataName) const {
	std::string str = pszDataName;
	str.erase(std::ranges::remove_if(str, [](const auto& c) -> bool { return std::isspace(c); }).begin(), str.end());
	const auto key = std::hash<std::string_view>{}(str) -700000;//as we convert it from u long to int i will take some of it out
	//int digits = static_cast<int>(log10(key)) + 1;
	return static_cast<int>(key);
}
//this code atm used on switch codes of maps, if using database can call it on forum close , or x npc close to delete all viewed textures 
//call free icons on teleporting or switch the map
void NewMPTexSet::ReleaseUnusedIcons() {
	const DWORD dwCurTick = GetTickCount();
	if (static DWORD time = 0; dwCurTick > time) {
		time = dwCurTick + 60000; // make function run every 1 min so its do not spam on teleport/many spam of tickets
		//search for every inactive icon in our list 
		for (auto& [key, value] : MPtexSet) {
			// we remove the icon if wasn't used in last 40seconds
			if (constexpr DWORD ReleaseIconsInterval = 40000; value && dwCurTick - value->dwLastUseTick > ReleaseIconsInterval) {
				//atm i just delete texture/icons folder unused if want include different folder ass it here but test before/after, do not do this for skins never
				if (std::string name = value->szDataName; !value->ItsSkillIcon && name.contains("texture/icon/")) {
					SAFE_RELEASE(value->LwtxtData)
					// LG("tex_DynamicRelase", "Release Texture Data [%s], size = %d %d index[%d] MapSize %lu\n", value->szDataName, value->sWidth, value->sHeight, key, MPtexSet.size());
					MPtexSetNameAndKeys.erase(name);
					delete value;
					value = nullptr;
					MPtexSet.erase(key);
				}
			}
		}
	}
}

BOOL NewMPTexSet::IsAlphaTexture(const int nID) const {
	if (MPtexSet.contains(nID)) {

		if (auto&& pinfo = MPtexSet.at(nID); pinfo && pinfo->bAlpha == 1) {
			return TRUE;
		}
	}
	return FALSE;
}

void NewMPTexSet::ReloadAllTexture() {
	for (auto& value : MPtexSet | std::views::values) {
		if (value) {
			SAFE_RELEASE(value->LwtxtData)
			delete value;
			value = nullptr;
		}
		// here need create new one still not sure how it work
	}
	MPtexSet.clear();
	MPtexSetNameAndKeys.clear();
}


void NewMPTexSet::SetTextureLevel(const DWORD nLevel) {
	if (_nTextureLevel != nLevel) {
		_nTextureLevel = nLevel;
		ReloadAllTexture();
	}
}

MPTexInfo* NewMPTexSet::CreateNewTextInfo(const int ID, const std::string& texName) {
	const auto newinfo = new MPTexInfo();
	// MPtexSet.insert(std::make_pair(ID, newinfo));
	if (MPtexSet.contains(ID)) {
		delete MPtexSet[ID];
		//MPtexSet[ID] = newinfo;
		MPtexSet.insert_or_assign(ID, newinfo);
	}
	//MPtexSet[ID] = newinfo;
	MPtexSet.insert_or_assign(ID, newinfo);
	MPtexSetNameAndKeys.insert_or_assign(texName, ID);
	return newinfo;
}

void NewMPTexSet::DeleteTextInfo(const int ID) {
	if (MPtexSet.contains(ID)) {
		if (MPtexSet[ID]) {
			SAFE_RELEASE(MPtexSet[ID]->LwtxtData)
			if (MPtexSetNameAndKeys.contains(MPtexSet[ID]->szDataName))
				MPtexSetNameAndKeys.erase(MPtexSet[ID] ->szDataName);
			delete MPtexSet[ID];
			MPtexSet[ID] = nullptr;
		}
		MPtexSet.erase(ID);
	}
}
void NewMPTexSet::TextureDynamicRelease(const BOOL EditorMode) {

	//if (IsFull() == FALSE)
	//	return;
	const DWORD dwCurTick = GetTickCount();
	for (auto& [key,value] : MPtexSet ) {
		if (value && dwCurTick - value->dwLastUseTick > ReleaseInterval) {
			SAFE_RELEASE(value->LwtxtData)
			//still need find better way to free unused icons,png skin etc maybe free them one by one better not sure
			//so for now we free lwtxt data and sceneobj of map editor stuff only ,
#ifdef _DEBUG
				//in debug build we skip all delete method otherwise would crash 
			continue;
#endif
			//in editor mod we do not clear sceneobj funny fact sceneobj folder load 1800 texture at once never released in release build
			if (!EditorMode ) {
				if (std::string name = value->szDataName; name.contains("sceneobj")) {
					//LG("tex_DynamicRelase", "Release Texture Data [%s], size = %d %d index[%d] MapSize %lu\n", value->szDataName, value->sWidth, value->sHeight, key, MPtexSet.size());
					MPtexSetNameAndKeys.erase(name);
					delete value;
					value = nullptr;
					MPtexSet.erase(key);
					
				}
			}
		}
	}
}

 lwITex* NewMPTexSet::CreateNewRlwITex(const int ID) {

	if (!MPtexSet.contains(ID)) {
		LG("CreateNewRlwITex", "MPtexSet do not contain id: %d \n", ID);
		return nullptr;
	}
	const auto& pTexInfo = MPtexSet[ID];
	if (!pTexInfo) {
		LG("CreateNewRlwITex", "pTexInfo nullptr! id \n", ID);
		return nullptr;
	}
	lwITex* tex;
	lwIResourceMgr* res_mgr = g_Render.GetInterfaceMgr()->res_mgr;
	res_mgr->CreateTex(&tex);

	lwTexInfo tex_info{};
	lwTexInfo_Construct(&tex_info);
	strncpy_s(tex_info.file_name, sizeof tex_info.file_name, pTexInfo->szDataName, _TRUNCATE);
	_tcslwr_s(tex_info.file_name);
	tex_info.pool = D3DPOOL_MANAGED;
	tex_info.usage = 0;
	tex_info.level = D3DX_DEFAULT;
	tex_info.type = TEX_TYPE_FILE;

	D3DFORMAT tex_fmt[2]{};
	tex_fmt[0] = g_Render.GetTexSetFormat(0);
	tex_fmt[1] = g_Render.GetTexSetFormat(1);

	if (const size_t l = _tcslen(tex_info.file_name); tex_info.file_name[l - 1] == 'a' && tex_info.file_name[l - 2] == 'g' && tex_info.file_name[l - 3] == 't') {
		tex_info.format = tex_fmt[1];
	} else {
		tex_info.format = tex_fmt[0];
	}
	//here we skip ui from been deleted 
	if (_tcsstr(tex_info.file_name, "ui")) {
		tex_info.level = D3DX_DEFAULT;

		if (const size_t str_len = _tcslen(tex_info.file_name); _tcsicmp(&tex_info.file_name[str_len - 3], "bmp") == 0) {
			tex_info.colorkey_type = COLORKEY_TYPE_COLOR;
			tex_info.colorkey.color = 0xffff00ff;
			tex_info.format = tex_fmt[1];
		}
	}

	tex->LoadTexInfo(&tex_info, nullptr);
	tex->LoadVideoMemory();

	tex->GetTexInfo(&tex_info);

	// return tex->GetTex();
	pTexInfo->sWidth = static_cast<short>(tex_info.width);
	pTexInfo->sHeight = static_cast<short>(tex_info.height);
	pTexInfo->LwtxtData = tex;
	LG("tex_NewRelease", "Load Texture [%s] size = %d %d, id = %d,mapsize %lu\n", pTexInfo->szDataName, pTexInfo->sWidth, pTexInfo->sHeight, ID, MPtexSet.size());
	return tex;
}

void NewMPTexSet::DeleteRlwITex(const int ID) {
	if (MPtexSet.contains(ID)) {
		const auto& pTexInfo = MPtexSet[ID];
		LG("DeleteRlwITex", "Release Texture Data [%s], size = %d %d pInfoIndex[%d]\n", pTexInfo->szDataName, pTexInfo->sWidth, pTexInfo->sHeight, ID);
		if (pTexInfo) {
			SAFE_RELEASE(pTexInfo->LwtxtData)
		}
	}
}



BOOL NewMPTexSet::IsFull() {
	const DWORD dwMem = g_Render.GetRegisteredDevMemSize();
	if (GenerateRandNumberInrange(0, 100) < 2) {
		LG("vmem", "vmem = %d k\n", dwMem / 1024);
	}
	if (dwMem >= 64 * 1024 * 1024) {
		return TRUE;
	}
	return FALSE;
}

int NewMPTexSet::GetTextureID(const char* pszDataName)  {

	if (MPtexSetNameAndKeys.contains(pszDataName)) {
		const auto& IDkey = MPtexSetNameAndKeys[pszDataName];
		if (MPtexSet.contains(IDkey)) {
			MPtexSet[IDkey]->dwLastUseTick = GetTickCount();
		}
		return IDkey;
	}

	if (!Util_IsFileExist(pszDataName)) { // check if texture exist in our client
		// LG("TextureNotExist", "%s\n", pszDataName);
		return -1;
	}
	//conver string into hash, using int cuz its awful to walk around all classes and change to long long so this work for now 
	const int textid = GenerateMapKeyByName(pszDataName); // Instance()->GetMPtexSetSize() + 1;
	const auto& ret = Instance()->CreateNewTextInfo(textid, pszDataName);
	if (!ret)
		return -1;
	ret->dwLastUseTick = GetTickCount();
	strncpy_s(ret->szDataName, sizeof(ret->szDataName), pszDataName, _TRUNCATE);
	if (const auto NewText = Instance()->CreateNewRlwITex(textid); !NewText) {
		LG("NewTextFail", "%s supposed key %ld\n", pszDataName, textid);
		return -1;
	}
	return textid;
}
