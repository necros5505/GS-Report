// ---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "main.h"

// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"

TClipboardWt * FClip;
TForm1 * Form1;

// ---------------------------------------------------------------------------
__fastcall TForm1::TForm1( TComponent * Owner ) : TForm( Owner )
{
}

// ---------------------------------------------------------------------------
void __fastcall TForm1::Label6Click( TObject * Sender )
{
	Switch1->IsChecked = !Switch1->IsChecked;
}

// ---------------------------------------------------------------------------
void __fastcall TForm1::Button4Click( TObject * Sender )
{
	Form2->ShowModal( );
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::OnTagItemClick(
	TCustomListBox * const Sender,
	TListBoxItem * const   Item )
{
	if ( Item != NULL )
	{
		Item->IsChecked = !Item->IsChecked;
	}
}

void __fastcall TForm1::OnTagPasteClick( TObject * Sender )
{
	System::UnicodeString Separator = Form2->Edit1->Text;
	System::UnicodeString Tags = "";
	Popup1->IsOpen = false;
	if ( Form2->CheckBox1->IsChecked )
	{
		Memo1->Lines->Clear( );
	}
	if ( Separator.IsEmpty( ) )
	{
		Separator = ", ";
	}

	for ( int i = 0; i < FPopupListBox->Items->Count; i++ )
	{
		if ( FPopupListBox->ListItems[ i ]->IsChecked )
		{
			Tags += ( ( ( i > 0 && FPopupListBox->Items->Count > 0 ) && i <
				FPopupListBox->Items->Count && !Tags.IsEmpty( ) ) ? Separator + " " : "" ) +
				FPopupListBox->ListItems[ i ]->Text;
		}
	}
	if ( !Tags.IsEmpty( ) )
	{
		if ( Form2->CheckBox1->IsChecked )
		{
			Memo1->Lines->Clear( );
		}
		Memo1->Lines->Text += Tags;
	}
}

void __fastcall TForm1::Button5Click( TObject * Sender )
{
	Popup1->IsOpen = true;
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click( TObject * Sender )
{
	ShowInExplorer( Form2->Edit3->Text, false );
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click( TObject * Sender )
{
	ShowInExplorer( Form2->Edit2->Text, Form2->CheckBox3->IsChecked );
}

// ---------------------------------------------------------------------------
void __fastcall TForm1::OnPopup( TObject * Sender )
{
	CreatePopupListBoxItem( );
}

void __fastcall TForm1::CreatePopupListBox( )
{
	FPopupListBox = new TListBox( Popup1 );
	FPopupListBox->Align = TAlignLayout::Top;
	FPopupListBox->Height = Popup1->Height - 35;
	FPopupListBox->ItemHeight = 20;
	FPopupListBox->OnItemClick = OnTagItemClick;
	FPopupListBox->Cursor = crHandPoint;
	FPopupListBox->ShowCheckboxes = true;
	FPopupListBox->Parent = Popup1;
}

void __fastcall TForm1::CreatePopupButton( )
{
	FPopupButton = new TButton( Popup1 );
	FPopupButton->Align = TAlignLayout::Bottom;
	FPopupButton->OnClick = OnTagPasteClick;
	ButtonStyledSettings( FPopupButton, 14 );
	FPopupButton->Text = "Paste";
	FPopupButton->TextSettings->EndUpdate( );
	FPopupButton->Height = 33;
	FPopupButton->Parent = Popup1;
}

void __fastcall TForm1::CreatePopupListBoxItem( )
{
	TStringList * TagList = new TStringList( );
	try
	{
		TagList = LoadListFromFile( TAG_LIST_FILE_NAME );
	}
	catch ( ... )
	{
		TagList->LoadFromStream( LoadListFromResource( TAG_LIST_RESOURCE_NAME ) );
	}
	FPopupListBox->Clear( );
	FPopupListBox->BeginUpdate( );
	for ( int i = 0; i < TagList->Count; i++ )
	{
		FPopupListBox->AddObject( CreateListBoxItem( TagList->Strings[ i ], "", false ) );
	}
	FPopupListBox->EndUpdate( );
	delete TagList;
}

void __fastcall TForm1::PopupMenu1Popup( TObject * Sender )
{
	PopupMenuStyledSettings( MenuItem1, 14 );
	PopupMenuStyledSettings( MenuItem2, 14 );
	PopupMenuStyledSettings( MenuItem4, 14 );
}

// ---------------------------------------------------------------------------

void __fastcall TForm1::MenuItem1Click( TObject * Sender )
{
	if ( ListBox1->Selected != NULL )
	{
		SetCText( ListBox1->Selected->Text );
	}
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::MenuItem2Click( TObject * Sender )
{
	if ( ListBox1->Selected != NULL )
	{
		SetCText( ListBox1->Selected->ItemData->Detail );
	}
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::MenuItem4Click( TObject * Sender )
{
	if ( ListBox1->Selected != NULL )
	{
		SetCText( ConvertSteamIdToCId( ListBox1->Selected->ItemData->Detail ) );
	}
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::Button3Click( TObject * Sender )
{
	const System::UnicodeString SERVER_NAME = ComboEdit1->Text;
	const System::UnicodeString PLAYER_NAME = Edit1->Text;
	const System::UnicodeString HIS_STEAMID = Edit2->Text;
	const System::UnicodeString WHAT_HAPPENED = Memo1->Text;
	System::UnicodeString Report = Form2->Memo1->Text;

	Report = StringReplace( Report, "%SERVER_NAME%", SERVER_NAME,
		TReplaceFlags( ) << rfReplaceAll );
	Report = StringReplace( Report, "%PLAYER_NAME%", PLAYER_NAME,
		TReplaceFlags( ) << rfReplaceAll );
	Report = StringReplace( Report, "%HIS_STEAMID%", HIS_STEAMID,
		TReplaceFlags( ) << rfReplaceAll );
	Report = StringReplace( Report, "%WHAT_HAPPENED%", WHAT_HAPPENED,
		TReplaceFlags( ) << rfReplaceAll );
	SetCText( Report );
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::Switch1Switch( TObject * Sender )
{
	FClip->IsPaused = !Switch1->IsChecked;
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::ListBox1DblClick( TObject * Sender )
{
	if ( ListBox1->Selected == NULL )
	{
		return;
	}
	Edit1->Text = ListBox1->Selected->Text;
	Edit2->Text = ListBox1->Selected->ItemData->Detail;
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::ListBox1MouseDown(
	TObject *    Sender,
	TMouseButton Button,
	TShiftState  Shift,
	float        X,
	float        Y )
{
	if ( Button == TMouseButton::mbRight && ListBox1->ItemByPoint( X, Y ) != NULL )
	{
		ListBox1->ListItems[ ListBox1->ItemByPoint( X, Y )->Index ]->IsSelected = true;
		TPoint P;
		try
		{
			GetCursorPos( & P );
		}
		catch ( Exception & e )
		{
			ShowMessage( e.Message );
		}
		if ( ListBox1->Selected )
		{
			PopupMenu1->Popup( P.X, P.Y );
		}
	}

}
// ---------------------------------------------------------------------------

void __fastcall TForm1::FormCreate( TObject * Sender )
{
	InitCService( );
	FClip = new TClipboardWt( true );
	FClip->Start( );
	CreatePopupListBox( );
	CreatePopupButton( );
#ifdef DEBUG
	ReportMemoryLeaksOnShutdown = true;
#else
	ReportMemoryLeaksOnShutdown = false;
#endif
}
