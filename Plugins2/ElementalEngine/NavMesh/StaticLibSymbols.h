//Autogenerated Static Lib File:
//Generated on: 03/23/09 14:27:41

#ifndef INCLUDE_SYMBOLS_NAVMESH
#define INCLUDE_SYMBOLS_NAVMESH
#endif	//#ifndef INCLUDE_SYMBOLS_NAVMESH
#ifdef _LIB

namespace ElementalEngine {
struct INITDLLINFO;
class CRegisterComponent;
class CRegisterMessage;
}

using namespace ElementalEngine;


extern void *NAVMESH_LIBEXTERNS[];
//Singleton externs
extern "C" CRegisterComponent CNavMeshManagerRO;
//Component externs
extern "C" CRegisterComponent CNavMeshObjectRO;
extern "C" CRegisterComponent CNavMeshManagerRO;
extern "C" CRegisterComponent CNavMeshRenderObjectRO;
//Message externs
extern "C" CRegisterMessage GenerateNavMesh_CNavMeshObjectRM;
extern "C" CRegisterMessage VisualizeNavMesh_CNavMeshObjectRM;
extern "C" CRegisterMessage Start_CNavMeshManagerRM;
extern "C" CRegisterMessage Stop_CNavMeshManagerRM;

#endif	//#ifdef _LIB
