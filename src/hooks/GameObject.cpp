#include "GameObject.hpp"

#include "LDMManager.hpp"

using namespace geode::prelude;


void HGameObject::checkDisabled() {
	static bool const& ldmOn = LDMManager::get()->getLDMOn();

	if (ldmOn && m_isHighDetail)
		m_fields->m_disabled = true;
	else
		m_fields->m_disabled = false;

	return;
}

void HGameObject::updateVisible() {
	this->setVisible(m_fields->m_realVisible);

	return;
}

$override
void HGameObject::setVisible(bool visible) {
	if (m_fields->m_disabled && !m_isSelected)
		GameObject::setVisible(false);
	else
		GameObject::setVisible(visible);

	m_fields->m_realVisible = visible;

	return;
}

$override
void HGameObject::selectObject(ccColor3B selectionColor) {
	GameObject::selectObject(selectionColor);

	static bool const& selectDisabled = LDMManager::get()->getSelectDisabled();

	if (m_fields->m_disabled && selectDisabled)
		this->updateVisible();

	return;
}

$override
void HGameObject::updateObjectEditorColor() {
	GameObject::updateObjectEditorColor();

	if (LDMManager::get()->getLDMOn()) {
		this->checkDisabled();

		if (m_fields->m_disabled)
			this->updateVisible();
	}

	return;
}