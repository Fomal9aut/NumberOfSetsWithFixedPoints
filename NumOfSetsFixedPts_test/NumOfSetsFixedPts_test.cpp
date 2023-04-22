#include "pch.h"
#include "CppUnitTest.h"
#include "../NumberOfSetsWithFixedPoints/Functions.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace NumOfSetsFixedPtstest
{
	TEST_CLASS(NumOfSetsFixedPtstest)
	{
	public:
		
		TEST_METHOD(FirstArgumentGreaterThanSecond)
		{
			uint value = NumOfSetsFixedPts(9,5);
			uint exp_value = 1134;
			Assert::AreEqual(value, exp_value);
		}

		TEST_METHOD(ArgumnetsAreEqual)
		{
			uint value = NumOfSetsFixedPts(5, 5);
			uint exp_value = 1;
			Assert::AreEqual(value, exp_value);
		}

		TEST_METHOD(SecondArgumentIsZero)
		{
			uint value = NumOfSetsFixedPts(9, 0);
			uint exp_value = 133496;
			Assert::AreEqual(value, exp_value);
		}

		TEST_METHOD(ArgumentsAreZero)
		{
			uint value = NumOfSetsFixedPts(0, 0);
			uint exp_value = 1;
			Assert::AreEqual(value, exp_value);
		}

		TEST_METHOD(StandartTest)
		{
			uint value = NumOfSetsFixedPts(9, 2);
			uint exp_value = 66744;
			Assert::AreEqual(value, exp_value);
		}
	};
}
