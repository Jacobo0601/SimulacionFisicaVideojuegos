#pragma once
#include "core.hpp"
#include "renderUtils.hpp"

class Particle
{
public:
	Particle(Vector3 Pos, Vector3 Vel, Vector3 Acc, float Damping); //particula con posicion y velocidad
	~Particle();

	void integrate(double t);
private:
	Vector3 vel;
	Vector3 acc;
	float damping;
	physx::PxTransform tr; //pasarlo a renderItem para actualizarlo automaticamente
	RenderItem* renderItem;
};