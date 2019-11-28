#ifndef FLUID_BEHAVIOUR_COMPONENT_H
#define FLUID_BEHAVIOUR_COMPONENT_H

class Object;

class FluidBehaviourComponent
{
private:
	Object *father;
public:
	FluidBehaviourComponent();
	FluidBehaviourComponent(Object *obj);
	Object Father();
	void Father(Object *obj);
	void Debug();
	void Update();
};

#endif // !FLUID_BEHAVIOUR_COMPONENT_H