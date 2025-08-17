#include <Geode/modify/EditorPauseLayer.hpp>

#include "LDMManager.hpp"
#include "utils.hpp"

using namespace geode::prelude;


class $modify(EditorPauseLayer) {
	$override
	bool init(LevelEditorLayer* lel) {
		if (!EditorPauseLayer::init(lel))
			return false;

		auto onLabel = CCLabelBMFont::create("LDM", "bigFont.fnt");
		auto offLabel = CCLabelBMFont::create("LDM", "bigFont.fnt");
		auto toggler = CCMenuItemExt::createToggler(
			CircleButtonSprite::create(
				onLabel,
				CircleBaseColor::Cyan,
				CircleBaseSize::Small
			),
			CircleButtonSprite::create(
				offLabel,
				CircleBaseColor::Green,
				CircleBaseSize::Small
			),
			[lel](CCMenuItemToggler* toggler) {
				bool newOn = !toggler->isOn();

				LDMManager::get()->setLDMOn(newOn);
				ldm::utils::updateVisible(lel);
			}
		);
		onLabel->setPosition(19.75f, 21.5f);
		offLabel->setPosition(19.75f, 21.5f);
		toggler->toggle(LDMManager::get()->getLDMOn());
		toggler->setID("ldm-preview-toggler"_spr);

		auto menu = this->getChildByID("guidelines-menu");
		menu->addChild(toggler);
		menu->updateLayout();

		return true;
	}
};