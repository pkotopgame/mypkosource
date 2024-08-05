//=============================================================================
// FileName: ChaAttrType.h
// Creater: ZhangXuedong
// Date: 2004.12.13
// Comment: Character Attribute type
//=============================================================================

#ifndef ATTRTYPE_H
#define ATTRTYPE_H

const long	ATTR_COUNT_BASE0    = 0;
const long	ATTR_LV             = ATTR_COUNT_BASE0 + 0; // ½ÇÉ«µÈ¼¶
const long	ATTR_HP             = ATTR_COUNT_BASE0 + 1; // µ±Ç°HP£¨¶ÔÓÚ´¬Ö»£¬±íÊ¾ÄÍ¾Ã£©
const long	ATTR_SP             = ATTR_COUNT_BASE0 + 2; // µ±Ç°SP£¨¶ÔÓÚ´¬Ö»£¬±íÊ¾²¹¸ø£©
const long	ATTR_TITLE          = ATTR_COUNT_BASE0 + 3; // ½ÇÉ«³ÆºÅ
const long	ATTR_JOB            = ATTR_COUNT_BASE0 + 4; // ½ÇÉ«Ö°Òµ
const long	ATTR_FAME           = ATTR_COUNT_BASE0 + 5; // ÃûÉù
const long	ATTR_AP             = ATTR_COUNT_BASE0 + 6; // ÊôÐÔµã
const long	ATTR_TP             = ATTR_COUNT_BASE0 + 7; // ¼¼ÄÜµã
const long	ATTR_GD             = ATTR_COUNT_BASE0 + 8; // ½ðÇ®
const long	ATTR_SPRI           = ATTR_COUNT_BASE0 + 9; // ÅÚµ¯·ÉÐÐËÙ¶È
const long	ATTR_CHATYPE        = ATTR_COUNT_BASE0 + 10; // ½ÇÉ«¿ØÖÆÀàÐÍ£¨Íæ¼Ò£¬NPC£¬¹ÖÎïµÈ£©
const long	ATTR_SAILLV         = ATTR_COUNT_BASE0 + 11; // º½º£µÈ¼¶
const long	ATTR_LIFELV         = ATTR_COUNT_BASE0 + 12; // Éú»îµÈ¼¶
const long	ATTR_LIFETP         = ATTR_COUNT_BASE0 + 13; // Éú»î¼¼ÄÜµã
const long	ATTR_BOAT_BERTH     = ATTR_COUNT_BASE0 + 14; // ´¬Ö»Í£²´¸Û¿Ú
//			// ÒÔÏÂ·¶Î§ÄÚµÄ¸÷ÊôÐÔµÄË³Ðò²»¿É¸Ä±ä
const long	ATTR_CEXP           = ATTR_COUNT_BASE0 + 15; // µ±Ç°¾­Ñé£¨¶ÔÓÚ´¬Ö»£¬±íÊ¾ÊìÁ·¶È£©
const long	ATTR_NLEXP          = ATTR_COUNT_BASE0 + 16; // ÏÂÒ»¼¶ËùÐè¾­Ñé
const long	ATTR_CLEXP          = ATTR_COUNT_BASE0 + 17; // µ±Ç°µÈ¼¶µÄ¾­Ñé
const long	ATTR_CLEFT_SAILEXP  = ATTR_COUNT_BASE0 + 18; // µ±Ç°Ê£Óàº½º£¾­Ñé
const long	ATTR_CSAILEXP       = ATTR_COUNT_BASE0 + 19; // ÀÛ»ýº½º£¾­Ñé£¨µ±Ç°º½º£¾­Ñé£©
const long	ATTR_CLV_SAILEXP    = ATTR_COUNT_BASE0 + 20; // µ±Ç°µÈ¼¶º½º£¾­Ñé
const long	ATTR_NLV_SAILEXP    = ATTR_COUNT_BASE0 + 21; // ÏÂÒ»µÈ¼¶µÈ¼¶º½º£¾­Ñé
const long	ATTR_CLIFEEXP       = ATTR_COUNT_BASE0 + 22; // µ±Ç°Éú»î¾­Ñé
const long	ATTR_CLV_LIFEEXP    = ATTR_COUNT_BASE0 + 23; // µ±Ç°µÈ¼¶Éú»î¾­Ñé
const long	ATTR_NLV_LIFEEXP    = ATTR_COUNT_BASE0 + 24; // ÏÂÒ»µÈ¼¶Éú»î¾­Ñé
//			//

const long	ATTR_COUNT_BASE1    = 25;
const long	ATTR_STR            = ATTR_COUNT_BASE1 + 0; // Á¦Á¿
const long	ATTR_DEX            = ATTR_COUNT_BASE1 + 1; // ×¨×¢
const long	ATTR_AGI            = ATTR_COUNT_BASE1 + 2; // Ãô½Ý
const long	ATTR_CON            = ATTR_COUNT_BASE1 + 3; // ÌåÖÊ
const long	ATTR_STA            = ATTR_COUNT_BASE1 + 4; // ¾«Á¦
const long	ATTR_LUK            = ATTR_COUNT_BASE1 + 5; // ÐÒÔË
const long	ATTR_MXHP           = ATTR_COUNT_BASE1 + 6; // ×î´óHP
const long	ATTR_MXSP           = ATTR_COUNT_BASE1 + 7; // ×î´óSP
const long	ATTR_MNATK          = ATTR_COUNT_BASE1 + 8; // ×îÐ¡¹¥»÷Á¦
const long	ATTR_MXATK          = ATTR_COUNT_BASE1 + 9; // ×î´ó¹¥»÷Á¦
const long	ATTR_DEF            = ATTR_COUNT_BASE1 + 10; // ·ÀÓùÁ¦
const long	ATTR_HIT            = ATTR_COUNT_BASE1 + 11; // ÃüÖÐÂÊ
const long	ATTR_FLEE           = ATTR_COUNT_BASE1 + 12; // ÉÁ±ÜÂÊ
const long	ATTR_MF             = ATTR_COUNT_BASE1 + 13; // Ñ°±¦ÂÊ
const long	ATTR_CRT            = ATTR_COUNT_BASE1 + 14; // ±¬»÷ÂÊ
const long	ATTR_HREC           = ATTR_COUNT_BASE1 + 15; // hp»Ö¸´ËÙ¶È
const long	ATTR_SREC           = ATTR_COUNT_BASE1 + 16; // sp»Ö¸´ËÙ¶È
const long	ATTR_ASPD           = ATTR_COUNT_BASE1 + 17; // ¹¥»÷¼ä¸ô
const long	ATTR_ADIS           = ATTR_COUNT_BASE1 + 18; // ¹¥»÷¾àÀë
const long	ATTR_MSPD           = ATTR_COUNT_BASE1 + 19; // ÒÆ¶¯ËÙ¶È
const long	ATTR_COL            = ATTR_COUNT_BASE1 + 20; // ×ÊÔ´²É¼¯ËÙ¶È
const long	ATTR_PDEF           = ATTR_COUNT_BASE1 + 21; // ÎïÀíµÖ¿¹
const long  ATTR_BOAT_CRANGE    = ATTR_COUNT_BASE1 + 22; // ´¬Ö»ÅÚµ¯±¬Õ¨·¶Î§
const long  ATTR_BOAT_CSPD      = ATTR_COUNT_BASE1 + 23; // ´¬Ö»ÅÚµ¯·ÉÐÐËÙ¶È
const long  ATTR_BOAT_PRICE     = ATTR_COUNT_BASE1 + 24; // ´¬µÄ¼ÛÖµ

const long	ATTR_COUNT_BASE2    = 50;
const long	ATTR_BSTR           = ATTR_COUNT_BASE2 + 0; // »ù±¾Á¦Á¿
const long	ATTR_BDEX           = ATTR_COUNT_BASE2 + 1; // »ù±¾×¨×¢
const long	ATTR_BAGI           = ATTR_COUNT_BASE2 + 2; // »ù±¾Ãô½Ý
const long	ATTR_BCON           = ATTR_COUNT_BASE2 + 3; // »ù±¾ÌåÖÊ
const long	ATTR_BSTA           = ATTR_COUNT_BASE2 + 4; // »ù±¾¾«Á¦
const long	ATTR_BLUK           = ATTR_COUNT_BASE2 + 5; // »ù±¾ÐÒÔË
const long	ATTR_BMXHP          = ATTR_COUNT_BASE2 + 6; // »ù±¾×î´óHP
const long	ATTR_BMXSP          = ATTR_COUNT_BASE2 + 7; // »ù±¾×î´óSP
const long	ATTR_BMNATK         = ATTR_COUNT_BASE2 + 8; // »ù±¾×îÐ¡¹¥»÷Á¦
const long	ATTR_BMXATK         = ATTR_COUNT_BASE2 + 9; // »ù±¾×î´ó¹¥»÷Á¦
const long	ATTR_BDEF           = ATTR_COUNT_BASE2 + 10; // »ù±¾·ÀÓùÁ¦
const long	ATTR_BHIT           = ATTR_COUNT_BASE2 + 11; // »ù±¾ÃüÖÐÂÊ
const long	ATTR_BFLEE          = ATTR_COUNT_BASE2 + 12; // »ù±¾ÉÁ±ÜÂÊ
const long	ATTR_BMF            = ATTR_COUNT_BASE2 + 13; // »ù±¾Ñ°±¦ÂÊ
const long	ATTR_BCRT           = ATTR_COUNT_BASE2 + 14; // »ù±¾±¬»÷ÂÊ
const long	ATTR_BHREC          = ATTR_COUNT_BASE2 + 15; // »ù±¾hp»Ö¸´ËÙ¶È
const long	ATTR_BSREC          = ATTR_COUNT_BASE2 + 16; // »ù±¾(½ÇÉ«sp»Ö¸´ËÙ¶È)(´¬Ö»ÎªÏûºÄËÙ¶È)
const long	ATTR_BASPD          = ATTR_COUNT_BASE2 + 17; // »ù±¾¹¥»÷¼ä¸ô
const long	ATTR_BADIS          = ATTR_COUNT_BASE2 + 18; // »ù±¾¹¥»÷¾àÀë
const long	ATTR_BMSPD          = ATTR_COUNT_BASE2 + 19; // »ù±¾ÒÆ¶¯ËÙ¶È
const long	ATTR_BCOL           = ATTR_COUNT_BASE2 + 20; // »ù±¾×ÊÔ´²É¼¯ËÙ¶È
const long	ATTR_BPDEF          = ATTR_COUNT_BASE2 + 21; // »ù±¾ÎïÀíµÖ¿¹
const long  ATTR_BOAT_BCRANGE   = ATTR_COUNT_BASE2 + 22; // ´¬Ö»»ù±¾ÅÚµ¯±¬Õ¨·¶Î§
const long  ATTR_BOAT_BCSPD     = ATTR_COUNT_BASE2 + 23; // ´¬Ö»»ù±¾ÅÚµ¯·ÉÐÐËÙ¶È

const long	ATTR_COUNT_BASE3    = 74;
const long	ATTR_ITEMC_STR      = ATTR_COUNT_BASE3 + 0; // Á¦Á¿µÀ¾ßÏµÊý£¨item coefficient£©¼Ó³É
const long	ATTR_ITEMC_AGI      = ATTR_COUNT_BASE3 + 1; // Ãô½ÝµÀ¾ßÏµÊý¼Ó³É
const long	ATTR_ITEMC_DEX      = ATTR_COUNT_BASE3 + 2; // ×¨×¢µÀ¾ßÏµÊý¼Ó³É
const long	ATTR_ITEMC_CON      = ATTR_COUNT_BASE3 + 3; // ÌåÖÊµÀ¾ßÏµÊý¼Ó³É
const long	ATTR_ITEMC_STA      = ATTR_COUNT_BASE3 + 4; // ¾«Á¦µÀ¾ßÏµÊý¼Ó³É
const long	ATTR_ITEMC_LUK      = ATTR_COUNT_BASE3 + 5; // ÐÒÔËµÀ¾ßÏµÊý¼Ó³É
const long	ATTR_ITEMC_ASPD     = ATTR_COUNT_BASE3 + 6; // ¹¥»÷¼ä¸ôµÀ¾ßÏµÊý¼Ó³É
const long	ATTR_ITEMC_ADIS     = ATTR_COUNT_BASE3 + 7; // ¹¥»÷¾àÀëµÀ¾ßÏµÊý¼Ó³É
const long	ATTR_ITEMC_MNATK    = ATTR_COUNT_BASE3 + 8; // ×îÐ¡¹¥»÷Á¦µÀ¾ßÏµÊý¼Ó³É
const long	ATTR_ITEMC_MXATK    = ATTR_COUNT_BASE3 + 9; // ×î´ó¹¥»÷Á¦µÀ¾ßÏµÊý¼Ó³É
const long	ATTR_ITEMC_DEF      = ATTR_COUNT_BASE3 + 10; // ·ÀÓùÁ¦µÀ¾ßÏµÊý¼Ó³É
const long	ATTR_ITEMC_MXHP     = ATTR_COUNT_BASE3 + 11; // ×î´óHPµÀ¾ßÏµÊý¼Ó³É
const long	ATTR_ITEMC_MXSP     = ATTR_COUNT_BASE3 + 12; // ×î´óSPµÀ¾ßÏµÊý¼Ó³É
const long	ATTR_ITEMC_FLEE     = ATTR_COUNT_BASE3 + 13; // ÉÁ±ÜÂÊµÀ¾ßÏµÊý¼Ó³É
const long	ATTR_ITEMC_HIT      = ATTR_COUNT_BASE3 + 14; // ÃüÖÐÂÊµÀ¾ßÏµÊý¼Ó³É
const long	ATTR_ITEMC_CRT      = ATTR_COUNT_BASE3 + 15; // ±¬»÷ÂÊµÀ¾ßÏµÊý¼Ó³É
const long	ATTR_ITEMC_MF       = ATTR_COUNT_BASE3 + 16; // Ñ°±¦ÂÊµÀ¾ßÏµÊý¼Ó³É
const long	ATTR_ITEMC_HREC     = ATTR_COUNT_BASE3 + 17; // hp»Ö¸´ËÙ¶ÈµÀ¾ßÏµÊý¼Ó³É
const long	ATTR_ITEMC_SREC     = ATTR_COUNT_BASE3 + 18; // sp»Ö¸´ËÙ¶ÈµÀ¾ßÏµÊý¼Ó³É
const long	ATTR_ITEMC_MSPD     = ATTR_COUNT_BASE3 + 19; // ÒÆ¶¯ËÙ¶ÈµÀ¾ßÏµÊý¼Ó³É
const long	ATTR_ITEMC_COL      = ATTR_COUNT_BASE3 + 20; // ×ÊÔ´²É¼¯ËÙ¶ÈµÀ¾ßÏµÊý¼Ó³É
const long	ATTR_ITEMC_PDEF     = ATTR_COUNT_BASE3 + 21; // ÎïÀíµÖ¿¹µÀ¾ßÏµÊý¼Ó³É

const long	ATTR_COUNT_BASE4    = 96;
const long	ATTR_ITEMV_STR      = ATTR_COUNT_BASE4 + 0; // Á¦Á¿µÀ¾ßÊýÖµ£¨item value£©¼Ó³É
const long	ATTR_ITEMV_AGI      = ATTR_COUNT_BASE4 + 1; // Ãô½ÝµÀ¾ßÊýÖµ¼Ó³É
const long	ATTR_ITEMV_DEX      = ATTR_COUNT_BASE4 + 2; // ×¨×¢µÀ¾ßÊýÖµ¼Ó³É
const long	ATTR_ITEMV_CON      = ATTR_COUNT_BASE4 + 3; // ÌåÖÊµÀ¾ßÊýÖµ¼Ó³É
const long	ATTR_ITEMV_STA      = ATTR_COUNT_BASE4 + 4; // ¾«Á¦µÀ¾ßÊýÖµ¼Ó³É
const long	ATTR_ITEMV_LUK      = ATTR_COUNT_BASE4 + 5; // ÐÒÔËµÀ¾ßÊýÖµ¼Ó³É
const long	ATTR_ITEMV_ASPD     = ATTR_COUNT_BASE4 + 6; // ¹¥»÷¼ä¸ôµÀ¾ßÊýÖµ¼Ó³É
const long	ATTR_ITEMV_ADIS     = ATTR_COUNT_BASE4 + 7; // ¹¥»÷¾àÀëµÀ¾ßÊýÖµ¼Ó³É
const long	ATTR_ITEMV_MNATK    = ATTR_COUNT_BASE4 + 8; // ×îÐ¡¹¥»÷Á¦µÀ¾ßÊýÖµ¼Ó³É
const long	ATTR_ITEMV_MXATK    = ATTR_COUNT_BASE4 + 9; // ×î´ó¹¥»÷Á¦µÀ¾ßÊýÖµ¼Ó³É
const long	ATTR_ITEMV_DEF      = ATTR_COUNT_BASE4 + 10; // ·ÀÓùÁ¦µÀ¾ßÊýÖµ¼Ó³É
const long	ATTR_ITEMV_MXHP     = ATTR_COUNT_BASE4 + 11; // ×î´óHPµÀ¾ßÊýÖµ¼Ó³É
const long	ATTR_ITEMV_MXSP     = ATTR_COUNT_BASE4 + 12; // ×î´óSPµÀ¾ßÊýÖµ¼Ó³É
const long	ATTR_ITEMV_FLEE     = ATTR_COUNT_BASE4 + 13; // ÉÁ±ÜÂÊµÀ¾ßÊýÖµ¼Ó³É
const long	ATTR_ITEMV_HIT      = ATTR_COUNT_BASE4 + 14; // ÃüÖÐÂÊµÀ¾ßÊýÖµ¼Ó³É
const long	ATTR_ITEMV_CRT      = ATTR_COUNT_BASE4 + 15; // ±¬»÷ÂÊµÀ¾ßÊýÖµ¼Ó³É
const long	ATTR_ITEMV_MF       = ATTR_COUNT_BASE4 + 16; // Ñ°±¦ÂÊµÀ¾ßÊýÖµ¼Ó³É
const long	ATTR_ITEMV_HREC     = ATTR_COUNT_BASE4 + 17; // hp»Ö¸´ËÙ¶ÈµÀ¾ßÊýÖµ¼Ó³É
const long	ATTR_ITEMV_SREC     = ATTR_COUNT_BASE4 + 18; // sp»Ö¸´ËÙ¶ÈµÀ¾ßÊýÖµ¼Ó³É
const long	ATTR_ITEMV_MSPD     = ATTR_COUNT_BASE4 + 19; // ÒÆ¶¯ËÙ¶ÈµÀ¾ßÊýÖµ¼Ó³É
const long	ATTR_ITEMV_COL      = ATTR_COUNT_BASE4 + 20; // ×ÊÔ´²É¼¯ËÙ¶ÈµÀ¾ßÊýÖµ¼Ó³É
const long	ATTR_ITEMV_PDEF     = ATTR_COUNT_BASE4 + 21; // ÎïÀíµÖ¿¹µÀ¾ßÊýÖµ¼Ó³É

const long	ATTR_COUNT_BASE5    = 118;
const long	ATTR_STATEC_STR     = ATTR_COUNT_BASE5 + 0; // Á¦Á¿×´Ì¬ÏµÊý£¨state coefficient£©¼Ó³É
const long	ATTR_STATEC_AGI     = ATTR_COUNT_BASE5 + 1; // Ãô½Ý×´Ì¬ÏµÊý¼Ó³É
const long	ATTR_STATEC_DEX     = ATTR_COUNT_BASE5 + 2; // ×¨×¢×´Ì¬ÏµÊý¼Ó³É
const long	ATTR_STATEC_CON     = ATTR_COUNT_BASE5 + 3; // ÌåÖÊ×´Ì¬ÏµÊý¼Ó³É
const long	ATTR_STATEC_STA     = ATTR_COUNT_BASE5 + 4; // ¾«Á¦×´Ì¬ÏµÊý¼Ó³É
const long	ATTR_STATEC_LUK     = ATTR_COUNT_BASE5 + 5; // ÐÒÔË×´Ì¬ÏµÊý¼Ó³É
const long	ATTR_STATEC_ASPD    = ATTR_COUNT_BASE5 + 6; // ¹¥»÷¼ä¸ô×´Ì¬ÏµÊý¼Ó³É
const long	ATTR_STATEC_ADIS    = ATTR_COUNT_BASE5 + 7; // ¹¥»÷¾àÀë×´Ì¬ÏµÊý¼Ó³É
const long	ATTR_STATEC_MNATK   = ATTR_COUNT_BASE5 + 8; // ×îÐ¡¹¥»÷Á¦×´Ì¬ÏµÊý¼Ó³É
const long	ATTR_STATEC_MXATK   = ATTR_COUNT_BASE5 + 9; // ×î´ó¹¥»÷Á¦×´Ì¬ÏµÊý¼Ó³É
const long	ATTR_STATEC_DEF     = ATTR_COUNT_BASE5 + 10; // ·ÀÓùÁ¦×´Ì¬ÏµÊý¼Ó³É
const long	ATTR_STATEC_MXHP    = ATTR_COUNT_BASE5 + 11; // ×î´óHP×´Ì¬ÏµÊý¼Ó³É
const long	ATTR_STATEC_MXSP    = ATTR_COUNT_BASE5 + 12; // ×î´óSP×´Ì¬ÏµÊý¼Ó³É
const long	ATTR_STATEC_FLEE    = ATTR_COUNT_BASE5 + 13; // ÉÁ±ÜÂÊ×´Ì¬ÏµÊý¼Ó³É
const long	ATTR_STATEC_HIT     = ATTR_COUNT_BASE5 + 14; // ÃüÖÐÂÊ×´Ì¬ÏµÊý¼Ó³É
const long	ATTR_STATEC_CRT     = ATTR_COUNT_BASE5 + 15; // ±¬»÷ÂÊ×´Ì¬ÏµÊý¼Ó³É
const long	ATTR_STATEC_MF      = ATTR_COUNT_BASE5 + 16; // Ñ°±¦ÂÊ×´Ì¬ÏµÊý¼Ó³É
const long	ATTR_STATEC_HREC    = ATTR_COUNT_BASE5 + 17; // hp»Ö¸´ËÙ¶È×´Ì¬ÏµÊý¼Ó³É
const long	ATTR_STATEC_SREC    = ATTR_COUNT_BASE5 + 18; // sp»Ö¸´ËÙ¶È×´Ì¬ÏµÊý¼Ó³É
const long	ATTR_STATEC_MSPD    = ATTR_COUNT_BASE5 + 19; // ÒÆ¶¯ËÙ¶È×´Ì¬ÏµÊý¼Ó³É
const long	ATTR_STATEC_COL     = ATTR_COUNT_BASE5 + 20; // ×ÊÔ´²É¼¯ËÙ¶È×´Ì¬ÏµÊý¼Ó³É
const long	ATTR_STATEC_PDEF    = ATTR_COUNT_BASE5 + 21; // ÎïÀíµÖ¿¹×´Ì¬ÏµÊý¼Ó³É

const long	ATTR_COUNT_BASE6    = 140;
const long	ATTR_STATEV_STR     = ATTR_COUNT_BASE6 + 0; // Á¦Á¿×´Ì¬ÊýÖµ£¨state value£©¼Ó³É
const long	ATTR_STATEV_AGI     = ATTR_COUNT_BASE6 + 1; // Ãô½Ý×´Ì¬ÊýÖµ¼Ó³É
const long	ATTR_STATEV_DEX     = ATTR_COUNT_BASE6 + 2; // ×¨×¢×´Ì¬ÊýÖµ¼Ó³É
const long	ATTR_STATEV_CON     = ATTR_COUNT_BASE6 + 3; // ÌåÖÊ×´Ì¬ÊýÖµ¼Ó³É
const long	ATTR_STATEV_STA     = ATTR_COUNT_BASE6 + 4; // ¾«Á¦×´Ì¬ÊýÖµ¼Ó³É
const long	ATTR_STATEV_LUK     = ATTR_COUNT_BASE6 + 5; // ÐÒÔË×´Ì¬ÊýÖµ¼Ó³É
const long	ATTR_STATEV_ASPD    = ATTR_COUNT_BASE6 + 6; // ¹¥»÷¼ä¸ô×´Ì¬ÊýÖµ¼Ó³É
const long	ATTR_STATEV_ADIS    = ATTR_COUNT_BASE6 + 7; // ¹¥»÷¾àÀë×´Ì¬ÊýÖµ¼Ó³É
const long	ATTR_STATEV_MNATK   = ATTR_COUNT_BASE6 + 8; // ×îÐ¡¹¥»÷Á¦×´Ì¬ÊýÖµ¼Ó³É
const long	ATTR_STATEV_MXATK   = ATTR_COUNT_BASE6 + 9; // ×î´ó¹¥»÷Á¦×´Ì¬ÊýÖµ¼Ó³É
const long	ATTR_STATEV_DEF     = ATTR_COUNT_BASE6 + 10; // ·ÀÓùÁ¦×´Ì¬ÊýÖµ¼Ó³É
const long	ATTR_STATEV_MXHP    = ATTR_COUNT_BASE6 + 11; // ×î´óHP×´Ì¬ÊýÖµ¼Ó³É
const long	ATTR_STATEV_MXSP    = ATTR_COUNT_BASE6 + 12; // ×î´óSP×´Ì¬ÊýÖµ¼Ó³É
const long	ATTR_STATEV_FLEE    = ATTR_COUNT_BASE6 + 13; // ÉÁ±ÜÂÊ×´Ì¬ÊýÖµ¼Ó³É
const long	ATTR_STATEV_HIT     = ATTR_COUNT_BASE6 + 14; // ÃüÖÐÂÊ×´Ì¬ÊýÖµ¼Ó³É
const long	ATTR_STATEV_CRT     = ATTR_COUNT_BASE6 + 15; // ±¬»÷ÂÊ×´Ì¬ÊýÖµ¼Ó³É
const long	ATTR_STATEV_MF      = ATTR_COUNT_BASE6 + 16; // Ñ°±¦ÂÊ×´Ì¬ÊýÖµ¼Ó³É
const long	ATTR_STATEV_HREC    = ATTR_COUNT_BASE6 + 17; // hp»Ö¸´ËÙ¶È×´Ì¬ÊýÖµ¼Ó³É
const long	ATTR_STATEV_SREC    = ATTR_COUNT_BASE6 + 18; // sp»Ö¸´ËÙ¶È×´Ì¬ÊýÖµ¼Ó³É
const long	ATTR_STATEV_MSPD    = ATTR_COUNT_BASE6 + 19; // ÒÆ¶¯ËÙ¶È×´Ì¬ÊýÖµ¼Ó³É
const long	ATTR_STATEV_COL     = ATTR_COUNT_BASE6 + 20; // ×ÊÔ´²É¼¯ËÙ¶È×´Ì¬ÊýÖµ¼Ó³É
const long	ATTR_STATEV_PDEF    = ATTR_COUNT_BASE6 + 21; // ÎïÀíµÖ¿¹×´Ì¬ÊýÖµ¼Ó³É

const long	ATTR_LHAND_ITEMV    = ATTR_COUNT_BASE6 + 22; // ×óÊÖµÀ¾ß¼Ó³É

const long	ATTR_COUNT_BASE7        = 163;
const long	ATTR_BOAT_SHIP          = ATTR_COUNT_BASE7 + 0; // ´¬Ö»ID
const long	ATTR_BOAT_HEADER        = ATTR_COUNT_BASE7 + 1; // ´¬Í·ÀàÐÍ
const long  ATTR_BOAT_BODY          = ATTR_COUNT_BASE7 + 2; // ´¬ÉíÀàÐÍ
const long  ATTR_BOAT_ENGINE        = ATTR_COUNT_BASE7 + 3; // ´¬ÒýÇæÀàÐÍ
const long  ATTR_BOAT_CANNON        = ATTR_COUNT_BASE7 + 4; // ´¬»ðÅÚÀàÐÍ
const long	ATTR_BOAT_PART          = ATTR_COUNT_BASE7 + 5; // ´¬Åä¼þÀàÐÍ
const long  ATTR_BOAT_DBID          = ATTR_COUNT_BASE7 + 6; // ´¬µÄÊý¾Ý¿â´æ´¢ID
const long  ATTR_BOAT_DIECOUNT      = ATTR_COUNT_BASE7 + 7; // ¸Ã´¬ËÀÍö¼ÆÊý
const long  ATTR_BOAT_ISDEAD	    = ATTR_COUNT_BASE7 + 8; // ¸Ã´¬Ä¿Ç°ÊÇ·ñÎªËÀÍö×´Ì¬

const long	ATTR_COUNT_BASE8        = 172;
const long	ATTR_BOAT_SKILLC_MNATK  = ATTR_COUNT_BASE8 + 0; // ´¬Ö»MNATK ¼¼ÄÜÏµÊýÓ°Ïì
const long	ATTR_BOAT_SKILLC_MXATK  = ATTR_COUNT_BASE8 + 1; // ´¬Ö»MXATK ¼¼ÄÜÏµÊýÓ°Ïì
const long	ATTR_BOAT_SKILLC_ADIS   = ATTR_COUNT_BASE8 + 2; // ´¬Ö»¹¥»÷¾àÀëatkrange ¼¼ÄÜÏµÊýÓ°Ïì
const long	ATTR_BOAT_SKILLC_MSPD   = ATTR_COUNT_BASE8 + 3; // ´¬Ö»ÒÆ¶¯ËÙ¶È¼¼ÄÜÏµÊýÓ°Ïì
const long	ATTR_BOAT_SKILLC_CSPD   = ATTR_COUNT_BASE8 + 4; // ÅÚµ¯·ÉÐÐËÙ¶È ¼¼ÄÜÏµÊýÓ°Ïì
const long	ATTR_BOAT_SKILLC_ASPD   = ATTR_COUNT_BASE8 + 5; // ´¬Ö»ASPD ¼¼ÄÜÏµÊýÓ°Ïì
const long	ATTR_BOAT_SKILLC_CRANGE = ATTR_COUNT_BASE8 + 6; // ÅÚµ¯±¬Õ¨·¶Î§ ¼¼ÄÜÏµÊýÓ°Ïì
const long	ATTR_BOAT_SKILLC_DEF    = ATTR_COUNT_BASE8 + 7; // ´¬Ö»DEF ¼¼ÄÜÏµÊýÓ°Ïì
const long	ATTR_BOAT_SKILLC_RESIST = ATTR_COUNT_BASE8 + 8; // ´¬Ö»RESIST ¼¼ÄÜÏµÊýÓ°Ïì
const long	ATTR_BOAT_SKILLC_MXUSE  = ATTR_COUNT_BASE8 + 9; // ´¬Ö»×î´óÄÍ¾Ã ¼¼ÄÜÏµÊýÓ°Ïì
const long	ATTR_BOAT_SKILLC_USEREC = ATTR_COUNT_BASE8 + 10; // ´¬Ö»ÄÍ¾Ã»Ø¸´ËÙ¶È ¼¼ÄÜÏµÊýÓ°Ïì
const long	ATTR_BOAT_SKILLC_EXP    = ATTR_COUNT_BASE8 + 11; // ´¬Ö»ÏûºÄÂÊ ¼¼ÄÜÏµÊýÓ°Ïì
const long	ATTR_BOAT_SKILLC_CPT    = ATTR_COUNT_BASE8 + 12; // ´¬²ÖÈÝÁ¿ ¼¼ÄÜÏµÊýÓ°Ïì
const long	ATTR_BOAT_SKILLC_SPD    = ATTR_COUNT_BASE8 + 13; // º½ËÙ ¼¼ÄÜÏµÊýÓ°Ïì
const long	ATTR_BOAT_SKILLC_MXSPLY = ATTR_COUNT_BASE8 + 14; // ×î´ó²¹¸øÖµ ¼¼ÄÜÏµÊýÓ°Ïì

const long	ATTR_COUNT_BASE9        = 187;
const long	ATTR_BOAT_SKILLV_MNATK  = ATTR_COUNT_BASE9 + 0; // ´¬Ö»MNATK ¼¼ÄÜ³£ÊýÓ°Ïì
const long	ATTR_BOAT_SKILLV_MXATK  = ATTR_COUNT_BASE9 + 1; // ´¬Ö»MXATK ¼¼ÄÜ³£ÊýÓ°Ïì
const long	ATTR_BOAT_SKILLV_ADIS   = ATTR_COUNT_BASE9 + 2; // ´¬Ö»¹¥»÷¾àÀëatkrange ¼¼ÄÜ³£ÊýÓ°Ïì
const long	ATTR_BOAT_SKILLV_MSPD   = ATTR_COUNT_BASE9 + 3; // ´¬Ö»ÒÆ¶¯ËÙ¶È¼¼ÄÜ³£ÊýÓ°Ïì
const long	ATTR_BOAT_SKILLV_CSPD   = ATTR_COUNT_BASE9 + 4; // ÅÚµ¯·ÉÐÐËÙ¶È ¼¼ÄÜ³£ÊýÓ°Ïì
const long	ATTR_BOAT_SKILLV_ASPD   = ATTR_COUNT_BASE9 + 5; // ´¬Ö»ASPD ¼¼ÄÜ³£ÊýÓ°Ïì
const long	ATTR_BOAT_SKILLV_CRANGE = ATTR_COUNT_BASE9 + 6; // ÅÚµ¯±¬Õ¨·¶Î§ ¼¼ÄÜ³£ÊýÓ°Ïì
const long	ATTR_BOAT_SKILLV_DEF    = ATTR_COUNT_BASE9 + 7; // ´¬Ö»DEF ¼¼ÄÜ³£ÊýÓ°Ïì
const long	ATTR_BOAT_SKILLV_RESIST = ATTR_COUNT_BASE9 + 8; // ´¬Ö»RESIST ¼¼ÄÜ³£ÊýÓ°Ïì
const long	ATTR_BOAT_SKILLV_MXUSE  = ATTR_COUNT_BASE9 + 9; // ´¬Ö»×î´óÄÍ¾Ã ¼¼ÄÜ³£ÊýÓ°Ïì
const long	ATTR_BOAT_SKILLV_USEREC = ATTR_COUNT_BASE9 + 10; // ´¬Ö»ÄÍ¾Ã»Ø¸´ËÙ¶È ¼¼ÄÜ³£ÊýÓ°Ïì
const long	ATTR_BOAT_SKILLV_EXP    = ATTR_COUNT_BASE9 + 11; // ´¬Ö»ÏûºÄÂÊ ¼¼ÄÜ³£ÊýÓ°Ïì
const long	ATTR_BOAT_SKILLV_CPT    = ATTR_COUNT_BASE9 + 12; // ´¬²ÖÈÝÁ¿ ¼¼ÄÜ³£ÊýÓ°Ïì
const long	ATTR_BOAT_SKILLV_SPD    = ATTR_COUNT_BASE9 + 13; // º½ËÙ ¼¼ÄÜ³£ÊýÓ°Ïì
const long	ATTR_BOAT_SKILLV_MXSPLY = ATTR_COUNT_BASE9 + 14; // ×î´ó²¹¸øÖµ ¼¼ÄÜ³£ÊýÓ°Ïì

/////////////////////////////////////////////////////
/////////// ** Start Custom Attributes ** ///////////
/////////////////////////////////////////////////////
const long	ATTR_COUNT_BASE10 = 202;
const long	ATTR_ARENA_RANK = ATTR_COUNT_BASE10 + 0;	//	202	Arena Ranking.
const long	ATTR_ARENA_BATTLE = ATTR_COUNT_BASE10 + 1;	//	203	Arena Battle.
const long	ATTR_ARENA_VICTORY = ATTR_COUNT_BASE10 + 2;	//	204	Arena Victory.
const long	ATTR_ARENA_KILL = ATTR_COUNT_BASE10 + 3;	//	205	Arena Kill.
const long	ATTR_ARENA_DEATH = ATTR_COUNT_BASE10 + 4;	//	206	Arena Death.
const long	ATTR_ARENA_POINT = ATTR_COUNT_BASE10 + 5;	//	207	Arena Point.

const long	ATTR_CHAOS_RANK = ATTR_COUNT_BASE10 + 6;	//	208	Chaos Argent Ranking.
const long	ATTR_CHAOS_BATTLE = ATTR_COUNT_BASE10 + 7;	//	209	Chaos Argent Battle.
const long	ATTR_CHAOS_VICTORY = ATTR_COUNT_BASE10 + 8;	//	210	Chaos Argent Victory.
const long	ATTR_CHAOS_KILL = ATTR_COUNT_BASE10 + 9;	//	211	Chaos Argent Kill.
const long	ATTR_CHAOS_DEATH = ATTR_COUNT_BASE10 + 10;	//	212	Chaos Argent Death.
const long	ATTR_CHAOS_POINT = ATTR_COUNT_BASE10 + 11;	//	213	Chaos Argent Point.
/////////////////////////////////////////////////////
//////////// ** End Custom Attributes ** ////////////
/////////////////////////////////////////////////////
const long	ATTR_MAX_NUM = ATTR_CHAOS_POINT + 1;

const long	ATTR_CLIENT_MAX = ATTR_MAX_NUM;
const long  MAX_ATTR_CLIENT = ATTR_MAX_NUM;				// 可用属性最大值,仅客户端用
const long	ATTR_CLIENT_SIGN_BYTE_NUM = (ATTR_CLIENT_MAX + sizeof(char) * 8 - 1) / (sizeof(char) * 8);
const long	ATTR_SIGN_BYTE_NUM = (ATTR_MAX_NUM + sizeof(char) * 8 - 1) / (sizeof(char) * 8);

inline bool	g_IsNosignChaAttr(long lAttrNo)
{
	if (lAttrNo >= ATTR_CEXP && lAttrNo <= ATTR_NLV_LIFEEXP)
		return true;

	return false;
}

#endif // ATTRTYPE_H