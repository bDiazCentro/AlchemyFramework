#ifndef BACKGROUND_BEHAVIOUR_COMPONENT_H
#define BACKGROUND_BEHAVIOUR_COMPONENT_H

class Object;

class BackgroundBehaviourComponent
{
private:
	Object *father;
public:
	BackgroundBehaviourComponent();
	BackgroundBehaviourComponent(Object *obj);
	Object Father();
	void Father(Object *obj);
	void Debug();
	void Update();
};

#endif // !BACKGROUND_BEHAVIOUR_COMPONENT_H