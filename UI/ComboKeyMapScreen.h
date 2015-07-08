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

#pragma once

#include "MiscScreens.h"

#include <map>

namespace UI {
	class CheckBox;
}

class Combo_keyScreen : public UIDialogScreenWithBackground {
public:
	Combo_keyScreen(int *key): mode(key) {}

	virtual void CreateViews();
	virtual void onFinish(DialogResult result);
	UI::EventReturn onCombo(UI::EventParams &e);
	static int arrayToInt(bool ary[16]) {
		int value = 0;

		for (int i = 15; i >=0; i--){
			value |= ary[i];
			value = value <<  1;
		}
		return value >> 1;
	}
private:
	std::map<std::string, bool*> keyToggles;
	bool array[16];
	int *mode;
	UI::ChoiceStrip *comboselect;
	UI::ScrollView *rightScroll_;
	class ChoiceEventHandler{
	public:
		ChoiceEventHandler(UI::CheckBox *checkbox) : checkbox_(checkbox) {}
		UI::EventReturn onChoiceClick(UI::EventParams &e);
	private:
		UI::CheckBox *checkbox_;
	};
};

