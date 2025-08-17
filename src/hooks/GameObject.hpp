#pragma once

#include <Geode/modify/GameObject.hpp>


class $modify(HGameObject, GameObject) {
	struct Fields {
		bool m_disabled = false;
		bool m_ogVisible = false;
	};

	void checkDisabled();

	$override
	void setVisible(bool visible);
};