// ---------------------------------------------------------------------------

#pragma hdrstop

#include "steam_id.h"

// ---------------------------------------------------------------------------
#pragma package(smart_init)

const unsigned __int64 V = 76561197960265728;

bool IsSteamIdValid( System::UnicodeString ASteamId )
{
	if ( ASteamId.IsEmpty( ) )
	{
		return false;
	}
	const UnicodeString pattern = "STEAM_[0-5]\\:[0-1]\\:\\d+";
	return TRegEx::IsMatch( Trim( ASteamId ), pattern );
}

System::UnicodeString ConvertSteamIdToCId(
	const System::UnicodeString ASteamId,
	bool                        ResultAs3 )
{
	const System::UnicodeString pattern = "^STEAM_[0-5]\\:([0-1])\\:(\\d+)$";
	System::UnicodeString csteamid = "";

	TRegEx * re = new TRegEx( );
	TGroupCollection gr;
	TMatchCollection mc = re->Matches( Trim( ASteamId ), Trim( pattern ) );

	if ( mc.Count > 0 )
	{
		gr = mc.Item[ 0 ].Groups;
		int Y = StrToInt( gr.Item[ 1 ].Value );
		int Z = StrToInt( gr.Item[ 2 ].Value );

		csteamid = IntToStr( ( __int64 )( Z * 2 + ( ResultAs3 ? 0 : V ) + Y ) );
	}
	return "https://steamcommunity.com/profiles/" + csteamid;
}

TStringList * ParseNickSIdString( System::UnicodeString AClipboardData )
{
	if ( AClipboardData.IsEmpty( ) )
	{
		return nullptr;
	}
	const UnicodeString pattern =
		"#\\s?+\\d+\\s+(\".+\")\\s+\\d+\\s+(STEAM_[0-5]\\:[0-1]\\:\\d+)\\s?+";

	TRegEx * re = new TRegEx( );
	TStringList * nickid_list = new TStringList( );
	TGroupCollection gr;
	TMatchCollection mc = re->Matches( AClipboardData, pattern );

	if ( mc.Count > 0 )
	{
		for ( int i = 0; i < mc.Count; i++ )
		{
			gr = mc.Item[ i ].Groups;
			if ( IsSteamIdValid( gr.Item[ 2 ].Value ) )
			{
				nickid_list->AddPair( gr.Item[ 2 ].Value, gr.Item[ 1 ].Value );
			}
		}
	}
	return nickid_list;
}
