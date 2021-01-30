#pragma once
#include <BML/BMLAll.h>

extern "C" {
	__declspec(dllexport) IMod* BMLEntry(IBML* bml);
}

class FramerateUnlocker : public IMod {
public:
	FramerateUnlocker(IBML* bml) : IMod(bml) {}

	virtual CKSTRING GetID() override { return "FramerateUnlocker"; }
	virtual CKSTRING GetVersion() override { return "1.0.1"; }
	virtual CKSTRING GetName() override { return "Framerate Unlocker"; }
	virtual CKSTRING GetAuthor() override { return "Swung0x48"; }
	virtual CKSTRING GetDescription() override { return "Unlock or customize framerate as you like!"; }
	DECLARE_BML_VERSION;
	IProperty* _props[2];
	virtual void Reload(int type, float framerate);
private:
	virtual void OnLoad() override;
	virtual void OnPreStartMenu() override;
	virtual void OnModifyConfig(CKSTRING category, CKSTRING key, IProperty* prop) override;
	virtual void OnLoadObject(CKSTRING filename, BOOL isMap, CKSTRING masterName,
		CK_CLASSID filterClass, BOOL addtoscene, BOOL reuseMeshes, BOOL reuseMaterials,
		BOOL dynamic, XObjectArray* objArray, CKObject* masterObj) override;
};
