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

$override
void HGameObject::setVisible(bool visible) {
	if (m_fields->m_disabled)
		GameObject::setVisible(false);
	else
		GameObject::setVisible(visible);

	m_fields->m_ogVisible = visible;

	return;
}