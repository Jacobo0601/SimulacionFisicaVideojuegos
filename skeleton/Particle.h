#pragma once
#include "core.hpp"
#include "renderUtils.hpp"

class Particle
{
public:
	Particle(Vector3 Pos, Vector3 Vel); //particula con posicion y velocidad
	~Particle();

	void integrate(double t);
private:
	Vector3 vel;
	physx::PxTransform tr; //pasarlo a renderItem para actualizarlo automaticamente
	RenderItem* renderItem;
};