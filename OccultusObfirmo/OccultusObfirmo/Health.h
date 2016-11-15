#pragma once
class Health
{

private:
	int fHealth;
public:
	Health(int baseHealth) { fHealth = baseHealth; };
	Health() {};
	~Health() { delete this; };

	int getHealth()
	{
		return fHealth;
	}

	void setHealth(int sHealth)
	{
		fHealth = sHealth;
	}
};