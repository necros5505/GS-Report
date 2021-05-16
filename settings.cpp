// ---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "settings.h"

// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"

TForm2 * Form2;

// ---------------------------------------------------------------------------
__fastcall TForm2::TForm2( TComponent * Owner ) : TForm( Owner )
{
}

// ---------------------------------------------------------------------------
void __fastcall TForm2::Button10Click( TObject * Sender )
{
	Edit2->Text = GetDir( );
}
// ---------------------------------------------------------------------------

void __fastcall TForm2::Button9Click( TObject * Sender )
{
	Form2->Close( );
}
// ---------------------------------------------------------------------------

void __fastcall TForm2::Button11Click( TObject * Sender )
{
	Edit3->Text = GetDir( );
}
// ---------------------------------------------------------------------------

System::UnicodeString TForm2::GetDir( )
{
	System::UnicodeString Dir;
	Fmx::Dialogs::SelectDirectory( "Select directory", "", Dir );
	return Dir;
}

void __fastcall TForm2::Button1Click( TObject * Sender )
{
	System::UnicodeString InputData = InputBox( "Add Server", "Enter Server name", "" );
	if ( !InputData.IsEmpty( ) )
	{
		ListBox1->AddObject( CreateListBoxItem( InputData, "", false ) );
	}
	FillMainServerList( NULL );
}

// ---------------------------------------------------------------------------

void __fastcall TForm2::Button2Click( TObject * Sender )
{
	delete ListBox1->Selected;
	FillMainServerList( NULL );
}
// ---------------------------------------------------------------------------

void __fastcall TForm2::Button8Click( TObject * Sender )
{
	delete ListBox2->Selected;
}
// ---------------------------------------------------------------------------

void __fastcall TForm2::Button7Click( TObject * Sender )
{
	System::UnicodeString InputData = InputBox( "Add Tag", "Enter Tag text", "" );
	if ( !InputData.IsEmpty( ) )
	{
		ListBox1->AddObject( CreateListBoxItem( InputData, "", false ) );
	}
}
// ---------------------------------------------------------------------------

void __fastcall TForm2::Button5Click( TObject * Sender )
{
	if ( ListBox2->Selected->Index > 0 && ListBox2->Selected != NULL )
	{
		ListBox2->ItemsExchange( ListBox2->Selected,
		ListBox2->ListItems[ ListBox2->ItemIndex - 1 ] );
	}
}

// ---------------------------------------------------------------------------

void __fastcall TForm2::Button6Click( TObject * Sender )
{
	if ( ListBox2->Selected->Index < ListBox2->Items->Count - 1 && ListBox2->Selected != NULL )
	{
		ListBox2->ItemsExchange( ListBox2->Selected,
		ListBox2->ListItems[ ListBox2->ItemIndex + 1 ] );
	}
}

// ---------------------------------------------------------------------------

void __fastcall TForm2::Button3Click( TObject * Sender )
{
	if ( ListBox1->Selected->Index > 0 && ListBox1->Selected != NULL )
	{
		ListBox1->ItemsExchange( ListBox1->Selected,
		ListBox1->ListItems[ ListBox1->ItemIndex - 1 ] );
	}
	FillMainServerList( NULL );
}

// ---------------------------------------------------------------------------

void __fastcall TForm2::Button4Click( TObject * Sender )
{
	if ( ListBox1->Selected->Index < ListBox1->Items->Count - 1 && ListBox1->Selected != NULL )
	{
		ListBox1->ItemsExchange( ListBox1->Selected,
		ListBox1->ListItems[ ListBox1->ItemIndex + 1 ] );
	}
	FillMainServerList( NULL );
}

// ---------------------------------------------------------------------------

void __fastcall TForm2::FillMainServerList( TObject * Sender )
{
	Form1->ComboEdit1->Items->Clear( );
	for ( int i = 0; i < ListBox1->Items->Count; i++ )
	{
		Form1->ComboEdit1->Items->Add( ListBox1->ListItems[ i ]->Text );
	}
	if ( Form1->ComboEdit1->Items->Count > -1 )
	{
		Form1->ComboEdit1->ItemIndex = 0;
	}
}

// ---------------------------------------------------------------------------

void __fastcall TForm2::FormShow( TObject * Sender )
{
	LoadSettings( );
}
// ---------------------------------------------------------------------------

void __fastcall TForm2::FormClose(
	TObject *      Sender,
	TCloseAction & Action )
{
	SaveSettings( );
}
// ---------------------------------------------------------------------------

void __fastcall TForm2::FormCreate( TObject * Sender )
{
	LoadSettings( );
	FillMainServerList( NULL );
	SaveSettings( );
}
// ---------------------------------------------------------------------------

void __fastcall TForm2::Button12Click( TObject * Sender )
{
	Memo1->Lines->Clear( );
	Memo1->Lines->LoadFromStream( LoadListFromResource( REPORT_FORMAT_RESOURCE_NAME ) );
}
// ---------------------------------------------------------------------------

void __fastcall TForm2::ListBox1DblClick( TObject * Sender )
{
	if ( ListBox1->Selected != NULL )
	{
		ListBox1->Selected->Text = InputBox( "Rename", "", ListBox1->Selected->Text );
	}
}
// ---------------------------------------------------------------------------

void __fastcall TForm2::ListBox2DblClick( TObject * Sender )
{
	if ( ListBox2->Selected != NULL )
	{
		ListBox2->Selected->Text = InputBox( "Rename", "", ListBox2->Selected->Text );
	}
}
// ---------------------------------------------------------------------------

void __fastcall TForm2::CheckBox2Change( TObject * Sender )
{
	Form1->ListBox1->AlternatingRowBackground = CheckBox2->IsChecked;
}
// ---------------------------------------------------------------------------
