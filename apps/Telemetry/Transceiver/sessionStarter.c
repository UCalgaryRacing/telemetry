#include "interfaces.h"
#include "sessionStarter.h"

static le_avdata_RequestSessionObjRef_t AvSession;
static le_avdata_SessionStateHandlerRef_t SessionStateHandlerRef;

void AvSessionStateHandler(le_avdata_SessionState_t state, void *context) {
   switch (state) {
		case LE_AVDATA_SESSION_STARTED:
			LE_INFO("Session Started!");
			break;
		case LE_AVDATA_SESSION_STOPPED:
			LE_INFO("AVData session stopped.");
			break;
		default:
			LE_FATAL("Unsupported AV session state %d", state);
			break;
   }
}

void startSession() {
	SessionStateHandlerRef = le_avdata_AddSessionStateHandler(AvSessionStateHandler, NULL);
	AvSession = le_avdata_RequestSession();
	LE_FATAL_IF(AvSession == NULL, "Failed to request avdata session");
}

