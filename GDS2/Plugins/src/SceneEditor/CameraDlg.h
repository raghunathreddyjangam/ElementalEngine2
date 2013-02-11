///============================================================================
/// \note   Elemental Engine
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
///============================================================================

#pragma once


// CCameraDlg dialog

class CCameraDlg : public CDialog
{
	DECLARE_DYNAMIC(CCameraDlg)

public:
	CCameraDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~CCameraDlg();

	void UpdateTick();

// Dialog Data
	enum { IDD = IDD_CAMERADLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	Vec3 m_CameraPosition;
	EulerAngle m_CameraRotation;
	float m_fCameraMoveSpeed;
	afx_msg void OnEnChangeCameraPos();
	afx_msg void OnEnChangeCameraRot();
	afx_msg void OnEnChangeCameraMovespeed();
	afx_msg void OnClose();
};
