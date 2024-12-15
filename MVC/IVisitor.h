#pragma once

class AbsPlayer;
class AbsMissile;
class GameObject;
class TextObject;

class IVisitor {
public:
	//virtual void visitPlayer(AbsPlayer* player) = 0;
	//virtual void visitMissile(AbsMissile* missile) = 0;
	virtual void visitObject(GameObject* missile) = 0;
	virtual void visitTextObject(TextObject* text) = 0;
};