#pragma once
#include <math.h>

struct Vec2
{
	float x{}, y{};
};

struct Vec4
{
	float x{}, y{}, z{}, w{};
};

struct Vec3
{
	constexpr Vec3(const float x = 0.f, const float y = 0.f, const float z = 0.f) noexcept : x(x), y(y), z(z) {}
	constexpr const Vec3& operator+(const Vec3& other)
	{
		return Vec3{ x + other.x, y + other.y, z + other.z };
	}
	constexpr const Vec3& operator-(const Vec3& other)
	{
		return Vec3{ x - other.x, y - other.y, z - other.z };
	}
	constexpr const Vec3& operator*(const Vec3& other)
	{
		return Vec3{ x * other.x, y * other.y, z * other.z };
	}
	constexpr const Vec3& operator/(const Vec3& other)
	{
		return Vec3{ x / other.x, y / other.y, z / other.z };
	}

	float x, y, z;

	float GetDistance(Vec3 targetpos)
	{
		Vec3 player_pos{this->x, this->y, this->z};

		return sqrt(((player_pos.x - targetpos.x) * (player_pos.x - targetpos.x))
			+ ((player_pos.y - targetpos.y) * (player_pos.y - targetpos.y))
			+ ((player_pos.z - targetpos.z) * (player_pos.z - targetpos.z)));
	}
};

