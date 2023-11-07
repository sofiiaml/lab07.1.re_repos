#include "pch.h"
#include "CppUnitTest.h"
#include "../PT7.1re/PT7.1re.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest71re
{
	TEST_CLASS(UnitTest71re)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
            const int rowCount = 4;
            const int colCount = 4;
            int** matrix = new int* [rowCount];
            for (int i = 0; i < rowCount; i++) {
                matrix[i] = new int[colCount];
                for (int j = 0; j < colCount; j++) {
                    matrix[i][j] = 0; 
                }
            }
            int sum = 0;
            int count = 0;
            int expectedSum = 0; 
            int expectedCount = 0;  
            Calc(matrix, rowCount, colCount, sum, count, 0);
            Assert::AreEqual(expectedSum, sum);
            Assert::AreEqual(expectedCount, count);

            for (int i = 0; i < rowCount; i++) {
                delete[] matrix[i];
            }
            delete[] matrix;
		}
	};
}
