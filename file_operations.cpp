// ---------------------------------------------------------------------------

#pragma hdrstop

#include "file_operations.h"

// ---------------------------------------------------------------------------
#pragma package(smart_init)

const System::UnicodeString SETTINGS_FILE_NAME =
	System::Ioutils::TPath::Combine( TDirectory::GetCurrentDirectory( ), "settings.ini" );
const System::UnicodeString SERVER_LIST_FILE_NAME =
	System::Ioutils::TPath::Combine( TDirectory::GetCurrentDirectory( ), "serverlist.txt" );
const System::UnicodeString TAG_LIST_FILE_NAME =
	System::Ioutils::TPath::Combine( TDirectory::GetCurrentDirectory( ), "tags.txt" );
const System::UnicodeString REPORT_FORMAT_FILE_NAME =
	System::Ioutils::TPath::Combine( TDirectory::GetCurrentDirectory( ), "reportformat.txt" );
const System::UnicodeString SERVER_LIST_RESOURCE_NAME = L"_SERVERLIST_RES";
const System::UnicodeString TAG_LIST_RESOURCE_NAME = L"_TAGS_RES";
const System::UnicodeString REPORT_FORMAT_RESOURCE_NAME = L"_REPORT_FORMAT_RES";

TStringList * LoadListFromFile( System::UnicodeString AFileName )
{
	const System::UnicodeString FileName = AFileName;
	TStringList * List = new TStringList( );
	List->Duplicates = TDuplicates::dupIgnore;
	List->LoadFromFile( FileName );
	for ( int i = 0; i < List->Count; i++ )
	{
		if ( List->Strings[ i ].IsEmpty( ) )
		{
			List->Delete( i );
		}
	}
	return List;
}

void ShowInExplorer(
	System::UnicodeString APath,
	bool                  SelectLastFile )
{
	if ( APath.IsEmpty( ) || !TDirectory::Exists( APath ) )
	{
		return;
	}
	if ( SelectLastFile )
	{
		TStringDynArray arr = TDirectory::GetFiles( APath );
		String File = "explorer.exe";
		String Param = "/select," + System::Ioutils::TPath::Combine( APath, arr[ arr.High ] );
		ShellExecuteW( NULL, L"open", File.c_str( ), Param.c_str( ), NULL, SW_SHOWNORMAL );
	}
	else
	{
		ShellExecuteW( NULL, L"open", APath.c_str( ), NULL, NULL, SW_SHOWNORMAL );
	}
}

void SaveSettings( )
{
	try
	{
		Form2->ListBox1->Items->SaveToFile( SERVER_LIST_FILE_NAME );
		Form2->ListBox2->Items->SaveToFile( TAG_LIST_FILE_NAME );

		TIniFile * ini = new TIniFile( SETTINGS_FILE_NAME );
		ini->WriteBool( "Settings", "ClearWHField", Form2->CheckBox1->IsChecked );
		ini->WriteBool( "Settings", "AltNickIdBackground", Form2->CheckBox2->IsChecked );
		ini->WriteBool( "Settings", "ShowLastFile", Form2->CheckBox3->IsChecked );
		ini->WriteString( "Settings", "TagSeparator", Form2->Edit1->Text );
		ini->WriteString( "Settings", "Videos", Form2->Edit2->Text );
		ini->WriteString( "Settings", "Screenshots", Form2->Edit3->Text );

		Form2->Memo1->Lines->SaveToFile( REPORT_FORMAT_FILE_NAME );
	}
	catch ( Exception & e )
	{
		MessageBoxW( NULL, ( L"Unable to save settings:\n\n" + e.Message ).w_str( ), L"Error",
			MB_OK | MB_ICONERROR );
	}
}

void LoadSettings( )
{
	try
	{
		TStringList * ServerList = new TStringList( );
		try
		{
			ServerList = LoadListFromFile( SERVER_LIST_FILE_NAME );
		}
		catch ( ... )
		{
			ServerList->LoadFromStream( LoadListFromResource( SERVER_LIST_RESOURCE_NAME ) );
		}

		Form2->ListBox1->Clear( );
		Form2->ListBox1->BeginUpdate( );
		for ( int i = 0; i < ServerList->Count; i++ )
		{
			Form2->ListBox1->AddObject( CreateListBoxItem( ServerList->Strings[ i ], "", false ) );
		}
		Form2->ListBox1->EndUpdate( );
		delete ServerList;

		TStringList * TagList = new TStringList( );
		try
		{
			TagList = LoadListFromFile( TAG_LIST_FILE_NAME );
		}
		catch ( ... )
		{
			TagList->LoadFromStream( LoadListFromResource( TAG_LIST_RESOURCE_NAME ) );
		}

		Form2->ListBox2->Clear( );
		Form2->ListBox2->BeginUpdate( );
		for ( int k = 0; k < TagList->Count; k++ )
		{
			Form2->ListBox2->AddObject( CreateListBoxItem( TagList->Strings[ k ], "", false ) );
		}
		Form2->ListBox2->EndUpdate( );
		delete TagList;

		try
		{
			Form2->Memo1->Lines->LoadFromFile( REPORT_FORMAT_FILE_NAME );
		}
		catch ( ... )
		{
			Form2->Memo1->Lines->LoadFromStream
				( LoadListFromResource( REPORT_FORMAT_RESOURCE_NAME ) );
		}

		TIniFile * ini = new TIniFile( SETTINGS_FILE_NAME );
		Form2->CheckBox1->IsChecked = ini->ReadBool( "Settings", "ClearWHField", true );
		Form2->CheckBox2->IsChecked = ini->ReadBool( "Settings", "AltNickIdBackground", true );
		Form2->CheckBox3->IsChecked = ini->ReadBool( "Settings", "ShowLastFile", true );
		Form2->Edit1->Text = ini->ReadString( "Settings", "TagSeparator", "," );
		Form2->Edit2->Text = ini->ReadString( "Settings", "Videos", "" );
		Form2->Edit3->Text = ini->ReadString( "Settings", "Screenshots", "" );
	}
	catch ( Exception & e )
	{
		MessageBoxW( NULL, ( L"Unable to load settings:\n\n" + e.Message ).w_str( ), L"Error",
			MB_OK | MB_ICONERROR );
	}
}

TResourceStream * LoadListFromResource( System::UnicodeString ResourceName )
{
	TResourceStream * Res = new TResourceStream( ( NativeUInt )HInstance, ResourceName,
		( WideChar * )RT_RCDATA );
	return Res;
}
