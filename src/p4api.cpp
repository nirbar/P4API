#include "p4/p4api.h"

ClientApi* CreateClientApi()
{
	ClientApi* api = new ClientApi();
	return api;
}

void ReleaseClientApi(ClientApi* api)
{
	if( api != NULL)
	{
		delete api;
	}
}
