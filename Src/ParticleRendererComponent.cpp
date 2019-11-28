#include "ParticleRendererComponent.hpp"
#include "Object.hpp"

ParticleRendererComponent::ParticleRendererComponent()
{
}

ParticleRendererComponent::ParticleRendererComponent(const std::string path)
{
}

ParticleRendererComponent::ParticleRendererComponent(Object *obj)
{
	father = obj;
}

void ParticleRendererComponent::LoadImage(const std::string path)
{
}

void ParticleRendererComponent::Draw()
{
	system("cls");
	cout << "This must be drawing something" << endl;
}

void ParticleRendererComponent::Debug()
{
	cout << "Vertex Shader path: " << ParticleMaterial().VertShaderPath() << endl;
	cout << "Fragment Shader path: " << ParticleMaterial().FragShaderPath() << endl;
}

void ParticleRendererComponent::Update()
{

}

Material ParticleRendererComponent::ParticleMaterial()
{
	return *material;
}

void ParticleRendererComponent::ParticleMaterial(Material *mat)
{
	material = mat;
}

void ParticleRendererComponent::Father(Object *obj)
{
	father = obj;
}

Object ParticleRendererComponent::Father()
{
	return *father;
}