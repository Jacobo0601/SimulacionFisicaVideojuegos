#include "Particle.h"

Particle::Particle(Vector3 Pos, Vector3 Vel)
{
	vel = Vel;

	tr = physx::PxTransform(Pos.x, Pos.y, Pos.z);
	renderItem = new RenderItem(CreateShape(physx::PxSphereGeometry(1.0)), &tr, { 1.0, 1.0, 1.0, 1.0 });
}

Particle::~Particle()
{
	DeregisterRenderItem(renderItem);
}

void Particle::integrate(double t) //Update
{
	tr.p += vel * t;
}