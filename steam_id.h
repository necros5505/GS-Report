// ---------------------------------------------------------------------------

#ifndef steam_idH
#define steam_idH

// ---------------------------------------------------------------------------

#include <System.RegularExpressions.hpp>

// ---------------------------------------------------------------------------

extern bool IsSteamIdValid( System::UnicodeString ASteamId );
extern System::UnicodeString ConvertSteamIdToCId(
	const System::UnicodeString ASteamId,
	bool ResultAs3 =            false );
extern TStringList * ParseNickSIdString( System::UnicodeString AClipboardData );
extern System::UnicodeString ConvertNickIdListToCIdsStr( TStringList * ANickSIdList );

#endif
