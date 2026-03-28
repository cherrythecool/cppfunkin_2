#include "Stage.hpp"

namespace funkin::objects{
    Stage::Stage(const std::string& stageName, const std::shared_ptr<Character>& boyfriend) {
		this->stageName = stageName;
    	script = std::make_shared<modding::LuaScript>("assets/stages/" + stageName + "/stage.lua");
    	script->set("boyfriend", boyfriend);
        script->call("onCreateStage", this);
    }

    Stage::~Stage() = default;
}