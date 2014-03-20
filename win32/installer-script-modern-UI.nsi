!include "MUI.nsh"

; Il nome dell'installatore
Name "Logout-FML"

;Icona del file dell'installatore
!define MUI_ICON power.ico


;Banner laterale
!define MUI_WELCOMEFINISHPAGE_BITMAP "banner.bmp" ;immagine per la pagina di benvenuto
!define MUI_HEADERIMAGE							  ;Usa immagine d'intestazione
!define MUI_HEADERIMAGE_BITMAP "header.bmp"		  ;immagine d'intestazione per le varie schermate	

; Il nome del file dell'installatore
OutFile "logout-fml-installer.exe"

;Le varie "pagine" da visualizzare (Benvenuto, licenza, scelta cartella,conclusione etc...)
!insertmacro MUI_PAGE_WELCOME
!insertmacro MUI_PAGE_LICENSE "license.rtf"
!insertmacro MUI_PAGE_DIRECTORY
;!insertmacro MUI_PAGE_COMPONENTS
!insertmacro MUI_PAGE_INSTFILES
!insertmacro MUI_PAGE_FINISH

;Lingue nelle quali deve essere disponibile l'installer
!insertmacro MUI_LANGUAGE "English"
!insertmacro MUI_LANGUAGE "German"
!insertmacro MUI_LANGUAGE "French"
!insertmacro MUI_LANGUAGE "Italian"



; La directory di installazione predefinita
InstallDir $PROGRAMFILES\logout-fml

; Del testo da mostrare al momento della scelta della directory
;DirText "This will install Logout-fml on your computer. Choose a directory"

;--------------------------------

; La sezione dedicata all'installazione
Section "Install" 

	; Setto la directory dove mettere i file da questo momento in poi
	; (se la directory non esiste, la creera') e copio i file.
	SetOutPath $INSTDIR\bin
	File bin\logout-fml.exe

	;Cambio directory e copio altri file 
	SetOutPath $INSTDIR\share\logout
	File share\logout\logout.png
	File share\logout\logout-it_IT.qm

	;Menu start
	CreateDirectory "$SMPROGRAMS\Logout-fml"
	CreateShortCut "$SMPROGRAMS\Logout-fml\logout-fml.lnk" "$INSTDIR\bin\logout-fml.exe"
	CreateShortCut "$SMPROGRAMS\Logout-fml\uninstall.lnk" "$INSTDIR\Uninstall.exe"


	
	
	
	; Informiamo il compilatore che sara' presente una sezione per il disinstallatore  
	WriteUninstaller $INSTDIR\Uninstall.exe
	
SectionEnd 



; La sezione dedicata alla disinstallazione
Section "un.Uninstall"

	;Rimuoviamo i file del programma
	Delete $INSTDIR\Uninstall.exe
	Delete $INSTDIR\bin\logout-fml.exe
	Delete $INSTDIR\share\logout\logout.png
	Delete $INSTDIR\share\logout\logout-it_IT.qm
	RMDir /r $INSTDIR
	
	; Rimuoviamo tutti i link dallo start menu
	Delete "$SMPROGRAMS\Logout-fml\logout-fml.lnk" 
	Delete "$SMPROGRAMS\Logout-fml\uninstall.lnk" 
	RMDIR  "$SMPROGRAMS\Logout-fml"

SectionEnd 
