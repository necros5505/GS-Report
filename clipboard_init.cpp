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
	return ClService->HasText( ) ? ClService->GetText( ) : "";
}

void SetCText( System::UnicodeString Text )
{
	ClService->SetText( Text );
}
