#pragma once


class LDMManager final {
public:
	static LDMManager* get();

	LDMManager(LDMManager const&) = delete;
	LDMManager& operator=(LDMManager const&) = delete;
	LDMManager(LDMManager&&) = delete;
	LDMManager& operator=(LDMManager&&) = delete;

private:
	LDMManager();
	~LDMManager() = default;

public:
	[[nodiscard]] bool const& getLDMOn() const { return m_ldmOn; }
	void setLDMOn(bool on) { m_ldmOn = on; }

private:
	bool m_ldmOn;
};