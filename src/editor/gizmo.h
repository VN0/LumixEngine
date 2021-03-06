#pragma once


#include "engine/array.h"
#include "engine/lumix.h"
#include "engine/math.h"


namespace Lumix
{


struct Transform;
struct UniverseView;
template <typename T> struct Array;


namespace Gizmo {

struct LUMIX_EDITOR_API Config {
	enum Mode {
		TRANSLATE,
		ROTATE,
		SCALE
	} mode = TRANSLATE;

	enum CoordSystem {
		GLOBAL,
		LOCAL
	} coord_system = GLOBAL;

	bool autosnap = false;
	float steps[3] = {};
	bool is_step = false;
	Vec3 offset = {};

	bool isTranslateMode() const { return mode == TRANSLATE; }
	bool isRotateMode() const { return mode == ROTATE; }
	bool isScaleMode() const { return mode == SCALE; }
	bool isLocalCoordSystem() const { return coord_system == LOCAL; }
	bool isGlobalCoordSystem() const { return coord_system == GLOBAL; }
	bool isAutosnapDown() const { return autosnap; }
	void setAutosnapDown(bool value) { autosnap = value; }
	float getStep() const { return steps[mode]; }
	void setStep(float step) { steps[mode] = step; }
	void enableStep(bool enable) { is_step = enable; }
	Vec3 getOffset() const  { return offset; }
	void setOffset(Vec3 val) { offset = val; }
};

LUMIX_EDITOR_API bool manipulate(u64 id, UniverseView& view, Ref<Transform> tr, const Config& cfg);
LUMIX_EDITOR_API bool isActive();

}


} // namespace Lumix
