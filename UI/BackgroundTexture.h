#// Copyright (c) 2013- PPSSPP Project.

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

#include <algorithm>

#include "gfx_es2/draw_buffer.h"
#include "ui/ui_context.h"
#include "ui/view.h"
#include "ui/viewgroup.h"
#include "ui/ui.h"
#include "file/vfs.h"
#include "Core/Config.h"
#include "Core/System.h"

class BackgroundTexture {

public:
	BackgroundTexture() : texture_(NULL),OnresumeFlag(false) {}

	~BackgroundTexture() {
		if (texture_)
		delete texture_;
		ILOG("BackgroundTexture destroy");
	};

	Thin3DTexture *SetupTexture(UIContext &dc);
	Thin3DTexture *texture_;
	bool OnresumeFlag;
private:
	std::string textureData_;
	
};

extern BackgroundTexture backgroundtexture;