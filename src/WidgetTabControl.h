/*
Copyright © 2011-2012 Clint Bellanger

This file is part of FLARE.

FLARE is free software: you can redistribute it and/or modify it under the terms
of the GNU General Public License as published by the Free Software Foundation,
either version 3 of the License, or (at your option) any later version.

FLARE is distributed in the hope that it will be useful, but WITHOUT ANY
WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A
PARTICULAR PURPOSE.  See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with
FLARE.  If not, see http://www.gnu.org/licenses/
*/

#ifndef MENU_TAB_CONTROL_H
#define MENU_TAB_CONTROL_H

#include "CommonIncludes.h"
#include "SharedResources.h"
#include "Widget.h"
#include "WidgetLabel.h"

class WidgetTabControl : public Widget {
private:

	void loadGraphics();
	void renderTab(unsigned number);

	Sprite *active_tab_surface;
	Sprite *inactive_tab_surface;

	std::vector<std::string> titles; // Titles of the tabs.
	std::vector<Rect> tabs; // Rectangles for each tab title on the tab header.
	std::vector<WidgetLabel> active_labels;
	std::vector<WidgetLabel> inactive_labels;


	unsigned active_tab;    // Index of the currently active tab.
	Rect tabs_area;    // Area the tab titles are displayed.
	Rect content_area; // Area where the content of the active tab is displayed.
	Point tab_padding; // Padding between tab titles.

	Color color_normal;
	Color color_disabled;

public:

	WidgetTabControl();
	~WidgetTabControl();

	void setTabTitle(unsigned index, const std::string& title);
	void setMainArea(int x, int y, int width, int height);

	int getActiveTab();
	void setActiveTab(unsigned tab);

	Rect getContentArea();
	int getTabHeight() {
		return active_tab_surface->getGraphicsHeight();
	}

	void updateHeader();

	void logic();
	void logic(int x, int y);
	void render();

	bool getNext();
	bool getPrev();
};

#endif
