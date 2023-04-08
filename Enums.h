#ifndef ENUMS_H
#define ENUMS_H

namespace Enums
{
	enum ECallType
	{
		CALL_TYPE_INVALID = -1,
		CALL_TYPE_DIALED,
		CALL_TYPE_MISSED,
		CALL_TYPE_RECEIVED,

		NUM_CALL_TYPES
	};
}

#endif // !ENUMS_H