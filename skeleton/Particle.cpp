#include "Particle.h"

Particle::Particle(Vector3 Pos, Vector3 Vel, Vector3 Acc, float Damping)
{
	vel = Vel;
	acc = Acc;
	damping = Damping;
	tr = physx::PxTransform(Pos.x, Pos.y, Pos.z);
	renderItem = new RenderItem(CreateShape(physx::PxSphereGeometry(1.0)), &tr, { 1.0, 1.0, 1.0, 1.0 });
}

Particle::~Particle()
{
	DeregisterRenderItem(renderItem);
}

void Particle::integrate(double t) //Update
{
	tr = physx::PxTransform(tr.p.x + vel.x * t, tr.p.y + vel.y * t, tr.p.z + vel.z * t);
	//tr.p += vel * t;
	vel += acc * t;
	vel *= powf(damping, t);
}