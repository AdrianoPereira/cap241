function countNeighbors(cell, val)
  if val == nil then
    return #cell:getNeighborhood()
  end

  local count = 0
  forEachNeighbor(cell, function(neigh)
    if neigh.past.state == val then
        count = count + 1
    end
  end)
  return count
end

dimension = 40
-- print(Random({min=1, max=5, step=1}):number()..' number')
-- print(Random():sample()..' float')
Evacuation = Model{
    finalTime = 900,
    -- random = true,
    dim = dimension,
    people = 2,
    t = {},
    pos_door = Random({min=0, max=3, step=1}):sample(),
    idx_door = Random({min=0, max=dimension-1, step=1}):sample(),
    random = true,
    init = function(self)
        -- print('Door in X = '..self.pos_door..' and Y = '..self.idx_door)
        if self.pos_door == 0 then
            print('Door X = 0'..' Y = '..self.idx_door)
        elseif self.pos_door == 1 then
            print('Door X = '..self.idx_door..' Y = '..self.dim-1)            
        elseif self.pos_door == 2 then
            print('Door X = '..(self.dim-1)..' Y = '..self.idx_door)
        elseif self.pos_door == 3 then
            print('Door X = '..self.idx_door..' Y = '..0)
        end
        print('Total people: '..self.people)
        self.cell = Cell {
            init = function(cell)
                if cell.y == 0 then --Top wall
                    cell.state = "wall"
                    if self.pos_door == 0 then 
                        if self.idx_door == cell.x then
                            cell.state = "door"
                        end
                    end
                elseif cell.x == self.dim-1 then --Right wall
                    cell.state = "wall"
                    if self.pos_door == 1 then 
                        if self.idx_door == cell.y then
                            cell.state = "door"
                        end
                    end
                elseif cell.y == self.dim-1 then --Bottom wall
                    cell.state = "wall"
                    if self.pos_door == 2 then 
                        if self.idx_door == cell.x then
                            cell.state = "door"
                        end
                    end
                elseif cell.x == 0 then --Left wall
                    cell.state = "wall"
                    if self.pos_door == 3 then 
                        if self.idx_door == cell.y then
                            cell.state = "door"
                        end
                    end
                else
                    math.randomseed(os.time())
                    peoples = self.people
                    -- print('Peoples: '..peoples)
                    for i=1, peoples do 
                        x = math.random(1, self.dim-2)
                        y = math.random(1, self.dim-2)
                        table.insert(self.t, {x, y, false})
                        if cell.x == y and cell.y == x then
                            cell.state = "people"
                            print('People '..i..': X = '..x..' Y = '..y)
                            break
                        else
                            cell.state = "empty"
                        end            
                    end
                    -- cell.state = "empty" 
                    -- s = Random{"empty", "people"}
                    -- cell.state = s:sample()
                end
            end,
            execute = function(cell)
                for i=1, self.people do
                    if cell.y == self.t[i][2] and cell.x == self.t[i][1]-1 then
                        cell.state = "people"
                        if self.t[i][1]-1 > 1 then
                            self.t[i][1] = self.t[i][1]-1
                        end
                    end
                end
            end
        }

        self.space = CellularSpace {
            xdim = self.dim,
            instance = self.cell,
        }

        self.space:createNeighborhood{strategy = "vonneumann"}

        self.map = Map {
            target = self.space,
            select = "state",
            value = {"wall", "people", "door", "empty", "selected"},
            color = {"black", "blue", "green", "white", "red"}
        }

        self.timer = Timer {
            Event { action = self.space },
            Event { action = self.map }
        }
    end
}

evacuation = Evacuation{}
evacuation:run()

evacuation.map:save("evacuation.png")