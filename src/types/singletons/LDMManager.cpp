#include "LDMManager.hpp"

#include <Geode/loader/Mod.hpp>

using namespace geode::prelude;


LDMManager* LDMManager::get() {
	static auto instance = LDMManager();

	return &instance;
}

LDMManager::LDMManager() {
	m_ldmOn = Mod::get()->getSavedValue<bool>("ldm-on");

	log::info("Manager initialized.");
}

$on_mod(DataSaved) {
	Mod::get()->setSavedValue("ldm-on", LDMManager::get()->getLDMOn());

	log::info("Data saved.");
}