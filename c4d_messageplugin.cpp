#include "c4d_messageplugin.h"
#include "c4d_memory.h"
#include "c4d_basebitmap.h"
#include "c4d_file.h"
#include "c4d_general.h"
#include "c4d_gui.h"

Int32 MessageData::GetTimer(void)
{
	return 0;
}

Bool RegisterMessagePlugin(Int32 id, const String& str, Int32 info, MessageData* dat)
{
	if (!dat)
		return false;

	MESSAGEPLUGIN np;
	ClearMem(&np, sizeof(np));

	np.adr	= dat;
	np.info	= info;
	np.Destructor	 = &BaseData::Destructor;
	np.CoreMessage = &MessageData::CoreMessage;
	np.GetTimer	= &MessageData::GetTimer;

	return GeRegisterPlugin(PLUGINTYPE_COREMESSAGE, id, str, &np, sizeof(np));
}
