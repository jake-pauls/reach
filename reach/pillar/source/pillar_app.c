#include "PCH.h"
#include "pillar/pillar_app.h"

#ifdef WIN32
#include "pillar/dx11/dx11_renderer.h"
#endif

void pillar_app_init()
{
	RLOG("%s", __FUNCTION__);
}

void pillar_app_update()
{
	RLOG("%s", __FUNCTION__);
}

void pillar_app_draw(PillarApp* pillar_app)
{
	dx11_renderer_draw(pillar_app->dx11_renderer);
}

void pillar_app_destroy()
{
	RLOG("%s", __FUNCTION__);
}
