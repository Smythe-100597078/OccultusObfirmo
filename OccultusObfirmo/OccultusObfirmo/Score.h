#pragma once
class Score
{

private:
	int fScore;
public:
	Score(int baseScore) { fScore = baseScore; };
	Score() {};
	~Score() { delete this; };

	int getScore()
	{
		return fScore;
	}

	void setScore(int sScore)
	{
		fScore = sScore;
	}
};