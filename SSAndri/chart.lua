MonoLake4 = Model{
    waterInLake = 2228,
    finalTime = 2090,
    elevation = function(self)
        return 10
    end,
    execute = function(self)
        self.waterInLake = self.waterInLake + 1
    end,
    init = function(self)
        self.timer = Timer{
            Event{start = 1991, action = self}
        }
    end
}

env = Environment{
    MonoLake4{},
    MonoLake4{waterInLake = 1000},
}

chart = Chart{
    target = env,
    select = "elevation" -- if update to "waterInLake" it works
}

env:add(Event{start = 1990, action = chart})

env:run()