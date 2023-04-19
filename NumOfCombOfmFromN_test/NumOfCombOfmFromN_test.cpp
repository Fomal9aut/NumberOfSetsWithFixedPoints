#include "pch.h"
#include "CppUnitTest.h"
#include "../NumberOfSetsWithFixedPoints/Functions.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace NumOfCombOfmFromNtest
{
	TEST_CLASS(NumOfCombOfmFromNtest)
	{
	public:
		
		TEST_METHOD(FirstArgumentGreaterSecond)
		{
			uint value = NumOfCombOfmFromN(9, 5);
			uint exp_value = 126;
			Assert::AreEqual(value, exp_value);
		}

		TEST_METHOD(ArgumentsAreEqual)
		{
			uint value = NumOfCombOfmFromN(5, 5);
			uint exp_value = 1;
			Assert::AreEqual(value, exp_value);
		}

		TEST_METHOD(SecondArgumentIsZero)
		{
			uint value = NumOfCombOfmFromN(9, 0);
			uint exp_value = 1;
			Assert::AreEqual(value, exp_value);
		}

		TEST_METHOD(ArgumentsAreZero)
		{
			uint value = NumOfCombOfmFromN(0, 0);
			uint exp_value = 1;
			Assert::AreEqual(value, exp_value);
		}

		TEST_METHOD(ComplexTest)
		{
			uint value = NumOfCombOfmFromN(9, 2);
			uint exp_value = 36;
			Assert::AreEqual(value, exp_value);
		}
	};
}
