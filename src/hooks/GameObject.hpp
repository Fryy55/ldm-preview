#pragma once

#include <Geode/modify/GameObject.hpp>


class $modify(HGameObject, GameObject) {
	struct Fields {
		bool m_disabled = false;
		bool m_realVisible = false;
	};

	// this is a separate function so it doesn't affect
	// PlayLayer and stuff
	void checkDisabled();
	void updateVisible();

	$override
	void setVisible(bool visible);

	// updateObjectEditorColor isn't called on selecting
	$override
	void selectObject(cocos2d::ccColor3B selectionColor);
	$override
	void updateObjectEditorColor();
};