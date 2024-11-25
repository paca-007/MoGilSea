#pragma once
class DataObject
{
public:
	DataObject(DataObjectType type);
	virtual ~DataObject();


	virtual void Init() abstract;
	virtual void Update() abstract;
	virtual void Render(HDC hdc) abstract;

protected:
	DataObjectType _type = DataObjectType::NONE;
};

