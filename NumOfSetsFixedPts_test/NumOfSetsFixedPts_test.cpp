#include "pch.h"
#include "CppUnitTest.h"
#include "../NumberOfSetsWithFixedPoints/Functions.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace NumOfSetsFixedPtstest
{
	TEST_CLASS(NumOfSetsFixedPtstest)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			uint value = NumOfSetsFixedPts(7,7);
			uint exp_value = 7;
			Assert::AreEqual(value, exp_value);
		}
	};
}
