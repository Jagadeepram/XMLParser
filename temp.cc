static void CreateChambAdpterScreen()
{

	static GfxPen pen,probeInfoPen;  // Use a static pen, to not risk heap memory leakage for the dynamic display view structure
	GUICompMenu *detectorInfoTypeMenu;
	GUICompMenu *detectorInfoSNMenu;

	char* strptr;
	char *menuString;
	pen = *GfxGPen();
	probeInfoPen = *GfxGPen();
	U8 i,j;
	GfxPenAttachFont( &pen, font_BW );
	GfxPenAttachFont( &probeInfoPen, font_BG );

	pen.alignment = GFX_TEXT_ALIGNMENT_LEFT;
	pen.bgFillBitmap = bitmapBlackColor;
	pen.fgFillBitmap = bitmapWhiteColor;


	detectorInfoTypeMenu = new GUICompMenu( 20,155,320,100, NULL, &probeInfoPen, GUICOMPMENU_STYLE_SELECT_NONE, true, false, true );
	detectorInfoSNMenu = new GUICompMenu( 20,182,320,100, NULL, &probeInfoPen, GUICOMPMENU_STYLE_SELECT_NONE, true, false, true );

	chambAdpterScreen = new GUICompScreen();

	Rect frame,detectorInfoFrame;
	GUICompMenu *listMenu = new GUICompMenu( 0,45,320,160, NULL, &pen, GUICOMPMENU_STYLE_SELECT_BY_CURSOR_SINGLE_MENU, true, false, true );
	listMenu->SetTag( COMP_TAG_LIST_MENU );
	listMenu->SetCursorSymbol( bitmap_listCursorSymbol );
	GUICompTextBox *item;
	listMenu->SetTag( COMP_TAG_LIST_MENU );

	listMenu->SetCursorSymbol( bitmap_listCursorSymbol );
	for(i=0 ; ( i < (GetNoOfProbe()) && i < MAX_ALLOWED_PROBE) ; i++)
	{
		for (j=0;j<MAX_SIZE_OF_STRING;j++)
			xmlOutStr[i][j]=' ';
		/* Display the Probe types present in chamber adaptor. */
		StrCopy(xmlOutStr[i],GetProbeType(i),MAX_SIZE_OF_STRING);
		if((strptr = strstr(xmlOutStr[i],"(PBCA)")) != NULL)
			*strptr = '\0';
		StrCat(xmlOutStr[i],(char*) ": ",(MAX_SIZE_OF_STRING-strlen(xmlOutStr[i])) );
		StrCat(xmlOutStr[i],GetProbeSerial(i),(MAX_SIZE_OF_STRING-strlen(xmlOutStr[i])) );

		item = new GUICompTextBox( &frame, (char *)xmlOutStr[i]);
		item -> SetTag( i );
		listMenu -> AddChild( item );
	}

	detectorSN[0] = '\0';
	ReadProbeNameXml ((char *) GetChptType() , detectorSN,MAX_SIZE_OF_STRING);
	menuString = bUseLanguageString ? sStrSystemInfo_Type : NULL;
	if(bUseLanguageString == true)
	{
		strcpy( detectorType,menuString);
		strcat( detectorType,": ");
		strcat( detectorType, detectorSN );
		detectorType[MAX_SIZE_OF_STRING -1]='\0';
		item = new GUICompTextBox( &detectorInfoFrame, detectorType );
		detectorInfoTypeMenu->AddChild( item );
	}
	else
	{
		strcpy( detectorType,detectorSN);
		item = new GUICompTextBox( &detectorInfoFrame, detectorType );
		detectorType[MAX_SIZE_OF_STRING -WIDTH_OFFSET_CHINESE]='\0';
		item->SetXOffset((WIDTH_OFFSET_CHINESE-1) * CHAR_WIDTH_BW );;
		detectorInfoTypeMenu->AddChild( item );
	}

	menuString = bUseLanguageString ? sStrSystemInfo_Serial : NULL;
	strcpy( detectorSN,menuString);
	if(bUseLanguageString == true)
	{
		strcat( detectorSN,": ");
		strcat( detectorSN,(char *)  GetChptSerial());
		detectorSN[MAX_SIZE_OF_STRING-1]='\0';
		item = new GUICompTextBox( &detectorInfoFrame, detectorSN );
		detectorInfoSNMenu ->AddChild( item );
	}
	else
	{
		strcpy( detectorSN , (char *)  GetChptSerial());
		item = new GUICompTextBox( &detectorInfoFrame, detectorSN );
		detectorSN[MAX_SIZE_OF_STRING -WIDTH_OFFSET_CHINESE -1]='\0';
		item->SetXOffset(WIDTH_OFFSET_CHINESE * CHAR_WIDTH_BW );
		detectorInfoSNMenu->AddChild( item );
	}


	chambAdpterScreen->InstallEventHandler( &eHandlerEntry_Right_ChambScreen );
	chambAdpterScreen->InstallEventHandler( &eHandlerEntry_Menu_MenuScreen );
	chambAdpterScreen->InstallEventHandler( &eHandlerEntry_Left_SettingsScreen  );
	chambAdpterScreen->SetBackgroundImage( screenBitmap_ChambAdptScreen );

	listMenu->SetFocus( true );
	listMenu->SetSelection( activeMenuChoice.chambMenu );


	if (!bUseLanguageString)
			listMenu->SetOnlyBackgroundScreen();

	GUICompIndicator *battInd         = CreateBatteryIndicator();
	GUICompIndicatorSymbol *chargeInd = CreateChargeIndicator();
	GUICompIndicatorSymbol *dwInd     = CreateDWSettingIndicator();
	GUICompIndicatorSymbol *kVInd     = CreatekVSettingIndicator();
	GUICompIndicatorSymbolProbe* extProbeInd = CreateExtSymbolProbeIndicator();

	chambAdpterScreen -> AddChild( chargeInd );
	chambAdpterScreen -> AddChild( battInd );
	chambAdpterScreen -> AddChild( dwInd );
	chambAdpterScreen -> AddChild( kVInd );
	chambAdpterScreen -> AddChild (extProbeInd );
	chambAdpterScreen -> AddChild( listMenu );
	chambAdpterScreen -> AddChild( detectorInfoTypeMenu );
	chambAdpterScreen -> AddChild( detectorInfoSNMenu );
}
