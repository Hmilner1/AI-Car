#include "Vehicle.h"
#include "AIManager.h"

#define NORMAL_SPEED 500
#define MAX_SPEED 500


HRESULT	Vehicle::initMesh(ID3D11Device* pd3dDevice, carColour colour)
{

	m_Aiman = new AIManager();
	m_scale = XMFLOAT3(30, 20, 1);

	if (colour == carColour::redCar)
	{
		setTextureName(L"Resources\\car_red.dds");
	}
	else if (colour == carColour::blueCar)
	{
		setTextureName(L"Resources\\car_blue.dds");
	}

	HRESULT hr = DrawableGameObject::initMesh(pd3dDevice);

	m_Mass = 1.0f;

	m_maxSpeed = MAX_SPEED;
	setMaxSpeed(MAX_SPEED);
	m_currentSpeed = NORMAL_SPEED;

	setVehiclePosition(Vector2D(0, 0));

	m_lastPosition = Vector2D(0, 0);
	vel = Vector2D(0, 0);

	return hr;
}

void Vehicle::update(const float deltaTime)
{
	Vector2D vecTo = m_positionTo - m_currentPosition;

	Vector2D acc = m_Seek / m_Mass;
	vel = acc * deltaTime;

	m_currentPosition += vel * deltaTime;

	// rotate the object based on its last & current position
	Vector2D diff = m_currentPosition - m_lastPosition;
	if (diff.Length() > 0) { // if zero then don't update rotation
		diff.Normalize();
		m_radianRotation = atan2f((float)diff.y, (float)diff.x); // this is used by DrawableGameObject to set the rotation
	}
	m_lastPosition = m_currentPosition;

	// set the current poistion for the drawablegameobject
	setPosition(Vector2D(m_currentPosition));

	DrawableGameObject::update(deltaTime);
}


// a ratio: a value between 0 and 1 (1 being max speed)
void Vehicle::setCurrentSpeed(const float speed)
{
	m_currentSpeed = m_maxSpeed * speed;
	m_currentSpeed = max(0, m_currentSpeed);
	m_currentSpeed = min(m_maxSpeed, m_currentSpeed);
}

// set a position to move to
void Vehicle::setPositionTo(Vector2D position)
{
	m_startPosition = m_currentPosition;

	m_positionTo = position;
}

// set the current position
void Vehicle::setVehiclePosition(Vector2D position)
{
	m_currentPosition = position;
	m_positionTo = position;
	m_startPosition = position;
	setPosition(position);
}

void Vehicle::setWaypointManager(WaypointManager* wpm)
{
	m_waypointManager = wpm;
}


