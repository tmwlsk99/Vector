#include <iostream>

class Vector3D
{
public:
	int x, y, z;

	Vector3D()
		:x(0),y(0),z(0)
	{}

	Vector3D(const int &_x,const int &_y,const int &_z)
		:x(_x),y(_y),z(_z)
	{}

	Vector3D operator+(const Vector3D &input) //+operator overloading
	{
		Vector3D vec;
		vec.x = this->x + input.x;
		vec.y = this->y + input.y;
		vec.z = this->z + input.z;
		return vec;
	}

	int operator*(const Vector3D &input) //*operator overloading return integer
	{
		int ans;
		ans = this->x * input.x;
		ans += this->y * input.y;
		ans += this->z * input.z;
		return ans;
	}

	friend std::ostream& operator<<(std::ostream& os, const Vector3D& vec); //stream operator overloading
};

class Matrix3x3
{
public:
	Vector3D row0, row1, row2;
	
	Matrix3x3(const Vector3D &r0, const Vector3D &r1, const Vector3D &r2)
		:row0(r0), row1(r1), row2(r2)
	{}

	Vector3D operator*(const Vector3D &rightside) //*operator overloading return integer
	{
		Vector3D ans;
		ans.x = row0*rightside;
		ans.y = row1*rightside;
		ans.z = row2*rightside;

		return ans;
	}
};

std::ostream& operator<<(std::ostream& os, const Vector3D& vec)
{
	os << vec.x << " " << vec.y << " " << vec.z << std::endl;
	return os;
}

int main()
{
	Vector3D v0(1,2,3);
	Vector3D v1 = Vector3D(4, 5, 6);
	Vector3D v2;
	v2 = v0 + v1;
	
	std::cout << v0 << std::endl;
	std::cout << v1 << std::endl;
	std::cout << v2 << std::endl;
	std::cout << v0 * v1 << std::endl;
	//std::cout << v2.x << " " << v2.y << " " << v2.z << " " << std::endl;

	Matrix3x3 m(Vector3D(1,2,3),v1,Vector3D(7,8,9));

	Vector3D y = m*v0;

	std::cout << y << std::endl;

}