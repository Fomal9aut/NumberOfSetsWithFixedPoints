#include "pch.h"
#include "CppUnitTest.h"
#include "../NumberOfSetsWithFixedPoints/Functions.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace NumOfSetsNoFixedPtsTests
{
	TEST_CLASS(NumOfSetsNoFixedPtsTests)
	{
	public:
		
		TEST_METHOD(ArgumentIsPositive)
		{
			uint value = numOfSetsNoFixedPts(5);
			uint exp_value = 44;
			Assert::AreEqual(value, exp_value);
		}

		TEST_METHOD(ArgumentIsOne)
		{
			uint value = numOfSetsNoFixedPts(1);
			uint exp_value = 0;
			Assert::AreEqual(value, exp_value);
		}

		TEST_METHOD(StandartTest)
		{
			uint value = numOfSetsNoFixedPts(7);
			uint exp_value = 1854;
			Assert::AreEqual(value, exp_value);
		}

	};
}
