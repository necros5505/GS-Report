// ---------------------------------------------------------------------------

#pragma hdrstop

#include "clipboard_init.h"

// ---------------------------------------------------------------------------

#pragma package(smart_init)

_di_IFMXExtendedClipboardService ClService;

void InitCService( )
{
	if ( !TPlatformServices::Current->SupportsPlatformService
		( __uuidof( IFMXExtendedClipboardService ), &ClService ) )
	{
		return;
	}
}

System::UnicodeString GetCText( )
{
	if( ClService->HasText( ) )return ClService->GetText( );
	return "";
}

void SetCText( System::UnicodeString Text )
{
	ClService->SetText( Text );
}
