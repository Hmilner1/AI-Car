#pragma once

#include "WaypointManager.h"

using namespace std;

class Vehicle;
class PickupItem;
typedef vector<PickupItem*> vecPickups;

class AIManager
{
public:
	AIManager();
	virtual  ~AIManager();
	void	release();
	HRESULT initialise(ID3D11Device* pd3dDevice);
	void	update(const float fDeltaTime);
	void	mouseUp(int x, int y);
	void	keyDown(WPARAM param);
	void	keyUp(WPARAM param);
	void	Car2Move();
	Vector2D RandomWaypoint();
protected:
	bool	checkForCollisions();
	void	setRandomPickupPosition(PickupItem* pickup);
	bool	CarAtLocation = true;

private:
	vecPickups              m_pickups;
	Vehicle*				m_pCar = nullptr;
	Vehicle*				m_pCar2 = nullptr;
	WaypointManager			m_waypointManager;

};

