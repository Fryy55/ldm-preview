#include "utils.hpp"

#include "GameObject.hpp"

using namespace geode::prelude;


void ldm::utils::updateVisible(LevelEditorLayer* lel) {
	for (auto obj : CCArrayExt<HGameObject*>(lel->m_objects)) {
		obj->checkDisabled();
		obj->setVisible(obj->m_fields->m_ogVisible); // this is always called at least once by game itself before we call it
	}

	return;
}