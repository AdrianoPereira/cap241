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

dimension = 32
-- print(Random({min=1, max=5, step=1}):number()..' number')
-- print(Random():sample()..' float')
Evacuation = Model{
    finalTime = 900,
    -- random = true,
    dim = dimension,
    people = 20,
    pos_door = Random({min=0, max=3, step=1}):sample(),
    idx_door = Random({min=0, max=dimension-1, step=1}):sample(),
    random = true,
    
    init = function(self)
        print(self.pos_door..' ---- '..self.idx_door)
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
                    cell.state = "empty" 
                    s = Random{"empty", "people"}
                    cell.state = s:sample()
                end
            end,
            execute = function(cell)
                if cell.x ~= 0 and cell.y ~= 0 and cell.x ~= self.dim-1 and cell.y ~= self.dim-1 then
                    s = Random{"empty", "people"}
                    cell.state = s:sample()
                end
                -- forEachNeighbor(cell, function(neigh)
                --     if cell.state == "people" and neigh.x ~= 0 and neigh.y ~= 0 and neigh.x ~= self.dim-1 and neigh.y ~= self.dim-1 then
                --         neigh.past.state = "selected"
                --         cell.state = "empty"
                --     end
                -- end)
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