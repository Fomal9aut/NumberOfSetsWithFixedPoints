#include "pch.h"
#include "CppUnitTest.h"
#include "../NumberOfSetsWithFixedPoints/Functions.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace NumOfSetsNoFixedPtsTests
{
	TEST_CLASS(NumOfSetsNoFixedPtsTests)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			uint value = numOfSetsNoFixedPts(7);
			uint exp_value = 7;
			Assert::AreEqual(value, exp_value);
		}
	};
}
