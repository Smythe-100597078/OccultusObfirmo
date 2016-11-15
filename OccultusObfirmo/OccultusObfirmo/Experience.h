#pragma once
class Experience
{

private:
	int fExperience;
public:
	Experience(int baseExperience) { fExperience = baseExperience; };
	Experience() {};
	~Experience() { delete this; };

	int getExperience()
	{
		return fExperience;
	}

	void setExperience(int sExperience)
	{
		fExperience = sExperience;
	}
};