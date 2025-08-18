#include <Geode/modify/LevelEditorLayer.hpp>

#include "LDMManager.hpp"
#include "utils.hpp"

using namespace geode::prelude;


class $modify(LevelEditorLayer) {
	$override
	bool init(GJGameLevel* level, bool p1) {
		if (!LevelEditorLayer::init(level, p1))
			return false;

		LDMManager::get()->updateSettings();
		ldm::utils::updateVisibleAll(this);

		return true;
	}
};