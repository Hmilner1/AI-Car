#pragma once

#include "DrawableGameObject.h"
#include "WaypointManager.h"
#include "Vector2D.h"
#include "Collidable.h"
#include "AIManager.h"


using namespace std;

enum class carColour
{
	redCar,
	blueCar,
};

class Vehicle : public DrawableGameObject, public Collidable
{
public:
	virtual HRESULT initMesh(ID3D11Device* pd3dDevice, carColour colour);
	virtual void update(const float deltaTime);

	void setMaxSpeed(const float maxSpeed) { m_maxSpeed = maxSpeed; }
	void setCurrentSpeed(const float speed); // a ratio: a value between 0 and 1 (1 being max speed)
	Vector2D GetPosition() { return m_currentPosition; }
	Vector2D GetVelocity() { return vel; }
	void setPositionTo(Vector2D positionTo); // a position to move to
	void setVehiclePosition(Vector2D position); // the current position - this resets positionTo
	void setWaypointManager(WaypointManager* wpm);
	void hasCollided() {}
	Vector2D m_currentPosition;
	Vector2D m_SecondCarPos;
	float m_currentSpeed;
	float m_Acceleration;
	Vector2D m_SteeringForce;
	float m_Mass;
	Vector2D vel;
	float m_maxSpeed;
	bool Seeking;
	Vector2D m_Target;
	Vector2D Seek(Vector2D Target);
	Vector2D Arrive(Vector2D Target);
	Vector2D Wander(Vector2D Target);
	Vector2D Pursuit(Vector2D Target);
	Vector2D Flee(Vector2D Target);
	Vector2D ObsticalAvoidance(Vector2D Target, Vector2D SecondCarPos);
	Vector2D RandomTarget();
	float m_Distance;
	int m_State;


protected: // protected methods


protected: // preotected properties

	Vector2D m_startPosition;
	Vector2D m_positionTo;
	Vector2D m_lastPosition;
	WaypointManager* m_waypointManager;
private:


};

