moveCell = function(cell, dim, pos_door, idx_door)
    line = getDoorIndexs(dim, pos_door, idx_door).door_line
    column = getDoorIndexs(dim, pos_door, idx_door).door_column
    
    if cell.x > column then
        if cell.parent:get(cell.x-1, cell.y).state == 'empty' then
            cell.state = 'empty'
            cell = cell.parent:get(cell.x-1, cell.y)
            cell.state = 'people'
        elseif cell.parent:get(cell.x-1, cell.y).state == 'door' then
            cell.state = 'empty'
        end
    elseif cell.x ~= column then
        if cell.parent:get(cell.x+1, cell.y).state == 'empty' then
            cell.state = 'empty'
            cell = cell.parent:get(cell.x+1, cell.y)
            cell.state = 'people'
        elseif cell.parent:get(cell.x+1, cell.y).state == 'door' then
            cell.state = 'empty'
        end
    end

    if cell.y > line then
        if cell.parent:get(cell.x, cell.y-1).state == 'empty' then
            cell.state = 'empty'
            cell = cell.parent:get(cell.x, cell.y-1)
            cell.state = 'people'
        elseif cell.parent:get(cell.x, cell.y-1).state == 'door' then 
            cell.state = 'empty'
        end
    elseif cell.y ~= line then
        if cell.parent:get(cell.x, cell.y+1).state == 'empty' then
            cell.state = 'empty'
            cell = cell.parent:get(cell.x, cell.y+1)
            cell.state = 'people'
        elseif cell.parent:get(cell.x, cell.y+1).state == 'door' then 
            cell.state = 'empty'
        end
    end
end

getDoorIndexs = function(dim, pos_door, idx_door)
    if pos_door == 0 then   
        return {door_line = 0, door_column = idx_door}
    elseif pos_door == 1 then
        return {door_line = idx_door, door_column = dim-1}
    elseif pos_door == 2 then
        return {door_line = dim-1, door_column = idx_door}
    elseif pos_door == 3 then
        return {door_line = idx_door, door_column = 0}
    end
end


dimension = 100

Evacuation = Model{
    finalTime = 900,
    dim = dimension,
    peoples = 50,
    door_column = 0,
    door_line = 0,
    pos_door = Random({min=0, max=3, step=1}):sample(),
    idx_door = Random({min=0, max=dimension-1, step=1}):sample(),
    random = true,
    init = function(self)
        print('Linha: '..getDoorIndexs(self.dim, self.pos_door, self.idx_door).door_line)
        print('Coluna: '..getDoorIndexs(self.dim, self.pos_door, self.idx_door).door_column)

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
                    -- print('Pessoas: '..self.peoples)
                    for i=1, self.peoples do 
                        x = math.random(1, self.dim-2)
                        y = math.random(1, self.dim-2)
                        if cell.x == y and cell.y == x then
                            cell.state = "people"
                            print('People '..i..': X = '..x..' Y = '..y)
                            break
                        else
                            cell.state = "empty"
                        end            
                    end
                end
            end,
            execute = function(cell)
                if cell.state == 'people' then
                    moveCell(cell, self.dim, self.pos_door, self.idx_door)
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