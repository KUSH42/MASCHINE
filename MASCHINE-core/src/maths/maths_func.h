#ifndef __MATHS_FUNC_H_
#define __MATHS_FUNC_H_

#define _USE_MATH_DEFINES
#include <math.h>

namespace MASCHINE { namespace maths {

		inline float toRadians(float degrees)
		{
			return degrees * (M_PI / 180.0f);
		}

} }

#endif // !__MATHS_FUNC_H_

