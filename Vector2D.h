#pragma once
#include "stdafx.h"


template <class Ty>
class Vector2D
{
public:
	Vector2D() : x(), y() {}
	Vector2D(Ty x_, Ty y_) : x(x_), y(y_) {}
	union { 
		struct { Ty x, y; }; 
		Ty arr[2]; 
	};

	static double Dot(const Vector2D<Ty> &a, const Vector2D<Ty> &b) { return a.x * b.x + a.y * b.y; }
	double Dot(const Vector2D<Ty> &other) const { return x * other.x + y * other.y; }

	static Vector2D<Ty> Normalize(const Vector2D<Ty> &vector)
	{
		double length = vector.Length();
		return { vector.x / length, vector.y / length };
	}
	void Normalize() { double length = Length(); x /= length, y /= length; }
		
	double Length() const { return std::sqrt(x * x + y * y); }

	Vector2D<Ty> Reflect(const Vector2D<Ty> &other) const
	{
		Vector2D<Ty> normal = Vector2D<Ty>::Normalize(other);
		double dot = -(*this).Dot(normal);
		return (*this + 2 * normal * dot);
	}
	
	Vector2D<Ty> Rotate(double angle) const
	{
		Vector2D<Ty> retValue;
		retValue.x = cos(DegToRad(angle)) * x - sin(DegToRad(angle)) * y;
		retValue.y = sin(DegToRad(angle)) * x + cos(DegToRad(angle)) * y;
		return retValue;
	}
	Vector2D<Ty> Add(Ty scalar) const { return { x + scalar, y + scalar }; }
	Vector2D<Ty> Sub(Ty scalar) const { return { x - scalar, y - scalar }; }
	Vector2D<Ty> Mul(Ty scalar) const { return { x * scalar, y * scalar }; }
	Vector2D<Ty> Div(Ty scalar) const { return { x / scalar, y / scalar }; }
	
	Vector2D<Ty>& Add(Ty scalar) { x += scalar, y += scalar; return *this; }
	Vector2D<Ty>& Sub(Ty scalar) { x -= scalar, y -= scalar; return *this; }
	Vector2D<Ty>& Mul(Ty scalar) { x *= scalar, y *= scalar; return *this; }
	Vector2D<Ty>& Div(Ty scalar) { x /= scalar, y /= scalar; return *this; }

	Vector2D<Ty>& Add(const Vector2D<Ty>& other) { x += other.x, y += other.y; return *this; }
	Vector2D<Ty>& Sub(const Vector2D<Ty>& other) { x -= other.x, y -= other.y; return *this; }
	Vector2D<Ty>& Mul(const Vector2D<Ty>& other) { x *= other.x, y *= other.y; return *this; }
	Vector2D<Ty>& Div(const Vector2D<Ty>& other) { x /= other.x, y /= other.y; return *this; }
	
	Vector2D<Ty> operator+(Ty scalar) const { return { x + scalar, y + scalar }; }
	Vector2D<Ty> operator-(Ty scalar) const { return { x - scalar, y - scalar }; }
	Vector2D<Ty> operator*(Ty scalar) const { return { x * scalar, y * scalar }; }
	Vector2D<Ty> operator/(Ty scalar) const { return { x / scalar, y / scalar }; }

	Vector2D<Ty> operator+(const Vector2D<Ty>& other) const { return { x + other.x, y + other.y }; }
	Vector2D<Ty> operator-(const Vector2D<Ty>& other) const { return { x - other.x, y - other.y }; }
	Vector2D<Ty> operator*(const Vector2D<Ty>& other) const { return { x * other.x, y * other.y }; }
	Vector2D<Ty> operator/(const Vector2D<Ty>& other) const { return { x / other.x, y / other.y }; }

	Vector2D<Ty>& operator+=(Ty scalar) { x += scalar, y += scalar; return *this; }
	Vector2D<Ty>& operator-=(Ty scalar) { x -= scalar, y -= scalar; return *this; }
	Vector2D<Ty>& operator*=(Ty scalar) { x *= scalar, y *= scalar; return *this; }
	Vector2D<Ty>& operator/=(Ty scalar) { x /= scalar, y /= scalar; return *this; }

	Vector2D<Ty>& operator+=(const Vector2D<Ty>& other) { x += other.x, y += other.y; return *this; }
	Vector2D<Ty>& operator-=(const Vector2D<Ty>& other) { x -= other.x, y -= other.y; return *this; }
	Vector2D<Ty>& operator*=(const Vector2D<Ty>& other) { x *= other.x, y *= other.y; return *this; }
	Vector2D<Ty>& operator/=(const Vector2D<Ty>& other) { x /= other.x, y /= other.y; return *this; }

};

using Vector2i = Vector2D<int>;
using Vector2d = Vector2D<double>;
using Vector2f = Vector2D<float>;
using Point2D = Vector2D<int>;