//Autogenerated Static Lib File:
//Generated on: 03/23/09 14:25:32

#ifndef INCLUDE_SYMBOLS_WORLDEVENT
#define INCLUDE_SYMBOLS_WORLDEVENT
#endif	//#ifndef INCLUDE_SYMBOLS_WORLDEVENT
#ifdef _LIB

namespace ElementalEngine {
struct INITDLLINFO;
class CRegisterComponent;
class CRegisterMessage;
}

using namespace ElementalEngine;


extern void *WORLDEVENT_LIBEXTERNS[];
//Singleton externs
extern "C" CRegisterComponent CWorldEventManagerRO;
//Component externs
extern "C" CRegisterComponent CWorldEventRO;
extern "C" CRegisterComponent CWorldEventManagerRO;
extern "C" CRegisterComponent CWorldEventTriggerRO;
//Message externs
extern "C" CRegisterMessage TriggerWorldEvent_CWorldEventRM;
extern "C" CRegisterMessage GetWorldEventInfo_CWorldEventRM;
extern "C" CRegisterMessage SetWorldEventEvent_CWorldEventRM;
extern "C" CRegisterMessage Start_CWorldEventManagerRM;
extern "C" CRegisterMessage Stop_CWorldEventManagerRM;
extern "C" CRegisterMessage QueryWorldEventTriggers_CWorldEventManagerRM;
extern "C" CRegisterMessage GetWorldEvents_CWorldEventManagerRM;
extern "C" CRegisterMessage FindWorldEventTrigger_CWorldEventManagerRM;
extern "C" CRegisterMessage BroadcastWorldEvent_CWorldEventManagerRM;
extern "C" CRegisterMessage AddWorldEvent_CWorldEventTriggerRM;
extern "C" CRegisterMessage RemoveWorldEvent_CWorldEventTriggerRM;
extern "C" CRegisterMessage QueryWorldEvents_CWorldEventTriggerRM;
extern "C" CRegisterMessage GetWorldEventInfo_CWorldEventTriggerRM;

#endif	//#ifdef _LIB
