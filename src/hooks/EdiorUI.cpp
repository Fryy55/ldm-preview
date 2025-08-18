#include <Geode/modify/EditorUI.hpp>

#include "LDMManager.hpp"
#include "GameObject.hpp"

using namespace geode::prelude;


class $modify(EditorUI) {
	$override
	void selectObject(GameObject* p0, bool p1) {
		static bool const& selectDisabled = LDMManager::get()->getSelectDisabled();

		if (!selectDisabled && static_cast<HGameObject*>(p0)->m_fields->m_disabled) {
			// hope this works fine :pray:
			LevelEditorLayer::get()->m_undoObjects->removeLastObject();

			return;
		}

		EditorUI::selectObject(p0, p1);

		return;
	}

	$override
	void selectObjects(CCArray* p0, bool p1) {
		static bool const& selectDisabled = LDMManager::get()->getSelectDisabled();

		if (!selectDisabled) {
			for (auto obj : CCArrayExt<HGameObject*>(p0->shallowCopy())) {
				if (obj->m_fields->m_disabled)
					p0->removeObject(obj);
			}

			if (!p0->count()) // hope this works fine as well
				LevelEditorLayer::get()->m_undoObjects->removeLastObject();
		}

		EditorUI::selectObjects(p0, p1);

		return;
	}
};