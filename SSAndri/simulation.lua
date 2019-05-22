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

function populateNeighbors(cell, dx, dy)
    -- cell.state = "empty"

    -- if cell.parent:get()
    print((cell.x)..' '..(dx))
    
    if cell.x > dy then
        if cell.parent:get(cell.y-1, cell.x).state == 'empty' then
            cell.state = 'empty'
            cell.parent:get(cell.y-1, cell.x).state = 'people'
        end
    elseif cell.x ~= dy then
        if cell.parent:get(cell.y+1, cell.x).state == 'empty' then
            cell.state = 'empty'
            cell.parent:get(cell.y+1, cell.x).state = 'people'
        end
    end
    -- if cell.parent:get(cell.x, cell.y-1) == 'empty' then -- top valid

    -- end
    -- if cell.parent:get(cell.x, cell.y-1).state ~= 'wall' then
    --     cell = cell.parent:get(cell.x, cell.y-1)
    --     cell.state = "people"
    -- end
--     cell.state = "empty"
--     cell = cs:get(cell.x + 1, cell.y)
--     if cell.state == 'wall' then
--          cell.state = 'empty'
--          return
--     end    
--     cell.state = "people"
-- return
    -- local visited = false
    -- local rand = Random{min = 0, max = 8}
    -- forEachNeighbor(cell, function(neigh)
    --     if neigh.state == 'empty' and not visited and (rand:sample() > 3) then
    --         print(neigh.x, neigh.y)
    --         visited = true 
    --         neigh.state = 'people'
    --         cell.state = 'empty'
    --         print('X = '..neigh.y..' Y = '..neigh.x)
    --     end
    --     if neigh.state == 'wall' then
    --         cell.state = 'empty'
    --     end
    -- end)
end

dimension = 40
-- print(Random({min=1, max=5, step=1}):number()..' number')
-- print(Random():sample()..' float')
Evacuation = Model{
    finalTime = 900,
    -- random = true,
    dim = dimension,
    people = 10,
    t = {},
    mcount = 0,
    dx = 0,
    dy = 0,
    pos_door = Random({min=0, max=3, step=1}):sample(),
    idx_door = Random({min=0, max=dimension-1, step=1}):sample(),
    random = true,
    init = function(self)
        -- print('Door in X = '..self.pos_door..' and Y = '..self.idx_door)
        if self.pos_door == 0 then
            self.dx = 0
            self.dy = self.idx_door
            print('Door X = 0'..' Y = '..self.idx_door)
        elseif self.pos_door == 1 then
            self.dx = self.idx_door
            self.dy = self.dim-1
            print('Door X = '..self.idx_door..' Y = '..self.dim-1)            
        elseif self.pos_door == 2 then
            self.dx = self.dim-1
            self.dy = self.idx_door
            print('Door X = '..(self.dim-1)..' Y = '..self.idx_door)
        elseif self.pos_door == 3 then
            self.dx = self.idx_door
            self.dy = 0
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
                --print(self)
                --forEachCell(self, function(cell)
                    if cell.state == 'people' then
                        -- if self.mcount < 20 then
                        populateNeighbors(cell, self.dx, self.dy)
                        --self.mcount = self.mcount + 1
                        -- end
                    end
                --end)
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