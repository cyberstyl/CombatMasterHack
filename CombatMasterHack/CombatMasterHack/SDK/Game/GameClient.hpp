#pragma once
//@TODO: bypass their hacker detection, u can just hook the diff HackerDetected functions and set it to false
//either way u wont get banned atm
class GameClient
{
	static inline bool(*oIsHackerDetected)() = nullptr;
};