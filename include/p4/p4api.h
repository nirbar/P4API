#pragma once
#include "clientapi.h"

extern "C"
{
	ClientApi* CreateClientApi();

	void ReleaseClientApi(ClientApi* api);
};