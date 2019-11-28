#include "BackgroundBehaviourComponent.hpp"
#include "Object.hpp"

BackgroundBehaviourComponent::BackgroundBehaviourComponent()
{
}

BackgroundBehaviourComponent::BackgroundBehaviourComponent(Object *obj)
{
	father = obj;
}

Object BackgroundBehaviourComponent::Father()
{
	return *father;
}

void BackgroundBehaviourComponent::Father(Object *obj)
{
	father = obj;
}

void BackgroundBehaviourComponent::Debug()
{

}

void BackgroundBehaviourComponent::Update()
{

}

