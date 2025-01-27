#pragma once
#include <random>
#include <chrono>


using namespace std;


namespace ae
{
	class Random
	{
	public:
		static Random* instance();

		//template<typename T>
		//T Next();
		//template<typename T>
		//T Next(T max);
		//template<typename T>
		//T Next(T min, T max);

		bool NextBool();

		char NextChar();
		char NextChar(char max);
		char NextChar(char min, char max);

		int NextInt();
		int NextInt(int max);
		int NextInt(int min, int max);

		float NextFloat();

		double NextDouble();

	protected:
		Random(void);
		~Random(void);

	private:
		// Vorerst deaktiviert
		float NextFloat(float max);
		float NextFloat(float min, float max);

		// Vorerst deaktiviert
		double NextDouble(double max);
		double NextDouble(double min, double max);


	private:
		static Random* mInstance;
		default_random_engine engine;
	};
}


//template<typename T>
//T ae::Random::Next()
//{
//	T min = std::numeric_limits<T>::min();
//	T max = std::numeric_limits<T>::max();
//	return Next(min, max);
//}
//
//
//template<typename T>
//T ae::Random::Next(T max)
//{
//	T min = std::numeric_limits<T>::min();
//	return Next(min, max);
//}
//
//
//template<typename T>
//T ae::Random::Next(T min, T max)
//{
//	if (min > max) std::swap(min, max);
//	return uniform_int_distribution<>(min, max)(ae::Random::engine);
//}

