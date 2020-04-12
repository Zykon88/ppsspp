// Copyright (c) 2013- PPSSPP Project.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, version 2.0 or later versions.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License 2.0 for more details.

// A copy of the GPL 2.0 should have been included with the program.
// If not, see http://www.gnu.org/licenses/

// Official git repository and contact information can be found at
// https://github.com/hrydgard/ppsspp and http://www.ppsspp.org/.

#include <cstdint>
#include <functional>

#include "ui/view.h"
#include "ui/ui_screen.h"
#include "ui/ui_context.h"
#include "UI/MiscScreens.h"

struct CheatFileInfo;
class CWCheatEngine;

class CwCheatScreen : public UIDialogScreenWithBackground {
public:
	CwCheatScreen(const std::string &gamePath);
	~CwCheatScreen();

	void LoadCheatInfo();
	void ParseCheatDB(std::string line, std::vector<std::string> title, std::vector<std::string> newList, std::string cheatFile);
	UI::EventReturn OnAddCheat(UI::EventParams &params);
	UI::EventReturn OnImportCheat(UI::EventParams &params);
	UI::EventReturn OnEditCheatFile(UI::EventParams &params);
	UI::EventReturn OnEnableAll(UI::EventParams &params);

	void update() override;
	void onFinish(DialogResult result) override;

protected:
	void CreateViews() override;

private:
	UI::EventReturn OnCheckBox(int index);

	enum { INDEX_ALL = -1 };
	bool RebuildCheatFile(int index);

	UI::ScrollView *rightScroll_ = nullptr;
	CWCheatEngine *engine_ = nullptr;
	std::vector<CheatFileInfo> fileInfo_;
	std::string gamePath_;
	std::string gameID_;
	int fileCheckCounter_ = 0;
	uint64_t fileCheckHash_;
	bool enableAllFlag_ = false;
};
