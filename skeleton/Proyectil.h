#pragma once
#include "core.hpp"
#include "renderUtils.hpp"

class Proyectil //: public Particle(Vector3 Pos, Vector3 Vel, Vector3 Acc, float Damping)
{
public:
	enum ShotType{ PISTOL, ARTILLERY, FIREBALL, LASER };
	Proyectil(ShotType shotType, Vector3 Pos, Vector3 Dir);
	~Proyectil();

private:
	float mass;
	Vector3 vel;
	Vector3 acc;
	float damping;
	physx::PxTransform tr; //pasarlo a renderItem para actualizarlo automaticamente
	RenderItem* renderItem;
};