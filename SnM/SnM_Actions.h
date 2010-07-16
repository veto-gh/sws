/******************************************************************************
/ SnM_Actions.h
/
/ Copyright (c) 2009-2010 Tim Payne (SWS), JF B�dague 
/ http://www.standingwaterstudios.com/reaper
/
/ Permission is hereby granted, free of charge, to any person obtaining a copy
/ of this software and associated documentation files (the "Software"), to deal
/ in the Software without restriction, including without limitation the rights to
/ use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies
/ of the Software, and to permit persons to whom the Software is furnished to
/ do so, subject to the following conditions:
/ 
/ The above copyright notice and this permission notice shall be included in all
/ copies or substantial portions of the Software.
/ 
/ THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
/ EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
/ OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
/ NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
/ HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
/ WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
/ FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
/ OTHER DEALINGS IN THE SOFTWARE.
/
******************************************************************************/

#pragma once

#include "SNM_Chunk.h"

#define SNM_CMD_SHORTNAME(_ct) (_ct->accel.desc + 9) // +9 to skip "SWS/S&M: "
#define SNM_FORMATED_INI_FILE "%s\\Plugins\\S&M.ini"
#define SNM_ACTION_HELP_INI_FILE "%s\\Plugins\\Action_help_en.ini"

#define MAX_ACTION_COUNT 0xFFFF
#define MAX_FXCHAIN_SLOTS 32 
#define MAX_TRACK_GROUPS 32 
#define SNM_MAX_HW_OUTS 8

// Global vars
extern WDL_String g_fxChainList[MAX_FXCHAIN_SLOTS]; 

// *** SnM_Actions.cpp ***
int SnMActionsInit();
void SnMExit();
void SnMSlice();
void SNM_ShowConsoleMsg(const char* _title, const char* _msg); 
void fakeToggleAction(COMMAND_T* _ct);
bool fakeIsToggledAction(COMMAND_T* _ct);

// *** SnM_FX.cpp ***
bool patchSelTracksFXState(int _mode, int _token, int _fx, const char* _value, const char * _undoMsg);
void toggleFXOfflineSelectedTracks(COMMAND_T* _ct);
bool isFXOfflineSelectedTracks(COMMAND_T* _ct);
void toggleFXBypassSelectedTracks(COMMAND_T* _ct);
bool isFXBypassedSelectedTracks(COMMAND_T * _ct);
void toggleExceptFXOfflineSelectedTracks(COMMAND_T* _ct);
void toggleExceptFXBypassSelectedTracks(COMMAND_T* _ct);
void toggleAllFXsOfflineSelectedTracks(COMMAND_T* _ct);
void toggleAllFXsBypassSelectedTracks(COMMAND_T* _ct);
void setFXOfflineSelectedTracks(COMMAND_T* _ct); 
void setFXBypassSelectedTracks(COMMAND_T* _ct);
void setFXOnlineSelectedTracks(COMMAND_T* _ct);
void setFXUnbypassSelectedTracks(COMMAND_T* _ct);
void setAllFXsBypassSelectedTracks(COMMAND_T* _ct); // ..related online/offline actions natively implemented

int selectFX(MediaTrack* _tr, int _fx);
int getSelectedFX(MediaTrack* _tr);
void selectFX(COMMAND_T* _ct);


// *** SnM_FXChain.cpp ***
void loadPasteTakeFXChain(COMMAND_T* _ct);
void loadPasteAllTakesFXChain(COMMAND_T* _ct);
void loadPasteTakeFXChain(const char* _title, int _slot, bool _activeOnly);
void copyTakeFXChain(COMMAND_T* _ct);
void cutTakeFXChain(COMMAND_T* _ct);
void pasteTakeFXChain(COMMAND_T* _ct);
void pasteAllTakesFXChain(COMMAND_T* _ct);
void clearActiveTakeFXChain(COMMAND_T* _ct);
void clearAllTakesFXChain(COMMAND_T* _ct);
void setTakeFXChain(const char* _title, int _slot, bool _activeOnly, bool _clear);

void loadPasteTrackFXChain(const char* _title, int _slot);
void setTrackFXChain(const char* _title, int _slot, bool _clear);
void loadPasteTrackFXChain(COMMAND_T* _ct);
void clearTrackFXChain(COMMAND_T* _ct);
void copyTrackFXChain(COMMAND_T* _ct);
void cutTrackFXChain(COMMAND_T* _ct);
void pasteTrackFXChain(COMMAND_T* _ct);

int promptForSlot(const char* _title);
void clearFXChainSlotPrompt(COMMAND_T* _ct);
void clearFXChainSlot(int _slot);
bool loadStoreFXChain(int _slot, const char* _filename);
bool browseStoreFXChain(int _slot);
bool loadOrBrowseFXChain(int _slot);
void readFXChainSlotIniFile(int _slot, char* _buf, int _bufSize);
void saveFXChainSlotIniFile(int _slot, const char* _path);
void copySlotToClipBoard(int _slot);
void displayFXChain(int _slot);


// *** SnM_Windows.cpp ***
//#ifdef _WIN32
bool toggleShowHideWin(const char * _title);
bool closeWin(const char * _title);
void closeOrToggleAllWindows(bool _routing, bool _env, bool _toggle);
void closeAllRoutingWindows(COMMAND_T * _ct);
void closeAllEnvWindows(COMMAND_T * _ct);
void toggleAllRoutingWindows(COMMAND_T * _ct);
void toggleAllEnvWindows(COMMAND_T * _ct);
//#endif

void showFXChain(COMMAND_T* _ct);
void hideFXChain(COMMAND_T* _ct);
void toggleFXChain(COMMAND_T* _ct);
bool isToggleFXChain(COMMAND_T * _ct);

void showAllFXChainsWindows(COMMAND_T* _ct);
void closeAllFXChainsWindows(COMMAND_T * _ct);
void toggleAllFXChainsWindows(COMMAND_T * _ct);

void toggleFloatFX(MediaTrack* _tr, int _fx);
void floatUnfloatFXs(MediaTrack* _tr, bool _all, int _showFlag, int _fx, bool _selTracks);
void floatUnfloatFXs(bool _all, int _showFlag, int _fx, bool _selTracks);
void floatFX(COMMAND_T* _ct);
void unfloatFX(COMMAND_T* _ct);
void toggleFloatFX(COMMAND_T* _ct);
void showAllFXWindows(COMMAND_T * _ct);
void closeAllFXWindows(COMMAND_T * _ct);
void closeAllFXWindowsExceptFocused(COMMAND_T * _ct);
void toggleAllFXWindows(COMMAND_T * _ct);
void flushHiddenFXWindows();
int getFocusedFX(MediaTrack* _tr, int _dir, int* _firstFound = NULL);
bool cycleFocusFXWnd(int _dir, bool _selectedTracks);
void cycleFocusFXWndSelTracks(COMMAND_T * _ct);
void cycleFocusFXWndAllTracks(COMMAND_T * _ct);
void cycleFloatFXWndSelTracks(COMMAND_T * _ct);
void cycleFocusFXAndMainWndAllTracks(COMMAND_T * _ct);
void cycleFocusFXMainWndSelTracks(COMMAND_T * _ct);
void cycleFocusWnd(COMMAND_T * _ct);
void setMainWindowActive(COMMAND_T* _ct);


// *** SnM_Sends.cpp ***
bool cueTrack(const char* _busName, int _type, const char* _undoMsg, bool _showRouting = true, int _soloDefeat = 1, char* _trTemplatePath = NULL, bool _sendToMaster = false, int* _hwOuts = NULL);
void cueTrackPrompt(COMMAND_T* _ct);
void cueTrack(COMMAND_T* _ct);

void flushAllRoutingClipboards();

void copyWithIOs(COMMAND_T* _ct);
void cutWithIOs(COMMAND_T* _ct);
void pasteWithIOs(COMMAND_T* _ct);

void copyRoutings(COMMAND_T* _ct);
void cutRoutings(COMMAND_T* _ct);
void pasteRoutings(COMMAND_T* _ct);

void copySends(COMMAND_T* _ct);
void cutSends(COMMAND_T* _ct);
void pasteSends(COMMAND_T* _ct);

void copyReceives(COMMAND_T* _ct);
void cutReceives(COMMAND_T* _ct);
void pasteReceives(COMMAND_T* _ct);

int GetComboSendIdxType(int _reaType) ;
const char* GetSendTypeStr(int _type);
void removeSends(COMMAND_T* _ct);
void removeReceives(COMMAND_T* _ct);
void removeRouting(COMMAND_T* _ct);

void readCueBusIniFile(char* _busName, int* _reaType, bool* _trTemplate, char* _trTemplatePath, bool* _showRouting, int* _soloDefeat, bool* _sendToMaster, int* _hwOuts);
void saveCueBusIniFile(char* _busName, int _type, bool _trTemplate, char* _trTemplatePath, bool _showRouting, int _soloDefeat, bool _sendToMaster, int* _hwOuts);


// *** SnM_Item.cpp ***
void splitMidiAudio(COMMAND_T* _ct);
void smartSplitMidiAudio(COMMAND_T* _ct);
void splitSelectedItems(COMMAND_T* _ct);
void goferSplitSelectedItems(COMMAND_T* _ct);

bool isEmptyMidi(MediaItem_Take* _take);
void setEmptyTakeChunk(WDL_String* _chunk);
bool addEmptyTake(MediaItem* _item);
int buildLanes(const char* _undoTitle, int _mode);
bool removeEmptyTakes(const char* _undoTitle, bool _empty, bool _midiEmpty, bool _trSel = false, bool _itemSel = true);
void clearTake(COMMAND_T* _ct);
void moveTakes(COMMAND_T* _ct);
void moveActiveTake(COMMAND_T* _ct);
void selectTakeLane(COMMAND_T* _ct);
void buildLanes(COMMAND_T* _ct);
void removeEmptyTakes(COMMAND_T* _ct);
void removeEmptyMidiTakes(COMMAND_T* _ct);
void removeAllEmptyTakes(COMMAND_T* _ct);

int getTakeIndex(MediaItem* _item, MediaItem_Take* _take);

void showHideTakeVolEnvelope(COMMAND_T* _ct); 
void showHideTakePanEnvelope(COMMAND_T* _ct);
void showHideTakeMuteEnvelope(COMMAND_T* _ct);
bool ShowTakeEnvVol(MediaItem_Take* _take);
bool ShowTakeEnvPan(MediaItem_Take* _take);
bool ShowTakeEnvMute(MediaItem_Take* _take);


// *** SnM_Track.cpp ***
int addSoloToGroup(MediaTrack * _tr, int _group, bool _master, SNM_ChunkParserPatcher* _cpp);
bool loadTrackTemplate(char* _filename, WDL_String* _chunk);


// *** SnM_FXChainView.cpp ***
int FXChainViewInit();
void FXChainViewExit();
void OpenFXChainView(COMMAND_T*);


// *** SnM_NotesHelpView.cpp ***
int NotesHelpViewInit();
void NotesHelpViewExit();
void OpenNotesHelpView(COMMAND_T*);
void SetActionHelpFilename(COMMAND_T*);


// *** SnM_Dlg.cpp ***
void fillHWoutDropDown(HWND _hwnd, int _idc);
WDL_DLGRET CueBusDlgProc(HWND hwnd, UINT Message, WPARAM wParam, LPARAM lParam);
WDL_DLGRET WaitDlgProc(HWND hwnd, UINT Message, WPARAM wParam, LPARAM lParam);


// *** SnM_ME.cpp ***
void MECreateCCLane(COMMAND_T* _ct);
void MEHideCCLanes(COMMAND_T* _ct);
void MESetCCLanes(COMMAND_T* _ct);
void MESaveCCLanes(COMMAND_T* _ct);


// *** SnM_Misc.cpp ***
void letREAPERBreathe(COMMAND_T* _ct);
#ifdef _SNM_MISC
void ShowTakeEnvPadreTest(COMMAND_T* _ct);
void openStuff(COMMAND_T* _ct);
#endif