#ifndef PARTICLE_RENDERER_COMPONENT_H
#define PARTICLE_RENDERER_COMPONENT_H
#include <iostream>
#include<string>
#include "Material.hpp"
using namespace std;

class Object;

class ParticleRendererComponent
{
private:
	Material *material;
	Object *father;
public:
	ParticleRendererComponent();
	ParticleRendererComponent(const string path);
	ParticleRendererComponent(Object *obj);
	void LoadImage(const string path);
	Material ParticleMaterial();
	void ParticleMaterial(Material *mat);
	void Draw();
	void Debug();
	void Update();
	Object Father();
	void Father(Object *obj);
};

#endif // !PARTICLE_RENDERER_COMPONENT_H