print("hello world")

function onCreatePost()
    local sprite = Sprite.new(300, 300)
    sprite:loadTexture("assets/images/slungus.png")
    add(sprite)

    local song = Song.parseSong("bonedoggle-sans")
    local pf = PlayField.new(100, 150, 4, song.speed, song.opponentNotes, conductor)
    pf.botplay = true
    add(pf)
end
