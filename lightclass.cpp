////////////////////////////////////////////////////////////////////////////////
// Filename: lightclass.cpp
////////////////////////////////////////////////////////////////////////////////
#include "lightclass.h"


LightClass::LightClass()
{
}


LightClass::LightClass(const LightClass& other)
{
}


LightClass::~LightClass()
{
}


void LightClass::SetDirection(float x, float y, float z)
{
	m_direction = DirectX::XMFLOAT3(x, y, z);
	return;
}


void LightClass::SetPosition(float x, float y, float z)
{
	m_position = DirectX::XMFLOAT3(x, y, z);
	return;
}


void LightClass::SetLookAt(float x, float y, float z)
{
	m_lookAt.x = x;
	m_lookAt.y = y;
	m_lookAt.z = z;
	return;
}


DirectX::XMFLOAT3 LightClass::GetDirection()
{
	return m_direction;
}


DirectX::XMFLOAT3 LightClass::GetPosition()
{
	return m_position;
}


void LightClass::GenerateViewMatrix()
{
	DirectX::XMFLOAT3 up;


	// Setup the vector that points upwards.
	up.x = 0.0f;
	up.y = 1.0f;
	up.z = 0.0f;

	// Create the view matrix from the three vectors.
	m_viewMatrix = DirectX::XMMatrixLookAtLH(DirectX::XMLoadFloat3(&m_position), DirectX::XMLoadFloat3(&m_lookAt), DirectX::XMLoadFloat3(&up));
	
	return;
}


void LightClass::GenerateProjectionMatrix(float screenDepth, float screenNear)
{
	float fieldOfView, screenAspect;


	// Setup field of view and screen aspect for a square light source.
	fieldOfView = (float)DirectX::XM_PI / 2.0f;
	screenAspect = 1.0f;

	// Create the projection matrix for the light.
	m_projectionMatrix = DirectX::XMMatrixPerspectiveFovLH(fieldOfView, screenAspect, screenNear, screenDepth);

	return;
}


void LightClass::GenerateOrthoMatrix(float width, float height, float screenDepth, float screenNear)
{
	// Create the projection matrix for the light.
	m_orthoMatrix = DirectX::XMMatrixOrthographicLH(width, height, screenNear, screenDepth);

	return;
}


void LightClass::GetViewMatrix(DirectX::XMMATRIX & viewMatrix)
{
	viewMatrix = m_viewMatrix;
	return;
}


void LightClass::GetProjectionMatrix(DirectX::XMMATRIX & projectionMatrix)
{
	projectionMatrix = m_projectionMatrix;
	return;
}


void LightClass::GetOrthoMatrix(DirectX::XMMATRIX & orthoMatrix)
{
	orthoMatrix = m_orthoMatrix;
	return;
}