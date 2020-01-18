#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
	srand(time(0));

	int N(100000);
	double count(0);

	for (int i = 0; i < N; ++i)
	{
		double x = (rand()/(double) RAND_MAX) + 1;
		double y = rand()/(double) RAND_MAX;
		if (x * y <= 1.0)
			++count;
	}

	cout << "Ln 2 is approximately: " << count / N << endl;

	return 0;
}