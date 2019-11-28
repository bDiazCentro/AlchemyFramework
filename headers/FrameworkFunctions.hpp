#ifndef FRAMEWORK_FUNCTIONS_H
#define FRAMEWORK_FUNCTIONS_H
#include "Vector3.hpp"
#include "Vector2.hpp"
#include "Color.hpp"
#include <math.h>
#include "GameManager.hpp"
#include "vulkan\vulkan.h"

namespace VectorFuncs
{
	namespace v2 {
	inline float DistanceSquared(const Vector2 &firstVector, const Vector2 &secondVector)
	{
		const float distanceX = firstVector.X() - secondVector.X();
		const float squareX = distanceX * distanceX;

		const float distanceY = firstVector.Y() - secondVector.Y();
		const float squareY = distanceY * distanceY;

		return squareX + squareY;
	}

	inline float Distance(const Vector2 &firstVector, const Vector2 &secondVector)
	{
		return 	sqrt(DistanceSquared(firstVector, secondVector));
	}

	inline Vector2 operator* (const float s, Vector2 &v)
	{
		return Vector2(v.X() * s, v.Y() * s);
	}

	inline Vector2 Lerp(const Vector2 &initialPos, const Vector2 &finalPos, const float percentage)
	{
		return initialPos + percentage * (finalPos - initialPos);
	}

	inline float Magnitude(Vector2 &vector)
	{
		return sqrt(vector.X() * vector.X() + vector.Y() * vector.Y());
	}

	inline float Dot(Vector2 &v1, Vector2 &v2)
	{
		return v1.X() * v2.X() + v1.Y() * v2.Y();
	}

	inline Vector2 Normalize(Vector2 &v1)
	{
		const float magnitude = Magnitude(v1);
		return Vector2(v1.X() / magnitude, v1.Y() / magnitude);
	}
}

	namespace V3 {
	inline float DistanceSquared(const Vector3 &firstVector, const Vector3 &secondVector)
	{
		const float distanceX = firstVector.X() - secondVector.X();
		const float squareX = distanceX * distanceX;

		const float distanceY = firstVector.Y() - secondVector.Y();
		const float squareY = distanceY * distanceY;

		const float distanceZ = firstVector.Z() - secondVector.Z();
		const float squareZ = distanceZ * distanceZ;

		return squareX + squareY + squareZ;
	}

	inline float Distance(const Vector3 &firstVector, const Vector3 &secondVector)
	{
		return 	sqrt(DistanceSquared(firstVector, secondVector));
	}

	inline Vector3 operator* (const float s, Vector3 &v)
	{
		return Vector3(v.X() * s, v.Y() * s, v.Z() * s);
	}

	inline Vector3 Lerp(const Vector3 &initialPos, const Vector3 &finalPos, const float percentage)
	{
		return initialPos + percentage * (finalPos - initialPos);
	}


	inline float Magnitude(Vector3 &vector)
	{
		return sqrt(vector.X() * vector.X() + vector.Y() * vector.Y() + vector.Z() * vector.Z());
	}

	inline float Dot(Vector3 &v1, Vector3 &v2)
	{
		return v1.X() * v2.X() + v1.Y() * v2.Y() + v1.Z() * v2.Z();
	}

	inline float CrossProdcut(Vector3 &v1, Vector3 &v2, Vector3 &v3)
	{
		return v1.X() * (v2.Y() * v3.Z() - v3.Y() * v2.Z())
			- v1.Y() * (v2.X() * v3.Z() - v3.X() * v2.Z())
			+ v1.Z() * (v2.X() * v3.Y() - v3.X() * v2.Y());
	}

	inline Vector3 Normalize(Vector3 &v1)
	{
		const float magnitude = Magnitude(v1);
		return Vector3(v1.X() / magnitude, v1.Y() / magnitude, v1.Z() / magnitude);
	}
}
}

namespace ColorFuncs
{
	inline Color Lerp(Color a, Color b, float percentage)
	{
		float newR = a.R() + percentage * (b.R() - a.R());
		float newG = a.G() + percentage * (b.G() - a.G());
		float newB = a.B() + percentage * (b.B() - a.B());
		float newA = a.A() + percentage * (b.A() - a.A());
		return Color(newR, newG, newB, newA);
	}
}

struct TextureData {
	VkSampler				sampler;
	VkImage					image;
	VkImageLayout			imageLayout;
	VkMemoryAllocateInfo	memoryAlloc;
	VkDeviceMemory			mem;
	VkImageView				view;
	uint32_t				mipMapLevels;
	uint32_t				layerCount;
	uint32_t				textureWidth, textureHeight;
	VkDescriptorImageInfo	descsImgInfo;
};

struct Sprites
{
	VkImage textureImage;
	VkDeviceMemory textureImageMemory;
	VkImageView textureImageView;
	VkDescriptorSet descriptorSet;
};


#endif