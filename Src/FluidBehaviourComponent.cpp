#include "FluidBehaviourComponent.hpp"
#include "Object.hpp"

FluidBehaviourComponent::FluidBehaviourComponent()
{
}

FluidBehaviourComponent::FluidBehaviourComponent(Object *obj)
{
	father = obj;
}

Object FluidBehaviourComponent::Father()
{
	return *father;
}

void FluidBehaviourComponent::Father(Object *obj)
{
	father = obj;
}

void FluidBehaviourComponent::Debug()
{

}

void FluidBehaviourComponent::Update()
{

}