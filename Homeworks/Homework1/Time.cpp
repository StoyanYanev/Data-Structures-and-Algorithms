#include<iostream>

struct Time {
	int hour;
	int minutes;
};

bool CheckIsValid(Time first, Time second);
int FindMaxTime(int first, int second, int third);
int FindMinTime(int first, int second, int third);
void PrintResult(Time minTime, Time maxTime);
int ConvertInMinutes(Time start, Time end);

int main()
{
	Time firstTimeStart;
	Time firstTimeFinish;

	Time secondTimeStart;
	Time secondTimeFinish;

	Time thirdTimeStart;
	Time thirdTimeFinish;

	std::cin >> firstTimeStart.hour >> firstTimeStart.minutes >> firstTimeFinish.hour >> firstTimeFinish.minutes;
	std::cin >> secondTimeStart.hour >> secondTimeStart.minutes >> secondTimeFinish.hour >> secondTimeFinish.minutes;
	std::cin >> thirdTimeStart.hour >> thirdTimeStart.minutes >> thirdTimeFinish.hour >> thirdTimeFinish.minutes;

	if (CheckIsValid(firstTimeStart, firstTimeFinish) == true &&
		CheckIsValid(secondTimeStart, secondTimeFinish) == true &&
		CheckIsValid(thirdTimeStart, thirdTimeFinish) == true)
	{
		int first = ConvertInMinutes(firstTimeStart, firstTimeFinish);
		int second = ConvertInMinutes(secondTimeStart, secondTimeFinish);
		int third = ConvertInMinutes(thirdTimeStart, thirdTimeFinish);

		int maxT = FindMaxTime(first, second, third);
		int minT = FindMinTime(first, second, third);

		Time maxTime;
		Time minTime;

		maxTime.hour = maxT / 60;
		maxTime.minutes = maxT % 60;

		minTime.hour = minT / 60;
		minTime.minutes = minT % 60;

		PrintResult(minTime, maxTime);
	}
	return 0;
}

bool CheckIsValid(Time first, Time second)
{
	if (first.hour <= 24 && first.hour >= 0 && second.hour <= 24 && second.hour >= 0)
	{
		if (first.minutes < 60 && first.minutes >= 0 && second.minutes < 60 && second.minutes >= 0)
		{
			return true;
		}
	}
	return false;
}

int FindMaxTime(int first, int second, int third)
{
	int maxTime = first;
	if (maxTime < second)
	{
		maxTime = second;
	}
	if (maxTime < third)
	{
		maxTime = third;
	}
	return maxTime;
}

int FindMinTime(int first, int second, int third)
{
	int minTime = first;
	if (minTime > second)
	{
		minTime = second;
	}
	if (minTime > third)
	{
		minTime = third;
	}
	return minTime;
}

void PrintResult(Time minTime, Time maxTime)
{
	std::cout << minTime.hour << ":";
	if (minTime.minutes < 10)
	{
		std::cout << "0" << minTime.minutes << std::endl;
	}
	else
	{
		std::cout << minTime.minutes << std::endl;
	}

	std::cout << maxTime.hour << ":";
	if (maxTime.minutes < 10)
	{
		std::cout << "0" << maxTime.minutes << std::endl;
	}
	else {
		std::cout << maxTime.minutes << std::endl;
	}
}

int ConvertInMinutes(Time start, Time end)
{
	int difference;
	if (end.hour >= start.hour)
	{
		difference = (end.hour * 60 + end.minutes) - (start.hour * 60 + start.minutes);
	}
	else {
		difference = ((end.hour + 24) * 60 + end.minutes) - (start.hour * 60 + start.minutes);
	}

	return difference;
}