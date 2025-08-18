#include "utils.hpp"

#include "GameObject.hpp"

using namespace geode::prelude;


void ldm::utils::updateVisibleAll(LevelEditorLayer* lel) {
	for (auto obj : CCArrayExt<HGameObject*>(lel->m_objects)) {
		obj->checkDisabled();
		// setVisible is always called at least once by the game
		// itself before we call it so m_realVisible is always correct
		obj->updateVisible();
	}

	return;
}