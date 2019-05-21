-- @example A simple example with one Agent that moves randomly in space.
-- @image single-agent.png

singleFooAgent = Agent{
    execute = function(self)
        self:walk()
    end
}

cs = CellularSpace{
	xdim = 5
}

cs:createNeighborhood()

e = Environment{
	cs,
	singleFooAgent
}

e:createPlacement()

m = Map{
	target = singleFooAgent,
	symbol = "owl",
	background = "white"
}

t = Timer{
	Event{action = singleFooAgent},
	Event{action = m}
}

t:run(100)

