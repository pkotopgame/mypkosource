//
#include "stdafx.h"
#include <memory.h>
#include "lwFileEncode.h"

LW_BEGIN

LW_RESULT lwTexEncode::_Encode0(lwIBuffer* buf)
{
    const DWORD i = 38;
    BYTE tmp[i];

    BYTE* p;
    DWORD s;

    p = buf->GetData();
    s = buf->GetSize();

    if(s > i)
    {
        memcpy(tmp, p, i);
        memcpy(p, &p[s - i], i);
        memcpy(&p[s - i], tmp, i);
    }

    return LW_RET_OK;
}
LW_RESULT lwTexEncode::_Decode0(lwIBuffer* buf)
{
    return _Encode0(buf);
}
LW_RESULT lwTexEncode::_Encode1(lwIBuffer* buf)
{
    constexpr auto key = 5;
    BYTE* p;
    DWORD s;

    lwDwordByte4* sp;
    lwDwordByte4 e;
    e.b[0] = 'c';
    e.b[1] = 'f';
    e.b[2] = 'a';
    e.b[3] = 'k';
    e.b[4] = 'z';

    p = buf->GetData();
    s = buf->GetSize();

    sp = (lwDwordByte4*)&p[s - key];

    if(sp->d == e.d)
        return LW_RET_OK;

    _Encode0(buf);

    buf->Realloc(s + key);

    p = buf->GetData();
    s = buf->GetSize();
    const auto maxlength = s - key;
    for (DWORD i = 0; i < maxlength; i++) {
        p[i] += 20;
    }
    memcpy(&p[s - key], &e, sizeof(e));

    return LW_RET_OK;
}
LW_RESULT lwTexEncode::_Decode1(lwIBuffer* buf)
{
    constexpr auto key = 5;
    BYTE* p;
    DWORD s;

    lwDwordByte4* sp;
    lwDwordByte4 e;
    e.b[0] = 'c';
    e.b[1] = 'f';
    e.b[2] = 'a';
    e.b[3] = 'k';
    e.b[4] = 'z';

    p = buf->GetData();
    s = buf->GetSize();

    sp = (lwDwordByte4*)&p[s - key];

    if(sp->d != e.d)
        return LW_RET_OK;

    buf->SetSizeArbitrary(s - key);

    _Decode0(buf);
    const auto maxlength = s - key;
    for (DWORD i = 0; i < maxlength; i++) {
        p[i] -= 20;
    }

    return LW_RET_OK;
}
LW_RESULT lwTexEncode::Encode(lwIBuffer* buf)
{
    return _Encode1(buf);
}
LW_RESULT lwTexEncode::Decode(lwIBuffer* buf)
{
    return _Decode1(buf);
}


LW_END