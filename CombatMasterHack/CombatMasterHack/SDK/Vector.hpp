#pragma once

class Vector2D 
{
public:
	float x, y;

	Vector2D() 
	{
		x = y = 0.f;
	}

	Vector2D(float newX, float newY) 
	{
		x = newX;
		y = newY;
	}

	Vector2D operator+(float fInput) const 
	{
		return Vector2D{ x + fInput, y + fInput };
	}

	Vector2D operator-(float fInput) const 
	{
		return Vector2D{ x - fInput, y - fInput };
	}

	Vector2D operator/(float fInput) const 
	{
		return Vector2D{ x / fInput, y / fInput };
	}

	Vector2D operator*(float fInput) const 
	{
		return Vector2D{ x * fInput, y * fInput };
	}

	Vector2D operator+(const Vector2D& vInput) const 
	{
		return Vector2D{ x + vInput.x, y + vInput.y };
	}

	Vector2D operator-(const Vector2D& vInput) const 
	{
		return Vector2D{ x - vInput.x, y - vInput.y };
	}

	Vector2D operator*(Vector2D vInput) const 
	{
		return Vector2D{ x * vInput.x, y * vInput.y };
	}

	Vector2D operator/(Vector2D vInput) const 
	{
		return Vector2D{ x / vInput.x, y / vInput.y };
	}

	Vector2D& operator-=(const Vector2D& vInput) 
	{
		x -= vInput.x;
		y -= vInput.y;
		return *this;
	}

	Vector2D& operator+=(const Vector2D& vInput) 
	{
		x += vInput.x;
		y += vInput.y;
		return *this;
	}

	Vector2D& operator*=(const Vector2D& vInput) 
	{
		x *= vInput.x;
		y *= vInput.y;
		return *this;
	}

	Vector2D& operator/=(const Vector2D& vInput) 
	{
		x /= vInput.x;
		y /= vInput.y;
		return *this;
	}

	Vector2D& operator/=(float fInput)
	{
		x /= fInput;
		y /= fInput;
		return *this;
	}

	Vector2D& operator*=(float fInput) 
	{
		x *= fInput;
		y *= fInput;
		return *this;
	}

	Vector2D& operator-=(float fInput) 
	{
		x -= fInput;
		y -= fInput;
		return *this;
	}

	Vector2D& operator+=(float fInput) 
	{
		x += fInput;
		y += fInput;
		return *this;
	}

	bool operator==(const Vector2D& vInput) const 
	{
		return x == vInput.x && y == vInput.y;
	}

	bool operator!=(const Vector2D& vInput) const 
	{
		if (x != vInput.x || y != vInput.y)
			return true;

		return false;
	}

	void Abs() 
	{
		x = abs(x);
		y = abs(y);
	}

	float Length() const 
	{
		return sqrt((x * x) + (y * y));
	}

	float Distance(Vector2D vInput) const 
	{
		return (*this - vInput).Length();
	}

	float Distance2D(Vector2D vInput) const 
	{
		return sqrt(powf(x - vInput.x, 2) + powf(y - vInput.y, 2));
	}

	float Magnitude() 
	{
		return sqrt(this->x * this->x + this->y * this->y);
	}

	float Magnitude2D() 
	{
		return sqrt(this->x * this->x);
	}

	Vector2D Normalized() const 
	{
		return { x / Length(), y / Length() };
	}

	bool Empty() const 
	{
		return x == 0.f && y == 0.f;
	}

	void Clear()
	{
		x = y = 0.f;
	}
};

class Vector3D 
{
public:
	float x, y, z;

	Vector3D() 
	{
		x = y = z = 0.f;
	}

	Vector3D(float newX, float newY, float newZ) 
	{
		x = newX;
		y = newY;
		z = newZ;
	}

	Vector3D operator+(float fInput) const 
	{
		return Vector3D{ x + fInput, y + fInput, z + fInput };
	}

	Vector3D operator-(float fInput) const 
	{
		return Vector3D{ x - fInput, y - fInput, z - fInput };
	}

	Vector3D operator/(float fInput) const 
	{
		return Vector3D{ x / fInput, y / fInput, z / fInput };
	}

	Vector3D operator*(float fInput) const 
	{
		return Vector3D{ x * fInput, y * fInput, z * fInput };
	}

	Vector3D operator+(const Vector3D& vInput) const 
	{
		return Vector3D{ x + vInput.x, y + vInput.y, z + vInput.z };
	}

	Vector3D operator-(const Vector3D& vInput) const 
	{
		return Vector3D{ x - vInput.x, y - vInput.y, z - vInput.z };
	}

	Vector3D operator*(Vector3D vInput) const 
	{
		return Vector3D{ x * vInput.x, y * vInput.y, z * vInput.z };
	}

	Vector3D operator/(Vector3D vInput) const 
	{
		return Vector3D{ x / vInput.x, y / vInput.y, z / vInput.z };
	}

	Vector3D& operator-=(const Vector3D& vInput) 
	{
		x -= vInput.x;
		y -= vInput.y;
		z -= vInput.z;
		return *this;
	}

	Vector3D& operator+=(const Vector3D& vInput) 
	{
		x += vInput.x;
		y += vInput.y;
		z += vInput.z;
		return *this;
	}

	Vector3D& operator*=(const Vector3D& vInput) 
	{
		x *= vInput.x;
		y *= vInput.y;
		z *= vInput.z;
		return *this;
	}

	Vector3D& operator/=(const Vector3D& vInput) 
	{
		x /= vInput.x;
		y /= vInput.y;
		z /= vInput.z;
		return *this;
	}

	Vector3D& operator/=(float fInput) 
	{
		x /= fInput;
		y /= fInput;
		z /= fInput;
		return *this;
	}

	Vector3D& operator*=(float fInput) 
	{
		x *= fInput;
		y *= fInput;
		z *= fInput;
		return *this;
	}

	Vector3D& operator-=(float fInput) 
	{
		x -= fInput;
		y -= fInput;
		z -= fInput;
		return *this;
	}

	Vector3D& operator+=(float fInput) 
	{
		x += fInput;
		y += fInput;
		z += fInput;
		return *this;
	}

	bool operator==(const Vector3D& vInput) const 
	{
		return x == vInput.x && y == vInput.y && z == vInput.z;
	}

	bool operator!=(const Vector3D& vInput) const 
	{
		if (x != vInput.x || y != vInput.y || z != vInput.z)
			return true;

		return false;
	}

	void Abs()
	{
		x = abs(x);
		y = abs(y);
		z = abs(z);
	}

	float LengthSqr() const 
	{
		return (x * x) + (y * y) + (z * z);
	}

	float Length() const
	{
		return sqrt(LengthSqr());
	}

	float Length2D() const
	{
		return sqrt((x * x) + (y * y));
	}

	float Distance(Vector3D vInput) const
	{
		return (*this - vInput).Length();
	}

	float Distance2D(Vector3D vInput) const
	{
		return (*this - vInput).Length2D();
	}

	inline float Dot(const Vector3D& Vec2)
	{
		return this->x * Vec2.x + this->y * Vec2.y + this->z * Vec2.z;
	}

	float Magnitude() 
	{
		return sqrt(this->x * this->x + this->y * this->y + this->z * this->z);
	}

	float Magnitude2D() 
	{
		return sqrt(this->x * this->x + this->z * this->z);
	}

	Vector3D Normalized() const 
	{
		return { x / Length(), y / Length(), z / Length() };
	}

	bool Empty() const
	{
		return x == 0.f && y == 0.f && z == 0.f;
	}

	void Clear()
	{
		x = y = z = 0.f;
	}
};