#include "PawnPelletHit.hpp"
#include "ManaBarManager.hpp"

void PawnPelletHit::Hit(bool& hasHit)
{
	hasHit = true;
	ManaBarManager::RefillManaShard(1, true);
}
