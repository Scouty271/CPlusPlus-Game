#include "Random.h"
//#include <cassert>


ae::Random* ae::Random::mInstance = nullptr;


ae::Random* ae::Random::instance()
{
	if (mInstance == nullptr)
	{
		mInstance = new ae::Random();
	}
	return mInstance;
}


ae::Random::Random(void)
{
	unsigned long seed = chrono::system_clock::now().time_since_epoch().count();
	engine.seed(seed);
}


ae::Random::~Random(void)
{
	if (mInstance != nullptr)
		delete mInstance;
}


//
// ----- BOOL
//
bool ae::Random::NextBool()
{
	return NextFloat() < 0.5f ? false : true;
}


//
// ----- INT
//
int ae::Random::NextInt()
{
	int max = std::numeric_limits<int>::max();
	return NextInt(0, max);
	//return uniform_int_distribution<>()(engine);
}


int ae::Random::NextInt(int max)
{
	return NextInt(0, max);
	//return uniform_int_distribution<>(0, max)(engine);
}


int ae::Random::NextInt(int min, int max)
{
	if (min > max) std::swap(min, max);
	return uniform_int_distribution<>(min, max)(engine);
}


//
// ----- CHAR
//
char ae::Random::NextChar()
{
	int max = std::numeric_limits<char>::max();
	return NextChar(0, max);
	//return (char)NextInt(std::numeric_limits<char>::max());
}


char ae::Random::NextChar(char max)
{
	return NextChar(0, max);
	//return uniform_int_distribution<>(0, max)(engine);
}


char ae::Random::NextChar(char min, char max)
{
	if (min > max) std::swap(min, max);
	return uniform_int_distribution<>(min, max)(engine);
}


//
// ----- FLOAT
//
float ae::Random::NextFloat()
{
	//return NextFloat(0.0f, 1.0f);
	return (float)uniform_real_distribution<>(0.0, 1.0)(engine);
}


float ae::Random::NextFloat(float max)
{
	return NextFloat(0.0f, max);
	//return NextFloat() * max;
}


float ae::Random::NextFloat(float min, float max)
{
	if (min > max) std::swap(min, max);
	float delta = max - min;

	unsigned int maxint = std::numeric_limits<unsigned int>::max();
	unsigned int random = (unsigned int)uniform_int_distribution<>(std::numeric_limits<int>::min(), std::numeric_limits<int>::max())(engine);

	if (random == 0)
		return 0.0f;
	if (random == std::numeric_limits<unsigned int>::max())
		return std::numeric_limits<float>::max();

	double faktor = (double)random / (double)maxint;
	double erg = (double)delta * faktor;
	return (float)erg + min;

	//return NextFloat(max - min) + min;
}


//
// ----- DOUBLE
//
double ae::Random::NextDouble()
{
	return uniform_real_distribution<>(0.0, 1.0)(engine);
}


double ae::Random::NextDouble(double max)
{
	return NextDouble() * max;
}


double ae::Random::NextDouble(double min, double max)
{
	if (min > max) std::swap(min, max);
	return NextDouble(max - min) + min;
}


