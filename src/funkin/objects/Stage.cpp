#include "Stage.hpp"

namespace funkin::objects{
    Stage::Stage(const std::string& stageName) {
		this->stageName = stageName;
    	script = std::make_shared<modding::LuaScript>("assets/stages/" + stageName + "/stage.lua");
        script->call("onCreateStage", this);
    }

    Stage::~Stage() = default;
}