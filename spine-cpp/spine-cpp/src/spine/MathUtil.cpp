/******************************************************************************
 * Spine Runtimes License Agreement
 * Last updated April 5, 2025. Replaces all prior versions.
 *
 * Copyright (c) 2013-2025, Esoteric Software LLC
 *
 * Integration of the Spine Runtimes into software or otherwise creating
 * derivative works of the Spine Runtimes is permitted under the terms and
 * conditions of Section 2 of the Spine Editor License Agreement:
 * http://esotericsoftware.com/spine-editor-license
 *
 * Otherwise, it is permitted to integrate the Spine Runtimes into software
 * or otherwise create derivative works of the Spine Runtimes (collectively,
 * "Products"), provided that each user of the Products must obtain their own
 * Spine Editor license and redistribution of the Products in any form must
 * include this license and copyright notice.
 *
 * THE SPINE RUNTIMES ARE PROVIDED BY ESOTERIC SOFTWARE LLC "AS IS" AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL ESOTERIC SOFTWARE LLC BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES,
 * BUSINESS INTERRUPTION, OR LOSS OF USE, DATA, OR PROFITS) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 * THE SPINE RUNTIMES, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *****************************************************************************/

#include <spine/MathUtil.h>
#include <math.h>
#include <stdlib.h>
#include <cmath>


// Required for division by 0 in _isNaN on MSVC
#ifdef _MSC_VER
#pragma warning(disable : 4723)
#endif

// #ifdef  _MSC_VER //  msvc 编译器绑定的标准数学函数库比glm的要快 : glm大约830ms , std大约580ms
// #define USE_GLM_MATH 0
// #define USE_SIMD_MATH 0
// #endif

#if USE_GLM_MATH
#define GLM_FORCE_INLINE 
#define GLM_ENABLE_EXPERIMENTAL
#include <glm/gtx/fast_exponential.hpp>
#include <glm/gtx/fast_trigonometry.hpp>
#include <glm/gtx/fast_square_root.hpp>
#endif

#if USE_SIMD_MATH
#include <spine/cml.h>
#endif


using namespace spine;

const float MathUtil::Pi = 3.1415926535897932385f;
const float MathUtil::Pi_2 = 3.1415926535897932385f * 2;
const float MathUtil::InvPi_2 = 1 / MathUtil::Pi_2;
const float MathUtil::Deg_Rad = (3.1415926535897932385f / 180.0f);
const float MathUtil::Rad_Deg = (180.0f / 3.1415926535897932385f);

float MathUtil::abs(float v)
{
    return ((v) < 0 ? -(v) : (v));
}

float MathUtil::sign(float v)
{
    return ((v) < 0
        ? -1.0f
        : (v) > 0
        ? 1.0f
        : 0.0f);
}

float MathUtil::clamp(float x, float min, float max)
{
    return ((x) < (min) ? (min) : ((x) > (max) ? (max) : (x)));
}

float MathUtil::fmod(float a, float b)
{
    return (float)::fmod(a, b);
}

/// Returns atan2 in radians, faster but less accurate than Math.Atan2. Average error of 0.00231 radians (0.1323
/// degrees), largest error of 0.00488 radians (0.2796 degrees).
float MathUtil::atan2(float y, float x)
{
#if USE_GLM_MATH
    return glm::fastAtan(y, x);
#else
    return (float)::atan2(y, x);
#endif
}

float MathUtil::atan2Deg(float y, float x)
{
#if USE_GLM_MATH
    return glm::fastAtan(y, x)* MathUtil::Rad_Deg;
#else
    return MathUtil::atan2(y, x) * MathUtil::Rad_Deg;
#endif
}

/// Returns the cosine in radians from a lookup table.
float MathUtil::cos(float radians)
{
#if USE_GLM_MATH
    return glm::fastCos(radians);
#else
    return (float)::cos(radians);
#endif

}

/// Returns the sine in radians from a lookup table.
float MathUtil::sin(float radians)
{
#if USE_GLM_MATH
    return glm::fastSin(radians);
#else
    return (float)::sin(radians);
#endif
}

float MathUtil::sqrt(float v)
{
#if USE_GLM_MATH
    return glm::fastSqrt(v);
#else
    return (float)::sqrt(v);
#endif
    // fast sqrt ... 

}

float MathUtil::acos(float v)
{
#if USE_GLM_MATH
    return glm::fastAcos(v);
#else
    return (float)::acos(v);
#endif
}

/// Returns the sine in radians from a lookup table.
float MathUtil::sinDeg(float degrees)
{
#if USE_GLM_MATH
    return glm::fastSin(degrees * MathUtil::Deg_Rad);
#else
    return (float)::sin(degrees * MathUtil::Deg_Rad);
#endif
}

/// Returns the cosine in radians from a lookup table.
float MathUtil::cosDeg(float degrees)
{
#if USE_GLM_MATH
    return glm::fastCos(degrees * MathUtil::Deg_Rad);
#else
    return (float)::cos(degrees * MathUtil::Deg_Rad);
#endif

}

bool MathUtil::isNan(float v)
{
    return std::isnan(v);
}

float MathUtil::quietNan()
{
    return std::nan("");
}

float MathUtil::random()
{
    return ::rand() / (float)RAND_MAX;
}

float MathUtil::randomTriangular(float min, float max)
{
    return randomTriangular(min, max, (min + max) * 0.5f);
}

float MathUtil::randomTriangular(float min, float max, float mode)
{
    float u = random();
    float d = max - min;
    if (u <= (mode - min) / d)
        return min + sqrt(u * d * (mode - min));
    return max - sqrt((1 - u) * d * (max - mode));
}

float MathUtil::pow(float a, float b)
{
#if USE_GLM_MATH
    return glm::fastPow(a, b);
#else
    return (float)::pow(a, b);
#endif
}

float MathUtil::ceil(float v)
{
    return ::ceil(v);
}
