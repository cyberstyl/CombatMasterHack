#pragma once

struct Box
{
	int x = 0;
	int y = 0;
	int w = 0;
	int h = 0;
};

namespace PlayerESP
{
	void OnRender();
	void GetBoundingBox(PlayerRoot* player, Box& box);
}