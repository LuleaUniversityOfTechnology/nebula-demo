#pragma once

#include "pythonbindings.h"
#include "foundation/stdneb.h"

#include "pybind11/operators.h"
#include "pybind11/cast.h"
#include "pybind11/embed.h"
#include "pybind11/detail/class.h"
#include "pybind11/stl.h"
#include "pybind11/numpy.h"

#include "basegamefeature/managers/entitymanager.h"
#include "topDownCameraUtil.h"
#include "graphicsfeature/properties/graphics.h"
#include "managers/playermanager.h"


using namespace Demo;

namespace python
{

namespace py = pybind11;

	PYBIND11_EMBEDDED_MODULE(con, m)
	{
			m.def("spawnCube", [](Math::point p) {
				Game::EntityCreateInfo info;
				info.immediate = true;
				info.templateId = Game::GetTemplateId("MovingEntity/cube"_atm);
				Game::Entity entity = Game::CreateEntity(info);
				Game::SetProperty(entity, Game::GetPropertyId("WorldTransform"_atm), Math::translation(p.vec));
			},"Allows to spawn in an entity at specified location");

			//sets a new position for the camera
			m.def("setCamPos", [](Math::point p){PlayerManager::Instance()->setCamPos(p);});

			m.def("setFov", [](float fov) {
				//gets player
				auto player = PlayerManager::Instance()->getPlayer();
				//gets camera and camera properties
				GraphicsFeature::Camera camera = Game::GetProperty<GraphicsFeature::Camera>(player, Game::GetPropertyId("Camera"_atm));

				camera.fieldOfView = fov;
				//sets new camera properties to player
				Game::SetProperty(player, Game::GetPropertyId("Camera"_atm), camera);
			});
	}
}
