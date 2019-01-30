/// Metrix 3 class
/// David Whiteford
/// 
#include "MyMatrix3.h"

#include <string>
#define PI           3.14159265358979323846



MyMatrix3::MyMatrix3() :

	//all nums in matrix initialized to 0
	m_11{ 0.0 },
	m_12{ 0.0 },
	m_13{ 0.0 },
	m_21{ 0.0 },
	m_22{ 0.0 },
	m_23{ 0.0 },
	m_31{ 0.0 },
	m_32{ 0.0 },
	m_33{ 0.0 }

{
}

MyMatrix3::MyMatrix3(double t_a11, double t_a12, double t_a13,
	double t_a21, double t_a22, double t_a23,
	double t_a31, double t_a32, double t_a33) :
	//make all matrix values equal to passed values
	m_11{ t_a11 },
	m_12{ t_a12 },
	m_13{ t_a13 },
	m_21{ t_a21 },
	m_22{ t_a22 },
	m_23{ t_a23 },
	m_31{ t_a31 },
	m_32{ t_a32 },
	m_33{ t_a33 }
{
}

MyMatrix3::MyMatrix3(MyVector3 t_row1, MyVector3 t_row2, MyVector3 t_row3)
//sets up the matrix rows
{
	//x y z coordinates of the first row columns 1 2 3
	m_11 = t_row1.x;
	m_12 = t_row1.y;
	m_13 = t_row1.z;

	//x y z coordinates of the second row colums 1 2 3
	m_21 = t_row2.x;
	m_22 = t_row2.y;
	m_23 = t_row2.z;

	//x y z coordinates of the third row columns 1 2 3
	m_31 = t_row3.x;
	m_32 = t_row3.y;
	m_33 = t_row3.z;


}

MyMatrix3::~MyMatrix3()
{
}


std::string MyMatrix3::toString()const
{
	// returns the matrix as a string
	const std::string output = "[" + std::to_string(m_11) + "," + std::to_string(m_12) + "," + std::to_string(m_13) + "," + std::to_string(m_21) + "," + std::to_string(m_22) + "," + std::to_string(m_23) + "," + std::to_string(m_31) + "," + std::to_string(m_32) + "," + std::to_string(m_33) + "]";
	return output;
}
bool MyMatrix3::operator==(const MyMatrix3 t_other) const
//checks for the equaily between two matices
{
	//checks if the rows and columns of the matrix equal to the rows and cols of the second matrix
	const bool answer(m_11 == t_other.m_11 && m_12 == t_other.m_12 && m_13 == t_other.m_13 &&
		m_21 == t_other.m_21 && m_22 == t_other.m_22 && m_23 == t_other.m_23 &&
		m_31 == t_other.m_31 && m_32 == t_other.m_32 && m_13 == t_other.m_33);
	return answer;
}


bool MyMatrix3::operator!=(const MyMatrix3 t_other) const
//checks if there is no equaily between two matices
{
	//checks if the rows and columns of the matrix not equal to the rows and cols of the second matrix
	const bool result{ m_11 != t_other.m_11 || m_12 != t_other.m_12 || m_13 != t_other.m_13 ||
		m_21 != t_other.m_21 || m_22 != t_other.m_22 || m_23 != t_other.m_23 ||
		m_31 != t_other.m_31 || m_32 != t_other.m_32 || m_13 != t_other.m_33 };
	return result;
}



MyMatrix3 MyMatrix3::operator +(const MyMatrix3 t_other) const
//adding two matrices
{
	//adds the values for the matrix to another matrix
	return MyMatrix3{ m_11 + t_other.m_11 , m_12 + t_other.m_12 , m_13 + t_other.m_13,
		m_21 + t_other.m_21 , m_22 + t_other.m_22 , m_23 + t_other.m_23,
		m_31 + t_other.m_31 , m_32 + t_other.m_32 , m_33 + t_other.m_33, };
}



MyMatrix3 MyMatrix3::operator -(const MyMatrix3 t_other) const
//subtracts two matrices
{
	//subtract the  values of the metrix for the negative operator
	return MyMatrix3{ m_11 - t_other.m_11 , m_12 - t_other.m_12 , m_13 - t_other.m_13,
		m_21 - t_other.m_21 , m_22 - t_other.m_22 , m_23 - t_other.m_23,
		m_31 - t_other.m_31 , m_32 - t_other.m_32 , m_33 - t_other.m_33, };
}


MyMatrix3 MyMatrix3::operator *(const MyMatrix3 t_other) const
//multiply the two matrices
{
	//multiply the  values of the metrix for the negative operator
	return MyMatrix3{ m_11 * t_other.m_11 , m_12 * t_other.m_12 , m_13 * t_other.m_13,
		m_21 * t_other.m_21 , m_22 * t_other.m_22 , m_23 * t_other.m_23,
		m_31 * t_other.m_31 , m_32 * t_other.m_32 , m_33 * t_other.m_33, };
}
MyMatrix3 MyMatrix3::operator *(const double t_scale)const
//multiply the two matrices
{
	//multiplies metrix values by t_scale for double
	return MyMatrix3{ m_11 * t_scale , m_12 * t_scale , m_13 * t_scale,
		m_21 * t_scale , m_22 * t_scale , m_23 * t_scale,
		m_31 * t_scale , m_32 * t_scale , m_33 * t_scale, };

}

MyVector3 MyMatrix3::operator *(const MyVector3 t_vector)const
//multiply the two matrices
{
	//multiplies metrix values by t_vector for double
	return MyVector3{ ((m_11 * t_vector.x )+  (m_12 * t_vector.y) +  (m_13 * t_vector.z)),
					   ((m_21 * t_vector.x ) + ( m_22 * t_vector.y) + (m_23 * t_vector.z)),
					   ((m_31 * t_vector.x) +  ( m_32 * t_vector.y) + ( m_33 * t_vector.z)) };

}

MyMatrix3 MyMatrix3::inverse() const
{
	//makes matrix for inverse
	MyMatrix3 inverse;
	//if determinate is not zero
	if (determinant() != 0)
	{
		//makes inverse equal to following maths
		inverse = { (m_33 * m_22) - (m_32 * m_23), (m_32 * m_13) - (m_33 * m_12),(m_23 * m_12) - (m_22 * m_13),
			(m_31 * m_23) - (m_33 * m_21), (m_33 * m_11) - (m_31 * m_13),(m_21 * m_13) - (m_23 * m_11),
			(m_32 * m_21) - (m_31 * m_22), (m_31 * m_12) - (m_32 * m_11),(m_22 * m_11) - (m_21 * m_12) };

		//multiplys inverse by 1 over determinate
		inverse = inverse * (1 / determinant());

	}

	return inverse;



}

double MyMatrix3::determinant() const
{
	//determines determinate for a matrix and returns
	double detr = (m_11*((m_22 * m_33) - (m_32 * m_23))) - m_21 * ((m_33 * m_12) - (m_32 * m_13)) + m_31 * ((m_23 * m_12) - (m_22 * m_13));
	return detr;
}



MyVector3 MyMatrix3::row(const int t_row)const
{

	//makes vector for the row 
	MyVector3 row;

	if (t_row == 0)
	{
		//if 0 makes row vector equal to first matrix row 
		row = { m_11, m_12, m_13 };
	}
	if (t_row == 1)
	{
		//if 1 makes row vector equal to second matrix row 
		row = { m_21, m_22, m_23 };
	}
	if (t_row == 2)
	{
		//if 3 makes row vector equal to third matrix row 
		row = { m_31, m_32, m_33 };
	}
	//returns the row
	return row;
}





MyVector3 MyMatrix3::column(const int t_column) const
{
	//makes vector for the column 
	MyVector3 col;
	if (t_column == 0)
	{
		//if 0 makes row vector equal to first matrix col 
		col = { m_11, m_21, m_31 };
	}
	if (t_column == 1)
	{
		//if 1 makes row vector equal to second matrix col 
		col = { m_12, m_22, m_32 };
	}
	if (t_column == 2)
	{
		//if 2 makes row vector equal to third matrix col 
		col = { m_13, m_23, m_33 };
	}
	//returns column
	return col;

}

MyMatrix3 MyMatrix3::transpose()const
{
	//makes vector for the transpose
	MyMatrix3 trans;
	//makes new matrix values equal to original values with rows and cols swapped
	double n_11 = m_11;
	double n_12 = m_21;
	double n_13 = m_31;
	double n_21 = m_12;
	double n_22 = m_22;
	double n_23 = m_32;
	double n_31 = m_13;
	double n_32 = m_23;
	double n_33 = m_33;

	//makes new matrix with rows and cols swapped and returns
	trans = { n_11, n_12, n_13, n_21, n_22, n_23, n_31, n_32, n_33 };
	return trans;
}



MyMatrix3 MyMatrix3::translation(const MyVector3 t_displacement)
{
	//makes matrix for translation
	MyMatrix3 translation;

	//assigns values to n
	double n_11 = 1;
	double n_12 = 0;
	double n_13 = t_displacement.x;
	double n_21 = 0;
	double n_22 = 1;
	double n_23 = t_displacement.y;
	double n_31 = 0;
	double n_32 = 0;
	double n_33 = 1;
	//makes matrix translation equal to n values
	translation = { n_11, n_12, n_13, n_21, n_22, n_23, n_31, n_32, n_33 };
	return translation;
}
MyMatrix3 MyMatrix3::scale(const double t_scalingfactor)
{
	//makes new matrix called scale
	MyMatrix3 scale;

	//assigns values to n
	double n_11 = t_scalingfactor;
	double n_12 = 0;
	double n_13 = 0;

	double n_21 = 0;
	double n_22 = t_scalingfactor;
	double n_23 = 0;

	double n_31 = 0;
	double n_32 = 0;
	double n_33 = t_scalingfactor;;
	//makes scale matrix equal to n values and returns
	scale = { n_11, n_12, n_13, n_21, n_22, n_23, n_31, n_32, n_33 };
	return scale;
}
MyMatrix3 MyMatrix3::rotationZ(const double t_angleRadians)
{
	//makes matrix for z rotation
	MyMatrix3 rotationZ;

	//assigns values to n
	double n_11 = cos(t_angleRadians);
	double n_12 = -sin(t_angleRadians);
	double n_13 = 0;
	double n_21 = sin(t_angleRadians);
	double n_22 = cos(t_angleRadians);
	double n_23 = 0;
	double n_31 = 0;
	double n_32 = 0;
	double n_33 = 1;
	//makes matrix rotationZ equal to n values
	rotationZ = { n_11, n_12, n_13, n_21, n_22, n_23, n_31, n_32, n_33 };
	return rotationZ;
}
MyMatrix3 MyMatrix3::rotationX(const double t_angleRadians)
{
	//makes matrix for x rotation
	MyMatrix3 rotationX;

	//assigns values to n
	double n_11 = 1;
	double n_12 = 0;
	double n_13 = 0;
	double n_21 = 0;
	double n_22 = cos(t_angleRadians);
	double n_23 = -sin(t_angleRadians);
	double n_31 = 0;
	double n_32 = sin(t_angleRadians);
	double n_33 = cos(t_angleRadians);
	//makes matrix rotationX equal to n values
	rotationX = { n_11, n_12, n_13, n_21, n_22, n_23, n_31, n_32, n_33 };
	return rotationX;
}
MyMatrix3 MyMatrix3::rotationY(const double t_angleRadians)
{
	//makes matrix for y rotation
	MyMatrix3 rotationY;

	//assigns values to n
	double n_11 = cos(t_angleRadians);
	double n_12 = 0;
	double n_13 = sin(t_angleRadians);
	double n_21 = 0;
	double n_22 = 1;
	double n_23 = 0;
	double n_31 = -sin(t_angleRadians);
	double n_32 = 0;
	double n_33 = cos(t_angleRadians);
	//makes matrix rotationY equal to n values
	rotationY = { n_11, n_12, n_13, n_21, n_22, n_23, n_31, n_32, n_33 };
	return rotationY;
}

