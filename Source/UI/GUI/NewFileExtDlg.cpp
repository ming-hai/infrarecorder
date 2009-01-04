/*
 * InfraRecorder - CD/DVD burning software
 * Copyright (C) 2006-2009 Christian Kindahl
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "stdafx.h"
#include "NewFileExtDlg.h"
#include "../../Common/StringUtil.h"
#include "StringTable.h"
#include "Settings.h"

CNewFileExtDlg::CNewFileExtDlg()
{
}

CNewFileExtDlg::~CNewFileExtDlg()
{
}

bool CNewFileExtDlg::Translate()
{
	if (g_LanguageSettings.m_pLNGProcessor == NULL)
		return false;

	CLNGProcessor *pLNG = g_LanguageSettings.m_pLNGProcessor;
	
	// Make sure that there is a newfileext translation section.
	if (!pLNG->EnterSection(_T("newfileext")))
		return false;

	// Translate.
	TCHAR *szStrValue;

	if (pLNG->GetValuePtr(IDD_NEWFILEEXTDLG,szStrValue))	// Title.
		SetWindowText(szStrValue);
	if (pLNG->GetValuePtr(IDOK,szStrValue))
		SetDlgItemText(IDOK,szStrValue);
	if (pLNG->GetValuePtr(IDCANCEL,szStrValue))
		SetDlgItemText(IDCANCEL,szStrValue);
	if (pLNG->GetValuePtr(IDC_DESCSTATIC,szStrValue))
		SetDlgItemText(IDC_DESCSTATIC,szStrValue);
	if (pLNG->GetValuePtr(IDC_EXTSTATIC,szStrValue))
		SetDlgItemText(IDC_EXTSTATIC,szStrValue);

	return true;
}

LRESULT CNewFileExtDlg::OnInitDialog(UINT uMsg,WPARAM wParam,LPARAM lParam,BOOL &bHandled)
{
	CenterWindow(GetParent());

	m_DescEdit.SubclassWindow(GetDlgItem(IDC_DESCEDIT));
	m_ExtEdit.SubclassWindow(GetDlgItem(IDC_EXTEDIT));

	m_DescEdit.SetLimitText(63);
	m_ExtEdit.SetLimitText(63);

	// Translate the window.
	Translate();

	return TRUE;
}

LRESULT CNewFileExtDlg::OnOK(WORD wNotifyCode,WORD wID,HWND hWndCtl,BOOL &bHandled)
{
	GetDlgItemText(IDC_DESCEDIT,m_szDescBuffer,63);
	GetDlgItemText(IDC_EXTEDIT,m_szExtBuffer,63);

	EndDialog(wID);
	return FALSE;
}

LRESULT CNewFileExtDlg::OnCancel(WORD wNotifyCode,WORD wID,HWND hWndCtl,BOOL &bHandled)
{
	EndDialog(wID);
	return FALSE;
}
