#pragma once

#include "NativeGameplayTags.h"

namespace MBTTags
{
	namespace Attribute
	{
		UE_DECLARE_GAMEPLAY_TAG_EXTERN(MoveSpeed);
	}

	namespace Character
	{
		namespace State
		{
			UE_DECLARE_GAMEPLAY_TAG_EXTERN(Sprinting);
			UE_DECLARE_GAMEPLAY_TAG_EXTERN(InSpeedUpZone);
		}
	}
}
