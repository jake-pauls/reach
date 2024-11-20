#include "PCH.h"
#include "autumn/autumn_app.h"

#include "pillar/pillar_app.h"

void autumn_app_init()
{
	pillar_app_init();
	RLOG("%s", __FUNCTION__);
}

void autumn_app_update()
{
	pillar_app_update();
	RLOG("%s", __FUNCTION__);
}

void autumn_app_destroy()
{
	pillar_app_destroy();
	RLOG("%s", __FUNCTION__);
}
