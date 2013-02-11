///==========================================================================
/// \file	stdafx.h
/// \brief	include file for standard system include files,
///			or project specific include files that are used frequently, but
///			are changed infrequently
/// \date	4/16/2008
/// \author	Kyle Swaim
///         Copyright (c)  2005-2008 Signature Devices, Inc.
///
///         This code is redistributable under the terms of the EE License.
///
///         This code is distributed without warranty or implied warranty of
///			merchantability or fitness for a particular purpose. See the 
///			EE License for more details.
///
///         You should have received a copy of the EE License along with this
///			code; If not, write to Signature Devices, Inc.,
///			3200 Bridge Parkway Suite 102, Redwood City, CA 94086 USA.
///==========================================================================

#pragma once

#define NOMINMAX
#include "Platform.h"

#include <assert.h>

// Elemental Engine Header Files
#include "ElementalEngine.hpp"
#include "EE-SDK.h"
#include "CObjectTemplate.hpp"
#include "EEDefines.h"
#include "CHashString.hpp"
#include "Register.h"
#include "BaseMessages.h"
#include "Vec3.h"
#include "Matrix3x3.h"
#include "Matrix4x4.h"
#include "Quaternion.h"
#include "MathUtils.h"
#include "CManager.h"

// Physics Plugin Header Files
#include "COctreeSceneManager.h"
#include "COctreeScene.h"
#include "COctreeSceneNode.h"