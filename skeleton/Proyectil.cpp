#include "Proyectil.h"
#include "Particle.h"

enum class ShotType { PISTOL, ARTILLERY, FIREBALL, LASER };

Proyectil::Proyectil(ShotType shotType, Vector3 Pos, Vector3 Dir)
{
	tr = physx::PxTransform(Pos.x, Pos.y, Pos.z);
	//renderItem = new RenderItem(CreateShape(physx::PxSphereGeometry(1.0)), &tr, { 1.0, 1.0, 1.0, 1.0 });
	Particle* newpart = new Particle({ 0,0,0 } , { 0,0,0 } ,{0,0,0}, 1.0f);
	
	switch (shotType) 
	{
		case PISTOL:
			shot->setMass(2.0f); // 2.0 Kg
			shot->newpart.setVelocity(0.0f, 0.0f, 35.0f); // 35 m/s
			shot->newpart.setAcceleration(0.0f, -1.0f, 0.0f);
			shot->newpart.setDamping(0.99f);
			break;
	}
}

Proyectil::~Proyectil()
{
	DeregisterRenderItem(renderItem);
}