#include "FramerateUnlocker.h"

IMod* BMLEntry(IBML* bml) {
	return new FramerateUnlocker(bml);
}

void FramerateUnlocker::Reload(int type, float framerate = 60.0)
{
	if (type == 0)
	{
		m_bml->GetTimeManager()->ChangeLimitOptions(CK_FRAMERATE_SYNC);
	}
	else if (type == 1) {
		m_bml->GetTimeManager()->ChangeLimitOptions(CK_FRAMERATE_FREE);
	}
	else if (type == 2) {
		m_bml->GetTimeManager()->SetFrameRateLimit(framerate);
		m_bml->GetTimeManager()->ChangeLimitOptions(CK_FRAMERATE_LIMIT);
	}
}


void FramerateUnlocker::OnLoad()
{
	GetConfig()->SetCategoryComment("Tweaking", "Tweaking");
	_props[0] = GetConfig()->GetProperty("Tweaking", "FrameRateOverrideType");
	_props[0]->SetComment("Set how to override ingame framerate. 0 for vsync, 1 for unlocked, 2 for custom capped. Other for disabled.");
	_props[0]->SetDefaultInteger(1);

	_props[1] = GetConfig()->GetProperty("Tweaking", "FramerateCap");
	_props[1]->SetComment("Framerate cap used if type has been set to 2.");
	_props[1]->SetDefaultFloat(120.0);
}

void FramerateUnlocker::OnPreStartMenu()
{
	Reload(_props[0]->GetInteger(), _props[1]->GetFloat());
}

void FramerateUnlocker::OnModifyConfig(CKSTRING category, CKSTRING key, IProperty* prop)
{
	Reload(_props[0]->GetInteger(), _props[1]->GetFloat());
}
