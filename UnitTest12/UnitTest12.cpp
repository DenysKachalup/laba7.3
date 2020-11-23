#include "pch.h"
#include "CppUnitTest.h"
#include "../laba7.3/Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest12
{
	TEST_CLASS(UnitTest12)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			//int** b = new int(2)
			int q = 0;
			int w = 0;
			int row = 3;
			int col = 2;
			int** mas = new int* [row];
			for (int i = 0; i < row; i++)
				mas[i] = new int[col];

			mas[0][0] = { 3 };
			mas[0][1] = { 2 };
			mas[1][0] = { 0 };
			mas[1][1] = { -22 };
			mas[2][0] = { 5 };
			mas[2][1] = { 18 };

			int t = Max(mas, 0, 1, col);

			for (int i = 0; i < row; i++)
				delete[] mas[i];
			delete[] mas;
			Assert::AreEqual(t, 0);
		}
	};
}
