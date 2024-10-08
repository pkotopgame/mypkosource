//=============================================================================
// FileName: Item.h
// Creater: ZhangXuedong
// Date: 2004.09.21
// Comment: CItem class
//=============================================================================

#ifndef ITEM_H
#define ITEM_H

#include "Character.h"
#include "ItemRecord.h"
#include "CompCommand.h"

#define defITEM_ON_TICK		3 * 60 * 1000

enum EItemProtType // 道具保护类型
{
	enumITEM_PROT_OWN,	// 自己外的其他人
	enumITEM_PROT_TEAM,	// 队伍外的其他人
};

class CItem : public Entity
{
public:
	CItem();

	void	Initially();
	void	Finally();

	virtual void	Run(dbc::uLong ulCurTick);

	SItemGrid	*GetGridContent(void) {return &m_SGridContent;}
	void		SetFromID(dbc::Long lFromEntityID) {m_lFromEntityID = lFromEntityID;}
	void		SetSpawnType(dbc::Char chType) {m_chSpawType = chType;}
	void		SetStartTick(dbc::uLong ulTick) {m_ulStartTick = ulTick;}
	void		SetOnTick(dbc::uLong ulOnTick) {m_ulOnTick = ulOnTick;}
	void		SetProtOnTick(dbc::uLong ulProtOnTick) {m_ulProtOnTick = ulProtOnTick;}
	void SetProtCha(const uLong ulChaID, const uLong ulChaHandle) {
		if (m_ulProtOnTick == 0)
			m_ulProtID = 0;
		else
			m_ulProtID = ulChaID;
		m_ulProtHandle = ulChaHandle;
	}
	dbc::uLong	GetProtChaID(void) {return m_ulProtID;}
	dbc::uLong	GetProtChaHandle(void) {return m_ulProtHandle;}
	void		SetProtType(dbc::Char chType = enumITEM_PROT_OWN) {m_chProtType = chType;}
	dbc::Char	GetProtType(void) {return m_chProtType;}

	char			chValid;
	CItemRecord		*m_pCItemRecord;

	SItemGrid		m_SGridContent;

protected:
	virtual CItem *IsItem(){return this;}

private:
	dbc::Char	m_chSpawType;
	dbc::Long	m_lFromEntityID;
	dbc::uLong	m_ulStartTick;
	dbc::uLong	m_ulOnTick;		// 为0，则永不销毁

	dbc::Char	m_chProtType;	// 保护类型
	dbc::uLong	m_ulProtOnTick;	// 保护时间，0则永久保护
	dbc::uLong	m_ulProtID;		// 道具保护的角色ID
	dbc::uLong	m_ulProtHandle;	// 道具保护的角色Handle

	virtual void OnBeginSeen(CCharacter *pCCha);
	virtual void OnEndSeen(CCharacter *pCCha);
};

#endif // ITEM_H