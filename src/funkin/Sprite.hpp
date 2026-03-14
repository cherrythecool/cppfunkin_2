#pragma once

#include <string>
#include <unordered_map>

#include "AnimationController.hpp"
#include "Object.hpp"
#include "Macros.h"

namespace funkin {
	class Sprite : public Object {
	public:
		explicit Sprite(float x = 0.0f, float y = 0.0f);

		~Sprite() override;

		bool drawHitbox = false;

		float angle = 0.0f;
		float alpha = 1.0f;

		Color color = WHITE;
		Color hitboxColor = BLUE;

		Vector2 origin = Vector2Zero();
		Vector2 offset = Vector2Zero();
		Vector2 scale = Vector2One();
		Vector2 scrollFactor = Vector2One();

		GETTERSETTER(Vector2, ScrollFactor, scrollFactor)

		Rectangle source = {};
		Rectangle dest = {};
		Rectangle hitbox = {};

		Texture texture = {};

		game::AnimationController animation = game::AnimationController();

		bool loadTexture(const std::string &path);
		bool isOnScreen(float x, float y) const;

		void updateHitbox();
		void centerOffsets();

		void draw(float x, float y) override;
		void update(float delta) override;

		static void clearTextureCache();
	protected:
		static std::unordered_map<std::string, Texture> textureCache;
	};
} // funkin