#include <iostream>

int main()
{
	int a[]{ 44, 55, 12, 42, 94, 18, 06, 67 };
	int b[100000];

	int n = 8;

	for (int i = 1; i < n; i *= 2)
	{
		for (int leftBorder = 0; leftBorder + i < n; leftBorder += i * 2)
		{
			int rightBorder = leftBorder + i;
			int nextRightBorder = (rightBorder + i < n) ? rightBorder + i : n;

			int left = leftBorder;
			int j = left;
			int right = rightBorder;

			while (j < rightBorder && right < nextRightBorder) {
				if (a[j] > a[right])
					b[left] = a[right++];
				else
					b[left] = a[j++];

				left++;
			}

			while (j < rightBorder) {
				b[left++] = a[j++];
			}

			while (right < nextRightBorder) {
				b[left++] = a[right++];
			}

			for (j = leftBorder; j < nextRightBorder; j++) {
				a[j] = b[j];
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		std::cout << a[i] << ' ';
	}
}
