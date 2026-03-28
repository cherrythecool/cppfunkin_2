function onCreateStage(stage)
    Game.defaultCamera.zoom = 0.7
    
    local sky = Sprite.new(-643, -313)
    sky:loadTexture("assets/stages/desert/skylayer.png")
    stage:add(sky)
    
    local bg5 = Sprite.new(-671, 89)
    bg5:loadTexture("assets/stages/desert/bg layer 5.png")
    stage:add(bg5)
    
    local bg4 = Sprite.new(-212, 381)
    bg4:loadTexture("assets/stages/desert/bg layer 4.png")
    stage:add(bg4)
    
    local bg3 = Sprite.new(-692, 171)
    bg3:loadTexture("assets/stages/desert/bg layer 3.png")
    stage:add(bg3)
    
    local bg2 = Sprite.new(-681, 397)
    bg2:loadTexture("assets/stages/desert/bg layer 2.png")
    stage:add(bg2)
    
    local bg1 = Sprite.new(-626, 401)
    bg1:loadTexture("assets/stages/desert/bg layer 1.png")
    stage:add(bg1)
    
    local road = Sprite.new(-755, 519)
    road:loadTexture("assets/stages/desert/road layer.png")
    stage:add(road)
    
    local car = Sprite.new(-62, 221)
    car:loadTexture("assets/stages/desert/policecar.png")
    stage:add(car)
end