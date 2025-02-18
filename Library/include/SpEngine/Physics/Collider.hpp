#pragma once

#include <DirectXMath.h>

namespace DX = DirectX;

/**
* A Collider need to retrieve information like
* -Position both x and y
* -Radius
*/

class Collider
{
public:
	/**
	* Constructor for a circle.
	* @param[IN] position XMFLOAT2
	* @param[IN] radius float
	*/
	Collider(DX::XMFLOAT2 position, float radius);

	/**
	* Constructor for an oval.
	* @param[IN] position XMFLOAT2
	* @param[IN] radius float
	* @param[IN] aspectRatio float (modifier for aspect ratio)
	*/
	Collider(DX::XMFLOAT2 position, float radius, float aspectRatio);

	/**
	* Updates position for a collider. (Should be called every frame)
	* @param[IN] position XMFLOAT2
	*/
	void updatePosition(DX::XMFLOAT2 position);

	DX::XMFLOAT2 GetPosition() const;
	float GetRadius() const;
	float GetRadiusX() const;
	float GetRadiusY() const;
	
private:
	DX::XMFLOAT2 m_position;
	float m_radiusX;
	float m_radiusY;
};