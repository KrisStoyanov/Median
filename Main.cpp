
#include <iostream>
#include <stack>
#include <queue> 
#include "build/catch.hpp"
using namespace std;

class StructureForMedian
{
private:
	double median;
	priority_queue <double> GreaterDigit;// this heap holds the digits that are smaller than the current median and returns the Greatest number of them all
	priority_queue <double, vector<double>, greater<double>> LowerDigit;//this heap holds the digits that are greater than the current median and returns the Lowest number of them all
	void RearangeHeaps()
	{
		switch (GreaterDigit.size() - LowerDigit.size())
		{
		case  2:
		{
			double temnumber = GreaterDigit.top();
			GreaterDigit.pop();
			LowerDigit.push(temnumber);
			break;
		}
		case -2:
		{
			double temnumber = LowerDigit.top();
			LowerDigit.pop();
			GreaterDigit.push(temnumber);
			break;
		}
		}
	}
public:
	StructureForMedian() : LowerDigit(), GreaterDigit(), median() {}
	void Add(double number)
	{
		if (GreaterDigit.empty() && LowerDigit.empty())
		{
			median = number;
			GreaterDigit.push(number);
		}
		else
		{
			if (number <= median)
			{
				GreaterDigit.push(number);
			}
			else
			{
				LowerDigit.push(number);
			}
		}
		RearangeHeaps();
	}
	double CalculateMedian()
	{
		switch (GreaterDigit.size() - LowerDigit.size())
		{
		case  1:
		{
			median = GreaterDigit.top();
			break;
		}
		case -1:
		{
			median = LowerDigit.top();
			break;
		}
		case  0:
		{
			median = (LowerDigit.top() + GreaterDigit.top()) / 2;
			break;
		}
		}
		return median;
	}
};

double func(std::vector<double> array)
{
	StructureForMedian MyStructure;
	for (int i = 0; i < array.size(); i++)
	{
		MyStructure.Add(array[i]);
	}
	return MyStructure.CalculateMedian();
}

#ifndef Unit_Testing
#define CATCH_CONFIG_MAIN
TEST_CASE("Add function is tested", "[add]")
{
	std::vector<double> newvec;


	newvec.push_back(8);
	newvec.push_back(9);
	newvec.push_back(10);
	newvec.push_back(11);
	newvec.push_back(12);
	newvec.push_back(15);
	REQUIRE(func(newvec) == 10.5);
	newvec.clear();

	newvec.push_back(-8);
	newvec.push_back(-9);
	newvec.push_back(-10);
	newvec.push_back(-11);
	newvec.push_back(-12);
	newvec.push_back(-15);
	REQUIRE(func(newvec) == -10.5);
	newvec.clear();

	newvec.push_back(8);
	newvec.push_back(9);
	newvec.push_back(10);
	newvec.push_back(-8);
	newvec.push_back(-9);
	newvec.push_back(-10);
	REQUIRE(func(newvec) == 0);
	newvec.clear();

	newvec.push_back(8);
	REQUIRE(func(newvec) == 8);
	newvec.clear();

	newvec.push_back(INTMAX_MIN);
	newvec.push_back(INTMAX_MAX);
	REQUIRE(func(newvec) == 0);
	newvec.clear();

	newvec.push_back(INTMAX_MAX);
	REQUIRE(func(newvec) == INTMAX_MAX);
	newvec.clear();


	newvec.push_back(INTMAX_MIN);
	REQUIRE(func(newvec) == INTMAX_MIN);
	newvec.clear();


}

#else
int main()
{

	StructureForMedian MyStructure;

	while (1)
	{
		double insertable_number;
		std::cout << "Enter new number: ";
		std::cin >> insertable_number;
		MyStructure.Add(insertable_number);
		std::cout << "Median is: " << MyStructure.CalculateMedian() << std::endl;
	}

	return 0;
}
#endif // !Unit_Testing