#pragma once
//------------------------------------------------------------------------------
/**
	@class	Demo::PlayerManager

	(C) 2020 Individual contributors, see AUTHORS file
*/
//------------------------------------------------------------------------------
#include "core/refcounted.h"
#include "core/singleton.h"
#include "game/manager.h"
#include "util/stringatom.h"
#include "renderutil/freecamerautil.h"
#include "topdownCameraUtil.h"
#include "topdowncamerautil.h"
#include "game/entity.h"

namespace Demo
{

class PlayerManager
{
	__DeclareSingleton(PlayerManager);
public:
	/// Create the singleton
	static Game::ManagerAPI Create();

	Game::Entity getPlayer() { return playerEntity; }

	void setCamPos(Math::point p) { topdownCamUtil.SetPosition(p); }


	/// Destroy the singleton
	static void Destroy();

private:
	/// constructor
	PlayerManager();
	/// destructor
	~PlayerManager();

	/// called when attached to game server.
	static void OnActivate();
    /// called once before every rendered frame
    static void OnBeginFrame();
	/// called once every frame
	static void OnFrame();

	Game::Entity playerEntity;

	RenderUtil::FreeCameraUtil freeCamUtil;
	RenderUtil::TopdownCameraUtil topdownCamUtil;
};

} // namespace Demo
