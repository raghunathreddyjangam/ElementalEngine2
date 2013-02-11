//Autogenerated Static Lib File:
//Generated on: 03/23/09 14:25:51

#ifndef INCLUDE_SYMBOLS_CAL3DMODEL
#define INCLUDE_SYMBOLS_CAL3DMODEL
#endif	//#ifndef INCLUDE_SYMBOLS_CAL3DMODEL
#ifdef _LIB

namespace ElementalEngine {
struct INITDLLINFO;
class CRegisterComponent;
class CRegisterMessage;
}

using namespace ElementalEngine;


extern void *CAL3DMODEL_LIBEXTERNS[];
//Singleton externs
extern "C" CRegisterComponent Cal3DModelManagerRO;
//Component externs
extern "C" CRegisterComponent CCal3DCoreAnimationCacheRO;
extern "C" CRegisterComponent CCal3DCoreMeshCacheRO;
extern "C" CRegisterComponent CCal3DCoreModelCacheRO;
extern "C" CRegisterComponent CCal3DCoreSkeletonCacheRO;
extern "C" CRegisterComponent Cal3DModelManagerRO;
extern "C" CRegisterComponent Cal3DRenderObjectRO;
//Message externs
extern "C" CRegisterMessage GetCal3dCallback_Cal3DModelManagerRM;
extern "C" CRegisterMessage GetCal3DModelInterface_Cal3DModelManagerRM;
extern "C" CRegisterMessage SaveAllCalCubes_Cal3DModelManagerRM;
extern "C" CRegisterMessage DestroyRenderer_Cal3DModelManagerRM;
extern "C" CRegisterMessage SetCalScaleVariable_Cal3DRenderObjectRM;
extern "C" CRegisterMessage GetModelFileId_Cal3DRenderObjectRM;
extern "C" CRegisterMessage GetControllerInterface_Cal3DRenderObjectRM;
extern "C" CRegisterMessage GetAnimationList_Cal3DRenderObjectRM;
extern "C" CRegisterMessage PlayAnimation_Cal3DRenderObjectRM;
extern "C" CRegisterMessage PlaySingleCycleAnimation_Cal3DRenderObjectRM;
extern "C" CRegisterMessage StopAnimation_Cal3DRenderObjectRM;
extern "C" CRegisterMessage StopAllAnimation_Cal3DRenderObjectRM;
extern "C" CRegisterMessage StopAllAnimationActions_Cal3DRenderObjectRM;
extern "C" CRegisterMessage SetVisibility_Cal3DRenderObjectRM;
extern "C" CRegisterMessage SetMatrix_Cal3DRenderObjectRM;
extern "C" CRegisterMessage GetBoundingSphere_Cal3DRenderObjectRM;
extern "C" CRegisterMessage RegisterAnimationCallback_Cal3DRenderObjectRM;
extern "C" CRegisterMessage UnregisterAnimationCallback_Cal3DRenderObjectRM;
extern "C" CRegisterMessage UnregisterAllAnimationCallbacks_Cal3DRenderObjectRM;
extern "C" CRegisterMessage GetAnimationId_Cal3DRenderObjectRM;
extern "C" CRegisterMessage GetGlobalBoneInfo_Cal3DRenderObjectRM;
extern "C" CRegisterMessage RemoveFromQuadTree_Cal3DRenderObjectRM;
extern "C" CRegisterMessage AddToQuadTree_Cal3DRenderObjectRM;
extern "C" CRegisterMessage GetModelFileName_Cal3DRenderObjectRM;
extern "C" CRegisterMessage GetGeometryAllocations_Cal3DRenderObjectRM;
extern "C" CRegisterMessage GetBoundingBox_Cal3DRenderObjectRM;
extern "C" CRegisterMessage SetLightmapData_Cal3DRenderObjectRM;
extern "C" CRegisterMessage GetParentName_Cal3DRenderObjectRM;
extern "C" CRegisterMessage SetSkeletonPose_Cal3DRenderObjectRM;
extern "C" CRegisterMessage GetSkeletonPose_Cal3DRenderObjectRM;
extern "C" CRegisterMessage EnablePhysicsAnimations_Cal3DRenderObjectRM;
extern "C" CRegisterMessage GetRenderObjectInterface_Cal3DRenderObjectRM;
extern "C" CRegisterMessage SetDrawSkeleton_Cal3DRenderObjectRM;
extern "C" CRegisterMessage SetMaterialOverride_Cal3DRenderObjectRM;
extern "C" CRegisterMessage ClearMaterialOverride_Cal3DRenderObjectRM;
extern "C" CRegisterMessage SetRenderOffset_Cal3DRenderObjectRM;
extern "C" CRegisterMessage GetRenderOffset_Cal3DRenderObjectRM;
extern "C" CRegisterMessage PauseAnimations_Cal3DRenderObjectRM;
extern "C" CRegisterMessage AttachSceneObject_Cal3DRenderObjectRM;

#endif	//#ifdef _LIB
