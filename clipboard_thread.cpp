// ---------------------------------------------------------------------------

#include <System.hpp>
#pragma hdrstop

#include "clipboard_thread.h"

// ---------------------------------------------------------------------------
#pragma package(smart_init)
// ---------------------------------------------------------------------------

DWORD ClipbrdSeq;

__fastcall TClipboardWt::TClipboardWt( bool CreateSuspended ) : TThread( CreateSuspended )
{
	this->FreeOnTerminate = true;
	FList = new TStringList( );
	ClipbrdSeq = GetClipboardSequenceNumber( );
	FPause = false;
}

// ---------------------------------------------------------------------------
void __fastcall TClipboardWt::Execute( )
{
	while ( !Terminated )
	{
		DWORD NewClipbrdSeq = GetClipboardSequenceNumber( );
		if ( ClipbrdSeq != NewClipbrdSeq && IsPaused == false )
		{
			Synchronize( UpdateListBox );
		}
		else
		{
			ClipbrdSeq = NewClipbrdSeq;
		}
	}
}

// ---------------------------------------------------------------------------
void __fastcall TClipboardWt::UpdateListBox( )
{
	TStringList * FList = new TStringList( );
	FList = ParseNickSIdString( GetCText( ) );
	const int ListCount = FList->Count;
	if ( ListCount <= 0 )
	{
		return;
	}
	Form1->ListBox1->Clear( );
	Form1->ListBox1->BeginUpdate( );
	for ( int i = 0; i < ListCount; i++ )
	{
		Application->ProcessMessages( );
		try
		{
			Form1->ListBox1->AddObject
				( CreateListBoxItem( AnsiDequotedStr( FList->ValueFromIndex[ i ], '"' ),
				FList->KeyNames[ i ], true ) );
		}
		catch ( Exception & e )
		{
			ShowMessage( e.Message );
		}
	}
	Form1->ListBox1->EndUpdate( );
	ClipbrdSeq = GetClipboardSequenceNumber( );
}
