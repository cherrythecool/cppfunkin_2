
#include "PerformanceTracker.hpp"

#include "utilities/CoolUtil.hpp"
#include "utilities/ProcessInfo.hpp"

#include <cmath>

namespace funkin::objects::debug {
	PerformanceTracker::PerformanceTracker(const float x, const float y) : Object(x, y) {
	}

	PerformanceTracker::~PerformanceTracker() = default;

	void PerformanceTracker::update(const float delta) {
		framesPassed++;
		const float deltaTime = std::fmaxf(static_cast<float>(GetTime()) - previousTime, 0.0f);
		updateClock += deltaTime;
		if (updateClock >= 1.0f) {
			fps = framesPassed;
			rawMemory = utilities::ProcessInfo::getMemoryUsage();
			formattedMemory = utilities::CoolUtil::formatBytes(rawMemory, 2);
			updateClock = 0.0f;
			framesPassed = 0;
		}
		previousTime = static_cast<float>(GetTime());
	}

	void PerformanceTracker::draw(const float x, const float y) {
		DrawText(TextFormat("%i FPS\n%s", fps, formattedMemory), position.x + x, position.y + y, 20, GREEN);
	}

} // namespace funkin::objects::debug
