#pragma once


class IDamageable {
public:
	void damage(int hp) {
		m_hp -= hp;
		if (m_hp <= 0)
			onKill();
	}

	bool dead() const {
		return m_hp <= 0;
	}

	virtual void onKill() = 0;

protected:
	int m_hp;
};