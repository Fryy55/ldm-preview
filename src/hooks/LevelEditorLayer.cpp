#include <Geode/modify/LevelEditorLayer.hpp>

#include "utils.hpp"

using namespace geode::prelude;


class $modify(LevelEditorLayer) {
	$override
	bool init(GJGameLevel* level, bool p1) {
		if (!LevelEditorLayer::init(level, p1))
			return false;

		ldm::utils::updateVisible(this);

		return true;
	}
};