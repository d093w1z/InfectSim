#pragma once
class Vector{
	float mx, my;

public:
	Vector();
	~Vector();

	float magnitude();
	Vector & operator+(Vector &, Vector &);
	Vector & operator-(Vector &, Vector &);
	Vector & operator*(Vector &, Vector &);
	Vector & operator/(Vector &, Vector &);


};