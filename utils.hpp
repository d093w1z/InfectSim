#pragma once
#include <iostream>
#include <random>

template<typename T>
inline T gRandom(T range_from, T range_to) {
    std::random_device                  rand_dev;
    std::mt19937                        generator(rand_dev());
    std::uniform_real_distribution<T>    distr(range_from, range_to);
    return distr(generator);
}

template<>
inline int gRandom(int range_from, int range_to) {
    std::random_device                  rand_dev;
    std::mt19937                        generator(rand_dev());
    std::uniform_int_distribution<int>    distr(range_from, range_to);
    return distr(generator);
}

template<typename T>
inline T gRandom(T range_to){
	float r = gRandom( 0.f, range_to);
	return r;
}

template<>
inline int gRandom(int range_to){
	int r = gRandom(0, range_to);
	return r;
}

template<typename T>
inline T  gRandom(){
	T r = gRandom(0.f, 1.f);
	return r;
}

template<typename T>
bool gChance(T prob)
{
    return gRandom<T>() <= prob;
}