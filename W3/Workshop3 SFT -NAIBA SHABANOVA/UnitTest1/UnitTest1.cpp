#include "pch.h"
#include "pch.h"
#include "CppUnitTest.h"
#include "testHeader.h"
#include <cstring>
#include <cctype>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;
bool stringIsValid(const string& tempString);
namespace blackBoxString {
	TEST_CLASS(stringTest) {
    public:
		TEST_METHOD(testStringIsValid) {
			bool isValid = stringIsValid("1234567890");
			Assert::IsTrue(isValid);
	}
	};
	TEST_CLASS(stringTest2)
	{
public:
	TEST_METHOD(testStringIsValid) {
		bool isValid = stringIsValid("is this string valid?");  
		Assert::IsTrue(isValid);
	}
	};
	TEST_CLASS(stringTest3)
	{
	public:
		TEST_METHOD(testStringIsValid) {
			bool isValid = stringIsValid("hh");
			Assert::IsTrue(!isValid);
		}
	};
}
namespace whiteBoxString {
	TEST_CLASS(StringTest1)
	{
	public:
		TEST_METHOD(TestStringIsValid)
		{
			bool isValid = stringIsValid(" "); 
			Assert::IsTrue(!isValid);
		}
	};
	TEST_CLASS(StringTest2)
	{
	public:
		TEST_METHOD(TestStringIsValid)
		{
			bool isValid = stringIsValid("\n");  
			Assert::IsTrue(!isValid);
		}
	};
	TEST_CLASS(StringTest3)
	{
	public:
		TEST_METHOD(TestStringIsValid)
		{
			bool isValid = stringIsValid(" \n");  
			Assert::IsTrue(!isValid);
		}
	};
}
bool stringIsValid(const string& tempString) {
	return !tempString.empty();
}
namespace blackBoxPostal {
	TEST_CLASS(PostalTest1)
	{
	public:
		TEST_METHOD(stringIsValidPostalCode)
		{
			bool isValid = postIsValid("M2J2X5"); 
			Assert::IsTrue(isValid);
		}
	};
	TEST_CLASS(PostalTest2)
	{
	public:
		TEST_METHOD(stringIsValidPostalCode)
		{
			bool isValid = postIsValid("m2j 2x5"); 
			Assert::IsTrue(isValid);
		}
	};
	TEST_CLASS(PostalTest3)
	{
	public:
		TEST_METHOD(stringIsValidPostalCode)
		{
			bool isValid = postIsValid("M2J x5"); 
			Assert::IsTrue(!isValid);
		}
	};
}
namespace whiteBoxPostal {
	TEST_CLASS(PostalTest1)
	{
	public:
		TEST_METHOD(stringIsValidPostalCode)
		{
			bool isValid = postIsValid("M2J 2X5"); 
			Assert::IsTrue(!isValid);
		}
	};
	TEST_CLASS(PostalTest2)
	{
	public:
		TEST_METHOD(stringIsValidPostalCode)
		{
			bool isValid = postIsValid("11111"); 
			Assert::IsTrue(!isValid);
		}
	};
	TEST_CLASS(PostalTest3)
	{
	public:
		TEST_METHOD(stringIsValidPostalCode)
		{
			bool isValid = postIsValid("M2J 2x5"); 
			Assert::IsTrue(!isValid);
		}
	};
}
bool stringIsValidPostalCode(int valid)
{
	return valid;
}