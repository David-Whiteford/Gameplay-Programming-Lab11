
/// Vector 3 class
/// David Whiteford
/// </summary>
#include "MyVector3.h"
#include "MyMatrix3.h"
#include <string.h>
#define PI           3.14159265358979323846


/// Defautl constructor set all 3 values to zero

MyVector3::MyVector3() :
	x{ 0.0 },
	y{ 0.0 },
	z{ 0.0 }
{
}

MyVector3::MyVector3(double t_x, double t_y, double t_z) :
	x{ t_x },
	y{ t_y },
	z{ t_z }
{
}
/// <summary>
/// default destructor
/// nothing to release because we only have
/// primitive type data
/// </summary>
MyVector3::MyVector3(sf::Vector3i t_sfVector) :

	x{ static_cast<double>(t_sfVector.x) },
	y{ static_cast<double>(t_sfVector.y) },
	z{ static_cast<double>(t_sfVector.z) }
{
}
MyVector3::MyVector3(sf::Vector3f t_sfVector)
{
	x = static_cast<double> (t_sfVector.x);
	y = static_cast<double> (t_sfVector.y);
	z = static_cast<double> (t_sfVector.z);
}
MyVector3::MyVector3(sf::Vector2u t_sfVector)
{
	//casts as Vector2f as a double
	x = static_cast<double> (t_sfVector.x);
	y = static_cast<double> (t_sfVector.y);

}
MyVector3::MyVector3(sf::Vector2i t_sfVector) :
	//casts as Vector2f as a double
	x{ static_cast<double>(t_sfVector.x) },
	y{ static_cast<double>(t_sfVector.y) }


{
}
MyVector3::MyVector3(sf::Vector2f t_sfVector)
{
	//casts as Vector2f as a double
	x = static_cast<double> (t_sfVector.x);
	y = static_cast<double> (t_sfVector.y);
}

MyVector3::~MyVector3()
{
}
/// <summary>gets the length squared of the three vector
/// <returns>returns the reusult of the equation</returns>
double MyVector3::lengthSquared() const
{
	const double result = (x * x) + (y * y) + (z * z);
	return result;

}

/// <returns>returns the variable known as return for x y z</returns>
MyVector3 MyVector3::unit() const
{
	// makes the return x y z 0.0
	double returnX{ 0.0 };
	double returnY{ 0.0 };
	double returnZ{ 0.0 };
	//makes vec lenght equal to lenght
	double vecLength = length();
	//never divide by zero
	if (vecLength != 0.0)
	{
		// makes the reurn for x y z the value for x y z divided by vec lenght
		returnX = x / vecLength;
		returnY = y / vecLength;
		returnZ = z / vecLength;
	}
	return MyVector3{ returnX , returnY , returnZ };
}

///determines normalize for the three vectors

void MyVector3::normalise()
{
	//makes the vec lenght equal to lenght
	double vecLength = length();


	if (vecLength != 0.0)// if the vec lenght is not 0.0
	{
		// makes x y z a new value by dividing it by vec lenght
		x = x / vecLength;
		y = y / vecLength;
		z = z / vecLength;
	}

}
double MyVector3::angleBetween(const MyVector3 t_other)const
{
	//determines the angle between and returns and converts the angle to degrees
	const double cosine = unit().dot(t_other.unit());
	const double angleInRadians = std::acos(cosine);
	const double angleInDegrees = angleInRadians * 180 / PI;
	return angleInDegrees;
}
double MyVector3::dot(MyVector3 t_other) const
{
	//determines the dot by multiplying x y z by t_other. x y z
	const double result = (x * t_other.x) + (y * t_other.y) + (z * t_other.z);
	return result;
}

MyVector3 MyVector3::projection(const MyVector3 t_other) const
{
	//determineds the projection of the vector using the lenght squared
	double scale = dot(t_other) / lengthSquared();
	return this->operator*(scale);


}
MyVector3 MyVector3::rejection(const MyVector3 t_other) const
{
	//determineds the rejection of the vector using the projection and has a return
	return MyVector3(t_other - projection(t_other));
}


std::string MyVector3::toString()
{
	//the vector as a string
	const std::string output = "[" + std::to_string(x) + "," + std::to_string(y) + "," + std::to_string(z) + "]";
	return output;
}

std::wstring MyVector3::ToString(MyVector3 t_vector)
{
	const std::wstring output = L"[" + std::to_wstring(t_vector.x) + L"," + std::to_wstring(t_vector.y) + L"," + std::to_wstring(t_vector.z) + L"]";
	return output;
}


// add the x component of the current vector in the plus operator

MyVector3 MyVector3::operator+ (const MyVector3 t_right) const
{
	// add the x y z component of the current vector in the plus operator
	return MyVector3{ x + t_right.x , y + t_right.y , z + t_right.z };
}

MyVector3 MyVector3::operator- (const MyVector3 t_right) const
{
	//subtract the x y z component of the current vector in the negative operator
	return MyVector3{ x - t_right.x, y - t_right.y, z - t_right.z };
}

MyVector3 MyVector3::operator/ (const double t_divisor) const
{
	if (t_divisor != 0)//if divisor is not 0
	{
		//math to determine the division for double values
		return MyVector3{ x / t_divisor, y / t_divisor, z / t_divisor };
	}
	return MyVector3{};
}

MyVector3 MyVector3::operator/ (const float t_divisor) const
{
	if (t_divisor != 0) //if divisor is not 0
	{
		//math to determine the division for float values
		return MyVector3{ x / t_divisor, y / t_divisor, z / t_divisor };
	}
	return MyVector3{};
}

MyVector3 MyVector3::operator/ (const int t_divisor) const
{
	if (t_divisor != 0)//if divisor is not 0
	{
		//math to determine the division for int values
		return MyVector3{ x / t_divisor, y / t_divisor, z / t_divisor };
	}
	return MyVector3{};
}

MyVector3 MyVector3::operator += (const MyVector3 t_right)
{
	//adds t_right.x y z from x y z 
	x += t_right.x;
	y += t_right.y;
	z += t_right.z;
	return MyVector3(x, y, z);
}


MyVector3 MyVector3::operator -= (const MyVector3 t_right)
{
	//subtracts t_right.x y z from x y z 
	x -= t_right.x;
	y -= t_right.y;
	z -= t_right.z;
	return MyVector3(x, y, z);
}
double MyVector3::length() const
{
	//math to determine the lenght of the vector
	const double answer = std::sqrt(x * x + y * y + z * z);
	return answer;
}


MyVector3 MyVector3::operator-()
{
	//return negative values for x y z
	return MyVector3(-x, -y, -z);
}


bool MyVector3::operator==(const MyVector3 t_right) const
{
	//makes the x y and z values equal to t_right.x y z
	const bool answer(x == t_right.x && y == t_right.y && z == t_right.z);
	return answer;
}


bool MyVector3::operator!=(const MyVector3 t_right) const
{
	//makes the x y and z values not equal to t_right.x y z
	const bool result{ x != t_right.x || y != t_right.y || z != t_right.z };
	return result;
}


MyVector3 MyVector3::operator * (const double t_scalar) const
{
	//reurns new vector from multipying them by scalar for double
	return MyVector3(x * t_scalar, y * t_scalar, z * t_scalar);
}


MyVector3 MyVector3::operator * (const float t_scalar) const
{
	//reurns new vector from multipying them by scalar for float value
	return MyVector3(x * t_scalar, y * t_scalar, z * t_scalar);
}


MyVector3 MyVector3::operator * (const int t_scalar) const
{
	//reurns new vector from multipying them by scalar for int value
	return MyVector3(x * t_scalar, y * t_scalar, z * t_scalar);
}
