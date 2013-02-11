//Autogenerated Static Lib File:
//Generated on: 03/23/09 13:58:04

#ifndef INCLUDE_SYMBOLS_DATABASEIO
#define INCLUDE_SYMBOLS_DATABASEIO
#endif	//#ifndef INCLUDE_SYMBOLS_DATABASEIO
#ifdef _LIB

namespace ElementalEngine {
struct INITDLLINFO;
class CRegisterComponent;
class CRegisterMessage;
}

using namespace ElementalEngine;


extern void *DATABASEIO_LIBEXTERNS[];
//Singleton externs
extern "C" CRegisterComponent CDatabaseIORO;
extern "C" CRegisterComponent CDefinedDatabaseLoaderRO;
extern "C" CRegisterComponent CSchemaLoaderRO;
//Component externs
extern "C" CRegisterComponent CDatabaseIORO;
extern "C" CRegisterComponent CDefinedDatabaseLoaderRO;
extern "C" CRegisterComponent CSchemaLoaderRO;
//Message externs
extern "C" CRegisterMessage LoadFile_CDatabaseIORM;
extern "C" CRegisterMessage SaveFile_CDatabaseIORM;
extern "C" CRegisterMessage LoadFile_CDefinedDatabaseLoaderRM;
extern "C" CRegisterMessage SaveFile_CDefinedDatabaseLoaderRM;
extern "C" CRegisterMessage LoadFile_CSchemaLoaderRM;
extern "C" CRegisterMessage SaveFile_CSchemaLoaderRM;

#endif	//#ifdef _LIB
